#pragma once
#include"mylib.h"
#include"DEFIND.h"
#include"Linhtinh.h"

using namespace std;
// Tao khung nho 

/// <summary>
//========================NGUYEN DUC TU==========================
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void KhungNho(int x, int y)
{
    gotoxy(x, y);
    //	SetColor(14);
    for (int i = 0; i < 30; i++)
    {
        if (i == 0)
            cout << char(218);
        else if (i == 29)
            cout << char(191);
        else cout << char(196);
    }
    gotoxy(x, y + 1);
    cout << char(179);
    gotoxy(x + 29, y + 1);
    cout << char(179);
    gotoxy(x, y + 2);
    for (int i = 0; i < 30; i++)
    {
        if (i == 0)
            cout << char(192);
        else if (i == 29)
            cout << char(217);
        else cout << char(196);
    }
    gotoxy(x + 1, y + 1);
}
void CanhBao(string s,/*int maunen,*/int cot, int hang)
{
    do
    {
        //       MauCB();
         //     SetColor(12);
        gotoxy(cot, hang);
        cout << s;//hien thi 1 chuoi ki tu
        Sleep(500);
        gotoxy(cot, hang);
        for (int i = 0; i < (int)s.size(); i++) cout << " ";
        Sleep(200);
        //       SetColor(11);
    } while (!kbhit());
    gotoxy(cot, hang); for (int i = 0; i < (int)s.size(); i++) cout << " ";
}

void MauCB()
{
    SetBGColor(2);
    SetColor(11);
}
void MauChon()
{
    SetBGColor(11);
    SetColor(12);
}
void MauLoi()
{
    SetBGColor(15);
    SetColor(12);
}
/*void Normal() {
    SetColor(15);
    SetBGColor(0);
}*/
void XoaManHinh()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
void resizeconsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, true);
}


// *********************   GIAO DIEN VAT TU    *************** 
void KhoiTaoMenuHieuChinhVT()
{
    system("cls");
    gotoxy(5, 1);
    cout << "HIEU CHINH THONG TIN VAT TU";
    gotoxy(1, 3);
    cout << "1. HIEU CHINH TEN VAT TU   ";
    gotoxy(1, 5);
    cout << "2. HIEU CHINH DON VI TINH  ";
    HD();
}



//========================TRAN MINH CHIEN===================



// ********* CHUAN HOA CHU  
void chuanhoa_chu(string& a)
{
	//xóa kí t?  kho?ng tr?ng ? d?u chu?i
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xoa ki tu khoang trang o cuoi chuoi
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	//xoa ky tu giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	//chuyen chu in hoa
		//tran----->Tran
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}
}



void xoabang()
{
	Normal();
	for (int i = 0; i < 10; i++)
	{

		gotoxy(14, 6 + i*2);
		cout << "   ";
		gotoxy(18, 6 + i*2);
		cout << "      ";
		gotoxy(31, 6 + i * 2);
		cout << "                                 ";
		gotoxy(65, 6 + i * 2);
		cout << "                  ";
		gotoxy(84, 6 + i * 2);
		cout << "   ";
	}
}
