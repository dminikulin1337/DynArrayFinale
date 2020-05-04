#include<iostream>
using namespace std;

void FillRand(int* arr, const int n);

void Print(int* arr, const int n);

template<typename T>T PushBack(T& arr, int& n, int a);
template<typename T>T PushFront(T& arr, int& n, int a);
template<typename T>T Insert(T& arr, int& n, int a);
template<typename T>T PopBack(T& arr, int& n);
template<typename T>T PopFront(T& arr, int& n);
template<typename T>T Erase(T& arr, int& n);

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

	Erase(arr, n);

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

template<typename T>
T PushBack(T& arr, int& n, int a)
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
}

template<typename T>
T PushFront(T& arr, int& n, int a)
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
}

template<typename T>
T Insert(T& arr, int& n, int a)
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
}

template<typename T>
T PopBack(T& arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}

template<typename T>
T PopFront(T& arr, int& n)
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
}

template<typename T>
T Erase(T& arr, int& n)
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
}