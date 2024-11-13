#include "User.h"
using namespace std;

// Constructor implementation
User::User(const string& uname, const string& pass, const string& role)
    : username(uname), password(pass), role(role) {}

// Method to login
void User::login() {
    cout << "Nhap ten dang nhap cua ban: " << endl;
    cin >> username;
    cout << "Nhap mat khau cua ban: " << endl;
    cin >> password;

}

void User::showProfile() {
    cout << "Ten dang nhap: " << username << endl;
    cout << "Mat khau: " << username << endl;
}
