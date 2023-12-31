﻿/*
1. Дан массив A размером N.
Найти минимальный элемент из его элементов
с четными номерами: A2, A4, A6, ...
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int min_arr(int*, const size_t&);

int main()
{
	setlocale(LC_ALL, "ru");

	string str;
	getline(cin, str);		//		C:\\lab10\\text.txt

	ifstream file;
	file.open(str);
	if (!file)
	{
		cerr << "Файл не открыт\n";
		return 1;
	}

	size_t n;
	file >> n;

	int* array = new int [n];

	for (size_t i = 0; i < n; i++)
	{
		file >> array[i];
	}

	cout << min_arr(array, n);

	delete[] array;
	file.close();
}

int min_arr(int* array, const size_t& n)
{
	int min = array[0];
	for (size_t i = 2; i < n; i += 2)
	{
		int mini = array[i];
		if (mini < min) {
			min = mini;
		}
	}
	return min;
}