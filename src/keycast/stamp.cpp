// "Stamp" is the branding.  It's a movable subwindow that floats above the rest of the window.
// #include <windows.h>
#include "stamp.h"
#include <gdiplus.h>
#include "keycastSettings.h"
using namespace Gdiplus;

// #define SHOWTIMER_INTERVAL 40

extern Color clearColor;
extern struct LabelSettings labelSettings;
extern Font *fontPlus;
// extern CTimer showTimer;

HWND hWndStamp;
LRESULT CALLBACK DraggableWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

ATOM stampRegisterClassEx(HINSTANCE hInst, LPCWSTR className, WNDPROC wndProc)
{
    WNDCLASSEX wcl;
    wcl.cbSize = sizeof(WNDCLASSEX);
    wcl.hInstance = hInst;
    wcl.lpszClassName = className;
    wcl.lpfnWndProc = wndProc;
    wcl.style = CS_DBLCLKS;
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcl.lpszMenuName = NULL;
    wcl.cbWndExtra = 0;
    wcl.cbClsExtra = 0;

    return RegisterClassEx(&wcl);
}

void InitStamp(HINSTANCE hThisInst)
{
    stampRegisterClassEx(hThisInst, L"STAMP", DraggableWndProc);
    hWndStamp = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_NOACTIVATE,
        L"STAMP", L"STAMP", WS_VISIBLE | WS_POPUP,
        0, 0, 1, 1,
        NULL, NULL, hThisInst, NULL);
}

void stamp(LPCWSTR text, RECT desktopRect)
{
    // DebugPrint("void stamp(HWND hwnd, LPCWSTR text)\n");
    HWND hwnd = hWndStamp;
    RECT rt;
    GetWindowRect(hwnd, &rt);
    HDC hdc = GetDC(hwnd);
    HDC memDC = ::CreateCompatibleDC(hdc);
    HBITMAP memBitmap = ::CreateCompatibleBitmap(hdc, desktopRect.right - desktopRect.left, desktopRect.bottom - desktopRect.top);
    ::SelectObject(memDC, memBitmap);
    Graphics g(memDC);
    g.SetSmoothingMode(SmoothingModeAntiAlias);
    g.SetTextRenderingHint(TextRenderingHintAntiAlias);
    g.Clear(clearColor);

    RectF rc((REAL)labelSettings.borderSize, (REAL)labelSettings.borderSize, 0.0, 0.0);
    SizeF stringSize, layoutSize((REAL)desktopRect.right - desktopRect.left - 2 * labelSettings.borderSize, (REAL)desktopRect.bottom - desktopRect.top - 2 * labelSettings.borderSize);
    StringFormat format;
    format.SetAlignment(StringAlignmentCenter);
    g.MeasureString(text, (INT)wcslen(text), fontPlus, layoutSize, &format, &stringSize);
    rc.Width = stringSize.Width;
    rc.Height = stringSize.Height;
    SIZE wndSize = {2 * labelSettings.borderSize + (LONG)rc.Width, 2 * labelSettings.borderSize + (LONG)rc.Height};
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, wndSize.cx, wndSize.cy, SWP_NOMOVE | SWP_NOACTIVATE);

    SolidBrush bgBrush(Color::Color(0xaf007cfe));
    g.FillRectangle(&bgBrush, rc);
    SolidBrush textBrushPlus(Color(0xaf303030));
    g.DrawString(text, (int)wcslen(text), fontPlus, rc, &format, &textBrushPlus);
    SolidBrush brushPlus(Color::Color(0xaffefefe));
    rc.X += 2;
    rc.Y += 2;
    g.DrawString(text, (INT)wcslen(text), fontPlus, rc, &format, &brushPlus);

    POINT ptSrc = {0, 0};
    POINT ptDst = {rt.left, rt.top};
    BLENDFUNCTION blendFunction;
    blendFunction.AlphaFormat = AC_SRC_ALPHA;
    blendFunction.BlendFlags = 0;
    blendFunction.BlendOp = AC_SRC_OVER;
    blendFunction.SourceConstantAlpha = 255;
    ::UpdateLayeredWindow(hwnd, hdc, &ptDst, &wndSize, memDC, &ptSrc, 0, &blendFunction, 2);
    ::DeleteDC(memDC);
    ::DeleteObject(memBitmap);
    ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK DraggableWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT s_last_mouse;
    switch (message)
    {
    // hold mouse to move
    case WM_LBUTTONDOWN:
        SetCapture(hWnd);
        GetCursorPos(&s_last_mouse);
        // showTimer.Stop();
        break;
    case WM_MOUSEMOVE:
        if (GetCapture() == hWnd)
        {
            POINT p;
            GetCursorPos(&p);
            int dx = p.x - s_last_mouse.x;
            int dy = p.y - s_last_mouse.y;
            if (dx || dy)
            {
                s_last_mouse = p;
                RECT r;
                GetWindowRect(hWnd, &r);
                SetWindowPos(hWnd, HWND_TOPMOST, r.left + dx, r.top + dy, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
            }
        }
        break;
    case WM_LBUTTONUP:
        ReleaseCapture();
        // showTimer.Start(SHOWTIMER_INTERVAL);
        break;
    case WM_LBUTTONDBLCLK:
        // this launches the config dlg - I don't want to do this
        // SendMessage(hMainWnd, WM_COMMAND, MENU_CONFIG, 0);
        // instead, I'll use this to exit the program
        ExitProcess(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}