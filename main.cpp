#include<iostream>
using namespace std;

void FillRand(int* arr, const int n);

void Print(int* arr, const int n);

int* PushBack(int* arr, int& n, int a);
int* PushFront(int* arr, int& n, int a);
int* Insert(int* arr, int& n, int a);
int* PopBack(int* arr, int& n);
int* PopFront(int* arr, int& n);
int* Erase(int* arr, int& n);

//#define Insertion

void main()
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

#ifdef Insertion
	int a;
	cout << "Enter a number for insert: ";
	cin >> a;
#endif // Insertion

	arr = Erase(arr, n);

	Print(arr, n);
	delete[] arr;

}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* PushBack(int* arr, int& n, int a)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = a;
	n++;
	return arr;
}

int* PushFront(int* arr, int& n, int a)
{
	int* extra = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		extra[i + 1] = arr[i];
	}
	delete[] arr;
	arr = extra;
	arr[0] = a;
	n++;
	return arr;
}

int* Insert(int* arr, int& n, int a)
{
	int put;
	cout << "In which spot do you want to put this number? "; cin >> put;
	if (put > n) { return arr; }
	int* second = new int[n + 1];
	for (int i = 0; i < put; i++)
	{
		second[i] = arr[i];
	}
	second[put] = a;
	for (int i = put; i < n; i++)
	{
		second[i + 1] = arr[i];
	}
	delete[] arr;
	arr = second;
	arr[put] = a;
	n++;
	return arr;
}

int* PopBack(int* arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* PopFront(int* arr, int& n)
{
	int* extra = new int[n];
	for (int i = 0; i < n; i++)
	{
		extra[i] = arr[i];
	}
	delete[] arr;
	arr = extra;
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}

int* Erase(int* arr, int& n)
{
	int put;
	cout << "Which number do you want to delete? "; cin >> put;
	if (put > n) { return arr; }
	int* second = new int[n];
	for (int i = 0; i < n; i++)
	{
		second[i] = arr[i];
	}
	delete[] arr;
	arr = second;
	for (int i = put; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}