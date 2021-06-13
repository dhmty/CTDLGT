#pragma once
#include "CTDL.h"
#include"RW_FILE.h"
#include"GRAPHIC.h"
#include"HOADON.h"

//*****************************NGUYEN MAU HAM*********************************************************
//==================them nv=====================
int them_nv(DS_NV& dsnv);
string tao_ma_nv(DS_NV dsnv);
int kt_trung_MSNV(DS_NV& dsnv, string ma);
int chen_them_NV(DS_NV& dsnv, NHAN_VIEN* p);
//==================Xuat nhan vien===============
void xuat_DS_NV(DS_NV dsnv, int trang, int chon);
void Xuat_thong_tin_1_NV(DS_NV dsnv, int vt);
//=============== Xoa nhan vien ===================
void xoa_nhan_vien(DS_NV& dsnv, int vt);
//============ Hieu chinh nhan vien ==============
void chinh_sua(DS_NV& dsnv, int vt);
void hieu_chinh_nv(DS_NV& dsnv);
string nhap_MS(string& ms, int x, int y);
//==========Xuat danh dach nhan vien theo ten-ho==========
void sap_xep_mang(DS_NV& dsnv);
void hoan_vi(NHAN_VIEN* a, NHAN_VIEN* b);
void copy_mang(DS_NV chinh, DS_NV& tam);
void xuat_DS_NV_theo_ten(DS_NV dsnv);
//====================================================
int khung_thao_tac_3(DS_NV dsnv, int x, int y);
//==================Nhap lieu===================
int nhap_hoten(char c, string& str, int x, int y);
void nhap_thongtin(NHAN_VIEN* p);

//=============MENU TONG=====================
int  MenuHieuChinhVT();
int  MenuXoaVatTu();
int MenuVT();
void EscVT();
void EscHD();
void EscXoaVT();
void EscHieuChinhVT();
int  MenuXoaVatTu1();
int MenuChinh();
//================== menu =================
int draw_menu()
{
	Normal();
	system("cls");
	int chon = 0;
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
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu)
		{
		case LEFT: if (chon > 0)
		{
			Normal();
			gotoxy(chon * khung, 0);
			cout << thucdon[chon];
			chon--;
			Highlight();
			gotoxy(chon * khung, 0);
			cout << thucdon[chon];
		}
				 break;
		case RIGHT:if (chon < item - 1)
		{
			Normal();
			gotoxy(chon * khung, 0);
			cout << thucdon[chon];
			chon++;
			Highlight();
			gotoxy(chon * khung, 0);
			cout << thucdon[chon];
		}
				  break;
		case ENTER:return chon + 1;
		}
	} while (true);
}
void thuc_thi_chinh()
{
	DS_NV dsnv;
	bool kt = true;
	int chon = draw_menu();
	//===================load file================
	doc_file_ds_nv(dsnv);
	//cout << endl << "here";
	while (kt == true)
	{
		switch (chon)
		{
		case 1: //them
		{

			if (dsnv.sl == MAX_NV)
			{
				cout << endl;
				gotoxy(38, 16);
				Highlight_thongbao;
				cout << "  Them khong thanh cong! (Du lieu da day)  " << endl;
				system("pause");
			}
			else
			{
				int kt = true;

				int vt = 0;
				while (kt)
				{
					Normal();
					xoa_khung_vien(50, 12);
					xoa_khung_vien(50, 14);
					gotoxy(51, 11);
					cout << "                                ";
					gotoxy(41, 13);
					cout << "                                ";
					gotoxy(63, 15);
					cout << "                   ";
					gotoxy(35, 18);
					cout << "                                               ";
					draw_khung_thao_tac_1(33, 7);
					vt = them_nv(dsnv);
					gotoxy(46, 17);
					Highlight_thongbao();
					cout << "     Them thanh cong     ";
					Sleep(1000);
					gotoxy(46, 17);
					Normal();
					cout << "                         ";
					gotoxy(35, 18);
					cout << "Enter: Tiep tuc                      ESC: Thoat";
					char kytu = _getch();
					if (kytu == ENTER)
					{
						AnDauNhay();
						kt = true;
					}
					else
					{
						//copy_mang(dsnv, ds);
						//p_xep_mang(dsnv);
						//doc_file_ds_nv(dsnv);
						draw_taskbar(3);
						draw_bang(12, 4);
						xuat_DS_NV(dsnv, vt / 10, vt % 10);
					}
				}
			}

			break;
		}
		case 2:
		{
			if (dsnv.sl == 0)
			{
				cout << endl;
				cout << "That bai!!! (Danh sach rong)" << endl;

			}
			else
			{
				while (true) {
					clrscr();
					draw_taskbar(2);
					draw_khung_thao_tac_2(33, 7);
					hieu_chinh_nv(dsnv);
					gotoxy(35, 28);
					Normal();
					cout << "Enter: Tiep tuc                      ESC: Thoat";
					char kytu = _getch();
					while(kytu!=ENTER && kytu!=ESC)
					{
						kytu=_getch();
					}
					if (kytu == ENTER)
					{
						kt = true;
					}
					else if(kytu==ESC) thuc_thi_chinh();
				}
			}
			//system("pause");
			break;
		}

		case 3:
		{
			draw_bang(8, 4);
			//DS_NV ds;
			//copy_mang(dsnv, ds);
			sap_xep_mang(dsnv);
			draw_taskbar(3);
			draw_bang(12, 4);
			xuat_DS_NV(dsnv, 0, 0);
			gotoxy(35, 28);
			Normal();
			cout << "Enter: Tiep tuc                      ESC: Thoat";
			char kytu = _getch();
			if (kytu == 13) kt = true;
			else thuc_thi_chinh();
			break;
		}
		case 4:
		{
			MenuChinh();
			break;
			//	return 0;

		}
		}

		//}
	}
}

//=================them nhan vien===============
int them_nv(DS_NV& dsnv)
{
	NHAN_VIEN* p = new NHAN_VIEN;
	p->ma_nv = tao_ma_nv(dsnv);
	//cout << endl;
	gotoxy(35, 9);
	Normal();
	cout << "Ma NV:  ";
	cout << p->ma_nv;
	gotoxy(35, 11);
	Normal();
	cout << "Ho " << char(38) << " ten dem:  ";
	gotoxy(35, 13);
	Normal();
	cout << "Ten:  ";
	gotoxy(35, 15);
	Normal();
	cout << "Gioi tinh:  ";
	gotoxy(51, 15);
	SetColor(0);
	SetBGColor(4);
	cout << "             Nu             ";
	Normal();
	gotoxy(34, 20);
	cout << "INSERT: Luu ban ghi";
	gotoxy(34, 21);
	cout << "ESC: Thoat";
	gotoxy(51, 11);
	cout << "                                ";
	gotoxy(41, 13);
	cout << "                                ";
	nhap_thongtin(p);
	int locate = chen_them_NV(dsnv, p);
	ghi_them_vao_file_1_nv(p, locate);
	return locate;
}

string tao_ma_nv(DS_NV dsnv)
{
	string ma = "NV0000";
	do
	{
		for (int i = 2; i < ma.length(); i++)
		{
			ma[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_MSNV(dsnv, ma) >= 0);

	return ma;
}

int kt_trung_MSNV(DS_NV& dsnv, string ma)
{
	for (int i = 0; i < dsnv.sl; i++) {
		if (dsnv.ds[i]->ma_nv == ma) {
			return i;
		}
	}
	return -1;
}

//=================Xuat danh sach nhan vien============
void xuat_DS_NV(DS_NV dsnv, int trang, int vitri_thanhsang)
{
	gotoxy(87, 27);
	Normal();
	cout << "Trang " << trang + 1 << "/" << dsnv.sl / 10 + 1;
	//int trang = 0;
	//int thanh_sang = 0;
	int vitri = 0;
	for (int i = trang * 10; i < dsnv.sl; i++, vitri++)
	{

		if ((i % 10) < 10)
		{
			Normal();
			gotoxy(14, vitri * 2 + 6);
			cout << vitri + 1;
			gotoxy(18, vitri * 2 + 6);
			cout << dsnv.ds[i]->ma_nv;
			gotoxy(31, vitri * 2 + 6);
			cout << dsnv.ds[i]->ho;
			gotoxy(65, vitri * 2 + 6);
			cout << dsnv.ds[i]->ten;
			gotoxy(84, vitri * 2 + 6);
			if (dsnv.ds[i]->phai == 0) cout << "Nu";
			else if (dsnv.ds[i]->phai == 1) cout << "Nam";
		}

		if (((i % 10) == 9) || (i + 1 == dsnv.sl))
		{
			vitri_thanhsang;
			SetColor(195);
			gotoxy(14, vitri_thanhsang * 2 + 6);
			cout << vitri_thanhsang + 1;
			gotoxy(18, vitri_thanhsang * 2 + 6);
			cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
			gotoxy(31, vitri_thanhsang * 2 + 6);
			cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ho;
			gotoxy(65, vitri_thanhsang * 2 + 6);
			cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ten;
			gotoxy(84, vitri_thanhsang * 2 + 6);
			if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 0) cout << "Nu";
			else if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 1) cout << "Nam";
			char kytu;
			do
			{
				kytu = _getch();
				//string ms_tam;
				if (kytu == 0) kytu = _getch();
				switch (kytu)
				{
				case UP: if (vitri_thanhsang > 0)
				{
					Normal();
					gotoxy(14, vitri_thanhsang * 2 + 6);
					cout << vitri_thanhsang + 1;
					gotoxy(18, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
					gotoxy(31, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ho;
					gotoxy(65, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ten;
					gotoxy(84, vitri_thanhsang * 2 + 6);
					if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 0) cout << "Nu";
					else if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 1) cout << "Nam";
					vitri_thanhsang--;
					SetColor(195);
					gotoxy(14, vitri_thanhsang * 2 + 6);
					cout << vitri_thanhsang + 1;
					gotoxy(18, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
					gotoxy(31, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ho;
					gotoxy(65, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ten;
					gotoxy(84, vitri_thanhsang * 2 + 6);
					if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 0) cout << "Nu";
					else if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 1) cout << "Nam";
				}
					   break;
				case DOWN:if ((vitri_thanhsang < 9) && (trang * 10) + vitri_thanhsang + 1 < dsnv.sl)
				{
					Normal();
					gotoxy(14, vitri_thanhsang * 2 + 6);
					cout << vitri_thanhsang + 1;
					gotoxy(18, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
					gotoxy(31, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ho;
					gotoxy(65, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ten;
					gotoxy(84, vitri_thanhsang * 2 + 6);
					if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 0) cout << "Nu";
					else if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 1) cout << "Nam";
					vitri_thanhsang++;
					SetColor(195);
					gotoxy(14, vitri_thanhsang * 2 + 6);
					cout << vitri_thanhsang + 1;
					gotoxy(18, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
					gotoxy(31, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ho;
					gotoxy(65, vitri_thanhsang * 2 + 6);
					cout << dsnv.ds[trang * 10 + vitri_thanhsang]->ten;
					gotoxy(84, vitri_thanhsang * 2 + 6);
					if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 0) cout << "Nu";
					else if (dsnv.ds[trang * 10 + vitri_thanhsang]->phai == 1) cout << "Nam";

				}
						 break;
				case LEFT:if (trang > 0)
				{
					trang--;
					vitri_thanhsang = 0;
					xoabang();
					xuat_DS_NV(dsnv, trang, vitri_thanhsang);
				}
						 break;
				case RIGHT:if (trang < dsnv.sl / 10)
				{
					trang++;
					vitri_thanhsang = 0;
					xoabang();
					xuat_DS_NV(dsnv, trang, vitri_thanhsang);
				}
						  break;
				case ENTER:
				{
					string ms_tam = dsnv.ds[trang * 10 + vitri_thanhsang]->ma_nv;
					int luachon = khung_thao_tac_3(dsnv, 97, 6 + vitri_thanhsang * 2);
					if (luachon == 1)
					{
						Normal();
						system("cls");
						PTR_B First = NULL;
						PTR_Bd First1 = NULL;
						TREE_VT t = NULL;
						Load_VT(t);
						Load_Bill(dsnv, First, First1);
						Setup_BillNV(t, dsnv, ms_tam);
						SaveVT(t);
						//int stt=trang*10+vitri_thanhsang;
						draw_taskbar(3);
						draw_bang(12, 4);
						xuat_DS_NV(dsnv, trang, vitri_thanhsang);
						//cout << "Xuat hoa don";
						//goi ham zo dday

					}
					else if (luachon == 2)
					{
						clrscr();
						draw_taskbar(2);
						draw_khung_thao_tac_2(33, 7);
						gotoxy(45, 12);
						cout << "                    ";
						gotoxy(35, 9);
						cout << "Ma NV:  " << ms_tam;
						int vt = kt_trung_MSNV(dsnv, ms_tam);
						Xuat_thong_tin_1_NV(dsnv, vt);
						gotoxy(35, 18);
						Normal();
						cout << "Enter: Tiep tuc                      ESC: Thoat";
						char kytu = _getch();
						while(kytu!=ENTER && kytu!=ESC)
						{
							kytu=_getch();
						}
						if (kytu == ENTER)
						{
							Normal();
							gotoxy(35, 18);
							cout << "                                               ";
							chinh_sua(dsnv, vt);
						}
						else if (kytu == ESC)
						{
							draw_taskbar(3);
							draw_bang(12, 4);
							xuat_DS_NV(dsnv, vt / 10, vt % 10);
						}
					}
					else
					{
						int vt = kt_trung_MSNV(dsnv, ms_tam);
						Normal();
						system("cls");
						gotoxy(34, 7);
						SetColor(0);
						SetBGColor(190);
						cout << "               Thong tin nhan vien               ";
						draw_khung_thao_tac_1(33,7);
						Xuat_thong_tin_1_NV(dsnv, vt);
						gotoxy(35, 18);
						Normal();
						cout << "Enter: Tiep tuc                      ESC: Thoat";
						AnDauNhay();
						char kytu = _getch();
						while(kytu!=ENTER && kytu!=ESC)
						{
							kytu=_getch();
						}
						if (kytu == ENTER)
						{
							PTR_B First=NULL;
							PTR_Bd First1=NULL;
							Load_Bill(dsnv, First, First1);
							xoa_nhan_vien(dsnv, vt);
							Normal();
							system("cls");
							draw_taskbar(3);
							draw_bang(12,4);
							xuat_DS_NV(dsnv,vt/10, vt%10);
						}
						else if (kytu == ESC)
						{
							Normal();
							system("cls");
							draw_taskbar(3);
							draw_bang(12,4);
							xuat_DS_NV(dsnv,vt/10, vt%10);
						}
					}
					break;
				}
				case ESC:
				{
					clrscr();
					thuc_thi_chinh();
				}
				}

			} while (true);
		}
	}

}

//=============== Xoa nhan vien ===================
void xoa_nhan_vien(DS_NV& dsnv, int vt)
{
	Normal();
	gotoxy(40, 18);
	cout << "                                     ";
	//Highlight();
	gotoxy(35, 18);
	Normal();
	cout << "Enter: Xoa                             ESC: Huy";
	char kytu = _getch();
	while(kytu!=ENTER && kytu!=ESC)
	{
		kytu=_getch();
	}
	if (kytu == ENTER)
	{
		if(dsnv.ds[vt]->PTRhd==NULL)
		{
			for (int i = vt; i < dsnv.sl - 1; i++)
			{
				dsnv.ds[i]->ma_nv = dsnv.ds[i + 1]->ma_nv;
				dsnv.ds[i]->ho = dsnv.ds[i + 1]->ho;
				dsnv.ds[i]->ten = dsnv.ds[i + 1]->ten;
				dsnv.ds[i]->phai = dsnv.ds[i + 1]->phai;
				dsnv.ds[i]->PTRhd = dsnv.ds[i + 1]->PTRhd;
			}
			dsnv.sl--;
			ghi_vao_file_dsnv(dsnv);
			clrscr();
			draw_taskbar(2);
			gotoxy(45, 11);
			Highlight_thongbao();
			cout << "                       " << endl;
			gotoxy(45, 12);
			cout << "   Xoa thanh cong!!!   " << endl;
			gotoxy(45, 13);
			cout << "                       " << endl;
			Sleep(1000);
			sap_xep_mang(dsnv);
			draw_taskbar(3);
			draw_bang(12, 4);
			xuat_DS_NV(dsnv, vt / 10, vt % 10);
		}
		else if(dsnv.ds[vt]->PTRhd!=NULL)
		{
			Normal();
			gotoxy(35, 18);
			cout << "                                               ";
			//cout << "                                           " << endl;
			gotoxy(37, 18);
			Highlight_thongbao();
			cout << "  Khong the xoa nhan vien da lap hoa don!  " << endl;
			Sleep(1500);
			
		}

	}
	else if (kytu == ESC)
	{
		Xuat_thong_tin_1_NV(dsnv, vt);
		int chon = dieu_huong_them(33, 7);
		if (chon==0) thuc_thi_chinh();
		else if (chon == 1) chinh_sua(dsnv, vt);
		else  xoa_nhan_vien(dsnv, vt);
	}
}

//============ Hieu chinh nhan vien ==============
void hieu_chinh_nv(DS_NV& dsnv)
{

	gotoxy(45, 12);
	cout << "Nhap MSNV:  ";
	string ms;
	gotoxy(57, 12);
	HienThiDauNhay();
	Normal();
	cout << "                   ";
	gotoxy(45, 14);
	Normal();
	cout << "                          " << endl;
	gotoxy(35, 18);
	cout << "                                               ";
	gotoxy(57, 12);
	nhap_MS(ms, 57, 12);
	int vt = kt_trung_MSNV(dsnv, ms);
	//====== hieu chinh =====
	if (vt < 0)
	{
		gotoxy(45, 14);
		AnDauNhay();
		Highlight_thongbao();
		cout << "  Ma NV khong ton tai!!!  " << endl;
		Sleep(1000);
		Normal();
		gotoxy(35, 18);
		cout << "Enter: Tiep tuc                      ESC: Thoat";
		char kytu = _getch();
		while(kytu!=ENTER && kytu!=ESC)
		{
			kytu=_getch();
		}
		if (kytu == ENTER) 
		{
			AnDauNhay();
			hieu_chinh_nv(dsnv);
		}
		else thuc_thi_chinh();
		Normal();
		gotoxy(56, 12);
		cout << "                ";
		gotoxy(45, 14);
		Normal();
		cout << "                          " << endl;
	}
	else
	{

		gotoxy(45, 12);
		cout << "                        ";
		gotoxy(34, 7);
		SetColor(0);
		SetBGColor(190);
		cout << "               Thong tin nhan vien               ";
		Xuat_thong_tin_1_NV(dsnv, vt);
		AnDauNhay();
		int chon = dieu_huong_them(33, 7);
		if(chon==0)	thuc_thi_chinh();
		else if (chon == 1)	chinh_sua(dsnv, vt);
		else
		{
		
			PTR_B First=NULL;
			PTR_Bd First1=NULL;
			Load_Bill(dsnv, First, First1);
			xoa_nhan_vien(dsnv, vt);
			thuc_thi_chinh();
		 } 

	}

	ghi_vao_file_dsnv(dsnv);
}

void hoan_vi(NHAN_VIEN* a, NHAN_VIEN* b)
{
	NHAN_VIEN* tam = new NHAN_VIEN;
	tam->ma_nv = a->ma_nv;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->phai = a->phai;
	tam->PTRhd = a->PTRhd;
	a->ma_nv = b->ma_nv;
	a->ho = b->ho;
	a->ten = b->ten;
	a->phai = b->phai;
	a->PTRhd = b->PTRhd;
	b->ma_nv = tam->ma_nv;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->phai = tam->phai;
	b->PTRhd = tam->PTRhd;
	delete tam;
}

void sap_xep_mang(DS_NV& dsnv)
{
	for (int i = 0; i < dsnv.sl - 1; i++)
	{
		for (int j = i + 1; j < dsnv.sl; j++)
		{
			if (dsnv.ds[i]->ten > dsnv.ds[j]->ten)
			{
				hoan_vi(dsnv.ds[i], dsnv.ds[j]);
			}
			else if (dsnv.ds[i]->ten == dsnv.ds[j]->ten)
			{

				if (dsnv.ds[i]->ho > dsnv.ds[j]->ho)
				{
					hoan_vi(dsnv.ds[i], dsnv.ds[j]);
				}
			}
		}
	}
}


void Xuat_thong_tin_1_NV(DS_NV dsnv, int vt)
{
	Normal();
	gotoxy(35, 9);
	Normal();
	cout << "Ma NV:  ";
	cout << dsnv.ds[vt]->ma_nv;
	gotoxy(35, 11);
	cout << "Ho " << char(38) << " ten dem:   " << dsnv.ds[vt]->ho;
	gotoxy(35, 13);
	cout << "Ten:  ";
	gotoxy(51,13);
	cout<<dsnv.ds[vt]->ten;
	gotoxy(35, 15);
	cout << "Gioi tinh:  ";
	gotoxy(51, 15);
	if (dsnv.ds[vt]->phai == 0)
	{
		SetColor(0);
		SetBGColor(4);
		cout << "             Nu             ";
	}
	else
	{
		SetColor(0);
		SetBGColor(203);
		cout << "            Nam             ";
	}
}

void chinh_sua(DS_NV& dsnv, int vt)
{
	gotoxy(35, 9);
	Normal();
	cout << "Ma NV:  ";
	cout << dsnv.ds[vt]->ma_nv;
	gotoxy(35, 18);
	Normal();
	cout << "                                             ";
	gotoxy(34, 20);
	cout << "INSERT: Luu ban ghi";
	gotoxy(34, 21);
	cout << "ESC: Thoat";
	for (int i = 0; i < dsnv.ds[vt]->ho.size(); i++)
	{
		dsnv.ds[vt]->ho.at(i) = toupper(dsnv.ds[vt]->ho.at(i));
	}
	for (int i = 0; i < dsnv.ds[vt]->ten.size(); i++)
	{
		dsnv.ds[vt]->ten.at(i) = toupper(dsnv.ds[vt]->ten.at(i));
	}
	gotoxy(51, 11);
	cout<<dsnv.ds[vt]->ho;
	gotoxy(51, 13);
	cout<<dsnv.ds[vt]->ten;
	gotoxy(51 + dsnv.ds[vt]->ho.length(), 11);
	nhap_thongtin(dsnv.ds[vt]);
	ghi_vao_file_dsnv(dsnv);
	gotoxy(46, 17);
	Highlight_thongbao();
	cout << "Hieu chinh thanh cong!!!" << endl;
	Sleep(1000);
	sap_xep_mang(dsnv);
	draw_taskbar(3);
	draw_bang(12, 4);
	xuat_DS_NV(dsnv, vt / 10, vt % 10);
}
int khung_thao_tac_3(DS_NV dsnv, int x, int y)
{
	//**************Ve khung*********************
	Normal();
	gotoxy(x, y);
	cout << goc_trai_tren;
	gotoxy(x + 15, y);
	cout << goc_phai_tren;
	Normal();
	for (int i = 1; i < 4; i++)
	{
		gotoxy(x, y + i);
		cout << doc;
	}
	gotoxy(x, y + 4);
	cout << goc_trai_duoi;
	for (int i = 1; i < 15; i++)
	{
		gotoxy(x + i, y);
		cout << ngang;
	}
	gotoxy(x + 15, y + 4);
	cout << goc_phai_duoi;
	for (int i = 1; i < 4; i++)
	{
		gotoxy(x + 15, y + i);
		cout << doc;
	}
	for (int i = 1; i < 15; i++)
	{
		gotoxy(x + i, y + 4);
		cout << ngang;
	}
	//**********************************************
	const char td2[item][20] = { " Lap hoa don  ",
								 "  Chinh sua   ",
								 "     Xoa      " };
	Normal();
	int chon = 0;
	for (int i = 0; i < 3; i++)
	{
		gotoxy(x + 1, y + i + 1);
		cout << td2[i];
	}
	SetColor(0);
	SetBGColor(203);
	gotoxy(x + 1, y + chon + 1);
	cout << td2[chon];
	char kytu;
	do
	{
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu)
		{
		case UP: if (chon > 0)
		{
			Normal();
			gotoxy(x + 1, y + chon + 1);
			cout << td2[chon];
			chon--;
			SetColor(0);
			SetBGColor(203);
			gotoxy(x + 1, y + chon + 1);
			cout << td2[chon];
		}
			   break;
		case DOWN:if (chon < 2)
		{
			Normal();
			gotoxy(x + 1, y + chon + 1);
			cout << td2[chon];
			chon++;
			SetColor(0);
			SetBGColor(203);
			gotoxy(x + 1, y + chon + 1);
			cout << td2[chon];
		}
				 break;
		case ENTER:return chon + 1;
		case ESC:
		{
			sap_xep_mang(dsnv);
			draw_taskbar(3);
			draw_bang(12, 4);
			xuat_DS_NV(dsnv, 0, 0);
		}
		}
	} while (true);
}

int nhap_hoten(char c, string& str, int x, int y)
{
	int xcu = x;
	int ycu = y;
	gotoxy(x, y);
	for (int i = 0; i < str.size(); i++)
	{
		str.at(i) = toupper(str.at(i));
	}
	Normal();
	ve_khung_vien(x - 1, y - 1);
	gotoxy(x + str.length(), y);
	HienThiDauNhay();
	while (true)
	{
		if (c == BACKSPACE)
		{
			if (whereX() > xcu)
			{
				string tam = "";
				cout << c << " \b";
				/*for (int i = 1; i < str.length(); i++)
				{
					tam[i] = str[i];
				}
				str = tam;*/
				str.replace(str.length() - 1, 1, "");
			}
		}
		else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32 || c == -32)
		{
			while (c == -32)
			{
				c = _getch();
				if (c == INSERT)
				{
					return -32;
				}
				else
				{
					c = _getch();
				}
				
				if (c == ENTER)
				{
					return ENTER;
				}
			}
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			{
				if (str.length() < 27)
				{
					str = str + c;
					cout << char(c - 32);
				}
			}
			else if (c == 32)
			{
				if (str.length() < 27)
				{
					str.push_back(c);
					cout << c;
				}
			}

		}
		else if (c == ENTER || c == 0)
		{
			if (c == ENTER)
			{
				return ENTER;
			}
			else
			{
				c = _getch();
				
			}
		}
		c = _getch();
	}
}

int chen_them_NV(DS_NV& dsnv, NHAN_VIEN* p)
{
	int vt = 0;
	for (int i = 0; i < dsnv.sl; i++)
	{
		if (dsnv.ds[i]->ten.compare(p->ten) > 0)
		{
			vt = i;
			break;
		}
		else if (dsnv.ds[i]->ten.compare(p->ten) == 0)
		{
			if (dsnv.ds[i]->ten.compare(p->ten) < 0)
			{
				vt = i;
				break;
			}
			else if (dsnv.ds[i]->ten.compare(p->ten) > 0)
			{
				vt = i - 1;
				break;
			}
		}
	}
	for (int i = dsnv.sl - 1; i >= vt; i--)
	{
		dsnv.ds[i + 1] = dsnv.ds[i];
	}
	dsnv.ds[vt] = p;
	dsnv.sl++;
	return vt;
}

void nhap_thongtin(NHAN_VIEN* p)
{
	char c;
	int chon = 0;
	bool kt = true;
	bool flag = true;
	int fl = 1;
	gotoxy(51, 11);
	do
	{
		switch (whereY())
		{
		case 11: //Nhap ho
		{
			SetColor(3);
			ve_khung_vien(50, 10);
			c = _getch();
			gotoxy(34, 21);
			cout << "          ";
			Normal();
			ve_khung_vien(50, 10);
			gotoxy(51, 11);
			HienThiDauNhay();
			if (c == -32 || c == ENTER)
			{
				if (c == ENTER)
				{
					Normal();
					xoa_khung_vien(50, 10);
					ve_khung_vien(50, 12);
					HienThiDauNhay();
					gotoxy(51 + p->ten.length(), 13);
				}
				else
				{
					c = _getch();
					if(c==DOWN)
					{
						Normal();
						xoa_khung_vien(50, 10);
						SetColor(3);
						ve_khung_vien(50, 12);
						AnDauNhay();
						gotoxy(51 + p->ten.length(), 13);
					}
					else if(c == INSERT && p->ten.length() != 0)
					{
						Normal();
						gotoxy(34, 20);
						cout << "                   ";
						flag = false;
						break;
					}
					else if(c == INSERT && p->ten.length() == 0)
					{
						gotoxy(46, 17);
						Highlight_thongbao();
						cout << "  Ten khong duoc trong  ";
						Normal();
						xoa_khung_vien(50, 10);
						ve_khung_vien(50, 12);
						HienThiDauNhay();
						gotoxy(51 + p->ten.length(), 13);
						break;
					}
					else
					{
						break;
					}
				}
			}
			else if (c == ESC)
			{
				thuc_thi_chinh();
				flag = false;
				break;
			}
			else
			{
				c = nhap_hoten(c, p->ho, 51, 11);
				if (c == ENTER)
				{
					Normal();
					xoa_khung_vien(50, 10);
					ve_khung_vien(50, 12);
					HienThiDauNhay();
					gotoxy(51 + p->ten.length(), 13);
				}
				else
				{
					if (p->ten.length() != 0)
					{
						Normal();
						gotoxy(34, 20);
						cout << "                   ";
						flag = false;
						break;
					}
					else
					{
						gotoxy(46, 17);
						Highlight_thongbao();
						cout << "  Ten khong duoc trong  ";
						Normal();
						xoa_khung_vien(50, 10);
						ve_khung_vien(50, 12);
						HienThiDauNhay();
						gotoxy(51 + p->ten.length(), 13);
						break;
					}
				}
			}

			break;
		}
		case 13:
		{
			c = _getch();
			gotoxy(34, 21);
			cout << "          ";
			gotoxy(46, 17);
			Normal();
			cout << "                        ";
			gotoxy(51 + p->ten.length(), 13);
			while (p->ten.length() == 0 && (c == -32 || c == ENTER))
			{
				if (c == -32)
				{
					c = _getch();
					c = _getch();
				}
				else if (c == ENTER)	c = _getch();
			}
			if ((c == -32 || c == ENTER) && p->ten.length() != 0)
			{
				if (c == ENTER)
				{
					Normal();
					xoa_khung_vien(50, 12);
					ve_khung_vien(50, 14);
					gotoxy(51, 15);
					AnDauNhay();
				}
				else
				{
					c = _getch();
					if (c == UP)
					{
						Normal();
						xoa_khung_vien(50, 12);
						SetColor(3);
						ve_khung_vien(50, 10);
						gotoxy(51 + p->ho.length(), 11);
					}
					else if (c == DOWN)
					{
						Normal();
						xoa_khung_vien(50, 12);
						SetColor(3);
						ve_khung_vien(50, 14);
						gotoxy(51, 15);
						AnDauNhay();
					}
					else if(c == INSERT && p->ten.length() != 0)
					{
						Normal();
						gotoxy(34, 20);
						cout << "                   ";
						flag = false;
						break;
					}
				}
			}
			else if (c == ESC)
			{
				thuc_thi_chinh();
				flag = false;
				break;
			}
			else
			{
				c = nhap_hoten(c, p->ten, 51, 13);
				if (c == ENTER)
				{
					Normal();
					xoa_khung_vien(50, 12);
					SetColor(3);
					ve_khung_vien(50, 14);
					gotoxy(51, 15);
					AnDauNhay();
				}
				else
				{
					if (p->ten.length() != 0)
					{
						Normal();
						gotoxy(34, 20);
						cout << "                   ";
						AnDauNhay();
						flag = false;
						break;
					}
				}
			}
			break;
		}
		case 15:
		{
			Normal();
			ve_khung_vien(50, 14);
			c = _getch();
			gotoxy(34, 21);
			cout << "          ";
			if (c == ESC)
			{
				thuc_thi_chinh();
				flag = false;
				break;
			}
			while (c == -32)
			{
				c = _getch();
				if (c == UP)
				{
					Normal();
					xoa_khung_vien(50, 14);
					SetColor(3);
					ve_khung_vien(50, 12);
					gotoxy(51 + p->ten.length(), 13);
					break;
				}
				else if(c == INSERT)
				{
					Normal();
					gotoxy(34, 20);
					cout << "                   ";
					AnDauNhay();
					flag = false;
					break;
				}
				else
				{
					kt = true;
					while (kt)
					{
						const char td3[2][29] = { "             Nu             ",
												  "            Nam             " };
						if (c == RIGHT || c == LEFT)
						{
							chon++;
							if (chon == 2)	chon = 0;
							if (chon == 0)
							{
								gotoxy(51, 15);
								SetColor(0);
								SetBGColor(4);
								cout << td3[chon];
							}
							else
							{
								gotoxy(51, 15);
								SetColor(0);
								SetBGColor(203);
								cout << td3[chon];
							}

						}
						kt = true;
						break;
					}
				}
			c = _getch();
			}
			break;
		}
		}
	} while (flag);
	p->phai = chon;
	if (p->ho.length() != 0)	chuanhoa_chu(p->ho);
	chuanhoa_chu(p->ten);
}

string nhap_MS(string& ms, int x, int y)
{
	ms = "NV";
	int xcu = x + 2;
	int ycu = y;
	gotoxy(x, y);
	cout << ms;
	Normal();
	char c = _getch();
	bool kt=true;
	while (kt)
	{
		gotoxy(48, 17);
		Normal();
		cout << "                     ";
		gotoxy(x + ms.length(), y);
		if (c == BACKSPACE)
		{
			if (whereX() > xcu)
			{
				cout << c << " \b";
				ms.replace(ms.length() - 1, 1, "");
			}
		}
		else if (c >= 48 && c <= 57 && ms.length() < 6)
		{
			ms += c;
			cout << c;
		}
		else if (c == ENTER && ms.length() < 6)
		{
			gotoxy(48, 17);
			Highlight_thongbao();
			cout << "  Ma so gom 6 ky tu  ";
			gotoxy(x + ms.length(), y);
		}
		else if (c == ENTER && ms.length() == 6)
		{
			return ms;
		}
		else if(c==ESC)
		{
			thuc_thi_chinh();
			kt=false;
		}
		c = _getch();
	}

}


///==================================NGUYEN DUC TU================================================
void KhoiTaoMenuChinh()
{
	gotoxy(0, 0);
	gotoxy(1, 1);
	gotoxy(32, 1);
	cout << "QUAN LY NHAP XUAT VAT TU";
	KhungNho(30, 3);
	KhungNho(30, 6);
	KhungNho(30, 9);
	
	gotoxy(31, 4);
	cout << "1. VAT TU                   ";
	gotoxy(31, 7);
	cout << "2. NHAN VIEN VA LAP HOA DON ";
	gotoxy(31, 10);
	cout << "3. HOA DON VA THONG KE      ";
}
int MenuChinh()
{
	//DSNV nv;
	Normal();
	system("cls");
	int check = 0;
	KhoiTaoMenuChinh();//tao menu vat tu
	string lt[13];
	lt[4] =   "1. VAT TU                   ";
	lt[7] =   "2. NHAN VIEN VA LAP HOA DON ";
	lt[10] =  "3. HOA DON VA THONG KE      ";
	
	HD();
	gotoxy(31, 4);
	MauChon();
	cout << lt[4];//chon cai thu nhat
	AnDauNhay();
	while (check == 0)
	{
		char kk = getch();
		if (kk == 72)//phim di chuyen len
		{
			int y = wherey();
			if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
			{
				gotoxy(31, y);
				Normal();
				cout << lt[4];
				gotoxy(31, 10);
				MauChon();
				cout << lt[10];
				Normal();
			}
			else//moi lan chay qua nhay 3 hang
			{
				gotoxy(31, y);
				Normal();
				cout << lt[y];
				gotoxy(31, y - 3);
				MauChon();
				cout << lt[y - 3];
				Normal();
			}
		}
		else if (kk == 80)
		{
			int y = wherey();
			if (y == 10) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
			{
				gotoxy(31, 10);
				Normal();
				cout << lt[10];
				gotoxy(31, 4);
				MauChon();
				cout << lt[4];
				Normal();
			}
			else
			{
				gotoxy(31, y);
				Normal();
				cout << lt[y];
				gotoxy(31, y + 3);
				MauChon();
				cout << lt[y + 3];
				Normal();
			}
		}
		else if (kk == 13)
		{
			int y = wherey();
			if (y == 4)
			{
				Normal();
				system("cls");
				EscVT();
				SaveVT(t);
				return 0;
			}
			if (y == 7)
			{



				srand(time(NULL));
				AnDauNhay();
				thuc_thi_chinh();
				return 0;
			}
			if (y == 10)
			{
				Normal();
				system("cls");
				EscHD();
				//SaveHD();
				return 0;
			}

		}
		else if (kk == 27)
		{
			return 1;

		}
	}
	AnDauNhay();

}
void EscMenuChinh()
{
	int check = 0;
	while (check == 0)
	{
		check = MenuChinh();
	}
}

// ************** MENU VAT TU ************* 

int MenuVT()
{
	AnDauNhay();
	Load_VT(t);
	system("CLS");
	int check = 0;
	KhoiTaoMenuVT();//tao menu vat tu
	string lt[19];
	lt[4] = "1. Nhap vat tu            ";
	lt[7] = "2. Hieu chinh vat tu      ";
	lt[10] = "3. Xoa vat tu             ";
	lt[13] = "4. Danh sach VT trong kho ";

	HD();
	gotoxy(3, 4);
	MauChon();
	cout << lt[4];//chon cai thu nhat
	while (check == 0)
	{
		char kk = getch();
		if (kk == 72)//phim di chuyen len
		{
			int y = wherey();
			if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
			{
				gotoxy(3, y);
				Normal();
				cout << lt[4];
				gotoxy(3, 13);
				MauChon();
				cout << lt[13];
				Normal();
			}
			else//moi lan chay qua nhay 3 hang
			{
				gotoxy(3, y);
				Normal();
				cout << lt[y];
				gotoxy(3, y - 3);
				MauChon();
				cout << lt[y - 3];
				Normal();
			}
		}
		else if (kk == 80)
		{
			int y = wherey();
			if (y == 13) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
			{
				gotoxy(3, 13);
				Normal();
				cout << lt[13];
				gotoxy(3, 4);
				MauChon();
				cout << lt[4];
				Normal();
			}
			else
			{
				gotoxy(3, y);
				Normal();
				cout << lt[y];
				gotoxy(3, y + 3);
				MauChon();
				cout << lt[y + 3];
				Normal();
			}
		}
		else   if (kk == 13)
		{

			int y = wherey();
			if (y == 4)
			{
				Normal();
				gotoxy(60, 3);
				KhungNho(15, 0);
				cout << "  +    THEM VAT TU + " << endl;
				ESCNhapVTmoi();
				return 0;
			}
			if (y == 7)
			{
				Normal();
				HienThiDauNhay();
				KhungNho(15, 0);
				cout << "   +   HIEU CHINH VAT TU + " << endl;
				//Load_VT(t);
				EscHieuChinhVT();
				Normal();
				return  0;
			}
			if (y == 10)
			{

				Normal();
				HienThiDauNhay();
				KhungNho(15, 0);
				cout << "   +  XOA VAT TU + " << endl;
				EscXoaVT();
				Normal();
				return 0;
			}
			if (y == 13)
			{

				Normal();
				gotoxy(15, 0);	
				Load_VT(t);

				xuat_DSVT(t, 0, 0);
				
				return 0;
			}
		}
		else if (kk == 27)
		{
			return MenuChinh();
		}
	}
	AnDauNhay();
}
void EscVT()
{
	int check = 0;
	while (check == 0)
	{
		check = MenuVT();
	}
}

int  MenuHieuChinhVT()
{
	system("cls");
	gotoxy(20, 1);
	
	cout << "   MENU VAT TU  ";
	HuongDanHCVT();
	string s = "";
	int vitri = 63;
	//	int y = wherey();
	HD();
	Luu_Y();
NhapLaix:
	HienThiDauNhay();
	gotoxy(60, 30);
	cout << "+ Nhan TAB de hien thi DSVT  ";
	gotoxy(45, 2);
	cout << "Nhap ma vat tu :";
	KhungNho(62, 1);
	gotoxy(50, 6);
	if (TinhsoNode(t) == 0)
	{
		gotoxy(69, 10);
		cout << "Ban chua co vat tu nao !!!";
	}
	else
	{
		int dem = 0;
		VAT_TU B[500];
		Load_VT(t);
		DuyetCay(t, B, dem);
		SapXepTheoTenVT(B);
	}
	
	HienThiDauNhay();
	gotoxy(63, 2);
	int check = 0;
	while (check == 0)
	{
		while (!kbhit())
		{
			char c = getch();			
			 if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c == 32))

			{
				gotoxy(63, 2);
				cout << "                            ";
				s.insert(vitri - 63, 1, c);
				Upper_case(s, 63, 2);
				vitri=vitri+s.length();
				gotoxy(vitri, 2);

			}
			else if (c == 8 && s.length() > 0 && vitri > 63)
			{
				if (s.size() != 0)
				{
					vitri--;
					gotoxy(63, 2);
					cout << "                            ";
					gotoxy(63, 2);
					s.erase(vitri - 63, 1);// xoa vi tri 
					cout << s;
					gotoxy(vitri, 2);

				}
			}
			else if (c == 13) //Enter de nhan du lieu kiem tra
			{
				if (KiemTraTrungMaVT(t, s) == 0)
				{
					string a = "Khong tim thay vat tu ";
					while (!kbhit()) CanhBao(a, 40, 5);
					gotoxy(63, 2);
					cout << s;
					gotoxy(vitri, 2);				
					c = getch();
				}
				else
				{
					
					HieuchinhVatTu(s);
					SaveVT(t);								
					return 1;

				}
			}
			else if (c == -32)
			{
				char kk = getch();
				if (kk == 75) // qua trai
				{
					if (s.length() > 0 && vitri > 63)
					{
						vitri--;
						gotoxy(vitri, 2);
					}
				}
				else if (kk == 77)//mui ten qua phai
				{
					if (s.length() > 0 && vitri < 63 + s.length())
					{
						vitri++;
						gotoxy(vitri, 2);
					}
				}
			}
			else if (c == 9)
			{
				xuat_DSVT(t, 0, 0);
				goto NhapLaix;
				return 1;

			}
			else if (c == 27)//27 la phim esc thi thoat khoi khoi menu nhap vat tu
			 {
				 check = 1;
				 return 1;
			 }
		}
	}
}

void EscHieuChinhVT()
{
	int check = 0;
	while (check == 0)
	{
		check = MenuHieuChinhVT();
	}
}
void EscXoaVT()
{
	int check = 0;
	while (check == 0)
	{
		check = MenuXoaVatTu1();

	}

}

int  MenuXoaVatTu1()
{
	
	string s = "";
	int vitri = 63;
	//	int y = wherey();
	HD();
	Luu_Y();
	gotoxy(60, 30);
	cout << "+ Nhan TAB de hien thi DSVT";
	gotoxy(45, 2);
	cout << "Nhap ma vat tu :";
	KhungNho(62, 1);
	gotoxy(50, 6);
	if (TinhsoNode(t) == 0)
	{
		gotoxy(69, 10);
		cout << "Ban chua co vat tu nao !!!";
	}
	else
	{
		int dem = 0;
		VAT_TU B[500];
		Load_VT(t);
		DuyetCay(t, B, dem);
		SapXepTheoTenVT(B);
	}
	NhapLai1:
	HienThiDauNhay();
	gotoxy(63, 2);
	//Upper_case(s, 63, 2);
	int check = 0;
	while (check == 0)
	{
		while (!kbhit())
		{
			char c = getch();
			if (c == 27)//27 la phim esc thi thoat khoi khoi menu nhap vat tu
			{
				check = 1;
				return 1;
			}		
			else if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c == 32))

			{		
				gotoxy(63, 2);
				cout << "                            ";
				Upper_case(s, 63, 2);				
				vitri = vitri + s.length();	
			NhapLai2:
				HienThiDauNhay();
				gotoxy(vitri, 2);
			}
			else if (c == 8 && s.length() > 0 && vitri > 63)
			{			
				if (s.size() != 0)
				{
					vitri--;
					gotoxy(63, 2);
					cout << "                            ";
					gotoxy(63, 2);
					s.erase(vitri - 63, 1);// xoa vi tri 
					cout << s;
					gotoxy(vitri, 2);

				}
			}
			else if (c == 13) //Enter de nhan du lieu kiem tra
			{
				if (KiemTraTrungMaVT(t, s) == 0)
				{
					string a = "KHONG TIM THAY VAT TU ";
					while (!kbhit()) CanhBao(a, 60, 5);
					gotoxy(63, 2);
					cout << s ;
					gotoxy(vitri, 2);
					
					c = getch();

				}
				else
				{
					bool flag=true;
					PTR_B First=NULL;
					PTR_Bd First1=NULL;
					DS_NV a;
        			a.sl=0;
					doc_file_ds_nv(a);
					Load_Bill(a,First,First1);
					int kt=XoaVatTu(s,t,a);
					
					if (kt==1)
					{	
						MauChon();
						SaveVT(t);
				 		CanhBao("      DA XOA VAT TU !     ",123,15);
						Normal();
						gotoxy(123,15);
						cout<<"                          ";	
						xuat_DSVT(t, 0, 0);
				 	}
					else CanhBao("KHONG THE XOA VAT TU CO TRONG HOA DON", 60, 4);
					Sleep(200);																				
					goto NhapLai2;
									
					return 1;

				}
			}
			
			else if (c == -32)
			{
				char kk = getch();
				if (kk == 75) // qua trai
				{
					if (s.length() > 0 && vitri > 63)
					{
						vitri--;
						gotoxy(vitri, 2);

					}
				}
				else if (kk == 77)//mui ten qua phai
				{
					if (s.length() > 0 && vitri < 63 + s.length())
					{
						vitri++;
						gotoxy(vitri, 2);
					}
				}
			}
			else if (c == 9)
			{
				xuat_DSVT(t, 0, 0);
				goto NhapLai1;
				HienThiDauNhay();

			}
		}
	}
}


//************** MENU HOA DON **************  
void KhoiTaoMenuHoaDon()
{
	gotoxy(0, 0);
	gotoxy(1, 1);
	gotoxy(37, 1);
	cout << "MENU HOA DON ";
	KhungNho(30, 3);
	KhungNho(30, 6);
	KhungNho(30, 9);
	KhungNho(30, 12);
	gotoxy(31, 4);
	cout << "1. In hoa don         ";
	gotoxy(31, 7);
	cout << "2. Thong ke hoa don    ";
	gotoxy(31, 10);
	cout << "3. 10 VT co doanh thu cao  ";
	gotoxy(31, 13);
	cout << "4. Thong ke doanh thu     ";
}
int MenuHD()
{
	PTR_B First=NULL;
	PTR_Bd First1=NULL;
	DS_NV a;
	a.sl=0;
	TREE_VT t=NULL;
	system("cls");
	int check = 0;
	KhoiTaoMenuHoaDon();//tao menu vat tu
	string lt[16];
	lt[4] = "1. In hoa don              ";
	lt[7] = "2. Thong ke hoa don        ";
	lt[10] = "3. 10 VT co doanh thu cao ";
	lt[13] = " 4. Thong ke doanh thu     ";
	HD();
	gotoxy(31, 4);
	MauChon();
	cout << lt[4];//chon cai thu nhat
	while (check == 0)
	{
		char kk = getch();
		if (kk == 72)//phim di chuyen len
		{
			int y = wherey();
			if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
			{
				gotoxy(31, y);
				Normal();
				cout << lt[4];
				gotoxy(31, 13);
				MauChon();
				cout << lt[13];
				Normal();
			}
			else//moi lan chay qua nhay 3 hang
			{
				gotoxy(31, y);
				Normal();
				cout << lt[y];
				gotoxy(31, y - 3);
				MauChon();
				cout << lt[y - 3];
				Normal();
			}
		}
		else if (kk == 80)
		{
			int y = wherey();
			if (y == 13) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
			{
				gotoxy(31, 13);
				Normal();
				cout << lt[13];
				gotoxy(31, 4);
				MauChon();
				cout << lt[4];
				Normal();
			}
			else
			{
				gotoxy(31, y);
				Normal();
				cout << lt[y];
				gotoxy(31, y + 3);
				MauChon();
				cout << lt[y + 3];
				Normal();
			}
		}
		else if (kk == 13)
		{
			doc_file_ds_nv(a);
			Load_Bill(a,First,First1);
			int y = wherey();
			if (y == 4)
			{
				Normal();
				system("cls");
				Search_Bill(a);
				//InMotHoaDon();
				//SaveHD();
				return 0;
			}
			if (y == 7)
			{
				Normal();
				system("cls");
				ThongKeHD(a);
				//Thong ke 
				//SaveHD();
				return 0;
			}
			if (y == 10)
			{
				Normal();
				system("cls");
				Load_VT(t);
				Top10VT(t,a);
				//In10VatTu();
				//SaveHD();
				return 0;

			}
			if (y == 13)
			{
				Normal();
				system("cls");
				ThongKeDT(a);
				//In10VatTu();
				//SaveHD();
				return 0;

			}
		}
		else if (kk == 27)
		{

			return MenuChinh();

		}
	}

}
void EscHD()
{
	int check = 0;
	while (check == 0)
	{
		check = MenuHD();
	}
}

