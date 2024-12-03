#ifndef REGISTER_VIEW_H
#define REGISTER_VIEW_H

#include <gtk/gtk.h>
#include <string>
#include <functional>
#include "../client/Client.h"  // Bao gồm Client.h để gọi hàm gửi yêu cầu đến server

class RegisterView {
public:
    RegisterView(const std::function<void()> &onLoginCallback)
        : onLoginCallback(onLoginCallback) {

        // Khởi tạo GTK
        gtk_init(nullptr, nullptr);

        // Tạo cửa sổ đăng ký
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Đăng ký");
        gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);

        // Tạo container chính
        mainBox = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(window), mainBox);
        
        GtkWidget *backgroundImage = createScaledImage("/home/dinhnam/Github/LTM-MeetingScheduler/src/images/bg1.jpg", 500, 300);

        gtk_fixed_put(GTK_FIXED(mainBox), backgroundImage, 0, 0);

        // Tạo các trường nhập liệu
        usernameEntry = gtk_entry_new();
        passwordEntry = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(passwordEntry), false);
        firstNameEntry = gtk_entry_new();
        lastNameEntry = gtk_entry_new();

        // Tạo ComboBox để chọn vai trò
        roleComboBox = gtk_combo_box_text_new();
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(roleComboBox), "student");
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(roleComboBox), "teacher");
        gtk_combo_box_set_active(GTK_COMBO_BOX(roleComboBox), 0);  // Mặc định là "student"

        // Tạo các nút
        GtkWidget *registerButton = gtk_button_new_with_label("Đăng ký");
        GtkWidget *loginButton = gtk_button_new_with_label("Đăng nhập");

        // Đặt các phần tử vào container
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Tên đăng nhập:"), 100, 60);
        gtk_fixed_put(GTK_FIXED(mainBox), usernameEntry, 230, 50);
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Mật khẩu:"), 100, 110);
        gtk_fixed_put(GTK_FIXED(mainBox), passwordEntry, 230, 100);
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Họ:"), 100, 160);
        gtk_fixed_put(GTK_FIXED(mainBox), firstNameEntry, 230, 150);
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Tên:"), 100, 210);
        gtk_fixed_put(GTK_FIXED(mainBox), lastNameEntry, 230, 200);
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Vai trò:"), 100, 260);
        gtk_fixed_put(GTK_FIXED(mainBox), roleComboBox, 305, 250);
        gtk_fixed_put(GTK_FIXED(mainBox), registerButton, 300, 300);
        gtk_fixed_put(GTK_FIXED(mainBox), loginButton, 100, 300);

        // Gắn kết các tín hiệu với các hàm xử lý
        g_signal_connect(registerButton, "clicked", G_CALLBACK(onRegisterButtonClicked), this);
        g_signal_connect(loginButton, "clicked", G_CALLBACK(onLoginButtonClicked), this);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);
    }

    void showRegisterWindow() {
        gtk_widget_show_all(window);
        gtk_main();
    }

    GtkWidget *createScaledImage(const char *filePath, int width, int height) {
    // Tải ảnh từ file
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(filePath, nullptr);
        
        // Kiểm tra nếu ảnh không tải được
        if (!pixbuf) {
            g_printerr("Lỗi khi tải ảnh: %s\n", filePath);
            return nullptr;  // Trả về nullptr nếu ảnh không tải được
        }

        // Scale ảnh
        GdkPixbuf *scaledPixbuf = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);
        
        // Giải phóng ảnh gốc sau khi scale
        g_object_unref(pixbuf); 

        if (!scaledPixbuf) {
            g_printerr("Lỗi khi scale ảnh\n");
            return nullptr;  // Trả về nullptr nếu không thể scale ảnh
        }

        GtkWidget *image = gtk_image_new_from_pixbuf(scaledPixbuf);

        // Giải phóng ảnh đã scale
        g_object_unref(scaledPixbuf); 

        return image;
    }
    void show() {
        gtk_widget_show_all(window);
    }

    void hide() {
        gtk_widget_hide(window);
    }

private:
    GtkWidget *window;
    GtkWidget *mainBox;
    GtkWidget *usernameEntry;
    GtkWidget *passwordEntry;
    GtkWidget *firstNameEntry;
    GtkWidget *lastNameEntry;
    GtkWidget *roleComboBox;  // ComboBox cho vai trò
    std::function<void()> onLoginCallback;  // Callback để chuyển sang màn hình đăng nhập

    static void onRegisterButtonClicked(GtkWidget *widget, gpointer data) {
        RegisterView *view = static_cast<RegisterView *>(data);
        std::string username = gtk_entry_get_text(GTK_ENTRY(view->usernameEntry));
        std::string password = gtk_entry_get_text(GTK_ENTRY(view->passwordEntry));
        std::string firstName = gtk_entry_get_text(GTK_ENTRY(view->firstNameEntry));
        std::string lastName = gtk_entry_get_text(GTK_ENTRY(view->lastNameEntry));

        // Lấy vai trò từ ComboBox
        const char *role = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(view->roleComboBox));

        // Tạo lệnh đăng ký và gửi tới server
        std::string registerCommand = "REGISTER|" + username + "|" + password + "|" + role + "|" + firstName + "|" + lastName;
        sendRequestToServer(registerCommand);  // Gửi yêu cầu tới server

        gtk_widget_destroy(view->window);  // Đóng cửa sổ đăng ký
    }

    static void onLoginButtonClicked(GtkWidget *widget, gpointer data) {
        RegisterView *view = static_cast<RegisterView *>(data);
        gtk_widget_destroy(view->window);  // Đóng cửa sổ đăng ký
        if (view->onLoginCallback) {
            view->onLoginCallback();  // Gọi callback chuyển sang màn hình đăng nhập
        }
    }
};

#endif
