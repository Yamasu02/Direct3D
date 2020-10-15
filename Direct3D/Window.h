#pragma once
#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include "Direct3D.h"

class Window
{
public:

	HWND hwnd;
	std::wstring ClassName = L"DefaultClassName";
	WNDCLASSEX wc = { 0 };
	HINSTANCE hInstance;
	MSG msg;
	Direct3D* D3DPtr;


	Window(std::wstring ClassName, WNDPROC WinProcPtr, std::wstring WindowTitle
		   ,int StartX = 0,int StartY = 0,int width = 1920,int height = 1080
		   ,HICON hIcon = nullptr,DWORD style = WS_OVERLAPPEDWINDOW);
	  
	void MsgLoop();
	~Window();
};

