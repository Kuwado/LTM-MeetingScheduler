#include "../controllers/ClientController.h"
#include "../controllers/ResponseController.h"
#include "../controllers/TeacherController.h"
#include "../controllers/StudentController.h"
#include "../controllers/UserController.h"

#include "../utils/MessageUtils.h"
#include "../views/StudentView.h"
#include "../views/TeacherView.h"
#include "../views/UserView.h"
#include <QApplication>
#include <QWidget>
#include "../views/teacherviews/timeslotdialog.h"
#include "../views/teacherviews/viewtimeslotsdialog.h"
#include "../views/teacherviews/update_timeslot_dialog.h"
#include "../views/teacherviews/teacherviewmeetingsdialog.h"
#include "../views/teacherviews/meetingdetaildialog.h"
#include "../views/teacherviews/meetinghistorydialog.h"
#include "../views/teacherviews/TeacherMenuWidget.h"
#include "../views/teacherviews/viewmeetinghistorydialog.h"
#include "../views/teacherviews/viewweeklymeetingsdialog.h"
#include "../views/userviews/loginwidget.h"
#include "../views/userviews/mainmenu.h"
#include "../views/userviews/registerwidget.h"
#include "../views/studentviews/ViewAllTeacherWidget.h"
#include <QMessageBox>

#include <algorithm>
#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>
#include <vector>

#define SERVER_IP "127.0.0.1"
// #define SERVER_IP "172.0.1.252"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

int clientSocket;
struct sockaddr_in serverAddr;
TeacherView teacherView;
StudentView studentView;
UserView userView;
UserController userController;
ClientController clientController;
ResponseController responseController;
TeacherController teacherController;
StudentController studentController;
int user_id = 0;
string role = "none";

void connectToServer() {
    // Tạo socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Lỗi tạo socket" << std::endl;
        exit(1);
    }

    // Cấu hình địa chỉ server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    // Kết nối tới server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Lỗi kết nối tới server" << std::endl;
        exit(1);
    }
}

vector<string> splitString(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);

    // Sử dụng getline để tách chuỗi
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool endsWith(const string &str, const string &suffix) {
    if (str.size() >= suffix.size()) {
        return str.substr(str.size() - suffix.size()) == suffix;
    }
    return false;
}

string sendRequestToServer(const string &command) {
    // send(clientSocket, command.c_str(), command.size(), 0);
    int totalSize = command.size();
    int offset = 0;

    // Gửi chuỗi theo từng phần nhỏ
    while (offset < totalSize) {
        // Tính toán độ dài của phần gửi
        int partSize = min(BUFFER_SIZE, totalSize - offset);

        // Gửi phần chuỗi
        int bytesSent = send(clientSocket, command.c_str() + offset, partSize, 0);

        if (bytesSent < 0) {
            cerr << "Lỗi khi gửi dữ liệu!" << endl;
            break;
        }

        // Cập nhật offset để gửi phần tiếp theo
        offset += bytesSent;
    }

    // Nhận phản hồi từ server
    char buffer[BUFFER_SIZE];
    string response;
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            break; // Kết thúc khi không nhận thêm dữ liệu hoặc có lỗi
        }
        // Chuyển buffer thành string
        string partResponse(buffer, bytesReceived);

        // Thêm phần phản hồi vào response
        response += partResponse;

        if (endsWith(partResponse, "|<END>")) {
            response = response.substr(0, response.length() - 6);
            break;
        }
    }

    return response.empty() ? "100" : response;
}
void handleUserMenu();
void logout() {
    user_id = 0;
    role = "none";
    
    // Đóng cửa sổ hiện tại
    QWidget* currentWidget = QApplication::activeWindow();
    if (currentWidget) {
        currentWidget->close();  // Đóng cửa sổ hiện tại
    }
    
    // Hiển thị lại menu người dùng
    handleUserMenu();
}


// Teacher
void handleDeclareTimeSlot() {
    TimeslotDialog dialog(user_id);  // Bỏ this vì không có parent widget
    if (dialog.exec() == QDialog::Accepted) {
        Timeslot ts = dialog.getTimeslot();
        string request = "DECLARE_TIME_SLOT|" + ts.toStringDeclare() + "|<END>";
        cout << request << endl;
        string response = sendRequestToServer(request);
        string status = response.substr(0, response.find('|'));
        if (status == "0") {
            vector<string> tokens = splitString(response, '|');
            QMessageBox::information(nullptr, "Thông báo", 
                QString::fromStdString(tokens[1]));

        } else if (status == "13") {
            vector<string> tokens = splitString(response, '|');
            QMessageBox::information(nullptr, "Thông báo", 
                QString::fromStdString(tokens[1]));
            
        }
    }
}

void handleUpdateTimeslot(const Timeslot &timeslot) {
    // Hiển thị hộp thoại cập nhật thời gian
    UpdateTimeslotDialog dialog(timeslot);
    if (dialog.exec() == QDialog::Accepted) {
        // Lấy thông tin đã cập nhật từ hộp thoại
        Timeslot tsUpdate = dialog.getUpdatedTimeslot();
        
        // Tạo chuỗi yêu cầu gửi đến server
        string request = "UPDATE_TIME_SLOT|" + tsUpdate.toStringUpdate() + "|<END>";
        
        // Gửi yêu cầu đến server và nhận phản hồi
        string response = sendRequestToServer(request);
        
        // Kiểm tra trạng thái phản hồi
        string status = response.substr(0, response.find('|'));
        if (status == "0") {
            vector<string> tokens = splitString(response, '|');
            cout << tokens[1] << endl;
        }
    }
}


void handleViewTimeslots() {
    string request = "VIEW_TIME_SLOTS|" + to_string(user_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        map<string, vector<Timeslot>> timeslots = clientController.viewTimeslots(response);
        
       
        ViewTimeslotsDialog dialog(timeslots);  // Khởi tạo đối tượng dialog với timeslots
        if (dialog.exec() == QDialog::Accepted) {
            Timeslot ts = dialog.getSelectedTimeslot();
            if (ts.getId() == -1) {
                return;
            }

            int choice = dialog.showTimeslot(ts);  // Gọi showTimeslot từ dialog
            if (choice == 0) {
                handleViewTimeslots();  // Nếu không muốn chỉnh sửa, quay lại xem
            } else {
                handleUpdateTimeslot(ts);  // Nếu muốn chỉnh sửa, xử lý cập nhật
                handleViewTimeslots();  // Xem lại danh sách sau khi cập nhật
            }
        }

    } else if (status == "8") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "9") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleEditReport(const int &meeting_id, const string &report) {
    string request = "ENTER_MEETING_REPORT|" + to_string(meeting_id) + "|" + report + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    vector<string> tokens = splitString(response, '|');
    cout << tokens[1] << endl;
}

void handleUpdateStatus(const int &meeting_id, const string &mstatus) {
    string request = "UPDATE_MEETING_STATUS|" + to_string(meeting_id) + "|" + mstatus + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    vector<string> tokens = splitString(response, '|');
    cout << tokens[1] << endl;
}

void handleTeacherViewMeeting(const int &meeting_id) {
    string request = "VIEW_MEETING|" + to_string(meeting_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        pair<Meeting, vector<User>> meetingDetail = teacherController.getMeetingFromResponse(response);
        
        MeetingDetailDialog dialog(meetingDetail.first, meetingDetail.second);
        if (dialog.exec() == QDialog::Accepted) {
            int choice = dialog.getResult();
            if (choice == 0) {
                return;
            } else if (choice == 1) {
                string report = dialog.getReport().toStdString();
                handleEditReport(meeting_id, report);
                handleTeacherViewMeeting(meeting_id);
            } else if (choice == 2) {
                string newStatus = dialog.getStatus().toStdString();
                handleUpdateStatus(meeting_id, newStatus);
                handleTeacherViewMeeting(meeting_id);
            }
        }
    }
}
void handleTeacherViewMeetings() {
    Meeting selectedMeeting; 
    // Tạo yêu cầu từ ID người dùng
    string request = "VIEW_MEETINGS|" + to_string(user_id) + "|<END>";
    
    // Gửi yêu cầu và nhận phản hồi
    string response = sendRequestToServer(request);
    
    // Kiểm tra trạng thái phản hồi
    string status = response.substr(0, response.find('|'));

    // Nếu trạng thái phản hồi là "0", xử lý cuộc họp
    if (status == "0") {
        // Lấy danh sách cuộc họp từ phản hồi
        map<string, vector<Meeting>> meetings = teacherController.getMeetingsFromResponse(response);
        
        // Chuyển dữ liệu cuộc họp sang QMap<QString, QVector<Meeting>> cho giao diện Qt
        QMap<QString, QVector<Meeting>> qtMeetings;
        for (const auto& meetingPair : meetings) {
            QString date = QString::fromStdString(meetingPair.first);
            QVector<Meeting> meetingList;
            for (const Meeting& meeting : meetingPair.second) {
                meetingList.append(meeting);
            }
            qtMeetings[date] = meetingList;
        }

        // Hiển thị giao diện TeacherViewMeetingsDialog
        TeacherViewMeetingsDialog dialog(qtMeetings);
        if (dialog.exec() == QDialog::Accepted) {
            // Nhận cuộc họp đã chọn
            selectedMeeting = dialog.getSelectedMeeting();
            
            if (selectedMeeting.getId() == -1) {
                return; // Nếu không có cuộc họp nào được chọn
            }

            // Xử lý cuộc họp chi tiết
            handleTeacherViewMeeting(selectedMeeting.getId());
            
            // Tiếp tục xử lý các cuộc họp khác
            handleTeacherViewMeetings();
        }
    } 
    // Nếu trạng thái là "16", hiển thị thông báo lỗi
    else if (status == "16") {
        vector<string> tokens = splitString(response, '|');
        QString errorMessage = QString::fromStdString(tokens[1]);
        QMessageBox::critical(nullptr, "Lỗi", errorMessage); // Hiển thị lỗi trong QMessageBox Qt
    }
}

void handleTeacherViewHistoryMeeting(const int &meeting_id) {
    // Tạo yêu cầu để lấy thông tin lịch hẹn từ server
    string request = "VIEW_MEETING|" + to_string(meeting_id) + "|<END>";
    string response = sendRequestToServer(request);

    // Phân tích phản hồi từ server
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        // Lấy thông tin chi tiết lịch hẹn và danh sách người tham gia
        pair<Meeting, vector<User>> meetingDetail = teacherController.getMeetingFromResponse(response);

        // Tạo dialog và hiển thị thông tin lịch hẹn
        MeetingHistoryDialog dialog(meetingDetail.first, meetingDetail.second);
        if (dialog.exec() == QDialog::Accepted) {
            // Nếu nhấn "OK" trong dialog, kiểm tra xem văn bản báo cáo có thay đổi không
            QString newReport = dialog.getReport();
            if (newReport.toStdString() != meetingDetail.first.getReport()) {
                // Gửi báo cáo đã chỉnh sửa lên server
                handleEditReport(meeting_id, newReport.toStdString());

                // Hiển thị lại giao diện với thông tin đã cập nhật
                handleTeacherViewHistoryMeeting(meeting_id);
            }
        }
    } else {
        // Xử lý trường hợp lỗi
        cout << "Không thể lấy thông tin cuộc hẹn. Mã lỗi: " << status << endl;
    }
}

// Modified handleTeacherViewHistory function
void handleTeacherViewHistory() {
    string request = "VIEW_HISTORY|" + to_string(user_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    
    if (status == "0") {
        map<string, vector<Meeting>> meetings = teacherController.getMeetingsFromResponse(response);
        
        ViewMeetingHistoryDialog dialog;
        Meeting meeting = dialog.showHistory(meetings);
        
        if (meeting.getId() == -1) {
            return;
        }
        
        // Detail Meeting
        handleTeacherViewHistoryMeeting(meeting.getId());
        handleTeacherViewHistory();
    } else if (status == "18") {
        vector<string> tokens = splitString(response, '|');
        QMessageBox::warning(nullptr, "Thông báo", QString::fromStdString(tokens[1]));
    }
}

void handleTracherViewMeetingsInWeeks() {
    string request = "VIEW_MEETINGS_IN_WEEKS|" + to_string(user_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    
    if (status == "0") {
        map<string, map<string, vector<pair<Meeting, vector<User>>>>> meetings =
            teacherController.getMeetingsInWeeksFromResponse(response);
            
        ViewWeeklyMeetingsDialog dialog(meetings);
        if (dialog.exec() == QDialog::Accepted) {
            Meeting meeting = dialog.getSelectedMeeting();
            if (meeting.getId() == -1) {
                return;
            }
            // Detail Meeting
            handleTeacherViewMeeting(meeting.getId());
            handleTracherViewMeetingsInWeeks();
        }
    } else if (status == "16") {
        vector<string> tokens = splitString(response, '|');
        QMessageBox::warning(nullptr, "Lỗi", QString::fromStdString(tokens[1]));
    }
}


void handleTeacherMenu() {
    TeacherMenuWidget* teacherMenuWidget = new TeacherMenuWidget();

    // Kết nối tín hiệu từ các nút
    QObject::connect(teacherMenuWidget, &TeacherMenuWidget::actionSelected, [&](int action) {
        switch(action) {
            case 0: // Đăng xuất
                logout();
                break;
            case 1: // Khai báo thời gian rảnh
                handleDeclareTimeSlot();
                handleTeacherMenu();  // Gọi lại menu sau khi thực hiện
                break;
            case 2: // Kiểm tra thời gian rảnh
                handleViewTimeslots();
                handleTeacherMenu();
                break;
            case 3: // Xem lịch hẹn với sinh viên
                handleTeacherViewMeetings();
                handleTeacherMenu();
                break;
            case 4: // Xem lịch sử cuộc hẹn
                handleTeacherViewHistory();
                handleTeacherMenu();
                break;
            case 5: // Xem lịch hẹn theo tuần
                handleTracherViewMeetingsInWeeks();
                handleTeacherMenu();
                break;
            default:
                break;
        }
    });

    teacherMenuWidget->show();
}

// Student
// Student
void handleBookMeeting(const Meeting &meeting) {
    string request = "BOOK_MEETING|" + to_string(user_id) + "|" + to_string(meeting.getTimeslotId()) + "|" +
                     meeting.getType() + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "17") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "10") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "19") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "20") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleViewTimeslotsOfTeacher(const int &teacher_id, const string &teacherName) {
    string request = "VIEW_FREE_TIME_SLOTS|" + to_string(teacher_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        map<string, vector<Timeslot>> timeslots = studentController.viewTimeslots(response);
        Timeslot ts = studentView.showTimeslots(timeslots, teacherName);
        if (ts.getId() == -1) {
            return;
        }
        // Detail Timeslot
        Meeting meeting = studentView.showBookMeeting(ts, teacherName);
        if (meeting.getId() == -1) {
            return;
        } else {
            handleBookMeeting(meeting);
            handleViewTimeslotsOfTeacher(teacher_id, teacherName);
        }

    } else if (status == "8") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "9") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}
void handleStudentMenu();
void handleViewAllTeacher() {
    string request = "FETCH_ALL_TEACHER|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find("|"));

    if (status == "0") {
        vector<User> teachers = studentController.getAllTeacher(response);

        // Hiển thị giao diện Qt
        ViewAllTeacherWidget* widget = new ViewAllTeacherWidget(teachers);
        QEventLoop loop;
        
        QObject::connect(widget, &ViewAllTeacherWidget::teacherSelected, [&](const pair<string, int>& teacher) {
            if (teacher.second != -1) {
                handleViewTimeslotsOfTeacher(teacher.second, teacher.first);
            }
            loop.quit();
        });

        QObject::connect(widget, &ViewAllTeacherWidget::destroyed, [&]() {
            loop.quit();
        });

        widget->show();
        loop.exec();

        handleViewAllTeacher();  // Quay lại giao diện sau khi xử lý
    } else if (status == "8") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}





void handleCancelMeeting() {
    string requestMeeting = "FETCH_STUDENT_METTINGS|" + to_string(user_id) + "|<END>";
    string responseMeeting = sendRequestToServer(requestMeeting);
    string statusMeeting = responseMeeting.substr(0, responseMeeting.find('|'));
    if (statusMeeting == "0") {
        vector<Meeting> meetings = clientController.parseMeetingsFromResponse(responseMeeting);
        int meetingId = studentView.selectMeeting(meetings);
        string cancelRequest = "CANCEL_MEETING|" + to_string(meetingId) + "|" + to_string(user_id) + "|<END>";
        string cancelResponse = sendRequestToServer(cancelRequest);
    }
}

void handleStudentMenu() {
    int choice = studentView.showMenu();
    switch (choice) {
    case 0:
        logout();
        break;
    case 1:
        handleViewAllTeacher();
        handleStudentMenu();
        break;
    case 2:
        handleCancelMeeting();
        // handleViewTimeslots();
        handleTeacherMenu();
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        break;
    }
}


void handleLogin() {
    LoginWidget* loginWidget = new LoginWidget();
    
    // Kết nối signals
    QObject::connect(loginWidget, &LoginWidget::loginClicked, [loginWidget]() {
        map<string, string> info = loginWidget->getLoginInfo();
        string loginCommand = "LOGIN|" + info["username"] + "|" + info["password"] + "|<END>";
        string response = sendRequestToServer(loginCommand);
        vector<string> result = splitString(response, '|');
        
        if (result[0] == "0") {
            user_id = stoi(result[1]);
            role = result[2];
            cout << role << result[3] << endl;
            QMessageBox::information(loginWidget, "Thành công", 
                QString::fromStdString(result[3]));
            loginWidget->close();
            if (role == "teacher" && user_id != 0) {
                handleTeacherMenu();
            } 
            else if (role == "student" && user_id != 0) {
                handleStudentMenu();
            }
        } 
        else if (result[0] == "1" || result[0] == "2") {
            QMessageBox::warning(loginWidget, "Lỗi", 
                QString::fromStdString(result[1]));
        } 
        else {
            loginWidget->close();
            logout();
        }
    });
    
    QObject::connect(loginWidget, &LoginWidget::backClicked, [loginWidget]() {
        loginWidget->close();
        handleUserMenu();
    });
    
    loginWidget->show();
    
    // Event loop để đợi cửa sổ đóng
    QEventLoop loop;
    QObject::connect(loginWidget, &LoginWidget::destroyed, &loop, &QEventLoop::quit);
    loop.exec();
}

void handleRegister() {
    RegisterWidget* registerWidget = new RegisterWidget();
    
    // Kết nối signal đăng ký
    QObject::connect(registerWidget, &RegisterWidget::registerClicked, [registerWidget]() {
        map<string, string> info = registerWidget->getRegisterInfo();
        
        string registerCommand = "REGISTER|" + info["username"] + "|" + info["password"] + "|" + 
                               info["role"] + "|" + info["first_name"] + "|" + info["last_name"] + "|<END>";
        
        string response = sendRequestToServer(registerCommand);
        vector<string> result = splitString(response, '|');
        
        if (result[0] == "0") {
            user_id = stoi(result[2]);
            role = result[3];
            cout << user_id << role << result[1] << endl;
            QMessageBox::information(registerWidget, "Thành công", 
                QString::fromStdString(result[1]));
                
            registerWidget->close();
            
            if (role == "teacher" && user_id != 0) {
                handleTeacherMenu();
            } else if (role == "student" && user_id != 0) {
                handleStudentMenu();
            }
        } 
        else if (result[0] == "3") {
            QMessageBox::warning(registerWidget, "Lỗi", 
                QString::fromStdString(result[1]));
        }
    });
    
    // Kết nối signal quay lại
    QObject::connect(registerWidget, &RegisterWidget::backClicked, [registerWidget]() {
        registerWidget->close();
        handleUserMenu();
    });
    
    registerWidget->show();
    
    // Event loop để đợi cửa sổ đóng
    QEventLoop loop;
    QObject::connect(registerWidget, &RegisterWidget::destroyed, &loop, &QEventLoop::quit);
    loop.exec();
}
void handleUserMenu() {
    MainMenu* menu = new MainMenu();
    
    // Kết nối signals
    QObject::connect(menu, &MainMenu::loginSelected, [menu]() {
        menu->close();  // Đóng cửa sổ
        handleLogin();  // Xử lý đăng nhập
    });

    
    QObject::connect(menu, &MainMenu::registerSelected, [menu]() {
        menu->close();
        handleRegister();
    });
    
    menu->show();
    
    // Event loop để đợi cửa sổ đóng
    QEventLoop loop;
    QObject::connect(menu, &MainMenu::destroyed, &loop, &QEventLoop::quit);
    loop.exec();
    
    // Lấy lựa chọn và xử lý tiếp
    int choice = menu->getChoice();
    if (choice != 0) {  // Nếu đã chọn một option
        handleUserMenu();  // Quay lại menu chính
    }
}

void closeConnection() { close(clientSocket); }

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);  
    
    connectToServer();
    handleUserMenu();
    closeConnection();
    
    return app.exec();
}
