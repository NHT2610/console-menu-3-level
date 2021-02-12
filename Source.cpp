#include"Header.h"
//Định nghĩa hàm của Main Menu
int fMainMenu()
{
	system("cls");
	cout << "===== MAIN.MENU =====" << endl;
	cout << "1. KIEM TRA SO" << endl;
	cout << "2. MANG MOT CHIEU" << endl;
	cout << "3. MANG HAI CHIEU" << endl;
	cout << "4. THOAT" << endl;
	return 4;
}
int fSelectCommand(int number)
{
	int n;
	cout << "Lua chon cua ban: "; cin >> n;
	while (cin.fail() || (n > number && n < 1))
	{
		cin.clear(); cin.ignore();
	}
	return n;
}
void fRunMainMenu(int& Lenh)
{
	if (Lenh == 1)
	{
		int lenh = 0;
		while (lenh != 6)
		{
			lenh = fSelectCommand(fMenu1());
			Lenh = fRunMenu1(lenh);
		}
	}
	if (Lenh == 2)
	{
		int lenh = 0;
		while (lenh != 6)
		{
			lenh = fSelectCommand(fMenu2());
			Lenh = fRunMenu2(lenh);
		}
	}
	if (Lenh == 3)
	{
		int lenh = 0;
		while (lenh != 8)
		{
			lenh = fSelectCommand(fMenu3());
			Lenh = fRunMenu3(lenh);
		}
	}
	if (Lenh == 4)
	{
		char check;
		cout << "Press 'y' or 'Y' to exit... "; cin >> check;
		if (check != 'y' && check != 'Y')
		{
			Lenh = 0;
		}
	}
}
//Định nghĩa hàm của Menu.1
int fMenu1()
{
	system("cls");
	cout << "===== MENU.1 =====" << endl;
	cout << "1. Kiem tra so nguyen to" << endl;
	cout << "2. Kiem tra so chinh phuong" << endl;
	cout << "3. Kiem tra so hoan hao" << endl;
	cout << "4. Kiem tra so doi xung" << endl;
	cout << "5. Quay ve Main Menu" << endl;
	cout << "6. Thoat" << endl;
	return 6;
}
int fRunMenu1(int& lenh)
{
	if (lenh == 1)
	{
		system("cls");
		cout << "===== Kiem Tra So Nguyen To =====" << endl;
		int number;
		cout << "Nhap mot so nguyen duong "; cin >> number;
		while (cin.fail() || number <= 0)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap mot so nguyen duong "; cin >> number;
		}
		int check = fKTSoNguyenTo(number);
		if (check == 1)
		{
			cout << "So " << number << " la so nguyen to!" << endl;
		}
		else
		{
			cout << "So " << number << " khong la so nguyen to!" << endl;
		}
		system("pause");
	}
	if (lenh == 2)
	{
		system("cls");
		cout << "===== Kiem Tra So Chinh Phuong =====" << endl;
		int number;
		cout << "Nhap mot so nguyen duong "; cin >> number;
		while (cin.fail() || number <= 0)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap mot so nguyen duong "; cin >> number;
		}
		int check = fKTSoChinhPhuong(number);
		if (check == 1)
		{
			cout << "So " << number << " la so chinh phuong!" << endl;
		}
		else
		{
			cout << "So " << number << " khong la so chinh phuong!" << endl;
		}
		system("pause");
	}
	if (lenh == 3)
	{
		system("cls");
		cout << "===== Kiem Tra So Hoan Hao =====" << endl;
		int number;
		cout << "Nhap mot so nguyen duong "; cin >> number;
		while (cin.fail() || number <= 0)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap mot so nguyen duong "; cin >> number;
		}
		int check = fKTSoHoanHao(number);
		if (check == 1)
		{
			cout << "So " << number << " la so hoan hao!" << endl;
			system("pause");
		}
		else
		{
			cout << "So " << number << " khong la so hoan hao!" << endl;
			system("pause");
		}
	}
	if (lenh == 4)
	{
		system("cls");
		cout << "===== Kiem Tra So Doi Xung =====" << endl;
		int number;
		cout << "Nhap mot so nguyen duong "; cin >> number;
		while (cin.fail() || number <= 0)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap mot so nguyen duong "; cin >> number;
		}
		int check = fKTSoDoiXung(number);
		if (check == 1)
		{
			cout << number << " la so doi xung!" << endl;
		}
		else
		{
			cout << number << " khong la so doi xung!" << endl;
		}
		system("pause");
	}
	if (lenh == 5)
	{
		lenh = 6;
		return 1;
	}
	if (lenh == 6)
	{
		return 4;
	}
}
int fKTSoNguyenTo(int number)
{
	int count = 0;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)count = count + 1;
	}
	if (count == 0 && number >= 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int fKTSoChinhPhuong(int number)
{
	for (int i = 1; i <= sqrt(number); i++)
	{
		if (number == i * i)
		{
			return 1;
			break;
		}
		if (i == sqrt(number) && number != i * i)
		{
			return 0;
		}
	}
}
int fKTSoHoanHao(int number)
{
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum = sum + i;
		}
	}
	if (sum == number)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int fKTSoDoiXung(int number)
{
	int A = number, B = number;
	//Đếm số chữ số (k) trong số bumber
	int k = 0;
	while (A > 0)
	{
		A = A / 10;
		k = k + 1;
	}
	int a = 1, checkNumber = 0;
	for (int i = k; i >= 0; i--)
	{
		a = B / (pow(10, i - 1));
		checkNumber = checkNumber + a * pow(10, k - i);
		B = B - a * pow(10, i - 1);
	}
	if (checkNumber == number) { return 1; }
	else { return 0; }
}
//Định nghĩa hàm của Menu.2
int fMenu2()
{
	system("cls");
	cout << "===== MENU.2 =====" << endl;
	cout << "1. Tim phan tu lon nhat, nho nhat" << endl;
	cout << "2. Tim phan tu gan voi gia tri duoc nhap nhat" << endl;
	cout << "3. Phan tu cuc tri" << endl;
	cout << "4. Sap xep mang" << endl;
	cout << "5. Quay ve Main Menu" << endl;
	cout << "6. Thoat" << endl;
	return 6;
}
int fRunMenu2(int& lenh)
{
	int a[20], n = 0;
	if (lenh == 1)
	{
		system("cls");
		cout << "===== Tim Phan Tu Lon Nhat, Nho Nhat =====" << endl;
		int index_M[20], index_m[20], countMax = 0, countMin = 0;
		fNhapMang1Chieu(a, n);
		fXuatMang1chieu(a, n);
		fMinMaxMang1Chieu(a, n, index_M, countMax, index_m, countMin);
		//Xuất các phần tử có giá trị lớn nhất trong mảng 
		cout << "Co " << countMax << " phan tu co gia tri lon nhat trong mang" << endl;
		if (countMax == 1)
		{
			cout << "Phan tu do la " << a[index_M[0]] << ", nam o vi tri " << index_M[0] << endl;
		}
		else
		{
			cout << "Phan tu do la " << a[index_M[0]] << endl;
			for (int i = 0; i < countMax; i++)
			{
				cout << "Phan tu thu " << countMax + 1 << " nam o vi tri " << index_M[countMax] << endl;
			}
		}
		//Xuất các phần tử có giá trị nhỏ nhất trong mảng
		cout << "Co " << countMin << " phan tu co gia tri nho nhat trong mang" << endl;
		if (countMax == 1)
		{
			cout << "Phan tu do la " << a[index_m[0]] << ", nam o vi tri " << index_m[0] << endl;
		}
		else
		{
			cout << "Phan tu do la " << a[index_m[0]] << endl;
			for (int i = 0; i < countMin; i++)
			{
				cout << "Phan tu thu " << countMin + 1 << " nam o vi tri " << index_m[countMin] << endl;
			}
		}
		system("pause");
	}
	if (lenh == 2)
	{
		system("cls");
		cout << "===== Tim Phan Tu Gan Voi Gia Tri Duoc Nhap Nhat =====" << endl;
		fNhapMang1Chieu(a, n);
		fXuatMang1chieu(a, n);
		int x;
		cout << "Nhap so nguyen x: "; cin >> x;
		while (cin.fail())
		{
			cin.clear(); cin.ignore();
			cout << "Nhap so nguyen x: "; cin >> x;
		}
		int index[20], count = 0;
		fTimPhanTuGanNhat(a, n, x, index, count);
		cout << "Co " << count << " phan tu co gia tri gan voi " << x << " nhat" << endl;
		if (count == 1)
		{
			cout << "Phan tu do co gia tri " << a[index[0]] << " nam o vi tri " << index[0] << endl;
		}
		else
		{
			cout << "Cac phan tu co gia tri " << a[index[0]] << endl;
			for (int i = 0; i < count; i++)
			{
				cout << "Phan tu thu " << i + 1 << " nam o vi tri " << index[i] << endl;
			}
		}
		system("pause");
	}
	if (lenh == 3)
	{
		system("cls");
		cout << "===== Phan Tu Cuc Tri =====" << endl;
		fNhapMang1Chieu(a, n);
		fXuatMang1chieu(a, n);
		int indexMax[20], indexMin[20], countMax = 0, countMin = 0;
		fCucTriMang1Chieu(a, n, indexMax, countMax, indexMin, countMin);
		if (countMax + countMin == 0)
		{
			cout << "Mang khong co phan tu cuc tri" << endl;
		}
		else
		{
			cout << "Mang co " << countMax + countMin << " phan tu cuc tri gom" << endl;
			if (countMax == 0)
			{
				cout << "Mang khong co phan tu cuc dai" << endl;
				cout << countMin << " phan tu cuc tieu" << endl;
				for (int i = 0; i < countMin; i++)
				{
					cout << "Phan tu thu " << i + 1 << " co gia tri " << a[indexMin[i]] << ", nam o vi tri " << indexMin[i] << endl;
				}
			}
			if (countMax != 0 && countMin != 0)
			{
				cout << countMax << " phan tu cuc dai" << endl;
				for (int i = 0; i < countMax; i++)
				{
					cout << "Phan tu thu " << i + 1 << " co gia tri " << a[indexMax[i]] << ", nam o vi tri " << indexMax[i] << endl;
				}
				cout << countMin << " phan tu cuc tieu" << endl;
				for (int i = 0; i < countMin; i++)
				{
					cout << "Phan tu thu " << i + 1 << " co gia tri " << a[indexMin[i]] << ", nam o vi tri " << indexMin[i] << endl;
				}
			}
			if (countMin == 0)
			{
				cout << countMax << " phan tu cuc dai" << endl;
				for (int i = 0; i < countMax; i++)
				{
					cout << "Phan tu thu " << i + 1 << " co gia tri " << a[indexMax[i]] << ", nam o vi tri " << indexMax[i] << endl;
				}
				cout << "Mang khong co phan tu cuc tieu" << endl;
			}
		}
		system("pause");
	}
	if (lenh == 4)
	{
		int command = 0;
		while (command != 6)
		{
			command = fSelectCommand(fChildMenuSapXepMang1D());
			lenh = fRunChildMenuSapXepMang1D(command);
		}
	}
	if (lenh == 5)
	{
		lenh = 6;//Gán lenh=6 trước câu lệnh return vì nếu gán sau câu lệnh return thì lenh!=6 và vòng lặp ko dừng
		return 2;
	}
	if (lenh == 6)
	{
		return 4;
	}
}
void fNhapMang1Chieu(int a[], int& n)
{
	cout << "Nhap so phan tu cua mang "; cin >> n;
	while (cin.fail() || n <= 0)
	{
		cin.clear(); cin.ignore();
		cout << "Nhap so phan tu cua mang "; cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = "; cin >> a[i];
		while (cin.fail())
		{
			cin.clear(); cin.ignore();
			cout << "a[" << i << "] = "; cin >> a[i];
		}
	}
	cout << endl;
}
void fXuatMang1chieu(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
void fMinMaxMang1Chieu(int a[], int& n, int index_M[], int& countMax, int index_m[], int& countMin)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) { max = a[i]; }
		if (a[i] < min) { min = a[i]; }
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
		{
			index_M[countMax] = i;
			countMax += 1;
		}
		if (a[i] == min)
		{
			index_m[countMin] = i;
			countMin += 1;
		}
	}
}
void fTimPhanTuGanNhat(int a[], int& n, int x, int index[], int& count)
{
	int min = a[0] - x;
	if (min < 0) { min = -min; }
	for (int i = 0; i < n; i++)
	{
		int check = a[i] - x;
		if (check < 0)
		{
			check = -check;
		}
		if (check < min) { min = check; }
	}
	for (int i = 0; i < n; i++)
	{
		int check = a[i] - x;
		if (check < 0) { check = -check; }
		if (check == min)
		{
			index[count] = i;
			count += 1;
		}
	}
}
void fCucTriMang1Chieu(int a[], int& n, int indexMax[], int& countMax, int indexMin[], int& countMin)
{
	//Cực đại mảng một chiều
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (a[i] > a[i + 1])
			{
				indexMax[countMax] = i;
				countMax += 1;
			}
		}
		if (i == n - 1)
		{
			if (a[i] > a[i - 1])
			{
				indexMax[countMax] = i;
				countMax += 1;
			}
		}
		if (i != 0 && i != n - 1)
		{
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
			{
				indexMax[countMax] = i;
				countMax += 1;
			}
		}
	}
	//Cực tiểu mảng một chiều
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (a[i] < a[i + 1])
			{
				indexMin[countMin] = i;
				countMin += 1;
			}
		}
		if (i == n - 1)
		{
			if (a[i] < a[i - 1])
			{
				indexMin[countMin] = i;
				countMin += 1;
			}
		}
		if (i != 0 && i != n - 1)
		{
			if (a[i] < a[i - 1] && a[i] < a[i + 1])
			{
				indexMin[countMin] = i;
				countMin += 1;
			}
		}
	}
}
int fChildMenuSapXepMang1D()
{
	system("cls");
	cout << "===== Sap Xep Mang Mot Chieu =====" << endl;
	cout << "1. Sap xep tang dan" << endl;
	cout << "2. Sap xep giam dan" << endl;
	cout << "3. Sap xep so chan tang dan, so le giam dan" << endl;
	cout << "4. Sap xep so chan giam dan, so le tang dan" << endl;
	cout << "5. Quay ve Menu.2" << endl;
	cout << "6. Thoat" << endl;
	return 6;
}
int fRunChildMenuSapXepMang1D(int& command)
{
	int a[100], n = 0;
	if (command == 1)
	{
		system("cls");
		cout << "===== Sap Xep Mang Tang Dan =====" << endl;
		fNhapMang1Chieu(a, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		fSapXepMangTangDan(a, n);
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		system("pause");
	}
	if (command == 2)
	{
		system("cls");
		cout << "===== Sap Xep Mang Giam Dan =====" << endl;
		fNhapMang1Chieu(a, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		fSapXepMangGiamDan(a, n);
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		system("pause");
	}
	if (command == 3)
	{
		system("cls");
		cout << "Sap xep so chan tang dan, so le giam dan" << endl;
		fNhapMang1Chieu(a, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		fChanTangLeGiam(a, n);
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		system("pause");
	}
	if (command == 4)
	{
		system("cls");
		cout << "Sap xep so chan giam dan, so le tang dan" << endl;
		fNhapMang1Chieu(a, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		fChanGiamLeTang(a, n);
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang1chieu(a, n);
		system("pause");
	}
	if (command == 5)
	{
		command = 6;
		return 4;
	}
	if (command == 6)
	{
		return 6;
	}
}
void fSapXepMangTangDan(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				fDoiViTri(a[i], a[j]);
			}
		}
	}
}
void fSapXepMangGiamDan(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				fDoiViTri(a[i], a[j]);
			}
		}
	}
}
void fChanTangLeGiam(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		//Xét lần lượt từng phần tử của mảng, kiểm tra xem phần tử đó chẳn hay lẻ
		int check1 = fKTSoChanLe(a[i]);
		if (check1 == 1)
		{
			/*Nếu phần tử kiểm tra là chẳn thì thực hiện thuật toán sắp xếp với các phần tử chẳn tiếp theo,
			  phần tử lẻ thì bỏ qua */
			for (int j = i + 1; j < n; j++)
			{
				int check2 = fKTSoChanLe(a[j]);
				if (check2 == 1)
				{
					if (a[i] > a[j]) { fDoiViTri(a[i], a[j]); }
				}
				else continue;
			}
		}
		else
		{
			//Tương tự như trường hợp số chẳn 
			for (int j = i + 1; j < n; j++)
			{
				int check2 = fKTSoChanLe(a[j]);
				if (check2 == 0)
				{
					if (a[i] < a[j]) { fDoiViTri(a[i], a[j]); }
				}
				else continue;
			}
		}
	}
}
void fChanGiamLeTang(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		//Xét lần lượt từng phần tử của mảng, kiểm tra xem phần tử đó chẳn hay lẻ
		int check1 = fKTSoChanLe(a[i]);
		if (check1 == 1)
		{
			/*Nếu phần tử kiểm tra là chẳn thì thực hiện thuật toán sắp xếp với các phần tử chẳn tiếp theo,
			  phần tử lẻ thì bỏ qua */
			for (int j = i + 1; j < n; j++)
			{
				int check2 = fKTSoChanLe(a[j]);
				if (check2 == 1)
				{
					if (a[i] < a[j]) { fDoiViTri(a[i], a[j]); }
				}
				else continue;
			}
		}
		else
		{
			//Tương tự như trường hợp số chẳn 
			for (int j = i + 1; j < n; j++)
			{
				int check2 = fKTSoChanLe(a[j]);
				if (check2 == 0)
				{
					if (a[i] > a[j]) { fDoiViTri(a[i], a[j]); }
				}
				else continue;
			}
		}
	}
}
int fKTSoChanLe(int number)
{
	if (number % 2 != 0) { return 0; }
	else { return 1; }
}
//Định nghĩa hàm của Menu.3
int fMenu3()
{
	system("cls");
	cout << "===== MENU.3 =====" << endl;
	cout << "1. Tinh tong mot cot bat ky" << endl;
	cout << "2. Phan tu lon nhat, nho nhat" << endl;
	cout << "3. Phan tu yen ngua" << endl;
	cout << "4. Sap xep mang" << endl;
	cout << "5. Xoay ma tran vuong" << endl;
	cout << "6. Phan tu cuc tri" << endl;
	cout << "7. Quay ve Main Menu" << endl;
	cout << "8. Thoat" << endl;
	return 8;
}
int fRunMenu3(int& lenh)
{
	int a[10][10], m = 0, n = 0;
	if (lenh == 1)
	{
		system("cls");
		cout << "===== Tinh Tong Mot Cot Bat Ky =====" << endl;
		fNhapMang2Chieu(a, m, n);
		fXuatMang2Chieu(a, m, n);
		int x;
		cout << "Chon cot de tinh tong "; cin >> x;
		while (cin.fail() || x < 0 || x >= n)
		{
			cin.clear(); cin.ignore();
			cout << "Chon cot de tinh tong "; cin >> x;
		}
		int sum = fSumOfAColumm(a, m, x);
		cout << "Tong cac phan tu cua cot " << x << ": " << sum << endl;
		system("pause");
	}
	if (lenh == 2)
	{
		system("cls");
		cout << "===== Phan Tu Lon Nhat, Nho Nhat =====" << endl;
		int iMax[100], jMax[100], iMin[100], jMin[100], countMax = 0, countMin = 0;
		fNhapMang2Chieu(a, m, n);
		fXuatMang2Chieu(a, m, n);
		fMinMaxMang2Chieu(a, m, n, iMax, jMax, countMax, iMin, jMin, countMin);
		cout << "Mang co " << countMax << " phan tu lon nhat va " << countMin << " phan tu nho nhat" << endl;
		cout << "Phan tu lon nhat co gia tri " << a[iMax[0]][jMax[0]] << endl;
		cout << "Nam o vi tri: ";
		for (int i = 0; i < countMax; i++)
		{
			cout << iMax[i] << "x" << jMax[i] << "\t";
		}
		cout << endl;
		cout << "Phan tu no nhat co gia tri " << a[iMin[0]][jMin[0]] << endl;
		cout << "Nam o vi tri: ";
		for (int i = 0; i < countMin; i++)
		{
			cout << iMin[i] << "x" << jMin[i] << "\t";
		}
		cout << endl;
		system("pause");
	}
	if (lenh == 3)
	{
		system("cls");
		cout << "===== Phan Tu Yen Ngua =====" << endl;
		int i_index[10], j_index[10], count = 0;
		fNhapMang2Chieu(a, m, n);
		fXuatMang2Chieu(a, m, n);
		fPhanTuYenNgua(a, m, n, i_index, j_index, count);
		if (count == 0)
		{
			cout << "Mang khong ton tai phan tu yen ngua!" << endl;
		}
		else
		{
			if (count == 1)
			{
				cout << "Mang co 1 phan tu yen ngua co gia tri " << a[i_index[0]][j_index[0]] << " nam o vi tri " << i_index[0] << "x" << j_index[0] << endl;
			}
			else
			{
				cout << "Mang co " << count << " phan tu yen ngua" << endl;
				for (int i = 0; i < count; i++)
				{
					cout << "Phan tu thu " << i + 1 << " co gia tri " << a[i_index[i]][j_index[i]] << ", nam o vi tri " << i_index[i] << "x" << j_index[i] << endl;
				}
			}
		}
		system("pause");
	}
	if (lenh == 4)
	{
		system("cls");
		int command = 0;
		while (command != 6)
		{
			command = fSelectCommand(fChildMenu4());
			lenh = fRunChildMenu4(command);
		}
	}
	if (lenh == 5)
	{
		system("cls");
		cout << "===== Xoay Ma Tran Vuong =====" << endl;
		fNhapMang2Chieu(a, m, n);
		cout << "Mang truoc khi xoay" << endl;
		fXuatMang2Chieu(a, m, n);
		fXoayMaTranVuong(a, m, n);
		cout << "Mang sau khi xoay" << endl;
		fXuatMang2Chieu(a, m, n);
		system("pause");
	}
	if (lenh == 6)
	{
		system("cls");
		cout << "===== Phan Tu Cuc Tri =====" << endl;
		fNhapMang2Chieu(a, m, n);
		fXuatMang2Chieu(a, m, n);
		int i_MaxIndex[100], j_MaxIndex[100], i_MinIndex[100], j_MinIndex[100], countMax = 0, countMin = 0;
		fCucTriMang2Chieu(a, m, n, i_MaxIndex, j_MaxIndex, countMax, i_MinIndex, j_MinIndex, countMin);
		if (countMax + countMin == 0)
		{
			cout << "Mang khong co cuc tri!" << endl;
		}
		else
		{
			cout << "Mang co " << countMax + countMin << " cuc tri, gom " << endl;
			cout << countMax << " cuc dai" << endl;
			if (countMax == 1)
			{
				cout << "Co gia tri " << a[i_MaxIndex[0]][j_MaxIndex[0]] << ", nam o vi tri " << i_MaxIndex[0] << "x" << j_MaxIndex[0] << endl;
			}
			else
			{
				for (int i = 0; i < countMax; i++)
				{
					cout << "Cuc dai thu " << i + 1 << " co gia tri " << a[i_MaxIndex[i]][j_MaxIndex[i]] << ", nam o vi tri " << i_MaxIndex[i] << "x" << j_MaxIndex[i] << endl;
				}
			}
			cout << countMin << " cuc tieu" << endl;
			if (countMin == 1)
			{
				cout << "Co gia tri " << a[i_MinIndex[0]][j_MinIndex[0]] << ", nam o vi tri " << i_MinIndex[0] << "x" << j_MinIndex[0] << endl;
			}
			else
			{
				for (int i = 0; i < countMin; i++)
				{
					cout << "Cuc tieu thu " << i + 1 << " co gia tri " << a[i_MinIndex[i]][j_MinIndex[i]] << ", nam o vi tri " << i_MinIndex[i] << "x" << j_MinIndex[i] << endl;
				}
			}
		}
		system("pause");
	}
	if (lenh == 7)
	{
		lenh = 8;
		return 3;
	}
	if (lenh == 8)
	{
		return 4;
	}
}
int fSumOfAColumm(int a[10][10], int& m, int x)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum = sum + a[i][x];
	}
	return sum;
}
void fMinMaxMang2Chieu(int a[10][10], int& m, int& n, int iMax[], int jMax[], int& countMax, int iMin[], int jMin[], int& countMin)
{
	//Tìm giá trị lớn nhất, nhỏ nhất trong mảng
	int max = a[0][0], min = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max) { max = a[i][j]; }
			if (a[i][j] < min) { min = a[i][j]; }
		}
	}
	//Duyệt hết mảng xem phần tử nào có giá trị bằng giá trị max, min
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == max)
			{
				iMax[countMax] = i;
				jMax[countMax] = j;
				countMax += 1;
			}
			if (a[i][j] == min)
			{
				iMin[countMin] = i;
				jMin[countMin] = j;
				countMin += 1;
			}
		}
	}
}
void fPhanTuYenNgua(int a[10][10], int& m, int& n, int i_index[], int j_index[], int& count)
{
	for (int i = 0; i < m; i++)
	{
		//Tìm giá trị nhỏ nhất trong hàng thứ i
		int minRow = a[i][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < minRow) { minRow = a[i][j]; }
		}
		//Tìm tất cả các phần tử có giá trị nhỏ nhất trong hàng thứ i, xét cột tại những phần tử đó
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == minRow)
			{
				//Xét xem a[i][j] có lớn nhất trong cột j hay không
				int maxColumm = a[0][j];
				for (int k = 0; k < m; k++)
				{
					if (a[k][j] > maxColumm) { maxColumm = a[k][j]; }
				}
				if (maxColumm == a[i][j])
				{
					i_index[count] = i;
					j_index[count] = j;
					count += 1;
				}
			}
		}
	}
}
int fChildMenu4()
{
	system("cls");
	cout << "===== Sap Xep Mang Hai Chieu =====" << endl;
	cout << "1. Tang dan tren cot, giam dan tren hang" << endl;
	cout << "2. Tang dan tren hang, giam dan tren cot" << endl;
	cout << "3. Tang tren cot, hang, duong cheo chinh, duong cheo phu" << endl;
	cout << "4. Giam tren cot, hang, duong cheo chinh, duong cheo phu" << endl;
	cout << "5. Quay ve Menu.3" << endl;
	cout << "6. Thoat" << endl;
	return 6;
}
int fRunChildMenu4(int& command)
{
	int a[10][10], m = 0, n = 0, b[100], count2to1 = 0, count1to2 = 0;
	if (command == 1)
	{
		system("cls");
		cout << "===== Tang Dan Tren Cot, Giam Dan Tren Hang =====" << endl;
		fNhapMang2Chieu(a, m, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		fChuyenMang2DThanh1D(a, m, n, b, count2to1);
		fSapXepMangFullGiam(b, count2to1);
		fChuyenMang1DThanh2D(a, m, n, b, count1to2);
		fSapXepMangTangTrenCot(a, m, n);
		cout << endl;
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		system("pause");
	}
	if (command == 2)
	{
		system("cls");
		cout << "===== Tang Dan Tren Hang, Giam Dan Tren Cot =====" << endl;
		fNhapMang2Chieu(a, m, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		fChuyenMang2DThanh1D(a, m, n, b, count2to1);
		fSapXepMangFullTang(b, count2to1);
		fChuyenMang1DThanh2D(a, m, n, b, count1to2);
		fSapXepMangGiamTrenCot(a, m, n);
		cout << endl;
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		system("pause");
	}
	if (command == 3)
	{
		system("cls");
		cout << "===== Tang Tren Cot, Hang, Duong Cheo Chinh, Duong Cheo Phu =====" << endl;
		fNhapMang2Chieu(a, m, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		fChuyenMang2DThanh1D(a, m, n, b, count2to1);
		fSapXepMangFullTang(b, count2to1);
		fChuyenMang1DThanh2D(a, m, n, b, count1to2);
		cout << endl;
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		system("pause");
	}
	if (command == 4)
	{
		system("cls");
		cout << "===== Giam Tren Cot, Hang, Duong Cheo Chinh, Duong Cheo Phu =====" << endl;
		fNhapMang2Chieu(a, m, n);
		cout << "Mang truoc khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		fChuyenMang2DThanh1D(a, m, n, b, count2to1);
		fSapXepMangFullGiam(b, count2to1);
		fChuyenMang1DThanh2D(a, m, n, b, count1to2);
		cout << endl;
		cout << "Mang sau khi sap xep" << endl;
		fXuatMang2Chieu(a, m, n);
		system("pause");
	}
	if (command == 5)
	{
		command = 6;
		return 4;
	}
	if (command == 6)
	{
		return 8;
	}
}
void fNhapMang2Chieu(int a[10][10], int& m, int& n)
{
	cout << "1. Nhap ma tran thuong" << endl;
	cout << "2. Nhap ma tran vuong" << endl;
	int select = fSelectCommand(2);
	cout << "Lua chon: "; cin >> select;
	while (cin.fail() || (select < 1 || select>2))
	{
		cin.clear(); cin.ignore();
		//cout << "Lua chon: "; cin >> select;
	}
	if (select == 1)
	{
		cout << "Nhap so hang "; cin >> m;
		while (cin.fail() || m < 1 || m>10)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap so hang "; cin >> m;
		}
		cout << "Nhap so cot "; cin >> n;
		while (cin.fail() || n < 1 || n>10)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap so cot "; cin >> n;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Nhap so hang va cot cua ma tran vuong "; cin >> m;
		while (cin.fail() || m <= 0 || m > 10)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap so hang va cot cua ma tran vuong "; cin >> m;
		} n = m;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}
void fXuatMang2Chieu(int a[10][10], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void fChuyenMang2DThanh1D(int a[10][10], int& m, int& n, int b[], int& count2to1)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[count2to1] = a[i][j];
			count2to1 = count2to1 + 1;
		}
	}
}
void fChuyenMang1DThanh2D(int a[10][10], int& m, int& n, int b[], int& count1to2)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[count1to2];
			count1to2 = count1to2 + 1;
		}
	}
}
void fSapXepMangFullTang(int b[], int& count2to1)
{
	for (int i = 0; i < count2to1; i++)
	{
		for (int j = i + 1; j < count2to1; j++)
		{
			if (b[i] > b[j])
			{
				fDoiViTri(b[i], b[j]);
			}
		}
	}
}
void fSapXepMangFullGiam(int b[], int& count2to1)
{
	for (int i = 0; i < count2to1; i++)
	{
		for (int j = i + 1; j < count2to1; j++)
		{
			if (b[i] < b[j])
			{
				fDoiViTri(b[i], b[j]);
			}
		}
	}
}
void fSapXepMangTangTrenCot(int a[10][10], int& m, int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				if (a[j][i] > a[k][i])
				{
					fDoiViTri(a[j][i], a[k][i]);
				}
			}
		}
	}
}
void fSapXepMangGiamTrenCot(int a[10][10], int& m, int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = j + 1; k < m; k++)
			{
				if (a[j][i] < a[k][i])
				{
					fDoiViTri(a[j][i], a[k][i]);
				}
			}
		}
	}
}
int fKTMaPhuong(int a[10][10], int& m, int& n)
{
	//Tính tổng các phần tử của hàng đầu tiên
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[0][i];
	}
	//Kiểm tra tổng các hàng còn lại có bằng sum
	for (int i = 1; i < m; i++)
	{
		int sumRow = 0;
		for (int j = 0; j < n; j++)
		{
			sumRow = sumRow + a[i][j];
		}
		if (sumRow != sum) { return 0; }
	}
	//Kiểm tra tổng các cột có bằng sum
	for (int i = 0; i < n; i++)
	{
		int sumColumm = 0;
		for (int j = 0; j < m; j++)
		{
			sumColumm = sumColumm + a[j][i];
		}
		if (sumColumm != sum) { return 0; }
	}
	//Kiểm tra tổng các phần tử đường chéo chính có bằng sum
	int sumMain = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				sumMain = sumMain + a[i][j];
			}
		}
	}
	if (sumMain != sum) { return 0; }
	//Kiểm tra tổng các phần tử đường chéo phụ có bằng sum
	int sumExtra = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1 - i)
			{
				sumExtra = sumExtra + a[i][j];
			}
		}
	}
	if (sumExtra == sum) { return 1; }
	else { return 0; }
}
void fDoiViTri(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void fXoayMaTranVuong(int a[10][10], int& m, int& n)
{
	int check = fKTMaPhuong(a, m, n);
	if (check == 1) //Xoay ma trận 180 độ
	{
		//Đổi vị trí các phần tử trong từng hàng 
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				fDoiViTri(a[i][j], a[i][n - 1 - j]);
			}
		}
		//Đổi vị trí các phần tử trong từng cột
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m / 2; j++)
			{
				fDoiViTri(a[j][i], a[m - 1 - j][i]);
			}
		}
	}
	else //Xoay ma trận 90 độ theo chiều kim đồng hồ
	{
		//Chuyển mảng a sang mảng tạm b theo quy tắc cột của thành hàng của b
		int b[10][10];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = a[m - 1 - j][i];
			}
		}
		//Gán lại các phần tử của mảng b vào mảng a
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}
void fCucTriMang2Chieu(int a[10][10], int& m, int& n, int i_MaxIndex[], int j_MaxIndex[], int& countMax, int i_MinIndex[], int j_MinIndex[], int& countMin)
{
	int i_index[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int j_index[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	//Tìm cực đại
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//Với mỗi phần tử của mảng, so sánh nó với 8 phần tử xung quanh
			for (int k = 0; k < 8; k++)
			{
				//Nếu các phần tử ở biên so sánh với các phần ko ở trong mảng thì bỏ qua 
				if ((i + i_index[k] < 0) || (j + j_index[k] < 0) || (i + i_index[k] > m - 1) || (j + j_index[k] > n - 1))
				{
					if (k == 7)
					{
						i_MaxIndex[countMax] = i;
						j_MaxIndex[countMax] = j;
						countMax += 1;
					}
					else continue;
				}
				else
				{
					//Nếu có 1 phần tử trong 8 phần tử lớn hơn phần tử đang xét thì kết thúc việc kiểm tra a[i][j]
					if (a[i + i_index[k]][j + j_index[k]] >= a[i][j]) { break; }
					else
					{
						if (k == 7)
						{
							i_MaxIndex[countMax] = i;
							j_MaxIndex[countMax] = j;
							countMax += 1;
						}
					}
				}
			}
		}
	}
	//Tìm cực tiểu
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//Với mỗi phần tử của mảng, so sánh nó với 8 phần tử xung quanh
			for (int k = 0; k < 8; k++)
			{
				//Nếu các phần tử ở biên so sánh với các phần ko ở trong mảng thì bỏ qua 
				if ((i + i_index[k] < 0) || (j + j_index[k] < 0) || (i + i_index[k] > m - 1) || (j + j_index[k] > n - 1))
				{
					if (k == 7)
					{
						i_MinIndex[countMin] = i;
						j_MinIndex[countMin] = j;
						countMin += 1;
					}
					else continue;
				}
				else
				{
					//Nếu có 1 phần tử trong 8 phần tử nhỏ hơn phần tử đang xét thì kết thúc việc kiểm tra a[i][j]
					if (a[i + i_index[k]][j + j_index[k]] <= a[i][j]) { break; }
					else
					{
						if (k == 7)
						{
							i_MinIndex[countMin] = i;
							j_MinIndex[countMin] = j;
							countMin += 1;
						}
					}
				}
			}
		}
	}
}