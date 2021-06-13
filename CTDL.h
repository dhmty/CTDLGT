#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include"mylib.h"
#include<iomanip>

#define TRUE 1
#define FALSE 0
#define MAX_NV 500

using namespace std;
//*** DANH SACH VAT TU ***
struct vattu {
	string  ma_vt;
	string ten_vt;
	string donvi_tinh;
	int soluong_ton;
};
typedef struct vattu VAT_TU;

struct nodeVT {

	VAT_TU vt;
	nodeVT* pleft;
	nodeVT* pright;

};
typedef struct nodeVT NODEVT;
typedef NODEVT* TREE_VT;

struct hashtable {
	NODEVT* head;
	NODEVT* tail;
};
typedef struct hashtable Hashtable;
//TREE_VT t = NULL; // Khoi tao cay nhi phan


//**** DANH SACH CHI TIET HOA DON ****
typedef struct Billdetail {
	string MAVT;
	int sl;
	int price;
	int VAT;
}Billdetail;
typedef struct NodeB_detail {
	Billdetail cthd;
	NodeB_detail* next;
}*PTR_Bd;

typedef struct Bill {
	string SoHD;
	int ngay, thang, nam;
	char loai;

}Bill;
typedef struct NodeBill {
	Bill hd;
	PTR_Bd PTRcthd;
	NodeBill* next;
}*PTR_B;

//************* DANH SACH NHAN VIEN *************
struct nhanvien {
	string ma_nv;
	string ho;
	string ten;
	int phai;//0: nu 1: nam
	//ds hoadon
	PTR_B PTRhd;
};
typedef struct nhanvien NHAN_VIEN;
struct ds_nhanvien {
	NHAN_VIEN* ds[MAX_NV];
	int sl = 0;
};
typedef struct ds_nhanvien DS_NV;

typedef struct DoanhThu {
	string ma_vt;
	int dt;
}DT;

// ********* CHUAN HOA CHU  
/*string chuanhoa_chu(string& a)
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

	if (a[0] != 32)
	{
		if (a[0] > 96 && a[0] < 123)
		{
			a[0] -= 32;
		}
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == 32)
		{
			if (a[i + 1] > 96 && a[i + 1] < 123)
			{
				a[i + 1] -= 32;
			}


		}
	}
	return a;
}*/

