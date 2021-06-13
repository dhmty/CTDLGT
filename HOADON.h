#pragma once
#include "CTDL.h"
#include "RW_FILE.h"
#include "GRAPHIC.h"

#include "VATTU.h"

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstring>
#include <conio.h>
//#include <mylib.h>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

#define MAX_NV 500
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define BACKSPACE 8
#define DEL 83
#define TAB 9
#define INS 82
#define F2 -60
#define F3 -61


int ChiNhapSo1(short& x);
int StringToInt(string str);
void IntToString(int ,string &);

int GetKey();
int  GetKey1();
//void resizeconsole(int , int );
//void Normal();
void HighLightD();
void RemoveScroll();
int Menudong(int);
void NOTICE(string, string);
int NOTICE1(TREE_VT &,string,string,bool &);//dung cho mo bang ma VT
void Spacebar(int, int, int);
void Upper_case(string&, int, int);
void DrawLine(int, int, int, int);
void DrawBorder(int, int, int, int);

void Delete_Billdetail(PTR_Bd&);
void Insert_Billdetail(PTR_Bd&, string, int, int, int);// luu tung phan tu khi nhap vao ->chèn trong insertbill
void Insert_Bill(PTR_B&, string, int, int, int, char, PTR_Bd&);//khi nao dong y ms them zo bill
void Setup_Bill(TREE_VT& t, DS_NV&, PTR_B&);
int Setup_Billdetail(TREE_VT& t, PTR_Bd&, char);
void Draw_Billdetail();
void Draw_Bill();
void Draw_XemVT(TREE_VT);
void Draw_SearchBill();
int Draw_SetTime();
void Draw_TKHD();
void Draw_TKDT(int);
void Draw_TopVT();
void ThongKeHD(DS_NV& a);
void ThongKeDT(DS_NV& a);
void Top10VT(TREE_VT,DS_NV a);
int Delete_After(PTR_Bd&);
int Delete_First(PTR_Bd& First);

// doc vaf viet file Bill
void Load_Bill(DS_NV&, PTR_B&, PTR_Bd&);
void Write_Bill(PTR_B, char[]);

int Compare_Date(short, short, short, short, short, short);
void Setup_Date(short&, short&, short&, int, int, int, int);
int Check_Date(int, int, int);

void Draw_XemHD(DS_NV &a);
void Search_Bill(DS_NV& a);

void CapNhat_SLT(TREE_VT&, int, char, string);
//dung chung
void Setup_BillNV(TREE_VT& t, DS_NV& a, string Ma_nv);



int GetKey()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
int ChiNhapSo1(short& x)
{
	short kq;
	short st = 0;
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
int  GetKey1()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -(_getch());
	else return key;
}
void Spacebar(int x, int y, int row)
{
	gotoxy(x, row);
	for (int i = x; i <= y; i++)
	{
		cout << " ";
	}
}
void NOTICE(string s, string s1)
{
	AnDauNhay();
	HighLightD();
	gotoxy(25, 30);
	cout << "THONG BAO : ";
	Normal();
	gotoxy(37, 30);
	cout << s;
	gotoxy(37, 31);
	cout << s1;
	getch();
	gotoxy(25, 30);
	cout << "THONG BAO : ";
	Spacebar(37, 83, 30);
	Spacebar(37, 83, 31);
}
int NOTICE1(TREE_VT &t,string s,string s1)
{
	AnDauNhay();
	HighLightD();
	gotoxy(25, 30);
	cout << "THONG BAO : ";
	Normal();
	gotoxy(37,30);		
	cout<<s;
	gotoxy(37,31);
	cout<<s1;
    char k1=GetKey1();	
    while (k1!=ENTER && k1!=F3 && k1!=ESC) {
		k1=GetKey1();
	}
	Spacebar(37,83,30);
	Spacebar(37,83,31);		

	if (k1==F3) {
				Draw_XemVT(t);
				return 1;
			}
	else if (k1==ESC) return 0;
	else return 1; 
	Normal();
	gotoxy(25, 30);
	cout << "THONG BAO : ";
		
}
/*void Normal ()
{
	SetColor(15);
	SetBGColor(0);
}*/
void HighLightD()
{
	SetColor(15);
	SetBGColor(2);
}
int Menudong(int so_item)
{
	Normal();
	int i = 0;
	int chon = 0;
	HighLightD();
	gotoxy(103, 10 + chon);//sua laij
	cout << "ENTER DE XOA";
	char kt;
	do {
		kt = getch();
		if (kt == 0) kt = getch();
		switch (kt)
		{
		case UP:
			Normal();
			Spacebar(102, 115, 10 + chon);
			gotoxy(105, 10 + chon);
			cout << "XAC NHAN";
			if (chon + 1 > 1) chon--;
			else if (chon + 1 == 1) chon = so_item - 1;
			HighLightD();
			gotoxy(103, 10 + chon);
			cout << "ENTER DE XOA";
			break;
		case DOWN:
			Normal();
			Spacebar(102, 115, 10 + chon);
			gotoxy(105, 10 + chon);
			cout << "XAC NHAN";
			if (chon + 1 < so_item) chon++;
			else if (chon + 1 == so_item) chon = 0;
			HighLightD();
			gotoxy(103, 10 + chon);
			cout << "ENTER DE XOA";
			break;
		case 27: 	Normal();
			Spacebar(102, 115, 10 + chon);
			gotoxy(105, 10 + chon);
			cout << "XAC NHAN";
			return 0;
			break;
		case ENTER: Normal();
			Spacebar(102, 115, 10 + chon);
			gotoxy(105, 10 + chon);
			cout << "XAC NHAN";
			return chon + 1;
		}
	} while (1);
}
void RemoveScroll()//giâu thanh doc
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}
void Upper_case(string& s, int x, int y) //ham ktra sohd va mavattu ko co khoang trang va ko nhan rong
{

	gotoxy(x, y);
	getline(cin, s);
	int l = s.length();

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
		if (s[i] > 96 && s[i] < 123)
		{
			s[i] -= 32;
		}
	}
	if (s.length() == 0) Upper_case(s, x, y);

	Spacebar(x, x + l, y);
	gotoxy(x, y);
	cout << s;
}


int StringToInt(string str)
{
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		result = result * 10 + (int)(str[i] - '0');
	}
	return result;
}
void IntToString(int nb,string &s)
{            
    ostringstream convert;   
    convert << nb;      
    s = convert.str(); 
}
void Load_Bill(DS_NV& b, PTR_B& First, PTR_Bd& First1)
{
	char filename[30];
	int i = 0, j = 0;
	string a[MAX_NV];
	while (j < b.sl)
	{
		a[j] = b.ds[j]->ma_nv;
		j++;
	}
	string sohd, mvt;
	string ng, th, nam, s, pr, vat;
	int ng1, th1, nam1, s1, pr1, vat1;
	string temp;
	string l;
	char l1;
	int d = 0, d1;
	while (i < j)
	{
		b.ds[i]->PTRhd = NULL;
		a[i] = a[i] + ".txt";
		strcpy(filename, a[i].c_str());

		ifstream fin(filename, ios::app);
		if (!fin) cout << "ko tim thay file";

		//so luong hoa don cua mot nhan vien
		while (!fin.eof()) {
			getline(fin, temp);
			if (temp.length() > 0) d++;
		}

		//doc hoa don cua nhan vien
		d1 = 0;
		fin.seekg(0, ios::beg);
		while (!fin.eof() && d1 < d)
		{
			//doc thong tin hoa don

			getline(fin, sohd, ' ');
			getline(fin, ng, '/');
			getline(fin, th, '/');
			getline(fin, nam, ' ');
			getline(fin, l, ' ');
			//docj chi tiet hoa don

			while (fin.get() == '+')
			{

				getline(fin, mvt, ' ');
				getline(fin, s, ' ');
				getline(fin, pr, ' ');
				getline(fin, vat, ' ');
				s1 = StringToInt(s);
				pr1 = StringToInt(pr);
				vat1 = StringToInt(vat);
				Insert_Billdetail(First1, mvt, s1, pr1, vat1);
			}
			d1++;
			ng1 = StringToInt(ng);
			th1 = StringToInt(th);
			nam1 = StringToInt(nam);
			l1 = l[0];
			Insert_Bill(First, sohd, ng1, th1, nam1, l1, First1);
			First1 = NULL;
			//	cout<<d1<<endl;
		}
		b.ds[i]->PTRhd = First;
		First = NULL;
		fin.close();
		i++;
		d = 0;
	}
}
void Write_Bill(PTR_B First, char filename[30])
{
	ofstream fout(filename, ios::out);
	fout.clear();
	for (PTR_B p = First; p != NULL; p = p->next)
	{
		//if (p==First) fout<<endl; vi chi su dung 1 tep cho 1 nhan vien
		fout << p->hd.SoHD << " " << p->hd.ngay << "/" << p->hd.thang << "/" << p->hd.nam << " " << p->hd.loai << " ";
		PTR_Bd q1 = p->PTRcthd;
		while (p->PTRcthd != NULL)
		{
			fout << "+" << p->PTRcthd->cthd.MAVT << " " << p->PTRcthd->cthd.sl << " " << p->PTRcthd->cthd.price << " " << p->PTRcthd->cthd.VAT << " ";
			p->PTRcthd = p->PTRcthd->next;
		}
		if (p->next != NULL) fout << endl;
		p->PTRcthd = q1;

	}
	fout.close();
}

void DrawLine(int X, int Y, int X1, int Y1)
{

	if (Y == Y1)
	{
		gotoxy(X, Y); //ngang
		for (int i = X + 1; i <= X1; i++)
		{
			cout << char(196);
		}
	}
	else if (X == X1)
	{
		gotoxy(X, Y); //goc phai tren
		cout << char(191);
		for (int i = Y; i <= Y1 - 1; i++)
		{
			gotoxy(X, i + 1);
			cout << char(179);

		}
		gotoxy(X1, Y1 + 1); //goc phai duoi
		cout << char(217);
	}


}
void DrawBorder(int X, int Y, int ngang1, int doc1)
{
	gotoxy(X, Y); //goc trai tren
	cout << char(218);
	gotoxy(X, Y + doc1); //goc trai duoi
	cout << char(192);
	gotoxy(X + ngang1, Y); //goc phai tren
	cout << char(191);
	gotoxy(X + ngang1, Y + doc1); //goc phai duoi
	cout << char(217);

	//ve hang

	for (int i = 0; i < ngang1 - 1; i++)
	{
		gotoxy(X + 1 + i, Y);
		cout << char(196);
		gotoxy(X + 1 + i, Y + doc1);
		cout << char(196);

	}
	//ve cot
	for (int i = 0; i < doc1 - 1; i++) {
		gotoxy(X, Y + i + 1);
		cout << char(179);
		gotoxy(X + ngang1, Y + i + 1);
		cout << char(179);
	}
	cout << "\n";
}
void Draw_XemVT(TREE_VT t)
{
	int a=0;
	VAT_TU A[200];
	DuyetCay(t,A,a);
//	gotoxy(1,1);
//	cout<<a;
	DrawLine(121,14,145,14);
	DrawLine(121,16,145,16);
	DrawLine(121,30,145,30);
	DrawLine(130,14,130,29);
	
	gotoxy(121,15);
	cout<<"MA VAT TU";
	gotoxy(133,15);
	cout<<"TEN VAT TU";
	gotoxy(135,31);
	cout<<"Trang ";	
		int i=1;
		cout<<i;
		if (a>=13) cout << "/" << (a-1)/13+1;
		char kt;
		
		while (i<=(a-1)/13+1 && i>0)
		{
			int d=1;
					int j=13*i-13;
					while (j <  13*i)
		 			{
						  Spacebar(121,129,16+d);
						  gotoxy(122,16+d);	//chon vi tri viet ra
						  cout<<A[j].ma_vt;
						  Spacebar(132,142,16+d);
						  gotoxy(132,16+d);	
						  cout<<A[j].ten_vt;	 		     	 
		 		     	if (j>a-1)	 
						  {
						  	Spacebar(121,124,16+d);
						  	Spacebar(132,142,16+d);
						 }
						
		 		     	  d++;
		 		     	  j++;
		 		    }
		 		    d=0;
		 	kt=getch();
			if (kt==77 && i<(a-1)/13+1)
		    {
					
					
					Spacebar(141,141,31);
		 			i++;
		 			gotoxy(141,31);
		 			cout<<i;		 		
		 		   
         	}
         	else 
         	if (kt==75 && i>1)
		    {
					Spacebar(141,141,31);
		 			i--;
		 			gotoxy(141,31);
		 			cout<<i;
         	}
		    else 
         	if (kt==ESC) break;
         	
		}
	
}
void Draw_SearchBill()
{


	DrawBorder(32, 9, 86, 21);
	gotoxy(33, 10);
	cout << "_NHAN VIEN LAP : ";
	gotoxy(77, 10);
	cout << "_NGAY    THANG    NAM     ";
	gotoxy(104, 10);
	cout << "_HOA DON     _";
	//ve bang ctvthd
	DrawLine(33, 11, 118, 11);
	DrawLine(33, 13, 118, 13);
	gotoxy(39, 12);
	cout << "MA VAT TU";
	DrawLine(55, 11, 55, 29);
	gotoxy(60, 12);
	cout << "SO LUONG";
	DrawLine(73, 11, 73, 29);
	gotoxy(78, 12);
	cout << "DON GIA";
	DrawLine(90, 11, 90, 29);
	gotoxy(94, 12);
	cout << "VAT";
	DrawLine(100, 11, 100, 29);
	gotoxy(104, 12);
	cout << "THANH TIEN";
	gotoxy(90, 31);
	cout << "TONG CONG : ";


}
void Draw_XemHD(DS_NV &a)
{
	typedef struct SHD
	{
		string shd;
	}SHD;
	
	int n=0;
		for (int i=0;i<a.sl;i++)
			{
				if (a.ds[i]->PTRhd != NULL)
				{
					for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
						{															
							n++;
						}
				}
			}
	SHD A[n];
	int m=0;
	for (int i=0;i<a.sl;i++)
			{
				if (a.ds[i]->PTRhd != NULL)
				{
					for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
						{															
							A[m].shd=p->hd.SoHD;
							m++;
						}
				}
			}
	DrawBorder(1,4,28,28);
	DrawBorder(121,4,28,28);
	DrawLine(2,6,29,6);
	DrawLine(122,6,149,6);
	
	gotoxy(6,5); cout<<" BANG SO HOA DON";
	gotoxy(127,5); cout<<" BANG SO HOA DON";
	
	gotoxy(1,33); cout<<"ESC : QUAY LAI";
	gotoxy(19,33); cout<<"Trang";
	gotoxy(140,33); cout<<"Trang";
	
	int stt;
	int i=1;
	stt=(m-1)/50+1;
	gotoxy(25,33); cout<<i<<"/"<<stt;
	gotoxy(146,33); cout<<i<<"/"<<stt;	
	int j;	
		while (i<=stt && i>0)
			{
				int d=1;
						j=50*i-50;
						while (j <  50*i && j<m)
			 			{  
							  Spacebar(7,28,6+d);
							  gotoxy(7,6+d);	//chon vi tri viet ra
							  cout<<A[j].shd;
							  j++;
							  Spacebar(129,148,6+d);
							  gotoxy(129,6+d);	//chon vi tri viet ra
							  if (j<m) cout<<A[j].shd;				  	 		     	 						
			 		     	  d++;
			 		     	  j++;
			 		     	  if ( j>=m && j!=50*i )	 
								  {	
								  	if (j>m) j--;
									for(int j1=j%25+1; j1<=25;j1++)
									{
										Spacebar(7,28,6+j1);
										Spacebar(129,148,6+j1);
							 		}
								 }
			 		    }
			 		    d=0;
			 	int kt;
			 	kt=getch();
				if (kt==77 && i<stt)
			    {						
						Spacebar(25,27,33);
						Spacebar(146,148,33);
			 			i++;
			 			gotoxy(146,33);
			 			cout<<i<<"/"<<stt;
						gotoxy(25,33);		 		
			 		   	cout<<i<<"/"<<stt;
	         	}
	         	else 
	         	if (kt==75 && i>1)
			    {
			    		Spacebar(25,27,33);
						Spacebar(146,148,33);
			 			i--;
			 			gotoxy(146,33);
			 			cout<<i<<"/"<<stt;	
			 			gotoxy(25,33);		 		
			 		   	cout<<i<<"/"<<stt;
	         	}
			    else 
	         	if (kt==ESC) break;
	         	
			}
}
void Search_Bill(DS_NV &a)
{
	string sohd;
	bool flag,fl=true,fl1=true;
	int j1;
	clrscr();
	DrawBorder(30,4,90,28);// KHUNG
	
	
	DrawBorder(59,2,30,2);
	HighLightD();
	gotoxy(70,3);
	cout<<"IN HOA DON";
	Normal();
	int tong=0;
	char kt,k,kt2;
		
	DrawBorder(57, 5, 30, 2);
	gotoxy(58, 6);
	cout << "SO HOA DON : ";
	HighLightD();
	gotoxy(44,33);
	cout<<"ENTER : BAT DAU NHAP  F3 : TRA CUU SO HOA DON  ESC : QUAY LAI";
	Normal();
	kt2=GetKey1();
	while (kt2!=ESC && kt2!=ENTER && kt2!=F3)
	{
		kt2=GetKey1();
	}
	while (fl1)
	{
		
		if (kt2==ENTER)
		{
			Spacebar(44,110,33);
			while (fl)
			{
				flag=false;
				PTR_B q=NULL;
				DrawBorder(57,5,30,2);
			//	gotoxy(58,6);	
			//	cout<<"SO HOA DON : ";
				Spacebar(1,18,33);
				Spacebar(71,85,6);
				HienThiDauNhay();
				Upper_case(sohd,71,6);
				AnDauNhay();
				for(int i=0;i<a.sl;i++)
				{
					for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
						{
							if (p->hd.SoHD==sohd) 
							{
							    q=p;
							    //cout<<"oke";
							    j1=i;
								flag=true;
							}
						}
				}
				DrawBorder(89,5,5,2);
				HighLightD();
				gotoxy(91,6);
				cout<<"IN";
				Normal();
			
			    kt=getch();
				if (kt==ENTER && (flag) ) 
					{
						Normal();
						gotoxy(91,6);
						cout<<"IN";
						Draw_SearchBill();
						//xu ly xuat thong tin
						Spacebar(50,75,10); // xoa o trang cho dong ten
						gotoxy(50,10);
							cout<<a.ds[j1]->ho<<" "<<a.ds[j1]->ten;
						gotoxy(83,10); 
							cout<<q->hd.ngay;
						gotoxy(92,10); 
							cout<<q->hd.thang;
						gotoxy(99,10); 
							cout<<q->hd.nam;
						gotoxy(113,10); 
							if (q->hd.loai=='N') cout<<"NHAP"; 
							else cout<<"XUAT";
						int i=14;
					//	for (PTR_Bd p1=q->PTRcthd;p1!=NULL;p1=p1->next) 
					PTR_Bd p1=q->PTRcthd; // luu lai vi tri bat dau duyet cthd
					while (q->PTRcthd != NULL)
						{
						  gotoxy(40,i);
						  	cout<<q->PTRcthd->cthd.MAVT;
						  gotoxy(63,i);
						  	cout<<q->PTRcthd->cthd.sl;
						  gotoxy(80,i);
						  	cout<<q->PTRcthd->cthd.price;
						  gotoxy(95,i);
						  	cout<<q->PTRcthd->cthd.VAT;
						  gotoxy(106,i);
						  	cout<<(q->PTRcthd->cthd.sl*q->PTRcthd->cthd.price*(100+q->PTRcthd->cthd.VAT))/100;
						  tong+=(q->PTRcthd->cthd.sl*q->PTRcthd->cthd.price*(100+q->PTRcthd->cthd.VAT))/100;
						  q->PTRcthd=q->PTRcthd->next;
						  i++;
						}	
						q->PTRcthd=p1;//ttra lai vi tri cho lan duyet trung 
						
						gotoxy(103,31);
						cout<<tong;
						tong=0;
						
							
						HighLightD();
						gotoxy(33,31);
						cout<<"ENTER IN HOA DON KHAC. F3 TRA CUU SO HOA DON. ESC THOAT";
						Normal();
						
						k=GetKey1();
						while (k!=ENTER && k!=ESC && k!=F3) {
							 	k=GetKey1();
							}
						if (k==F3){
								Draw_XemHD(a);
							}
						else if (k==ESC) 
							{ 
								fl=false;
								fl1=false;
								break;
							}
						
						for (int j=14;j<=i;j++)
						{
							Spacebar(40,54,j);
							Spacebar(63,69,j);
							Spacebar(80,87,j);
							Spacebar(95,98,j);
							Spacebar(106,115,j);
							Spacebar(103,117,31);
							
						}
						Normal();
						Spacebar(33,88,31);
					}
			   else if (kt==ENTER && flag==false)
					{
						Normal();
						gotoxy(91,6);
						cout<<"IN";
						HighLightD();
						gotoxy(40,8);
						cout<<"KHONG CO SO HOA DON NAY. F3 DE TRA CUU. ENTER DE NHAP LAI. ESC DE THOAT";
						Normal();
						k=GetKey1();
						while (k!=ENTER && k!=ESC && k!=F3) {
								 k=GetKey1();
								}
						if (k==ESC) 
							{ 
								fl=false;
								fl1=false;
								break;
							}
						else if (k==F3)
							{
								Draw_XemHD(a);
							}
						Spacebar(40,110,8);
					}
			}
		}	
		else if (kt2==F3) 
		{
			Spacebar(44,110,33);
			
			Draw_XemHD(a);
								
			kt2=ENTER;
		}
		else if(kt2==ESC)
		{
			fl1=false;
			break;
		}
	}
}

int Draw_SetTime()
{
	int kt;
	DrawBorder(40, 7, 61, 10);
	DrawBorder(55, 5, 31, 2);
	DrawBorder(63, 15, 13, 2);
	HighLightD();
	gotoxy(57, 6);
	cout << "BANG CHON THOI GIAN THONG KE";
	Normal();
	
	gotoxy(45, 10);
	cout << " TU : NGAY       THANG      NAM";
	gotoxy(60, 13);
	cout << " DEN : NGAY       THANG      NAM";
	gotoxy(66, 16);
	cout << "XAC NHAN";
	DrawBorder(40,18,61,2);
	gotoxy(41,19);
	cout<<"ESC : QUAY LAI                           ENTER : TIEP TUC";
	kt=getch();
	while (kt!=ESC && kt!=ENTER)
	{
		kt=getch();
	}
	while (kt!=ESC)
	{	
		Spacebar(41,100,19);
		gotoxy(63,19);
		cout<<"ENTER : TIEP TUC";
		return 1;
		break;
	}
	return 0;
}
void Draw_TKHD()
{

	system("cls");
	HighLightD();
	gotoxy(57, 2);
	cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	Normal();


	DrawBorder(20, 4, 125, 28);

	DrawLine(21, 6, 145, 6);
	DrawLine(45, 4, 45, 31);
	DrawLine(70, 4, 70, 31);
	DrawLine(85, 4, 85, 31);
	DrawLine(120, 4, 120, 31);

	int i = 0;
	gotoxy(27 + i, 5);
	cout << "SO HOA DON";
	i += 25;
	gotoxy(25 + i, 5);
	cout << "NGAY LAP HOA DON";
	i += 25;
	gotoxy(22 + i, 5);
	cout << "LOAI HOA DON";
	i += 25;
	gotoxy(19 + i, 5);
	cout << "HO TEN NHAN VIEN LAP";
	i += 25;
	gotoxy(26 + i, 5);
	cout << "TRI GIA HOA DON";

	gotoxy(21, 33);
	cout<<"ESC : THOAT";
	gotoxy(135, 33);
	cout << "Trang ";
}
void ThongKeHD(DS_NV &a)
{
	typedef struct TKHD
	{
		string shd;
		short day;
		short month;
		short year;
		char type;
		string name;
		int total;
	}TKHD;
	

	int kt=Draw_SetTime();
	if (kt==1) 
	{
		short d1,m1,y1,d2,m2,y2;
			time_t now=time(0);
		tm *ltm = localtime(&now);
		d1=ltm->tm_mday;
		m1=ltm->tm_mon+1;
		y1=ltm->tm_year+1900;
		d2=d1; m2=m1;y2=y1;
	
		Setup_Date(d1,m1,y1,58,69,78,10);	
		Setup_Date(d2,m2,y2,73,85,93,13);
		while( Compare_Date(d2,m2,y2,d1,m1,y1)==false)
		{
				Spacebar(73,73+4,13);
				Spacebar(84,85+3,13);
	   			Spacebar(93,93+6,13);
	   			d2=ltm->tm_mday;
				m2=ltm->tm_mon+1;
				y2=ltm->tm_year+1900;
				Setup_Date(d2,m2,y2,73,85,93,13);
		}
		
		gotoxy(66,16);
		HighLightD();
		cout<<"XAC NHAN";
		Normal();
		if (getch()==ENTER) 
			{
				Draw_TKHD();
				gotoxy(60,3);
				cout<<"TU NGAY : "<<d1<<"/"<<m1<<"/"<<y1<<" DEN NGAY : "<< d2<<"/"<<m2<<"/"<<y2;
			}
		
		//xuat cac hoa don thoa yeu cau
		int n=0;
		for(int i=0;i<a.sl;i++)
		 {
		 for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
				{
					if (Compare_Date(p->hd.ngay,p->hd.thang,p->hd.nam,d1,m1,y1)
		    		&& Compare_Date(d2,m2,y2,p->hd.ngay,p->hd.thang,p->hd.nam))
		    			{
							n++;			
						}
				}
		}
		TKHD A[n];
		int stt=0;
		int tong;
		for(int i=0;i<a.sl;i++)
			 {
			 for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
					{
						if (Compare_Date(p->hd.ngay,p->hd.thang,p->hd.nam,d1,m1,y1)
			    		&& Compare_Date(d2,m2,y2,p->hd.ngay,p->hd.thang,p->hd.nam))
			    			{
								//TKHD *A1=new TKHD;						
								A[stt].shd=p->hd.SoHD;
								A[stt].day=p->hd.ngay;
								A[stt].month=p->hd.thang;
								A[stt].year=p->hd.nam;
								A[stt].type=p->hd.loai;
								A[stt].name=a.ds[i]->ho+" "+a.ds[i]->ten;
								tong=0;
								PTR_Bd q=p->PTRcthd;//luu
				 				while (p->PTRcthd!=NULL)
				 				 {
				 							  	//cout<<p->PTRcthd->cthd.sl<<" "<<p->PTRcthd->cthd.price<<" "<<p->PTRcthd->cthd.VAT<<endl;
				 					tong+=((p->PTRcthd->cthd.sl*p->PTRcthd->cthd.price)*(100+p->PTRcthd->cthd.VAT))/100;	 						
									p->PTRcthd=p->PTRcthd->next;
								 }
								p->PTRcthd=q;
								A[stt].total=tong;
								stt++;							
							}
					}
			}
		
		TKHD tmp;
		for (int i=0;i<stt-1;i++)
		{
			for (int j=i+1;j<stt;j++)
			if (Compare_Date(A[i].day,A[i].month,A[i].year,A[j].day,A[j].month,A[j].year))
			{
				tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}
		}	
		int stt1;
		int i=1;
		stt1=(stt-1)/25+1;
		gotoxy(142,33);
		cout<<i<<"/"<<stt1;
		int j;
		
		while (i<=stt1 && i>0)
			{
				int d=1;
						j=25*i-25;
						while (j <  25*i && j<stt)
			 			{  
							  Spacebar(30,38,6+d);
							  gotoxy(30,6+d);	//chon vi tri viet ra
							  cout<<A[j].shd;
							  Spacebar(53,65,6+d);
							  gotoxy(53,6+d);
							  cout<<A[j].day<<"/"<<A[j].month<<"/"<<A[j].year;
							  Spacebar(76,80,6+d);
							  gotoxy(76,6+d);
							  if (A[j].type=='N') cout<<"NHAP"; else cout<<"XUAT";
							  Spacebar(92,119,6+d);
							  gotoxy(92,6+d);
							  cout<<A[j].name;
							  Spacebar(129,140,6+d);
							  gotoxy(129,6+d);
							  cout<<A[j].total;						  	 		     	 						
			 		     	  d++;
			 		     	  j++;
			 		     	  if ( j==stt && j!=25*i )	 
								  {	
									for(int j1=j%25+1; j1<=25;j1++)
									{
									Spacebar(30,38,6+j1);
									Spacebar(53,69,6+j1);
									Spacebar(71,80,6+j1);
									Spacebar(92,119,6+j1);			
									Spacebar(129,140,6+j1);
							 		}
								 }
			 		    }
			 		    d=0;
			 	int kt;
			 	kt=getch();
				if (kt==77 && i<stt1)
			    {						
						Spacebar(142,144,33);
			 			i++;
			 			gotoxy(142,33);
			 			cout<<i<<"/"<<stt1;		 		
			 		   
	         	}
	         	else 
	         	if (kt==75 && i>1)
			    {
						Spacebar(142,144,33);
			 			i--;
			 			gotoxy(142,33);
			 			cout<<i<<"/"<<stt1;	
	         	}
			    else 
	         	if (kt==ESC) break;
	         	
			}
	}
}
void Draw_TKDT(int y)
{
	HighLightD();
	gotoxy(52, 3);
	cout << "BANG THONG KE DOANH THU NAM " << y;
	Normal();
	DrawBorder(47, 5, 40, 18);

	DrawLine(48, 7, 87, 7);

	DrawLine(48, 20, 87, 20);
	DrawLine(60, 5, 60, 22);
	gotoxy(51, 6);
	cout << "THANG";
	for (int i = 1; i <= 12; i++)
	{
		gotoxy(53, 7 + i);
		cout << i;
	}
	gotoxy(68, 6);
	cout << "DOANH THU";

	gotoxy(50, 21);
	cout << "TONG CONG ";
	
	gotoxy(75,24);
	cout<<"ESC : THOAT";
}
void ThongKeDT(DS_NV& a)
{
	AnDauNhay();
	DrawBorder(40, 7, 61, 10);

	DrawBorder(55,5,30,2);
	gotoxy(63,6);
	HighLightD();
	cout<<"THONG KE DOANH THU";
	Normal();
	DrawBorder(40,18,61,2);
	gotoxy(41,19);
	cout<<"  ESC : THOAT                             ENTER : TIEP TUC";
	int kt=getch();
	while (kt != ESC && kt!=ENTER)
	{
		kt=getch();
	}
	if (kt==ENTER)
	{
		Spacebar(41,100,19);
		gotoxy(62,19);
		cout<<"ENTER : TIEP TUC";
		gotoxy(52, 8);
		cout << "CHON NAM BAN MUON THONG KE DOANH THU";
		DrawBorder(63, 15, 13, 2);
		gotoxy(66, 16);
		cout << "XAC NHAN";
		int nam1;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		int year = ltm->tm_year + 1900;
		//lam mot ham nhap so
		HienThiDauNhay();
		do
		{
			Spacebar(67, 75, 11);
			gotoxy(67, 11);
			ChiNhapSo(nam1);
		} while (nam1 <= 0 || nam1 > year);
		DrawBorder(63, 15, 13, 2);
		gotoxy(66, 16);
		AnDauNhay();
		HighLightD();
		cout << "XAC NHAN";
		Normal();
		if (getch() == ENTER)
		{
			system("cls");
			Draw_TKDT(nam1);
			long int tong = 0, TONG = 0;
			for (int i = 1; i <= 12; i++)
			{
				for (int j = 0; j < a.sl; j++)
				{
					for (PTR_B p = a.ds[j]->PTRhd; p != NULL; p = p->next)
					{
						if (p->hd.loai == 'X' && p->hd.thang == i && p->hd.nam == nam1)
							for (PTR_Bd q = p->PTRcthd; q != NULL; q = q->next)
							{
								tong += ((q->cthd.sl * q->cthd.price) * (100 + q->cthd.VAT)) / 100;
							}
					}
				}
				//viet ra doanh thu cua thang
				gotoxy(70, 7 + i);
				cout << tong;
				TONG += tong;
				tong = 0;
			}
			gotoxy(70, 21);
			cout << TONG;
		}
		while (getch()!=ESC) {
			getch();
		}
	}
}
void Draw_TopVT()
{
	clrscr();
	HighLightD();
	gotoxy(59, 2);
	cout << "TOP 10 VAT TU CO DOANH THU CAO NHAT";
	Normal();

	DrawBorder(40, 5, 70, 20);

	DrawLine(41, 7, 110, 7);
	DrawLine(47, 5, 47, 24);
	DrawLine(60, 5, 60, 24);
	DrawLine(87, 5, 87, 24);

	gotoxy(42, 6);
	cout << "TOP";
	for (int i = 1; i <= 10; i++)
	{
		gotoxy(43, 7 + i);
		cout << i;
	}
	gotoxy(50, 6);
	cout << "MA VAT TU";
	gotoxy(68, 6);
	cout << "TEN VAT TU";
	gotoxy(95, 6);
	cout << "DOANH THU";
	
	DrawBorder(97,26,13,2);
	gotoxy(98,27);
	cout<<"ESC : THOAT";

}
void Top10VT(TREE_VT t,DS_NV a)
{
	typedef struct DoanhThu{
		string ma_vt;
		int dt;
	}DT;
	
		int kt=Draw_SetTime();
	if (kt==1) 
	{
		short d1,m1,y1,d2,m2,y2;
		DT dthu[100];
		time_t now=time(0);
		tm *ltm = localtime(&now);
		d1=ltm->tm_mday;
		m1=ltm->tm_mon+1;
		y1=ltm->tm_year+1900;
		d2=d1; m2=m1;y2=y1;
		Setup_Date(d1,m1,y1,58,69,78,10);	
		Setup_Date(d2,m2,y2,73,85,93,13);
		while( Compare_Date(d2,m2,y2,d1,m1,y1)==false)
		{
				Spacebar(73,73+4,13);
				Spacebar(84,85+3,13);
	   			Spacebar(93,93+6,13);
	   			d2=ltm->tm_mday;
				m2=ltm->tm_mon+1;
				y2=ltm->tm_year+1900;
				Setup_Date(d2,m2,y2,73,85,93,13);
		}
		gotoxy(66,16);
		HighLightD();
		cout<<"XAC NHAN";
		Normal();
		int j=0;
		if (getch()==ENTER) 
			{		
				system("CLS");
				Draw_TopVT();
				gotoxy(57,3);
				cout<<"TU NGAY : "<<d1<<"/"<<m1<<"/"<<y1<<" DEN NGAY : "<< d2<<"/"<<m2<<"/"<<y2;
			}
		//duyet tung vat tu trong danh sach->ktra co trong dccthd
		for(int i=0;i<a.sl;i++)
				 {	 	
			 		for (PTR_B p=a.ds[i]->PTRhd;p!=NULL ;p=p->next)
					{				
						if (p->hd.loai=='X')
						{
						if (Compare_Date(p->hd.ngay,p->hd.thang,p->hd.nam,d1,m1,y1)
			    		&& Compare_Date(d2,m2,y2,p->hd.ngay,p->hd.thang,p->hd.nam ))
			    			{
			    				
								PTR_Bd q=p->PTRcthd;//luu
				 				while (p->PTRcthd!=NULL)
				 					{
				 							dthu[j].ma_vt=p->PTRcthd->cthd.MAVT;
			    							dthu[j].dt=((p->PTRcthd->cthd.sl*p->PTRcthd->cthd.price)*(100+p->PTRcthd->cthd.VAT))/100;
			    							j++; 							
											p->PTRcthd=p->PTRcthd->next;
									}
								 p->PTRcthd=q;
								 
			    			}
			    		}
			    	}
				}
	/*		for (int i=0;i<j;i++)
		{
			cout<<dthu[i].ma_vt<<" "<<dthu[i].dt<<endl;
		}*/
				//gop cac ma_vt trung thanh mot
		int k=0;
		while( k<j-1)
		{
			for (int i=k+1;i<j;i++)
			{
				if (dthu[k].ma_vt==dthu[i].ma_vt)
					{
						dthu[k].dt+=dthu[i].dt;
						for (int i1=i;i1<j;i1++)
						  {
						  	dthu[i1]=dthu[i1+1];
						  }
						i--;
						j--;
					}
			}
			k++;
		}
	//	cout<<"het thu"<<endl;
		DT tmp;
		for (int i=0;i<j-1;i++)
		{
			for (int i1=i;i1<j;i1++	)
			if (dthu[i].dt<dthu[i1].dt)
			{
				tmp=dthu[i];
				dthu[i]=dthu[i1];
				dthu[i1]=tmp;
			}
		}
		int j1=8;
		for (int i=0;i<j;i++)
		{
			if (i<10)
			{
				gotoxy(50,j1);
				cout<<dthu[i].ma_vt;
				TREE_VT p=t;
				while (p != NULL && p->vt.ma_vt !=dthu[i].ma_vt)
				{
				    if(dthu[i].ma_vt < p->vt.ma_vt)
				         p = p->pleft;
				      else
				         p = p->pright;
		    	}
				gotoxy(70,j1);
				cout<<p->vt.ten_vt;
				gotoxy(95,j1);
				cout<<dthu[i].dt;
				j1++;
			}		
		}
		while (getch()!=ESC) {
		getch();}
	}
	
}

int Check_Date(int day ,int month, int year )
{
	time_t ht = time(0);
	tm* now = localtime(&ht);
	int ng = now->tm_mday;
	int th = now->tm_mon + 1;
	int nam = now->tm_year + 1900;
	if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
		return 0;
	else if (Compare_Date(ng,th,nam,day,month,year) == 0)
		return 0;
	else
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30)
				return 1;
		}
		else if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				if (day <= 29)
					return 1;
			}
			else
			{
				if (day <= 28)
					return 1;
			}
		}
		else
			if (day <= 31)
				return 1;
	}
	return 0;
}

int Compare_Date(short d, short m, short y, short d1, short m1, short y1)
{
	bool flag;
	if (y > y1) flag = true;
	else if (y < y1) flag = false;
	else
	{
		if (m > m1) flag = true;
		else if (m < m1) flag = false;
		else
		{
			if (d > d1) flag = true;
			else if (d < d1) flag = false;
			else flag = true;//bang nhau cungx return 
		}
	}
	if (flag == true) return 1;
	else return 0;
}
void Setup_Date(short& d, short& m, short& y, int c1, int c2, int c3, int row)
{
	short ng, th, nam;
	bool flag;
	

nhaplai:;
	HienThiDauNhay();
	//ngay
	gotoxy(c1, row);
	ChiNhapSo1(ng);
	while (ng > 31 || ng < 1)
	{
		Spacebar(c1, c1 + 3, row);
		gotoxy(c1, row);
		ChiNhapSo1(ng);
	}
	//thang
	if (ng == 31)
	{
		gotoxy(c2, row);
		ChiNhapSo1(th);
		while (th != 1 && th != 3 && th != 5 && th != 7 && th != 8 && th != 10 && th != 12)
		{
			Spacebar(c2, c2 + 3, row);
			gotoxy(c2, row);
			ChiNhapSo1(th);
		}
	}
	else if (ng == 30)
	{
		gotoxy(c2, row);
		ChiNhapSo1(th);
		while (th != 4 && th != 6 && th != 9 && th != 11 && th != 1 && th != 3 && th != 5 && th != 7 && th != 8 && th != 10 && th != 12)
		{
			Spacebar(c2, c2 + 3, row);
			gotoxy(c2, row);
			ChiNhapSo1(th);
		}
	}
	else
	{
		gotoxy(c2, row);
		ChiNhapSo1(th);
		while (th < 1 || th>12)
		{
			Spacebar(c2, c2 + 3, row);
			gotoxy(c2, row);
			ChiNhapSo1(th);
		}
	}

	//nam
	gotoxy(c3, row);
	ChiNhapSo1(nam);
	while (nam <= 0 || nam > y)
	{
		Spacebar(c3, c3 + 6, row);
		gotoxy(c3, row);
		ChiNhapSo1(nam);
	}
	while (ng == 29 && th == 2)
	{
		if (nam % 100 == 0)
		{
			if (nam % 400 == 0) flag = true;
			else flag = false;
		}
		else if (nam % 4 == 0) flag = true;
		else flag = false;

		if (!flag)
		{
			Spacebar(c3, c3 + 6, row);
			gotoxy(c3, row);
			ChiNhapSo1(nam);
		}
		else break;
	}
	if (!Compare_Date(d, m, y, ng, th, nam))
	{
		Spacebar(c1, c1 + 4, row);
		Spacebar(c2, c2 + 3, row);
		Spacebar(c3, c3 + 6, row);
		goto nhaplai;
	}
	d = ng;
	m = th;
	y = nam;
	AnDauNhay();
}
void Insert_Billdetail(PTR_Bd& First, string m, int s, int pr, int v)
{
	PTR_Bd p;
	p = new NodeB_detail;
	p->cthd.MAVT = m;
	p->cthd.sl = s;
	p->cthd.price = pr;
	p->cthd.VAT = v;

	p->next = NULL;
	if (First == NULL) First = p;
	else
	{
		PTR_Bd Last = First;
		for (; Last->next != NULL; Last = Last->next);
		Last->next = p;
	}
}
void Insert_Bill(PTR_B& First, string s, int ng, int th, int n, char l, PTR_Bd& First1)
{
	PTR_B p;
	p = new NodeBill;
	p->PTRcthd = NULL;
	p->hd.SoHD = s;
	p->hd.ngay = ng;
	p->hd.thang = th;
	p->hd.nam = n;
	p->hd.loai = l;
	p->PTRcthd = First1;


	//Insert_Billdetail(First1,p->hd.PTRcthd->MAVT,p->hd.PTRcthd->sl,p->hd.PTRcthd->price,p->hd.PTRcthd->VAT);
	p->next = NULL;
	if (First == NULL) First = p;
	else
	{
		PTR_B Last = First;
		for (; Last->next != NULL; Last = Last->next);
		Last->next = p;
	}
}
int Delete_First(PTR_Bd& First)
{
	PTR_Bd p;
	if (First == NULL)
		return 0;
	p = First;    // nut can xoa la nut dau
	First = p->next;
	delete p;
	return 1;
}
int Delete_After(PTR_Bd& p)
{
	PTR_Bd q;
	if ((p == NULL) || (p->next == NULL))
		return 0;
	q = p->next;  // q chi nut can xoa
	p->next = q->next;
	delete q;
	return 1;
}
void Draw_Billdetail()
{
	DrawBorder(20, 4, 125, 28);

	DrawLine(21, 6, 145, 6);

	DrawLine(45, 4, 45, 5);
	DrawLine(70, 4, 70, 5);
	DrawLine(95, 4, 95, 5);
	DrawLine(120, 4, 120, 31);

	int i = 0;

	gotoxy(21 + i, 5);
	cout << "MA VAT TU : ";
	i += 25;
	gotoxy(21 + i, 5);
	cout << "SO LUONG : ";
	i += 25;
	gotoxy(21 + i, 5);
	cout << "DON GIA : ";
	i += 25;
	gotoxy(21 + i, 5);
	cout << "VAT : ";
	i += 25;
	gotoxy(26 + i, 5);
	cout << "THEM THANH TOAN";
	//HUONG DAN
	gotoxy(24 + i, 7);
	cout << "----HUONG DAN---- ";
	gotoxy(22 + i, 8);
	cout << "ENTER: TIEP TUC NHAP ";
	gotoxy(22 + i, 9);
	cout << "DELETE: XOA THANH TOAN ";
	gotoxy(22 + i, 10);
	cout << "<- VA ->: DIEU HUONG ";
	gotoxy(22 + i, 11);
	cout << "BACKSPACE: XOA KY TU ";
	gotoxy(22 + i, 12);
	cout << "ESC: QUAY LAI VA LUU";
	gotoxy(27 + i, 13);
	cout << "HOA DON ";


	DrawBorder(24, 7, 93, 22);//ve khung

	DrawLine(25, 9, 117, 9); //ve hang
	//ve cot
	DrawLine(40, 7, 40, 28);
	DrawLine(55, 7, 55, 28);
	DrawLine(70, 7, 70, 28);
	DrawLine(85, 7, 85, 31);
	DrawLine(100, 7, 100, 31);

	gotoxy(86, 30);
	cout << "TONG CONG : ";
	gotoxy(25, 30);
	cout << "THONG BAO : ";

	i = 0;
	gotoxy(28 + i, 8);
	cout << "MA VAT TU";
	i += 15;
	gotoxy(28 + i + 1, 8);
	cout << "SO LUONG";
	i += 15;
	gotoxy(28 + i + 1, 8);
	cout << "DON GIA";
	i += 15;
	gotoxy(28 + i + 3, 8);
	cout << "VAT";
	i += 15;
	gotoxy(28 + i, 8);
	cout << "THANH TIEN ";
	i += 15;
	gotoxy(27 + i, 8);
	cout << "TRANG THAI TT";
}
int Setup_Billdetail(TREE_VT& t, PTR_Bd& First, char key) // key de luu loai, flag1 de xac dinh luu hoa don
{
	//clrscr();
	system("cls");
	HighLightD();
	DrawBorder(68, 1, 17, 2);
	gotoxy(69, 2);
	if (key == 'N') cout << "  HOA DON NHAP  "; else cout << "  HOA DON XUAT  ";
	Normal();
	
	Draw_Billdetail();

	// thuat toan them thanh toán	
	int i1 = 10, stt = 0, stt1;
	string mavt;
	long int tong;
	int s, v;
	int pr;
	bool flag, flag1,fl3=true;
	int Key;
	string s1="\0",v1="\0",pr1="\0",mavt1="\0";
	char kt2;
	//cin.ignore(100);
nhap:;

	stt++;
	int i = 0;
	HighLightD();
	gotoxy(25, 30);
	cout << "THONG BAO :";
	Normal();
	AnDauNhay();
	int key1=NOTICE1(t,"ENTER : BAT DAU NHAP  ESC : KHONG LUU VA THOAT ", "F3 : TRA CUU DANH SACH MA VAT TU ");
	if (key1 !=0 ) // kiem tra thoat hay khong
	{
			gotoxy(25, 30);
			cout << "THONG BAO : ";
			//xac dinh vat tu nam o dau trong cay va m_vt co chua	
			int slt;
			i=0;
			bool fl1=true;
			
		MAVT:
			HienThiDauNhay();
			while (1)
			{
				gotoxy(33+mavt1.length(),5);
				Key=GetKey();
				if (((Key >= 'A' && Key <= 'Z') || (Key <= '9' && Key >= '0') || (Key >= 'a' && Key <= 'z')) && mavt1.length()<10)
				{
					char k=char(Key);
					k=toupper(k);
					mavt1+=k;
					cout<<k;
				}
			
				if (Key== BACKSPACE && mavt1!="\0")
				{
					mavt1.erase(mavt1.length()-1);
					gotoxy(33+mavt1.length(), 5);
					cout << " ";
					gotoxy(33+mavt1.length(), 5);
				}
				if (Key==ENTER && mavt1!="\0")
				{
					while(1)
						{
							while(1)
								{		
									PTR_Bd q=First;
									for (; q!=NULL && q->cthd.MAVT!=mavt1; q=q->next);			
									if (q!=NULL)
										{
											NOTICE("VAT TU DA CO TRONG HOA DON","NHAP VAT TU KHAC");
											goto MAVT;
										}
									else if (q==NULL) break;
								}
							TREE_VT p=t;
							while (p != NULL && p->vt.ma_vt !=mavt1)
									{
									    if(mavt1 < p->vt.ma_vt)
									        p = p->pleft;
										else
										    p = p->pright;
									}
							if (p!=NULL)
									{
										break;
									}
							else
									{	
										NOTICE1(t,"VAT TU KHONG TON TAI", "F3 : XEM MA VAT TU  ESC/ENTER : NHAP LAI");
										goto MAVT;
									}
						}
					
					//ktradkien cua mavt
					gotoxy(58+s1.length(),5);
					goto SL;
				}
				if (Key==-77 && mavt1!="\0")
				{
					while(1)
						{
							while(1)
								{		
									PTR_Bd q=First;
									for (; q!=NULL && q->cthd.MAVT!=mavt1; q=q->next);			
									if (q!=NULL)
										{
											NOTICE("VAT TU DA CO TRONG HOA DON","NHAP VAT TU KHAC");
											goto MAVT;
										}
									else if (q==NULL) break;
								}
							//	slt=0;
							TREE_VT p=t;
							while (p != NULL && p->vt.ma_vt !=mavt1)
									{
									    if(mavt1 < p->vt.ma_vt)
									        p = p->pleft;
										else
										    p = p->pright;
									}
							if (p!=NULL)
									{
										//slt=p->vt.soluong_ton;
										break;
									}
							else
									{
										NOTICE1(t,"VAT TU KHONG TON TAI", "F3 : XEM MA VAT TU  ESC/ENTER : NHAP LAI");
										goto MAVT;
									}
						}
					//ktradkien cua mavt
					gotoxy(58+s1.length(),5);
					goto SL;
				}
				else if (Key==-77 && mavt1=="\0")
				{
					gotoxy(58+s1.length(),5);
					goto SL;
				}
				if (Key==ESC)
				{
					goto nhap;
				}
			}
		SL:
			HienThiDauNhay();
			while (1)
				{
					gotoxy(58+s1.length(),5);
					Key=GetKey();
					if (Key <= '9' && Key >= '0') 
					{
						char k=char(Key);
						s1+=k;
						cout<<k;
					}
				
					if (Key== BACKSPACE && s1!="\0")
					{
						s1.erase(s1.length()-1);
						gotoxy(58+s1.length(), 5);
						cout << " ";
						gotoxy(58+s1.length(), 5);
					}
					if (Key==ENTER && s1!="\0")
					{
						slt=0;
						TREE_VT p=t;
						while (p != NULL && p->vt.ma_vt !=mavt1)
							{
							    if(mavt1 < p->vt.ma_vt)
									    p = p->pleft;
								else
										p = p->pright;
							}
						if (p!=NULL)
							{
								slt=p->vt.soluong_ton;
							}
						s=StringToInt(s1);
						//gotoxy(2,2);
					//	cout<<s;
						AnDauNhay();
						while (s==0 && s1=="0")
						{
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									
									gotoxy(37,30);		
									cout<<"SO LUONG      PHAI LON HON 0";
									gotoxy(46,30);
									if (key=='X')	cout<<"XUAT"; else cout<<"NHAP";
									gotoxy(37,31);
									cout<<"ENTER : NHAP LAI";	
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";								
											break;
								   		 }
								}
													
							goto SL;
						}
						while (key=='X' && s>slt) 
						{	
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									gotoxy(37,30);		
									cout<<"SO LUONG TRONG KHO KHONG DU";
									gotoxy(37,31);
									cout<<"SO LUONG CON LAI :    ENTER : NHAP LAI";				
									gotoxy(56,31);
									cout<<slt;	
														
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";	
											break;
								   		 }
								}
													
							goto SL;
						}
						//ktradkien cua mavt
						gotoxy(83+pr1.length(),5);
						goto GIA;
					}
					if (Key==-77)
					{
						slt=0;
						TREE_VT p=t;
						while (p != NULL && p->vt.ma_vt !=mavt1)
							{
							    if(mavt1 < p->vt.ma_vt)
									    p = p->pleft;
								else
										p = p->pright;
							}
						if (p!=NULL)
							{
								slt=p->vt.soluong_ton;
							}
						s=StringToInt(s1);
						AnDauNhay();
						while (s==0 && s1=="0")
						{
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									
									gotoxy(37,30);		
									cout<<"SO LUONG      PHAI LON HON 0";
									gotoxy(46,30);
									if (key=='X')	cout<<"XUAT"; else cout<<"NHAP";
									gotoxy(37,31);
									cout<<"ENTER : NHAP LAI";	
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";								
											break;
								   		 }
								}
													
							goto SL;
						}
						while (key=='X' && s>slt) 
						{	
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									gotoxy(37,30);		
									cout<<"SO LUONG TRONG KHO KHONG DU";
									gotoxy(37,31);
									cout<<"SO LUONG CON LAI :    ENTER : NHAP LAI";				
									gotoxy(56,31);
									cout<<slt;	
														
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";	
											break;
								   		 }
								}
													
							goto SL;
						}
						//ktradkien cua mavt
						gotoxy(83+pr1.length(),5);
						goto GIA;
					}
					if (Key==-75)
					{
						slt=0;
						TREE_VT p=t;
						while (p != NULL && p->vt.ma_vt !=mavt1)
							{
							    if(mavt1 < p->vt.ma_vt)
									    p = p->pleft;
								else
										p = p->pright;
							}
						if (p!=NULL)
							{
								slt=p->vt.soluong_ton;
							}
						s=StringToInt(s1);
						AnDauNhay();
						while (s==0 && s1=="0")
						{
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									
									gotoxy(37,30);		
									cout<<"SO LUONG      PHAI LON HON 0";
									gotoxy(46,30);
									if (key=='X')	cout<<"XUAT"; else cout<<"NHAP";
									gotoxy(37,31);
									cout<<"ENTER : NHAP LAI";	
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";								
											break;
								   		 }
								}
													
							goto SL;
						}
						while (key=='X' && s>slt) 
						{	
							while (1)
								{
									HighLightD();
									gotoxy(25, 30);
									cout << "THONG BAO : ";
									Normal();
									gotoxy(37,30);		
									cout<<"SO LUONG TRONG KHO KHONG DU";
									gotoxy(37,31);
									cout<<"SO LUONG CON LAI :    ENTER : NHAP LAI";				
									gotoxy(56,31);
									cout<<slt;	
														
									if (getch()==ENTER) 
										{
											Spacebar(37,83,30);
											Spacebar(37,83,31);	
											Normal();
											gotoxy(25, 30);
											cout << "THONG BAO : ";	
											break;
								   		 }
								}
													
							goto SL;
						}
						//ktradkien cua mavt
						gotoxy(33+mavt1.length(),5);
						goto MAVT;
					}
				}
		GIA:
			HienThiDauNhay();
			while (1)
				{
					gotoxy(83+pr1.length(),5);
					Key=GetKey();
					if (Key <= '9' && Key >= '0') 
					{
						char k=char(Key);
						pr1+=k;
						cout<<k;
					}
				
					if (Key== BACKSPACE && pr1!="\0")
					{
						pr1.erase(pr1.length()-1);
						gotoxy(83+pr1.length(), 5);
						cout << " ";
						gotoxy(83+pr1.length(), 5);
						//gotoxy(1,1);
						//cout<<s1;
					}
					if (Key==ENTER && pr1!="\0")
					{
							//ktradkien cua mavt
						gotoxy(103+v1.length(),5);
						goto VAT;
					}
					if (Key==-77)
					{
						//ktradkien cua mavt
						gotoxy(103+v1.length(),5);
						goto VAT;
					}
					if (Key==-75)
					{
						//ktradkien cua mavt
						gotoxy(58+s1.length(),5);
						goto SL;
					}
				}
		VAT:
			HienThiDauNhay();
			while (1)
				{
					gotoxy(103+v1.length(),5);
					Key=GetKey();
					if (Key <= '9' && Key >= '0') 
					{
						char k=char(Key);
						v1+=k;
						cout<<k;
					}
				
					if (Key== BACKSPACE && v1!="\0")
					{
						v1.erase(v1.length()-1);
						gotoxy(103+v1.length(), 5);
						cout << " ";
						gotoxy(103+v1.length(), 5);
					}
					if (Key==ENTER && v1!="\0")
					{
						v=StringToInt(v1);
						if (v>100) 
							{
								NOTICE("VAT >=0 VA <=100","ENTER DE NHAP LAI");
								goto VAT;
							}
						goto TTT;
					}
					if (Key==-77)
					{
						//ktradkien cua mavt
						v=StringToInt(v1);
						if (v>100) 
							{
								NOTICE("VAT >=0 VA <=100","ENTER DE NHAP LAI");
								goto VAT;
							}
						goto TTT;
												
					}
					if (Key==-75)
					{
						v=StringToInt(v1);
						if (v>100) 
							{
								NOTICE("VAT >=0 VA <=100","ENTER DE NHAP LAI");
								goto VAT;
							}
						//ktradkien cua mavt
						gotoxy(83+pr1.length(),5);
						goto GIA;
					}
				}
		TTT:
			while (fl1)
			{
				AnDauNhay();
				gotoxy(126,5);
				HighLightD();
				cout<<"THEM THANH TOAN";
				gotoxy(126,5);
				Normal();
				
				Key=GetKey();
				if (Key==ENTER)
					{
						if (mavt1=="\0" || s1=="\0" || pr1=="\0" || v1=="\0")
						 	{
								NOTICE("PHAI NHAP DAY DU THONG TIN","ENTER DE TIEP TUC NHAP");
								goto MAVT;							
							} 	
						fl1=false;
						kt2=ENTER;
						s=StringToInt(s1);
						v=StringToInt(v1);
						pr=StringToInt(pr1);
						mavt=mavt1;
						s1="\0";
						pr1="\0";
						v1="\0";
						mavt1="\0";
					}
				if (Key==-75)
				{
						gotoxy(126,5);
						Normal();
						cout<<"THEM THANH TOAN";
						goto VAT;
					
				}
			}
		//viet ra va dua vaof cthd
		while (kt2 != ENTER )
			{
				kt2=getch();
			}
		
		if (kt2==ENTER)
			{
				int j = 0;
				gotoxy(30, i1);
				cout << mavt;
				j += 15;
				gotoxy(28 + j + 3, i1);
				cout << s;
				j += 15;
				gotoxy(28 + j + 2, i1);
				cout << pr;
				j += 15;
				gotoxy(28 + j + 4, i1);
				cout << v;
				j += 15;
				gotoxy(28 + j + 3, i1);
				cout << (s * pr * (100 + v)) / 100;
				j += 15;
				gotoxy(28 + j + 2, i1);
				cout << "XAC NHAN";
				Insert_Billdetail(First, mavt, s, pr, v);
				tong = 0;
				for (PTR_Bd p = First; p != NULL; p = p->next)
					tong += (p->cthd.sl * p->cthd.price * (100 + p->cthd.VAT)) / 100;
				Spacebar(89, 98, 31);
				gotoxy(89, 31);
				cout << tong;
				i1++;
			}
			//	huy:;//huy delete quay lai_dathaydoi
			gotoxy(126, 5);
			Normal();
			cout << "THEM THANH TOAN";
			HighLightD();
			gotoxy(124, 7);
			cout << "----HUONG DAN---- ";
			Normal();
			//them vat tu tiep theo vao hoa don
			int stt2;
			char kt;
			bool Flag = true;
			do {
				kt = getch();
				if (kt == 0 || kt == -32) kt = getch();
				switch (kt)
				{
		
				case ENTER:
					//dua phan nhap thanh trang
					i = 0;
					gotoxy(33 + i, 5);
					for (int k = 0; k <= mavt.length() - 1; k++)
						cout << " ";
					i += 25;
					Spacebar(33 + i, 33 + i + 8, 5);
					i += 25;
					Spacebar(33 + i, 33 + i + 8, 5);
					i += 25;
					Spacebar(33 + i - 5, 33 + i + 3, 5);
					Normal();
					gotoxy(124, 7);
					cout << "----HUONG DAN---- ";
					//ve buoc dau
					goto nhap;
					break;
					//thuat toan xoa thanh toan chua luu  
		
				case DEL:
		
					stt1 = stt;
					stt2 = stt;
					do {
						stt = stt1;
						int kt = 0;
						PTR_Bd p = First;
						int chon = Menudong(stt);
		
						Normal();
						if (chon == 0)
						{
							HighLightD();
							gotoxy(124, 7);
							cout << "----HUONG DAN---- ";
							Normal();
							break;
						}
						else
							if (chon == 1) kt = Delete_First(First);
							else {
								for (int j = 2; j < chon; j++)
								{
									p = p->next;
								}
								kt = Delete_After(p);
							}
						if (kt == 1)
						{
							stt1--;
							stt = stt1; // fix loi xoa het
						}
		
						// xoa cac thanh chu trong bang	
						for (int i = 10; i < stt2 + 10; i++)
						{
							int j = 0;
							Spacebar(30, 38, i);
							j += 15;
							Spacebar(28 + j + 3, 28 + j + 3 + 8, i);
							j += 15;
							Spacebar(28 + j + 2, 28 + j + 2 + 8, i);
							j += 15;
							Spacebar(28 + j + 4, 28 + j + 4 + 7, i);
							j += 15;
							Spacebar(28 + j + 3, 28 + j + 3 + 8, i);
							j += 15;
							Spacebar(28 + j + 2, 28 + j + 2 + 8, i);
						}
						if (stt1 == 0)
						{
							i1 = 10;
							Spacebar(89, 98, 31);
							HighLightD();
							gotoxy(124, 7);
							cout << "----HUONG DAN---- ";
							Normal();
							break;
						}
						//viet lai nhung thanh toan con lai chua xoa
						i1 = 10; tong = 0;
						for (PTR_Bd p = First; p != NULL; p = p->next)
						{
							int j = 0;
							gotoxy(30, i1);
							cout << p->cthd.MAVT;
							j += 15;
							gotoxy(28 + j + 3, i1);
							cout << p->cthd.sl;
							j += 15;
							gotoxy(28 + j + 2, i1);
							cout << p->cthd.price;
							j += 15;
							gotoxy(28 + j + 4, i1);
							cout << p->cthd.VAT;
							j += 15;
							gotoxy(28 + j + 3, i1);
							cout << (p->cthd.sl * p->cthd.price * (100 + p->cthd.VAT)) / 100;
							tong += (p->cthd.sl * p->cthd.price * (100 + p->cthd.VAT)) / 100;
							j += 15;
							gotoxy(28 + j + 2, i1);
							cout << "XAC NHAN";
							i1++;
						}
						Spacebar(89, 98, 31);
						gotoxy(89, 31);
						cout << tong;
					} while (stt1 > 0);
					break;
				case ESC: Flag = false;
					break;
				}
			} while (Flag);
	
	}
	else return 0;
	return 1;
}
void Draw_Bill()
{	
	HighLightD();
	DrawBorder(60,4,20,2);
	gotoxy(61,5);
	cout<<"    LAP HOA DON    ";
	Normal();
	
	DrawBorder(45,8,50,10);
	gotoxy(46,10);
	cout<<" SO HOA DON : ";
	gotoxy(46,12);
	cout<<" NGAY        THANG       NAM "<<endl;
	gotoxy(46,14);
	cout<<" LOAI HOA DON (Nhap/Xuat <N/X> ) : ";
	
	DrawBorder(57,16,25,2);
	gotoxy(59,17);
	cout<<"NHAP CHI TIET HOA DON";
	
	DrawBorder(45,19,50,2);
	gotoxy(46,20);
	cout<<"ESC : QUAY LAI                   ENTER : TIEP TUC";
}
void Setup_Bill(TREE_VT &t,DS_NV &a,PTR_B &First)
{
	Draw_Bill();
	
	time_t now=time(0);
	int Key,kt2;
	string s;
	short ng,th,nam; 
	string ng1="\0",th1="\0",nam1="\0";
	char l;	
	bool flag1=false,fl1=true;
	bool ktra;	
	int kt;
	int i=0;
	
	nhaplai:;
	
	gotoxy(46,20);
	AnDauNhay();
	cout<<"ESC : THOAT                  ENTER : BAT DAU NHAP";
	kt=getch();
	while (kt!=ESC && kt!=ENTER)
	{
		kt=getch();
	}
	while (kt!=ESC)
	{
		tm *ltm = localtime(&now);
		ng=ltm->tm_mday;
		th=ltm->tm_mon+1;
		nam=ltm->tm_year+1900;
		IntToString(ng,ng1);
		IntToString(th,th1);
		IntToString(nam,nam1);
		gotoxy(54,12); cout<<ng1;
		gotoxy(66,12); cout<<th1;
		gotoxy(78,12); cout<<nam1;
		
		SOHD:
			HienThiDauNhay();
			Spacebar(46,94,20);
			gotoxy(46,20);
			cout<<"ESC : QUAY LAI                   ENTER : TIEP TUC";
			while (1)
			{
				gotoxy(60+s.length(),10);
				Key=GetKey();
				if (((Key >= 'A' && Key <= 'Z') || (Key <= '9' && Key >= '0') || (Key >= 'a' && Key <= 'z')) && s.length()<20)
				{
					char k=char(Key);
					k=toupper(k);
					s+=k;
					cout<<k;
				}
			
				if (Key== BACKSPACE && s!="\0")
				{
					s.erase(s.length()-1);
					gotoxy(60+s.length(), 10);
					cout << " ";
					gotoxy(60+s.length(), 10);
					//gotoxy(1,1);
					//cout<<s1;
				}
				if (Key==ENTER && s!="\0")
				{
					while (1)
					{
				    	ktra=true;
						for (int i=0; i<a.sl;i++)
						{
							for (PTR_B p=a.ds[i]->PTRhd;p!=NULL;p=p->next)
							{
								if (p->hd.SoHD==s) ktra=false;					
							}
						}
						if (ktra==false)
								{	
									AnDauNhay();
									Spacebar(46,94,20);	
									gotoxy(50,20);
									cout<<"SO HOA DON BI TRUNG ,XIN VUI LONG NHAP LAI";
									getch();				
									Spacebar(50,94,20);			
									gotoxy(60,20);
									cout<<"ENTER : TIEP TUC";
									//Spacebar(60,70,10);
									goto SOHD;
								}
					    else break;
					}
					//ktra so hoa don trung
					gotoxy(54,12);
					goto DATE;
				}
				if (Key==-80)
				{
				
					//ktradkien cua mavt
					gotoxy(54,12);
					goto DATE;
				}
				if (Key==ESC)
				{
					goto nhaplai;
				}
			}
		DATE:
			HienThiDauNhay();
			Spacebar(46,94,20);
			gotoxy(60,20);
			cout<<"ENTER : TIEP TUC"; 
			    NGAY:
			    	while (1)
						{
							gotoxy(54+ng1.length(),12);
							Key=GetKey();
							if (Key <= '9' && Key >= '0' && ng1.length()<2) 
								{
									char k=char(Key);
									ng1+=k;
									cout<<k;
								}
							
							if (Key== BACKSPACE && ng1!="\0")
								{
									ng1.erase(ng1.length()-1);
									gotoxy(54+ng1.length(), 12);
									cout << " ";
									gotoxy(54+ng1.length(), 12);
								}
							if (Key==ENTER && ng1!="\0")
								{
									goto THANG;
								}
							if (Key==-77)
								{						
									goto THANG;						
								}
							if (Key==-80)
								{
									goto LOAI;
								}
							if (Key==-72)
								{
									goto SOHD;
								}
						}
				THANG:
					while (1)
						{
							gotoxy(66+th1.length(),12);
							Key=GetKey();
							if (Key <= '9' && Key >= '0' && th1.length()<2) 
								{
									char k=char(Key);
									th1+=k;
									cout<<k;
								}
							
							if (Key== BACKSPACE && th1!="\0")
								{
									th1.erase(th1.length()-1);
									gotoxy(66+th1.length(), 12);
									cout << " ";
									gotoxy(66+th1.length(), 12);
								}
							if (Key==ENTER && th1!="\0")
								{
									goto NAM;
								}
							if (Key==-77)
								{						
									goto NAM;						
								}
							if (Key==-75)
								{						
									goto NGAY;						
								}
							if (Key==-80)
								{
									goto LOAI;
								}
							if (Key==-72)
								{
									goto SOHD;
								}
						}
				NAM:
					while (1)
						{
							gotoxy(78+nam1.length(),12);
							Key=GetKey();
							if (Key <= '9' && Key >= '0' && nam1.length()<4) 
								{
									char k=char(Key);
									nam1+=k;
									cout<<k;
								}
							
							if (Key== BACKSPACE && nam1!="\0")
								{
									nam1.erase(nam1.length()-1);
									gotoxy(78+nam1.length(), 12);
									cout << " ";
									gotoxy(78+nam1.length(), 12);
								}
							if (Key==ENTER && nam1!="\0")
								{
									goto LOAI;
								}
							if (Key==-75)
								{						
									goto THANG;						
								}
							if (Key==-80)
								{
									goto LOAI;
								}
							if (Key==-72)
								{
									goto SOHD;
								}
						}
						
		LOAI:		
			HienThiDauNhay();	
			while (1)
			{
				gotoxy(82+i,14);
				Key=GetKey();
				if ( (Key=='n' || Key=='x' || Key=='N' || Key=='X') && i==0)
					{
						l=Key;
						l=toupper(l);
						cout<<l;
						i++;
					}	
				if (Key== BACKSPACE && i!=0)
					{
						i--;
						gotoxy(82,14);
						cout <<" ";
					}
				if (Key==ENTER && i==1)
					{
						goto NCTHD;
					}
				if (Key==-72)
					{
						goto DATE;
					}
				if (Key==-80)
					{
						goto NCTHD;
					}
			}
		NCTHD:
			AnDauNhay();
			while (fl1)
			{
				HighLightD();
				gotoxy(59,17);
				cout<<"NHAP CHI TIET HOA DON";	
				Normal();
				
				Key=GetKey();
				if (Key==ENTER)
					{
						ng=StringToInt(ng1);
						th=StringToInt(th1);
						nam=StringToInt(nam1);
						if (Check_Date(ng,th,nam)==0) 
							{
								gotoxy(50,20);
								cout<<"NGAY THANG KHONG HOP LE, ENTER DE CHINH SUA";
								getch();				
								Spacebar(50,94,20);			
								gotoxy(60,20);
								cout<<"ENTER : TIEP TUC";
								Normal();
								gotoxy(59,17);
								cout<<"NHAP CHI TIET HOA DON";				
								goto DATE;		
							}
						if (s=="\0" || i!=1 )
						 	{
								gotoxy(50,20);
								cout<<"THONG TIN CHUA DU, ENTER DE TIEP TUC NHAP";
								getch();				
								Spacebar(50,94,20);			
								gotoxy(60,20);
								cout<<"ENTER : TIEP TUC";
								Normal();
								gotoxy(59,17);
								cout<<"NHAP CHI TIET HOA DON";	
								goto SOHD;							
							} 
						else 
						    {
						    	kt2=ENTER;
						    	fl1=false;
							}
					}
				if (Key==-72)
				{
						Normal();
						gotoxy(59,17);
						cout<<"NHAP CHI TIET HOA DON";
						goto LOAI;
					
				}
			}
				
		PTR_Bd First1=new NodeB_detail;
		First1=NULL;
		int kt1;
		if (kt2==ENTER)
		{	
		    kt1=Setup_Billdetail(t,First1,l);
			kt=ESC;		
	    }
	    
	    if (kt1==1)
	    {
			Insert_Bill(First,s,ng,th,nam,l,First1);
			for(PTR_Bd p=First1;p!=NULL;p=p->next)
				{
					CapNhat_SLT(t,p->cthd.sl,l,p->cthd.MAVT);
				}
		}
	}
}
void Setup_BillNV(TREE_VT& t, DS_NV& a, string Ma_nv)
{
	char filename[30];
	int j;
	for (int i = 0; i < a.sl; i++)
	{
		if (a.ds[i]->ma_nv == Ma_nv)
		{
			j = i;
			break;
		}
	}
	Setup_Bill(t, a, a.ds[j]->PTRhd);
	Ma_nv = Ma_nv + ".txt";

	strcpy(filename, Ma_nv.c_str());
	Write_Bill(a.ds[j]->PTRhd, filename);
}
void CapNhat_SLT(TREE_VT& t, int sl, char l, string mvt)
{
	TREE_VT p;
	p = t;
	while (p != NULL && p->vt.ma_vt != mvt)
	{
		if (mvt < p->vt.ma_vt)
			p = p->pleft;
		else
			p = p->pright;
	}
	if (p != NULL)
	{
		if (l == 'N') p->vt.soluong_ton += sl;
		else p->vt.soluong_ton -= sl;
		//	cout<<"so luong ton la:"<<p->vt.soluong_ton;
	}
}

