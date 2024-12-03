#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <gtk/gtk.h>
#include <string>
#include <functional>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "../client/Client.h"  // Bao gồm Client.h để gọi hàm gửi yêu cầu đến server
using namespace std;

class LoginView {
public:
    LoginView(const std::function<void()> &onRegisterCallback)
        : onRegisterCallback(onRegisterCallback) {

        // Khởi tạo GTK
        gtk_init(nullptr, nullptr);

        // Tạo cửa sổ chính
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Đăng nhập");
        gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);

        // Tạo container chính
        mainBox = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(window), mainBox);

        

        // Sử dụng trong LoginView
        GtkWidget *backgroundImage = createScaledImage("/home/dinhnam/Github/LTM-MeetingScheduler/src/images/background.jpg", 500, 300);

        gtk_fixed_put(GTK_FIXED(mainBox), backgroundImage, 0, 0);
        // Tạo các trường nhập liệu
        usernameEntry = gtk_entry_new();
        passwordEntry = gtk_entry_new();
        gtk_entry_set_visibility(GTK_ENTRY(passwordEntry), false);

        // Tạo các nút
        GtkWidget *loginButton = gtk_button_new_with_label("Đăng nhập");
        GtkWidget *registerButton = gtk_button_new_with_label("Đăng ký");

        // Đặt các phần tử vào container
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Tên đăng nhập:"), 100, 60);
        gtk_fixed_put(GTK_FIXED(mainBox), usernameEntry, 230, 50);
        gtk_fixed_put(GTK_FIXED(mainBox), gtk_label_new("Mật khẩu:"), 100, 110);
        gtk_fixed_put(GTK_FIXED(mainBox), passwordEntry, 230, 100);
        gtk_fixed_put(GTK_FIXED(mainBox), loginButton, 100, 150);
        gtk_fixed_put(GTK_FIXED(mainBox), registerButton, 300, 150);

        // Gắn kết các tín hiệu với các hàm xử lý
        g_signal_connect(loginButton, "clicked", G_CALLBACK(onLoginButtonClicked), this);
        g_signal_connect(registerButton, "clicked", G_CALLBACK(onRegisterButtonClicked), this);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);
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


    void showLoginWindow() {
        gtk_widget_show_all(window);
        gtk_main();
    }

    std::string getUsername() {
        return username;
    }

    std::string getPassword() {
        return password;
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
    std::string username;
    std::string password;
    std::function<void()> onRegisterCallback;  // Callback để chuyển sang màn hình đăng ký

    static void onLoginButtonClicked(GtkWidget *widget, gpointer data) {
        LoginView *view = static_cast<LoginView *>(data);
        view->username = gtk_entry_get_text(GTK_ENTRY(view->usernameEntry));
        view->password = gtk_entry_get_text(GTK_ENTRY(view->passwordEntry));

        // Tạo lệnh đăng nhập và gửi tới server
        std::string loginCommand = "LOGIN|" + view->username + "|" + view->password;
        sendRequestToServer(loginCommand);  // Gửi yêu cầu tới server

        gtk_widget_destroy(view->window);  // Đóng cửa sổ đăng nhập
    }

    static void onRegisterButtonClicked(GtkWidget *widget, gpointer data) {
        LoginView *view = static_cast<LoginView *>(data);
        gtk_widget_destroy(view->window);  // Đóng cửa sổ đăng nhập
        if (view->onRegisterCallback) {
            view->onRegisterCallback();  // Gọi callback chuyển sang màn hình đăng ký
        }
    }
};

#endif
