#include "Window.h"

Window::Window(std::wstring ClassName, WNDPROC WinProcPtr, std::wstring WindowTitle
	           ,int StartX, int StartY, int width, int height
	           , HICON hIcon, DWORD style)
{
	this->ClassName = ClassName;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WinProcPtr;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = hIcon;
	wc.hCursor = NULL;
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)&ClassName;
	wc.hIconSm = hIcon;
	RegisterClassEx(&wc);
	hwnd = CreateWindowEx(0, (LPCWSTR)&ClassName, (LPCWSTR)&WindowTitle, style, StartX, StartY, width, height, nullptr, nullptr, hInstance, nullptr);
	D3DPtr = new Direct3D(hwnd);
	ShowWindow(hwnd, SW_SHOW);
	SetFocus(hwnd);

}

Window::~Window()
{
	UnregisterClass(ClassName.c_str(), hInstance);
}

void Window::MsgLoop()
{
	while (1)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}


			TranslateMessage(&msg);
			DispatchMessage(&msg);
			UpdateWindow(hwnd);
			Sleep(2);
		}
		break;
	}
}
