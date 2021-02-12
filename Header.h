#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<cmath>
using namespace std;
//Các hàm trong Main Menu và hàm xử lý cho cả bài 
int fSelectCommand(int number);
int fMainMenu();
void fRunMainMenu(int& Lenh);
int fMenu1();
int fRunMenu1(int& lenh);
//Các hàm trong menu.1
int fKTSoNguyenTo(int number);
int fKTSoChinhPhuong(int number);
int fKTSoHoanHao(int number);
int fKTSoDoiXung(int number);
//
int fMenu2();
int fRunMenu2(int& lenh);
//Các hàm trong menu.2
void fNhapMang1Chieu(int a[], int& n);
void fXuatMang1chieu(int a[], int& n);
void fMinMaxMang1Chieu(int a[], int& n, int index_M[], int& countMax, int index_m[], int& countMin);
void fTimPhanTuGanNhat(int a[], int& n, int x, int index[], int& count);
void fCucTriMang1Chieu(int a[], int& n, int indexMax[], int& countMax, int indexMin[], int& countMin);
int fChildMenuSapXepMang1D();
int fRunChildMenuSapXepMang1D(int& command);
//Các hàm trong child menu sap xep
void fSapXepMangTangDan(int a[], int& n);
void fSapXepMangGiamDan(int a[], int& n);
void fChanTangLeGiam(int a[], int& n);
void fChanGiamLeTang(int a[], int& n);
//
int fMenu3();
int fRunMenu3(int& lenh);
//Các hàm trong menu.3
int fChildMenu4();
int fRunChildMenu4(int& command);
void fNhapMang2Chieu(int a[10][10], int& m, int& n);
void fXuatMang2Chieu(int a[10][10], int& m, int& n);
int fSumOfAColumm(int a[10][10], int& m, int x);
void fMinMaxMang2Chieu(int a[10][10], int& m, int& n, int iMax[], int jMax[], int& countMax, int iMin[], int jMin[], int& countMin);
void fPhanTuYenNgua(int a[10][10], int& m, int& n, int i_index[], int j_index[], int& count);
void fDoiViTri(int& a, int& b);
//Các hàm trong Child Menu 4
void fChuyenMang2DThanh1D(int a[10][10], int& m, int& n, int b[], int& count2to1);
void fChuyenMang1DThanh2D(int a[10][10], int& m, int& n, int b[], int& count1to2);
void fSapXepMangFullTang(int b[], int& count2to1);
void fSapXepMangFullGiam(int b[], int& count2to1);
void fSapXepMangTangTrenCot(int a[10][10], int& m, int& n);
void fSapXepMangGiamTrenCot(int a[10][10], int& m, int& n);
int fKTSoChanLe(int number);
int fKTMaPhuong(int a[10][10], int& m, int& n);
void fXoayMaTranVuong(int a[10][10], int& m, int& n);
void fCucTriMang2Chieu(int a[10][10], int& m, int& n, int i_MaxIndex[], int j_MaxIndex[], int& countMax, int i_MinIndex[], int j_MinIndex[], int& countMin);
#endif // !HEADER_H

