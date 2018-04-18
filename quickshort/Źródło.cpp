#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdio.h>


using namespace std;



void quicksortr(int liczba[], int l, int r)
{
	int i = l;
	int j = r;
	int pivot = liczba[r];
	do
	{
		while (liczba[i] < pivot)
			i++;

		while (liczba[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(liczba[i], liczba[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (l < j) quicksortr(liczba, l, j);

	if (r > i) quicksortr(liczba, i, r);
}

 int Partition(int* liczba, int left, int right) {
	int x = liczba[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; ++j)
	{
		if (liczba[j] <= x)
		{
			++i;
			swap(liczba[i], liczba[j]);
		}
	}

	swap(liczba[i + 1], liczba[right]);

	return (i + 1);
}

 void quicksortnr(int* liczba,int l, int r) {
	int i = l;
	int j = r - 1;
	int top = -1;
	int* stack = new int[r];

	stack[++top] = i;
	stack[++top] = j;

	while (top >= 0)
	{
		j = stack[top--];
		i = stack[top--];

		int p = Partition(liczba, i, j);

		if (p - 1 > i)
		{
			stack[++top] = i;
			stack[++top] = p - 1;
		}

		if (p + 1 < j)
		{
			stack[++top] = p + 1;
			stack[++top] = j;
		}
	}

	delete stack;
}
 /*
void quicksortnraa(int liczba[], int l, int r)
{
	int i = l;
	int j = r;
	int pivot = liczba[r];
	for (int i = l; i <= r; i++)
	{
		if (liczba[i] < pivot)
			i++;
		else
		{
			swap(liczba[i], liczba[j]);
			j++;
			i++;
		}
	}
	if (l < j) quicksortnr(liczba, l, j);

	if (r > i) quicksortnr(liczba, i, r);
}*/


int main() {
	int ile;
	cout << "Hello Word" << endl;
	cout << "Podaj ile liczb ma posiadac twoj ciag" << endl;
	cin >> ile;
	int *liczba;
	liczba = new int[ile];

	int yy;
	cout << endl;
	cout << "1. Losowe liczby" << endl;
	cout << "2. Wpisanie samemu" << endl;
	cin >> yy;
	srand(time(NULL));
	switch (yy)
	{
	case 1:
		for (int i = 0; i <= ile - 1; i++)
		{
			liczba[i] = rand() % 100;
		}
		break;
	case 2:
		cout << "prosze wpisaæ liczby do posortowania" << endl;
		for (int i = 0; i <= ile - 1; i++)
		{
			cin >> liczba[i];
		}
		break;
	default:
		break;
	}

	system("cls");

	cout << "przed sortowaniem: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << liczba[i] << " ";
	}

	int xx;
	cout << endl;
	cout << "1. quicksort rekurencyjnie" << endl;
	cout << "2. quicksort nierekurencyjnie" << endl;
	cin >> xx;
	switch (xx)
	{
	case 1:
	quicksortr(liczba, 0, ile - 1);
	break;
	case 2:
	quicksortnr(liczba, 0, ile );
	break;
	default:
	break;
	}
	

	cout << endl << "po sortowaniu: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << liczba[i] << " ";
	}

	delete liczba;
	system("pause");
	return 0;
}
