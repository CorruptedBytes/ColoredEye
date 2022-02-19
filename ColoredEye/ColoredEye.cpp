#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	while (true)
	{
		HWND hwnd = GetDesktopWindow();
		HDC hdc = GetWindowDC(hwnd);
		RECT rekt;
		GetWindowRect(hwnd, &rekt);
		BitBlt(hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, hdc, 1, 1, NOTSRCCOPY);
		Sleep(20);
		BitBlt(hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, hdc, -10, -5, SRCINVERT | SRCERASE | SRCINVERT);
		Sleep(100);
		StretchBlt(hdc, 50, 50, rekt.right - 100, rekt.bottom - 100, hdc, 0, 0, rekt.right, rekt.bottom, SRCINVERT);
		Sleep(20);
		ReleaseDC(hwnd, hdc);
	}
}