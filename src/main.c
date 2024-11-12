#include <windows.h>

// Hàm Window Procedure xử lý các thông điệp của cửa sổ
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            if (LOWORD(wp) == 1) { // ID của nút bấm là 1
                MessageBox(hwnd, "Nút đã được nhấn!", "Thông báo", MB_OK | MB_ICONINFORMATION);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0); // Đóng ứng dụng khi cửa sổ bị đóng
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int main() {
    // Khai báo thông tin cửa sổ
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;  // Chỉ định hàm xử lý thông điệp
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "BasicWindowClass";

    // Đăng ký lớp cửa sổ
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Lỗi đăng ký lớp cửa sổ", "Lỗi", MB_OK | MB_ICONERROR);
        return 1;
    }

    // Tạo cửa sổ
    HWND hwnd = CreateWindow(
        wc.lpszClassName, "Ứng Dụng Cơ Bản", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, wc.hInstance, NULL
    );

    if (!hwnd) {
        MessageBox(NULL, "Lỗi tạo cửa sổ", "Lỗi", MB_OK | MB_ICONERROR);
        return 1;
    }

    // Tạo nút bấm
    CreateWindow("BUTTON", "Nhấn tôi", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 150, 100, 100, 30, hwnd, (HMENU)1, wc.hInstance, NULL);

    // Hiển thị cửa sổ
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // Vòng lặp tin nhắn
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
