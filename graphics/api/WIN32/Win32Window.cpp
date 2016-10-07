#include "Win32Window.h"

HINSTANCE Win32Window::hInstance = 0;
bool Win32Window::initialized = false;

const LPCSTR applicationName = "AVI_GAME_ENGINE";

static PIXELFORMATDESCRIPTOR getPixelFormatDescriptor() {
    PIXELFORMATDESCRIPTOR PixelFormatDesc = {};

    PixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    PixelFormatDesc.nVersion = 1;
    PixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    PixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
    PixelFormatDesc.cColorBits = 32;
    PixelFormatDesc.cDepthBits = 24;
    PixelFormatDesc.cStencilBits = 8;
    PixelFormatDesc.cAuxBuffers = 0;
    PixelFormatDesc.iLayerType = PFD_MAIN_PLANE;

    return PixelFormatDesc;
};

Win32Window::Win32Window() : Win32Window(GetModuleHandle(0), 640, 480) {
}

Win32Window::Win32Window(HINSTANCE hInst, int16_t width, int16_t height) {
    ApplicationHandle = this;
    windowWidth = width;
    windowHeight = height;

    WNDCLASSEX winClassEX = {};

    winClassEX.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    winClassEX.lpfnWndProc = WndProc;
    winClassEX.cbClsExtra = 0;
    winClassEX.cbWndExtra = 0;
    winClassEX.hInstance = hInst;
    winClassEX.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
    winClassEX.hIconSm = winClassEX.hIcon;
    winClassEX.hCursor = LoadCursor(nullptr, IDC_ARROW);
    winClassEX.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    winClassEX.lpszMenuName = nullptr;
    winClassEX.lpszClassName = applicationName;
    winClassEX.cbSize = sizeof(WNDCLASSEX);

    RegisterClassEx(&winClassEX);

    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);

    hwnd = CreateWindowEx(WS_EX_APPWINDOW,
                          applicationName,
                          applicationName,
                          WS_POPUP,
                          (int) ((screenWidth / 2) - (windowWidth / 2)),
                          (int) ((screenHeight / 2) - (windowHeight / 2)),
                          windowWidth, windowHeight,
                          nullptr, nullptr,
                          hInstance,
                          nullptr);

    if (hwnd == nullptr) {
        MessageBoxEx(hwnd, "Error", "Error Creating HWND", 0, 0);
    }

    ShowWindow(hwnd, SW_SHOW);
}


Win32Window::~Win32Window() {
    ShowCursor(true);

    DestroyWindow(hwnd);
    hwnd = nullptr;

    UnregisterClass(applicationName, hInstance);
    hInstance = nullptr;

    ApplicationHandle = nullptr;
}

LRESULT Win32Window::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) {
    switch (umsg) {
        case WM_KEYDOWN:
            PostQuitMessage(0);
            break;
        default: {
            return DefWindowProc(hwnd, umsg, wparam, lparam);
        }
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam) {
    switch (umessage) {
        case WM_CLOSE: {
            PostQuitMessage(0);
            return 0;
        }
        default: {
            return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
        }
    }
}

