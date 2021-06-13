#pragma once
//#include<string>
//#include"mylib.h"
//#include"CTDL.h"
#include"DEFIND.h"

#define goc_trai_tren char(218);
#define goc_phai_duoi char(217);
#define goc_phai_tren char(191);
#define goc_trai_duoi char(192);
#define ngang char(196);
#define doc char(179)
#define canh_ngang 50
#define canh_dung 12
#define re_ngang_trai 195
#define canh_bang 84
#define chieu_cao_bang 22
#define re_duoi char(193)

//===============================NGUYEN DUC TU=============================
int KiemTraChuoi(string s)
{
    if (s[0] == 32 || s.size() == 0) return 0;//ki tu dau tien ko duoc nhap khoan trang.va do dai phai khac 0
    return 1;
}
int KiemTraDoDaiMa(string s) //Kiem tra do dai cua ma
{
    if (s.size() <=10) return 1;
    return 0;
}

int Num(char x) { return x - '0'; }
int ChuyenThanhSo(string  s) //Chuyen string thanh int 
{
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) res = res * 10 + Num(s[i]);
    return res;
}
string ChuyenThanhChuoi(int number) {
    string s = "";
    while (number != 0) {
        s = char((number % 10) + 48) + s;
        number = number / 10;
    }
    if (s.length() < 2) s = '0' + s;
    return s;
}
int KiemTraNhapSoLuongTon(string s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (Num(s[i]) != 0 && Num(s[i]) != 1 && Num(s[i]) != 2 && Num(s[i]) != 3 && Num(s[i]) != 4 && Num(s[i]) != 5 && Num(s[i]) != 6 && Num(s[i]) != 7 && Num(s[i]) != 8 && Num(s[i]) != 9)
        {
            return 0;
        }

    }
    return 1;
}
int KiemTraNhapSoThapPhan(string s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (Num(s[i]) != 0 && Num(s[i]) != 1 && Num(s[i]) != 2 && Num(s[i]) != 3 && Num(s[i]) != 4 && Num(s[i]) != 5 && Num(s[i]) != 6 && Num(s[i]) != 7 && Num(s[i]) != 8 && Num(s[i]) != 9 && Num(s[i]) != -2)
        {
            return 0;
        }

    }
    return 1;
}
int KiemTraBoTrong(string s)
{
    if (s.size() != 0) return 1;
    return 0;
}
void HD()
{
    char l = 179;

    for (int i = 0; i <= 91; i++)
    {
        gotoxy(i, 27);
        cout << "_";
    }
    gotoxy(1, 28);
    cout << "+LUU Y:";
    gotoxy(60, 28);
    cout << "+Nhap phim ESC de thoat/tro ve.";

    gotoxy(60, 29);
    cout << "+ UP/DOWN ( mui ten)  di chuyen len xuong ";
}
void strchuhoa(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'A' && a[i] < 'Z')
            a[i] = a[i] + 32;
        else
            if (a[i] >= 'a' && a[i] <= 'z')
                a[i] = a[i] - 32;
    }
}
//Chi nhap so
int ChiNhapSo(int& x)
{
    int kq;
    int st = 0;
    while (true)
    {
        while (!_kbhit())
        {
            int key = getch();
            if (key != 224 && key != 0)
            {
                if (key >= 48 && key <= 57)
                {
                    kq = key - 48;
                    cout << kq;
                    st = st * 10 + kq;
                }
                else if (key == 13)
                {
                    x = st;
                    return 1;
                }
                else if (key == 8)
                {
                    cout << "\b" << " " << "\b";
                    st /= 10;
                }
            }
            else
            {
                key = getch();
            }
        }
    }
    x = st;
    return 1;
}

// an dau nhay di
void AnDauNhay()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//hien thi dau nhay len
void HienThiDauNhay()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

const char thucdon[item][50] = { "  Them nhan vien  ",
								 "    Hieu chinh    ",
								 "   In danh sach   ",
								 "       Thoat      " };

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void Highlight() {
	SetColor(15);
	SetBGColor(231);
}

void draw_khung_thao_tac_1(int x, int y)
{
	gotoxy(x, y);
	SetColor(0);
	SetBGColor(190);
	cout << "             Nhap thong tin nhan vien             ";
	Normal();
	for (int i = 0; i < 12; i++)
	{
		gotoxy(x, y + i);
		cout << doc;
	}
	gotoxy(x, y + 12);
	cout << goc_trai_duoi;
	for (int i = 1; i < canh_ngang; i++)
	{
		gotoxy(x + i, y + 12);
		cout << ngang;
	}
	gotoxy(x + canh_ngang, y + 12);
	cout << goc_phai_duoi;
	for (int i = 0; i < 12; i++)
	{
		gotoxy(x + canh_ngang, y + i);
		cout << doc;
	}
}

void Highlight_thongbao()
{
	SetColor(0);
	SetBGColor(195);
}

void draw_bang(int x, int y)
{
	gotoxy(x, y);
	SetColor(0);
	SetBGColor(190);
	cout << " STT "; //5 kitu
	Normal();
	for (int i = 1; i < chieu_cao_bang; i++)
	{
		gotoxy(x + 5, y + i);
		cout << doc;
	}
	gotoxy(x + 5, y);
	SetColor(0);
	SetBGColor(190);
	cout << "    Ma NV    "; //13 kitu
	Normal();
	for (int i = 1; i < chieu_cao_bang; i++)
	{
		gotoxy(x + 18, y + i);
		cout << doc;
	}
	gotoxy(x + 18, y);
	SetColor(0);
	SetBGColor(190);
	cout << "           Ho " << char(38) << " ten dem           "; //34 kitu
	Normal();
	for (int i = 1; i < chieu_cao_bang; i++)
	{
		gotoxy(x + 52, y + i);
		cout << doc;
	}
	gotoxy(x + 52, y);
	SetColor(0);
	SetBGColor(190);
	cout << "        Ten        "; //19 kitu
	Normal();
	for (int i = 1; i < chieu_cao_bang; i++)
	{
		gotoxy(x + 71, y + i);
		cout << doc;
	}
	gotoxy(x + 71, y);
	SetColor(0);
	SetBGColor(190);
	cout << "  Gioi tinh  ";// 13kitu
	Normal();
	for (int i = 0; i < chieu_cao_bang; i++)
	{
		gotoxy(x - 1, y + i);
		cout << doc;
	}
	gotoxy(x - 1, y + chieu_cao_bang);
	cout << goc_trai_duoi;
	for (int i = 0; i < canh_bang; i++)
	{
		gotoxy(x + i, y + chieu_cao_bang);
		cout << ngang;
	}
	gotoxy(x + canh_bang, y + chieu_cao_bang);
	cout << goc_phai_duoi;
	for (int i = 0; i < chieu_cao_bang; i++)
	{
		gotoxy(x + canh_bang, y + i);
		cout << doc;
	}
	gotoxy(x + 5, y + chieu_cao_bang);
	cout << re_duoi;
	/*for (int i = 0; i < 23; i++)
	{
		gotoxy(x + canh_bang, y + i);
		cout << doc;
	}*/
	gotoxy(x + 18, y + chieu_cao_bang);
	cout << re_duoi;
	/*for (int i = 0; i < 23; i++)
	{
		gotoxy(x + canh_bang, y + i);
		cout << doc;
	}*/
	gotoxy(x + 52, y + chieu_cao_bang);
	cout << re_duoi;
	/*for (int i = 0; i < 23; i++)
	{
		gotoxy(x + canh_bang, y + i);
		cout << doc;
	}*/
	gotoxy(x + 71, y + chieu_cao_bang);
	cout << re_duoi;
}
//Khung hieu chinh
void draw_khung_thao_tac_2(int x, int y)
{
	gotoxy(x, y);
	SetColor(0);
	SetBGColor(190);
	cout << "               Nhap vao ma nhan vien               "; //50 ki tu
	Normal();
	for (int i = 0; i < 12; i++)
	{
		gotoxy(x, y + i);
		cout << doc;
	}
	gotoxy(x, y + 12);
	cout << goc_trai_duoi;
	for (int i = 1; i < canh_ngang; i++)
	{
		gotoxy(x + i, y + 12);
		cout << ngang;
	}
	gotoxy(x + canh_ngang, y + 12);
	cout << goc_phai_duoi;
	for (int i = 0; i < 12; i++)
	{
		gotoxy(x + canh_ngang, y + i);
		cout << doc;
	}

}

int dieu_huong_them(int x, int y/*, int sonut, char td[sonut][50]*/)
{
	int ymoi = y + 11;
	string string1 = "       Chinh sua       ";
	string string2 = "         Xoa           ";
	gotoxy(x + 26, ymoi);
	Normal();
	cout << string2;
	gotoxy(x + 2, ymoi);
	Highlight();
	cout << string1;
	int chon = 0;
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == -32) 
		{
			kytu = _getch();
			switch (kytu)
			{
			case LEFT: if (chon > 0)
			{
				Normal();
				gotoxy(x + 26, ymoi);
				cout << string2;
				chon--;
				Highlight();
				gotoxy(2 + x, ymoi);
				cout << string1;
			}
					 break;
			case RIGHT:if (chon < 1)
			{
				Normal();
				gotoxy(2 + x, ymoi);
				cout << string1;
				chon++;
				Highlight();
				gotoxy(26 + x, ymoi);
				cout << string2;
			}
					  break;
			}
		}
		else if(kytu==ENTER) return chon+1;
		else if(kytu==ESC) return 0;

	} while (true);
}

void draw_taskbar(int chon)
{
	Normal();
	system("cls");
	chon -= 1;
	int kc = 0;
	for (int i = 0; i < item; i++)
	{
		gotoxy(kc, 0);
		cout << thucdon[i];
		kc += khung;
	}
	Highlight();
	gotoxy(chon * khung, 0);
	cout << thucdon[chon];
}


void ve_khung_vien(int x, int y)
{
	gotoxy(x, y);
	cout << goc_trai_tren;
	for (int i = 1; i < 29; i++)
	{
		cout << ngang;
	}
	cout << goc_phai_tren;
	gotoxy(x, y + 1);
	cout << doc;
	gotoxy(x, y + 2);
	cout << goc_trai_duoi;
	for (int i = 1; i < 29; i++)
	{
		cout << ngang;
	}
	gotoxy(x + 29, y + 1);
	cout << doc;
	gotoxy(x + 29, y + 2);
	cout << goc_phai_duoi;
}

void xoa_khung_vien(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
	for (int i = 1; i < 29; i++)
	{
		cout << " ";
	}
	cout << " ";
	gotoxy(x, y + 1);
	cout << " ";
	gotoxy(x, y + 2);
	cout << " ";
	for (int i = 1; i < 29; i++)
	{
		cout << " ";
	}
	gotoxy(x + 29, y + 1);
	cout << " ";
	gotoxy(x + 29, y + 2);
	cout << " ";
}
string Chuanhoa_chu(string& a)
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
	//xoa khoang trang  giua 
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	//chuyen chu in hoa
	for (int i = 0; i < a.length(); i++)
	{
		if(a[i]>96 && a[i]<123)
		{
			a[i] = a[i] - 32;
		}
	}
	
	return a;
}
void Luu_Y() {
	
	gotoxy(130, 1);
	cout << "*  LUU Y * ";
	gotoxy(120, 2);
	cout << "* MA VT khong bat dau khoang trang  ";	
	gotoxy(120,3);
	cout<<" * MA VT co toi da 10 ky tu  ";
	gotoxy(120, 4);
	cout << "*Gom cac ki tu (a-z), (A-Z)   ";
	gotoxy(120, 4);
	cout << "*Cac so (0-9)               ";
}

int StringToInt1(string str)
{
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		result = result * 10 + (int)(str[i] - '0');
	}
	return result;
}
