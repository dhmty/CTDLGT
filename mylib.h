#pragma once // tr�nh d?ng d? thu vi?n khi g?i ch?ng file l�n nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thu vi?n h? tr? v? th?i gian th?c */
#include "windows.h" // thu vi?n n�y b� d?o l?m nh� - ch?a nhi?u d? choi nek - c? t�m hi?u d?n d?n s? th?y s?c m?nh c?a n�
#pragma warning(disable:4996) // b? qua c�c l?i C4996 v? c� ph�p c?i ti?n c�c h�m c?a Visual Studio 

// Define th�m m?t s? ph�m k� t? c?n thi?t khi thao t�c tr�n b�n ph�m 
#define    KEY_A    0x41
#define    KEY_B    0x42
#define    KEY_C    0x43
#define    KEY_D    0x44
#define    KEY_E    0x45 
#define    KEY_F    0x46
#define    KEY_G    0x47
#define    KEY_H    0x48
#define    KEY_I    0x49
#define    KEY_J    0x4A
#define    KEY_K    0x4B
#define    KEY_L    0x4C
#define    KEY_M    0x4D
#define    KEY_N    0x4E
#define    KEY_O    0x4F
#define    KEY_P    0x50
#define    KEY_Q    0x51
#define    KEY_R    0x52
#define    KEY_S    0x53
#define    KEY_T    0x54
#define    KEY_U    0x55
#define    KEY_V    0x56
#define    KEY_W    0x57
#define    KEY_X    0x58
#define    KEY_Y    0x59
#define    KEY_Z    0x5A
#define    KEY_F2 
#define    KEY_F3 
#define    KEY_F4 


// c�c ph�m di?u khi?n l�n xu?ng tr�i ph?i...
#define     KEY_LEFT    VK_LEFT
#define     KEY_RIGHT   VK_RIGHT
#define     KEY_UP      VK_UP
#define     KEY_DOWN    VK_DOWN
#define     KEY_ESC     VK_ESCAPE
#define KEY_NONE	-1
// c�c m� m�u tuong ?ng
#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1 
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

/* =================== KHAI B�O C�C H�M H? TR? TR�N C?A S? D�NG L?NH  ===================*/


// L?y n�t b�n ph�m do ngu?i d�ng b?m
// Tr? v?: M� c?a ph�m
int inputKey();

// L?y t?a d? x hi?n t?i c?a con tr? console
int whereX();

// L?y t?a d? y hi?n t?i c?a con tr? console
int whereY();

// Di chuy?n con tr? console d?n v? tr� c� t?a d? (x, y)
void gotoxy(int x, int y);

// �?t m�u cho ch? mu?n in l�n m�n h�nh
void SetColor(WORD color);

// �?t m�u n?n cho ch? mu?n in l�n m�n h�nh
void SetBGColor(WORD color);

// Thi?t l?p ch? d? hi?n th?, c� fullscreen hay kh�ng
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode);

// �?t ch? d? FullScreen
void setFullScreen();

// Tho�t kh?i fullscreen
void exitFullScreen();

// ?n hi?n con tr? nh?p nh�y trong c?a s? Console
void ShowCur(bool CursorVisibility);

// X�a to�n b? n?i dung c?a s? console - ch�m t? MSDN
void cls(HANDLE hConsole);

// Vi?t l?i h�m clrscr, kh�ng c?n cung du?c nhung d? nh�n v�o code cho d?p m?t
void clrscr();

// Ki?m tra xem ph�m n�o du?c nh?n, tr? v? true n?u ph�m d� d� du?c nh?n xu?ng
bool checkKey(int key);


// H�m thay d?i k�ch c? c?a khung cmd v?i tham s? truy?n v�o l� chi?u cao, chi?u r?ng.
void resizeConsole(int, int);
// ============================ H�M PH�T SINH ============================
#include "mylib.h"



// X�a m�n h�nh
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

// L?y t?a d? x hi?n t?i c?a con tr? console
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

// L?y t?a d? y hi?n t?i c?a con tr? console
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


// L?y n�t b�n ph�m do ngu?i d�ng b?m
// Tr? v?: M� c?a ph�m
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}

// Di chuy?n con tr? console d?n v? tr� c� t?a d? (x, y)
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// �?t m�u cho ch? mu?n in l�n m�n h�nh
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void HighLight() {
	SetColor(15);
	SetBGColor(1);
}
// �?t m�u n?n cho ch? mu?n in l�n m�n h�nh
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Thi?t l?p ch? d? hi?n th?, c� fullscreen hay kh�ng
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI* SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

// �?t ch? d? FullScreen
void setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

// Tho�t kh?i fullscreen
void exitFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

// ?n hi?n con tr? nh?p nh�y trong c?a s? Console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}


// Ki?m tra xem ph�m n�o du?c nh?n, tr? v? true n?u ph�m d� d� du?c nh?n xu?ng
bool checkKey(int key)
{
	return GetAsyncKeyState(key);
}

// H�m thay d?i k�ch c? c?a khung cmd v?i tham s? truy?n v�o l� chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//chuan hos chu

int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}



