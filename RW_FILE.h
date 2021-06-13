
#pragma once
//#include "ctdl.h"
//===================== doc file ds nv ================
void doc_file_ds_nv(DS_NV& dsnv)
{
	ifstream filein;
	filein.open("dsnv.txt", ios_base::in);
	//dsnv.sl = 0;
	while (!filein.eof())
	{
		dsnv.ds[dsnv.sl] = new NHAN_VIEN;
		getline(filein, dsnv.ds[dsnv.sl]->ma_nv, ',');
		getline(filein, dsnv.ds[dsnv.sl]->ho, ',');
		getline(filein, dsnv.ds[dsnv.sl]->ten, ',');
		filein >> dsnv.ds[dsnv.sl]->phai;
		filein.ignore();
		dsnv.sl++;
	}
	filein.close();
}

void ghi_them_vao_file_1_nv(NHAN_VIEN* p, int vt)
{
	ofstream fileout;
	fileout.open("dsnv.txt", ios::app);
	//fileout._Seekbeg;
	//fileout.seekp(sizeof(NHAN_VIEN) * vt);
	fileout << "\n" << p->ma_nv << ',';
	fileout << p->ho << ',';
	fileout << p->ten << ',';
	fileout << p->phai;
	fileout.close();
}

void ghi_vao_file_dsnv(DS_NV dsnv)
{
	ofstream fileout;
	fileout.open("dsnv.txt", ios_base::out);
	//fileout._Seekbeg;
	for (int i = 0; i < dsnv.sl; i++)
	{
		fileout << dsnv.ds[i]->ma_nv << ',';
		fileout << dsnv.ds[i]->ho << ',';
		fileout << dsnv.ds[i]->ten << ',';
		if (i == dsnv.sl - 1)
		{
			fileout << dsnv.ds[i]->phai;
		}
		else
		{
			fileout << dsnv.ds[i]->phai << "\n";
		}
	}
	fileout.close();
}
