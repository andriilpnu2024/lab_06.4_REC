#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, int size, int Low, int High, int i);
void Max(int* a, const int size,int& imax,int i);
void Print(int* a, int size, int i);
int indexdodat(int* a, int size, int idod, int i);
int sum(int* a, int i, int size, int sum);
//void Sort(int* a, const int size, int poch, int kinz);
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	int n = 0;
	int a1;
	int b;
	int sum1 = 0;
	int idod = 0;

	cout << "Input size - ";
	cin >> n;
	/*cout << "Input a - ";
	cin >> a1;
	cout << "Input b - ";
	cin >> b;*/

	int imax;
	imax = n - 1;
	int* a = new int[n];
	int Low = -15;
	int High = 15;

	Create(a, n, Low, High,0);
	Max(a, n, imax,0);
	int c = indexdodat(a, n, idod ,0);
	cout << "       sum" << setw(2) << "=" << setw(2) << sum(a, c, n, sum1) << endl;
	cout << "Ind of max" << setw(2) << "=" << setw(2) << imax << endl;
	cout << "a [";
	Print(a, n,0);
	/*Sort(a, n, a1, b);*/
	/*Print(a, n,0);*/
	delete[] a;
	return 0;
}
int sum(int* a, int i, int size, int sum1)
{
	int c = a[i];
	if (i >= size) {
		return 0;
	}
	else
		sum1 = c + sum(a, i + 1, size, sum1);
}


int indexdodat(int* a, int size, int idod , int i)
{

	if (a[i] > 0) {
		idod = i;
		return idod;
	}
	else
		if (i<size-1)
	   return indexdodat(a,size,idod,i+1);
}

void Create(int* a, int size, int Low, int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Max(int* a, const int size, int& imax,int i)
{
	int max = a[imax];
	if (abs(max) < abs(a[i]))
	{
		max = a[i];
		imax = i;
	}
	if (i < size - 2)
		Max(a, size, imax,i+1);
}
//void Sort(int* a, const int size, int poch, int kinz)
//{
//	int n = 0;
//	for (int j = 1; j < size; j++) // номер поточного елемента
//		if (!(a[j] < kinz && a[j] > poch)) // якщо порушено умову впорядкування
//		{
//			int tmp = a[j];
//
//			for (int k = size - 1; k >= j; k--)
//			{ // зсув
//				a[k + 1] = a[k];
//			}
//			a[n] = a[j];
//			n++;
//		}
//}
//for (int c = 0; c <= size - 1; c++) {
//	for (int i = 0; i >= poch && i <= kinz; i++) {
//		int temp = a[c];
//		int s = kinz - poch;
//		a[c] = i;
//		a[c + s] = temp;
//		temp = 0;
//	}
//}
//for (int i = 0; i <= size - 1; i++) {
//	for (int j = i + 1; j < size; j++){
//		if (!(a[j] >= poch && a[j] <= kinz) && (a[i] >= poch && a[i] <= kinz)|| (a[j] >= poch && a[j] <= kinz) && !(a[i] >= poch && a[i] <= kinz)) {
//			int tmp = a[j];
//			a[j] = a[i];
//			a[i] = tmp;
//		}
//	};
//}
//
//    int cout = 0;
//
//		if (a[c] >= poch && a[c] <= kinz) {
//			if (a[cout] >= poch && a[cout] <= kinz)
//				cout += 1;
//			int temp;
//			temp = a[cout];
//			a[cout] = a[c];
//			a[c] = temp;
//			cout++;

void Print(int* a, int size, int i)
{
	if (i == size - 1)
		cout << setw(1) << a[i];
	else
		cout << setw(1) << a[i] << ",";
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << "]" << endl;
}