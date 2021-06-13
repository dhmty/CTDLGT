#pragma once
#include"CTDL.h"
#include"GRAPHIC.h"
#include"RW_FILE.h"
#include"NHANVIEN.h"

int MenuHieuChinhVT();
TREE_VT t = NULL;

int strcmp1(string a, string b)
{
    int n = 0;
    do
    {
        if (a[n] > b[n])
            return 1;
        else if (a[n] < b[n])
            return -1;
        n++;
    } while (a[n] != '\0' || b[n] != '\0');

    return 0;
}
int SoSanhChuoi(VAT_TU x, VAT_TU y)// So sanh hai chuoi x va y
{
    return strcmp1(x.ma_vt, y.ma_vt);
}
int KiemTraTrungMaVT(TREE_VT t, string a)
{
    char s[11];
    strcpy(s, a.c_str());
    //	strupr(s);
    nodeVT* p;
    while (t) {
        if (t->pleft == NULL) {
            if (strcmp1(t->vt.ma_vt, s) == 0) return 1;
            t = t->pright;
        }
        else {
            p = t->pleft;
            while (p->pright && p->pright != t) {
                p = p->pright;
            }
            if (p->pright == NULL) {
                p->pright = t;
                t = t->pleft;
            }
            else {
                p->pright = NULL;
                if (strcmp1(t->vt.ma_vt, s) == 0) return 1;

                t = t->pright;
            }
        }
    }
    return 0;
}
int KiemTraCay(TREE_VT t)
{
    return (t != NULL ? 1 : 0);
}
void Insert(TREE_VT& t, VAT_TU x)
{
    if (t == NULL)
    {
        NODEVT* q = new NODEVT();
        q->vt = x;
        q->pleft = q->pright = NULL;
        t = q;
    }
    else
    {
        if (SoSanhChuoi(t->vt, x) > 0)
        {
            Insert(t->pleft, x);
        }
        else if (SoSanhChuoi(t->vt, x) < 0)
        {
            Insert(t->pright, x);
        }
    }
}
void SaveVT(TREE_VT t)//dung duyet file theo kieu lnr khong de quy, de luu vao file txt
{
    ofstream f("VATTU.txt", ios::out);
    NODEVT* p;
    while (t != NULL) {
        if (t->pleft == NULL) {
            f << t->vt.ma_vt << endl;
            f << t->vt.ten_vt << endl;
            f << t->vt.donvi_tinh << endl;
            f << t->vt.soluong_ton << endl;
            t = t->pright;
        }
        else {
            p = t->pleft;
            while (p->pright && p->pright != t) {
                p = p->pright;
            }
            if (p->pright == NULL) {
                p->pright = t;
                t = t->pleft;
            }
            else {
                p->pright = NULL;
                f << t->vt.ma_vt << endl;
                f << t->vt.ten_vt << endl;
                f << t->vt.donvi_tinh << endl;
                f << t->vt.soluong_ton << endl;
                t = t->pright;
            }
        }
    }
    f.close();
}
void Load_VT(TREE_VT& t) // Load file vao cay
{
    ifstream f("VATTU.txt", ios::in);

    while (!f.eof())
    {
        VAT_TU x;
        getline(f, x.ma_vt);
        getline(f, x.ten_vt);
        getline(f, x.donvi_tinh);
        f >> x.soluong_ton;
        f.ignore();
        if (f.tellg() == -1)
        {
            break;
        }
        else
        {
            Insert(t, x);

        }

    }
    f.close();
}
void HuongDanNhap()
{
    char l = 179;
    //KhungNho(25, 0);
    // cout << "      + THEM VAT TU +   ";

    gotoxy(55, 3);
    cout << "     |Huong dan su dung|";
    cout << endl;
    gotoxy(50, 4);
    cout << "Nhap phim ESC de tro lai    " << endl;
    gotoxy(50, 5);
    cout << "Nhap Enter de tiep tuc nhap         " << endl;
    cout << endl;

    KhungNho(68, 10);
    gotoxy(50, 11);
    cout << "NHAP MA VAT TU ";
    KhungNho(68, 13);
    gotoxy(50, 14);
    cout << "NHAP TEN VAT TU ";
    KhungNho(68, 16);
    gotoxy(50, 17);
    cout << "NHAP DON VI TINH ";
    KhungNho(68, 19);
    gotoxy(50, 20);
    cout << "NHAP SO LUONG";

}
void KhoiTaoMenuVT()
{
    gotoxy(0, 0);
    gotoxy(1, 1);
    gotoxy(15, 0);
    cout << "MENU NHAP XUAT VAT TU";
    KhungNho(2, 3);
    KhungNho(2, 6);
    KhungNho(2, 9);
    KhungNho(2, 12);

    gotoxy(3, 4);
    cout << "1. Them vat tu          ";
    gotoxy(3, 7);
    cout << "2. Hieu chinh vat tu        ";
    gotoxy(3, 10);
    cout << "3. Xoa vat tu              ";
    gotoxy(3, 13);
    cout << "4. Danh sach VT trong kho   ";

}

int NhapVTmoi()
{

    system("cls");
    KhoiTaoMenuVT();
    string lt[19];
    lt[4] = "1. Nhap vat tu            ";
    lt[7] = "2. Hieu chinh vat tu      ";
    lt[10] = "3. Xoa vat tu             ";
    lt[13] = "4. Danh sach VT trong kho ";

    HD();
    
    gotoxy(3, 4);
    MauChon();
    cout << lt[4];
    Normal();
    HuongDanNhap();
    HienThiDauNhay();
    int dong1 = 11, dong2 = 14, dong3 = 17, dong4 = 20; //khai bao vi tri tung cot nhap
    int flag = 1;
    string f[4];
    f[0] = "";
    f[1] = "";
    f[2] = "";
    f[3] = "";
    int vitri1, vitri2, vitri3, vitri4;
    vitri1 = vitri2 = vitri3 = vitri4 = 70;
    //	 int x = wherex();
    int y = wherey();
    gotoxy(vitri1, dong1);
    int check = 0;
    while (check == 0)
    {
        while (kbhit())
        {
            VAT_TU nd;
            if (flag == 1)
            {
                vitri1 = 70 + f[0].size();//vi tri  con tro nam o cuoi cung cua chuoi           
                gotoxy(52, 6);
                cout << "*Ma Vat Tu khong bat dau bang khoang trang          ";
                gotoxy(52, 7);
                cout << "*Gom cac ki tu (a-z), (A-Z)                         ";
                gotoxy(52, 8);
                cout << "*Cac so (0-9)                                        ";
                gotoxy(vitri1, dong1);
            }
            else if (flag == 2)
            {
                vitri2 = 70 + f[1].size();//vi tri con nam o cuoi cung cua chuoi
                gotoxy(52, 6);
                cout << "*Ten VT khong bat dau bang khoang trang              ";
                gotoxy(52, 7);
                cout << "*Gom cac ki tu (a-z), (A-Z)                     ";
                gotoxy(52, 8);
                cout << "*Cac so (0-9)                                    ";
                gotoxy(vitri2, dong2);
            }
            else if (flag == 3)
            {
                vitri3 = 70 + f[2].size();
                gotoxy(52, 6);
                cout << "*DVT khong bat dau bang khoang trang                   ";
                gotoxy(52, 7);
                cout << "*Gom cac ki tu (a-z), (A-Z)                  	  	";
                gotoxy(52, 8);
                cout << "*Cac so (0-9)                                 ";
                gotoxy(vitri3, dong3);
                //   gotoxy(vitri,y);

            }
            else if (flag == 4)
            {
                vitri4 = 70 + f[3].size();
                gotoxy(52, 6);
                cout << "* SLT khong duoc de trong                    ";
                gotoxy(52, 6);
                cout << "* Cac so (0-9)                                 ";
                gotoxy(vitri4, dong4);
                //   gotoxy(vitri,y);

            }
            //-------------
            char c = getch();
            if (c == 27)//27 la phim esc thi thoat khoi khoi menu nhap vat tu
            {

                check = 1;
                return 1;

            }
            else if (c == 13) //Enter de nhan du lieu kiem tra
            {
                if (flag == 1)
                {

                    if (KiemTraTrungMaVT(t, f[0]) == 1)
                    {
                        string s = "Ma vat tu ban nhap bi trung. Xin hay nhap lai";
                        gotoxy(70, dong1);
                        cout << f[0];//to mau
                        while (!kbhit())
                            CanhBao(s, 100, 10);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(vitri1, dong1);
                    }
                    else if (KiemTraChuoi( f[0]) == 0)
                    {
                        string s = "Khong duoc bo trong Ma vat tu. Vui long Nhap lai ! ";
                        gotoxy(70, dong1);
                        cout << f[0];//to mau
                        while (!kbhit())
                            CanhBao(s, 100, 10);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(vitri1, dong1);
                    }
                    else if (KiemTraDoDaiMa(f[0]) == 0)
                    {
                        string s = "Ma vat tu co toi da 10 chu so. Xin hay nhap lai";
                        gotoxy(70, dong1);
                        cout << f[0];
                        while (!kbhit())
                            CanhBao(s, 100, 10);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(vitri1, dong1);
                    }
                    else
                    {

                        gotoxy(70, dong1);
                        cout << f[0];                               
                        gotoxy(vitri2, dong2);
                        flag = 2;//qua phan kiem tra ten
                    }
                }
                else if (flag == 2)
                {
                    if (KiemTraChuoi(f[1]) == 0)
                    {
                        string s = "Ban da nhap sai ten vat tu. Ban hay nhap lai";
                        gotoxy(70, dong2);
                        cout << f[1];
                        while (!kbhit())
                            CanhBao(s, 100, 12);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(vitri2, dong2);

                    }

                    else
                    {
                        gotoxy(70, dong2);
                        cout << f[1];
                        gotoxy(70, dong2);
                        cout << "                        ";
                        gotoxy(70, dong2);
                        cout << Chuanhoa_chu(f[1]);
                        gotoxy(vitri3, dong3);
                        flag = 3;
                    }
                }
                else if (flag == 3)
                {
                    if (KiemTraChuoi(f[2]) == 0)
                    {
                        string s = "Khong duoc bo trong. Ban hay nhap lai ";
                        gotoxy(70, dong3);
                        cout << f[2];
                        while (!kbhit())
                            CanhBao(s, 100, 5);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(vitri3, dong3);
                    }
                    else
                    {
                        gotoxy(70, dong3);
                        gotoxy(70, dong3);
                        cout << "                        ";
                        gotoxy(70, dong3);
                        cout << Chuanhoa_chu(f[2]);
                        gotoxy(vitri4, dong4);
                        flag = 4;
                    }
                }
                else if (flag == 4)
                {
                    if (KiemTraChuoi(f[3]) == 0)
                    {
                        string s = "SLT vat tu khong hop le. Ban hay nhap lai ";
                        gotoxy(70, dong4);
                        cout << f[3];

                        while (!kbhit())
                            CanhBao(s, 100, 5);
                        do
                        {
                            char  c1 = getch();
                        } while (c != 13 && c != 27);
                        gotoxy(70, dong4);
                    }
                    else
                    {
                        nd.ma_vt = f[0].c_str();
                        strchuhoa(nd.ma_vt);

                        nd.ten_vt = f[1].c_str();
                        strchuhoa(nd.ten_vt);
                        Chuanhoa_chu(nd.ten_vt);
                       
                        nd.donvi_tinh = f[2].c_str();
                        nd.soluong_ton = StringToInt1(f[3]);
                        Insert(t, nd);
                        SaveVT(t);

                        KhungNho(109, 14);
                        MauChon();
                        gotoxy(111, 15);
                        cout << "  + DA SAVE VAO FILE +";

                        Normal();
                        Sleep(600);
                        return 0;
                    }
                }

            }

            else if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c == 32))//chi dc nhap so.chu thuong.chu hoa.khoang trang.
            {
                if (flag == 1 && vitri1 < 80 && c != 32)//khong duoc nhap vao khoang trang
                {
                    gotoxy(vitri1, dong1); //tang vi tri con tro nhap len,,de nhap ki tu tiep theo ko bi chong len
                    if (c >= 97 && c <= 122) c = c - 32; //chuyen tu ky tu  thuong sang ky tu hoa                  
                    cout << c; //xuat ky tu vua nhap ra man hinh                 
                    f[0].insert(f[0].end(), 1, c);//chen ky tu vua nhap vao cuoi chuoi
                    vitri1++; //tang vi tri cot xuat hien ky tu
                }
                else if (flag == 2 && vitri2 < 85 /*&& c!=32*/)//khong duoc nhap vao khoang trang
                {
                    gotoxy(vitri2, dong2);
                    if (c >= 97 && c <= 122) c = c - 32;  
                    cout << c;
                    f[1].insert(f[1].end(), 1, c);
                    vitri2++;   
                   
                }
                else if (flag == 3 && vitri3 < 85 /*&& c!=32*/)
                {
                    gotoxy(vitri3, dong3);
                    if (c >= 97 && c <= 122) c = c - 32;
                    cout << c;
                    f[2].insert(f[2].end(), 1, c);
                    vitri3++;
                }
                else if (flag == 4 && vitri4 < 75)
                {
                    gotoxy(vitri4, dong4);
                    if (c >= 48 && c <= 57) {
                        cout << c;
                        f[3].insert(f[3].end(), 1, c);
                        vitri4++;
                    }
                    else {
                        gotoxy(vitri4, dong4);
                    }
                       
                }
            }
            else if (c == 8) //phim backspace.phim xoa chu
            {
                if (flag == 1 && f[0].size() != 0)
                {
                    vitri1--;
                    gotoxy(vitri1, dong1);
                    cout << " ";
                    gotoxy(vitri1, dong1);
                    f[0].erase(f[0].end() - 1);//xoa tu vi tri cuoi cung
                }
                else if (flag == 2 && f[1].size() != 0)
                {
                    vitri2--;
                    gotoxy(vitri2, dong2);
                    cout << " ";
                    gotoxy(vitri2, dong2);
                    f[1].erase(f[1].end() - 1);
                }
                else if (flag == 3 && f[2].size() != 0)
                {
                    vitri3--;
                    gotoxy(vitri3, dong3);
                    cout << " ";
                    gotoxy(vitri3, dong3);
                    f[2].erase(f[2].end() - 1);
                }
                else if (flag == 4 && f[3].size() != 0)
                {
                    vitri4--;
                    gotoxy(vitri4, dong4);
                    cout << " ";
                    gotoxy(vitri4, dong4);
                    f[3].erase(f[3].end() - 1);
                }

            }
            else if (c == -32)
            {
                char kk = getch();

                if (kk == 72) //mui ten di len 
                {

                    if (flag == 1 && f[3] != "")
                    {
                        gotoxy(vitri4, dong4);
                        flag = 4;
                    }


                    else if (flag == 2 && f[0] != "")
                    {
                        gotoxy(vitri1, dong1);
                        flag = 1;
                    }

                    else if (flag == 3 && f[1] != "")
                    {
                        gotoxy(vitri2, dong2);
                        flag = 2;
                    }

                    else if (flag == 4 && f[2] != "")
                    {
                        gotoxy(vitri3, dong3);
                        flag = 3;
                    }

                }
                else if (kk == 80) //mui ten di xuong
                {
                    /*	if (y = dong1) flag =1;
                        if (y = dong2) flag =2;
                         if (y = dong3) flag =3;
                          if (y = dong4) flag =4;  */
                          // i=i+1; y = y+1;
                    if (flag == 1 && f[1] != "") //&& i<=ds.n)
                    {
                        gotoxy(vitri2, dong2);
                        flag = 2;
                    }

                    else if (flag == 2 && f[2] != "")//&& i<=ds.n)
                    {
                        gotoxy(vitri3, dong3);
                        flag = 3;
                    }

                    else if (flag == 3 && f[3] != "")// && i<=ds.n)
                    {
                        gotoxy(vitri4, dong4);
                        flag = 4;
                    }
                    else if (flag == 4 && f[0] != "")
                    {
                        gotoxy(vitri1, dong1);
                        flag = 1;
                    }

                }

            }

        }
    }
}

void ESCNhapVTmoi()
{
    int check = 0;
    while (check == 0)
    {

        check = NhapVTmoi();
    }
} 

TREE_VT TimKiemVatTu(TREE_VT t, string a)
{
    TREE_VT k;
    k = t;
    char s[11];
    strcpy(s, a.c_str());
    // strupr(s);
    NODEVT* p;
    while (k) {
        if (k->pleft == NULL) {
            if (k->vt.ma_vt == s) return k;
            k = k->pright;
        }
        else {
            p = k->pleft;
            while (p->pright && p->pright != k) {
                p = p->pright;
            }
            if (p->pright == NULL) {
                p->pright = k;
                k = k->pleft;
            }
            else {
                p->pright = NULL;
                if (k->vt.ma_vt == s) return k;

                k = k->pright;
            }
        }
    }
    return k = NULL;
}

TREE_VT TimKiem(TREE_VT t, string a)
{
    char s[11];
    strcpy(s, a.c_str());
    TREE_VT  p;
    p = t;
    while (p != NULL && s != p->vt.ma_vt)
        if (s < p->vt.ma_vt)
            p = p->pleft;
        else
            p = p->pright;
    return p;
}

int TinhsoNode(TREE_VT t)
{
    int dem = 0;
    TREE_VT p;
    while (t)
    {
        if (t->pleft == NULL) {
            dem++;
            t = t->pright;
        }
        else {
            p = t->pleft;
            while (p->pright && p->pright != t) {
                p = p->pright;
            }
            if (p->pright == NULL) {
                p->pright = t;
                t = t->pleft;
            }
            else {
                p->pright = NULL;
                dem++;
                t = t->pright;
            }
        }
    }
    return dem;
}
void DuyetCay(TREE_VT t, VAT_TU A[], int& dem)
{
    if (t != NULL)
    {
        DuyetCay(t->pleft, A, dem);
        A[dem] = t->vt;

        dem++;
        DuyetCay(t->pright, A, dem);
    }
}

void SapXepTheoTenVT(VAT_TU A[])
{
    int i, j;
    int n = TinhsoNode(t);
    VAT_TU t;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (A[j - 1].ten_vt > A[j].ten_vt)
            {
                t = A[j - 1];
                A[j - 1] = A[j];
                A[j] = t;
            }
        }
    }
}
//In ds
void draw_bangVT(int x, int y)
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
    cout << "    MA VT    "; //13 kitu
    Normal();
    for (int i = 1; i < chieu_cao_bang; i++)
    {
        gotoxy(x + 18, y + i);
        cout << doc;
    }
    gotoxy(x + 18, y);
    SetColor(0);
    SetBGColor(190);
    cout << "           TEN VAT TU               "; //34 kitu
    Normal();
    for (int i = 1; i < chieu_cao_bang; i++)
    {
        gotoxy(x + 52, y + i);
        cout << doc;
    }
    gotoxy(x + 52, y);
    SetColor(0);
    SetBGColor(190);
    cout << "      DON VI TINH      "; //19 kitu
    Normal();
    for (int i = 1; i < chieu_cao_bang; i++)
    {
        gotoxy(x + 71, y + i);
        cout << doc;
    }
    gotoxy(x + 71, y);
    SetColor(0);
    SetBGColor(190);
    cout << " SO LUONG     ";// 13kitu
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

void xoabang1()
{
    Normal();
    for (int i = 0; i < 10; i++)
    {

        gotoxy(37, 6 + i * 2);
        cout << "    ";
        gotoxy(42, 6 + i * 2);
        cout << "            ";
        gotoxy(60, 6 + i * 2);
        cout << "                                   ";
        gotoxy(93, 6 + i * 2);
        cout << "                       ";
        gotoxy(110, 6 + i * 2);
        cout << "               ";
    }
}

int xuat_DSVT(TREE_VT t, int trang, int vitri_thanhsang)
{
    int dem = 0;
    VAT_TU A[500];
    Load_VT(t);
    DuyetCay(t, A, dem);
    SapXepTheoTenVT(A);
    int sl = TinhsoNode(t);
    //draw_taskbar(3);
    gotoxy(65, 0);
    cout << " DANH SACH VAT TU ";
    draw_bangVT(35, 5);
    gotoxy(107, 28);
    Normal();
    cout << "Trang " << trang + 1 << "/" << sl / 10 + 1;
    DuyetCay(t, A, dem);
    //int trang = 0;
    //int thanh_sang = 0;
    int vitri = 0;
    for (int i = trang * 10; i < sl; i++, vitri++)
    {
        AnDauNhay();
        if ((i % 10) < 10)
        {
            Normal();
            gotoxy(37, vitri * 2 + 6);
            cout << vitri + 1;
            gotoxy(42, vitri * 2 + 6);
            cout << A[i].ma_vt;
            gotoxy(60, vitri * 2 + 6);
            cout << A[i].ten_vt;
            gotoxy(93, vitri * 2 + 6);
            cout << A[i].donvi_tinh;
            gotoxy(110, vitri * 2 + 6);
            cout << A[i].soluong_ton;
        }
        if (((i % 10) == 9) || (i + 1 == sl))
        {
            //clrscr();
            vitri_thanhsang;
            //SetColor(195);
            gotoxy(37, vitri_thanhsang * 2 + 6);
            cout << vitri_thanhsang + 1;
            gotoxy(42, vitri_thanhsang * 2 + 6);
            cout << A[trang * 10 + vitri_thanhsang].ma_vt;
            gotoxy(60, vitri_thanhsang * 2 + 6);
            cout << A[trang * 10 + vitri_thanhsang].ten_vt;
            gotoxy(93, vitri_thanhsang * 2 + 6);
            cout << A[trang * 10 + vitri_thanhsang].donvi_tinh;
            gotoxy(110, vitri_thanhsang * 2 + 6);
            cout << A[trang * 10 + vitri_thanhsang].soluong_ton;
            char kytu;
            do
            {
                kytu = _getch();
                if (kytu == 0) kytu = _getch();
                switch (kytu)
                {
                case 75:if (trang > 0)
                {
                    xoabang1();
                    trang--;
                    vitri_thanhsang = 0;
                    xuat_DSVT(t, trang, vitri_thanhsang);
                    return 1;
                }
                       break;
                case 77:if (trang < sl / 10)
                {
                    xoabang1();
                    trang++;
                    vitri_thanhsang = 0;
                    xuat_DSVT(t, trang, vitri_thanhsang);
                    return 1;
                }
                       break;
                case 27:
                {
                    return 1;
                }
                }
            } while (true);
        }
    }

}

void HuongDanHCVT()
{
    KhungNho(2, 3);
    KhungNho(2, 6);
    KhungNho(2, 9);
    KhungNho(2, 12);

    gotoxy(3, 4);
    cout << "1. Them vat tu          ";
    gotoxy(3, 7);
    cout << "2. Hieu chinh vat tu        ";
    gotoxy(3, 10);
    cout << "3. Xoa vat tu              ";
    gotoxy(3, 13);
    cout << "4. Danh sach VT trong kho   ";

    string lt[19];
    lt[4] = "1. Nhap vat tu            ";
    lt[7] = "2. Hieu chinh vat tu      ";
    lt[10] = "3. Xoa vat tu             ";
    lt[13] = "4. Danh sach VT trong kho ";
    gotoxy(3, 7);
    MauChon();
    cout << lt[7];
    Normal();
   
}

int HieuchinhVatTu(string s)
{
    TREE_VT p;
    p = TimKiem(t, s);
    //KhoiTaoMenuHieuChinhVT();
    HuongDanHCVT();
    string lc[12];
    lc[8] = " 1. HIEU CHINH TEN VAT TU. ";
    lc[10] = " 2.HIEU CHINH DON VI TINH.";
    int x = 125;
    AnDauNhay();
    gotoxy(x, 10);
    Normal();
    cout << lc[10];
    gotoxy(x, 8);
    MauChon();
    cout << lc[8];
    
    while (1)
    {
        char kk = getch();
        if (kk == 72)//phim di chuyen len
        {
            int y = wherey();
            if (y == 8) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
            {
                gotoxy(x, y);
                Normal();
                cout << lc[y];
                gotoxy(x,10);
                MauChon();
                cout << lc[10];
                Normal();
            }
            else
            {
                gotoxy(x, y);
                Normal();
                cout << lc[y];
                gotoxy(x, y - 2);
                MauChon();
                cout << lc[y - 2];
                Normal();
            }
        }
        if (kk == 80)
        {
            int y = wherey();
            if (y == 10) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
            {
                gotoxy(x, 10);
                Normal();
                cout << lc[y];
                gotoxy(x, 8);
                MauChon();
                cout << lc[8];
                Normal();
            }
            else
            {
                gotoxy(x, y);
                Normal();
                cout << lc[y];
                gotoxy(x, y + 2);
                MauChon();
                cout << lc[y + 2];
                Normal();
            }
        }
       
        if (kk == 13)
        {
            HienThiDauNhay();
            int y = wherey();
            if (y == 8)
            {
                string tenvtmoi = "";
                do {
                    Normal();
                    system("cls");
                    gotoxy(35, 0);
                    cout << "HIEU CHINH TEN VAT TU ";
                    gotoxy(48, 3);
                    cout << "NHAP TEN VAT TU MOI : ";
                    KhungNho(68, 2);
                    gotoxy(0, 2);
                    
                    cout << "*       CHU Y          *"<<endl;
                    cout << "*Ten VT khong bat dau bang khoang trang              " << endl;
                    cout << "*Gom cac ki tu (a-z), (A-Z)                     " << endl;
                    cout << "*Cac so (0-9)                                    " << endl;
                    char l = 179;

                    for (int i = 0; i <= 12; i++)
                    {
                        gotoxy(i, 7);
                        cout << "_";
                    }
                    gotoxy(1, 8);
                    cout << "+LUU Y:";
                    gotoxy(1, 9);
                    cout << "+Nhap phim ESC de thoat/tro ve.";
                   
                    gotoxy(70, 3);
                    getline(cin, tenvtmoi);
                    gotoxy(70, 3);
                    cout << "                    ";
                    gotoxy(70, 3);
                    cout<<Chuanhoa_chu(tenvtmoi);
                    if (KiemTraChuoi(tenvtmoi) == 0)
                    {
                        string s = "Ban da nhap sai quy tac nhap ten vat tu  ";
                        while (!kbhit())CanhBao(s, 40, 10);
                    }
                } while (KiemTraChuoi(tenvtmoi) == 0);
                p->vt.ten_vt = tenvtmoi.c_str();
                Chuanhoa_chu(p->vt.ten_vt);
                string s = "Da chinh sua ten vat tu __ Nhan ENTER de in DSVT ."; 
                while (!kbhit()) CanhBao(s, 40, 10);
                SaveVT(t);
                HD;
                gotoxy(35, 10);
                xuat_DSVT(t, 0, 0);
                
                return 1;
                break;
            }

            if (y == 10)
            {
                string dvtmoi = "";
                do {
                    Normal();
                    system("cls");
                    gotoxy(35, 0);
                    cout << "HIEU CHINH DVT VAT TU ";
                    gotoxy( 58, 3);
                    cout << "NHAP DVT VAT TU MOI : ";
                    KhungNho(78, 2);
                    gotoxy(0, 2);
                    cout << "*       CHU Y          *" << endl;
                    cout << "*Don vi VT khong bat dau bang khoang trang              " << endl;
                    cout << "*Gom cac ki tu (a-z), (A-Z)                     " << endl;
                    cout << "*Cac so (0-9)                                    " << endl;
                    char l = 179;
                    
                    for (int i = 0; i <= 20; i++)
                    {
                        gotoxy(i, 7);
                        cout << "_";
                    }
                    gotoxy(1, 8);
                    cout << "+LUU Y:";
                    gotoxy(1, 9);
                    cout << "+Nhap phim ESC de thoat/tro ve.";
                    
                    gotoxy(80, 3);
                    getline(cin, dvtmoi);
                    gotoxy(80, 3);
                    cout << "                    ";
                    gotoxy(80, 3);
                    cout << Chuanhoa_chu(dvtmoi);
                    if (KiemTraChuoi(dvtmoi) == 0)
                    {
                        string s = "Ban da nhap sai quy tac nhap don vi vat tu  ";
                        while (!kbhit())CanhBao(s, 40, 10);
                    }
                } while (KiemTraChuoi(dvtmoi) == 0);
                p->vt.donvi_tinh = dvtmoi.c_str();
                Chuanhoa_chu(p->vt.donvi_tinh);
                string s = "Da chinh sua don vi vat tu __ Nhan ENTER de in DSVT .";
                while (!kbhit()) CanhBao(s, 40, 10);

                SaveVT(t);

                gotoxy(35, 10);
                xuat_DSVT(t, 0, 0);
                return 1;
                break;
            }
            else if (kk == 27)
            {
                Normal();
                MenuHieuChinhVT();
                break;
            }
        }
    }

}

// ************* XOA VT ***********

TREE_VT rp = NULL;
void RemoveCase3(TREE_VT& r)
{
    if (r->pleft != NULL)
        RemoveCase3(r->pleft);
    //den day r la nut cuc trai cua cay con ben phai co nut goc la rp
    else
    {
        rp->vt.ma_vt = r->vt.ma_vt;
        rp->vt.donvi_tinh = r->vt.donvi_tinh;
        rp->vt.soluong_ton = r->vt.soluong_ton;
        rp->vt.ten_vt = r->vt.ten_vt;
        rp = r;
        r = rp->pright;
    }
}

int XoaVatTu(string x, TREE_VT& p,DS_NV &a)
{
	 bool flag=true;		
	 for (int i=0;i<a.sl;i++)
		{
			if (a.ds[i]->PTRhd != NULL)
			{
				for (PTR_B p1=a.ds[i]->PTRhd;p1!=NULL;p1=p1->next)
				{
					PTR_Bd q=p1->PTRcthd;
					while (p1->PTRcthd != NULL)
						{
							if (p1->PTRcthd->cthd.MAVT==x)
								{
									flag=false;
								}
							p1->PTRcthd=p1->PTRcthd->next;
						}
					p1->PTRcthd=q;		
				}
			}
		}
	if (flag)
	{
	    if (x < p->vt.ma_vt)
	    	{
	          XoaVatTu(x, p->pleft,a);
	    	}
	    else if (x > p->vt.ma_vt)
	        {
				XoaVatTu(x, p->pright,a);
			}
	    else
	    {
	        rp = p;
	        if (rp->pright == NULL)p = rp->pleft;
	        //p la nut la hoac la nut chi co cay con ben trai
	        else if (rp->pleft == NULL)
	            p = rp->pright;//p la nut co cay con ben phai
	        else RemoveCase3(rp->pright);
	       
				
			delete rp;
		}
		return 1;
	}
	return 0;
}


