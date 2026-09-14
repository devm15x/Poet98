#include <windows.h>

void setMouseLook(HWND hWnd, float *yaw, float *pitch)
{
    RECT rect;
    POINT center;
    POINT mouse;
    static int first = 1;

    if(GetForegroundWindow() != hWnd) {
        first = 1;
        return;
    }

    GetClientRect(hWnd, &rect);

    center.x = (rect.right - rect.left) / 2;
    center.y = (rect.bottom - rect.top) / 2;

    ClientToScreen(hWnd, &center);

    if(first) {
        SetCursorPos(center.x, center.y);
        first = 0;
        return;
    }

    GetCursorPos(&mouse);

    *pitch += (mouse.x - center.x) * 0.15f;
    *yaw += (mouse.y - center.y) * 0.15f;

    if(*yaw > 89.0f)
        *yaw = 89.0f;

    if(*yaw < -89.0f)
        *yaw = -89.0f;

    SetCursorPos(center.x, center.y);
}
