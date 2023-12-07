﻿#include <iostream>

void three_max(int& num1, int& num2, int& num3) {
	int max = num1;
	max = max > num2 ? max : num2;
	max = max > num3 ? max : num3;
	num1 = max;
	num2 = max;
	num3 = max;
}
void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << *(arr + i) << ' ';
	std::cout << std::endl;
}
int& neg_element(int arr[], const int length) {
	int neg = 0;
	for (int i = 0; i < length; i++)
		if (*(arr + i) < 0) {
			neg = i;
			break;
		}
	return arr[neg];
}
void zero_repetitions(int arr[], int arr2[], const int length, const int length2) {
	for (int i = 0; i < length2; i++)
		if (*(arr + i) == *(arr2 + i))
			*(arr2 + i) = 0;
}


int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Задача 1. Присвоение максимума.\n\n";
	int A = 13, B = 5, C = 6;
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C << std::endl;


	std::cout << "\nЗадача 2. Ссылка на элемент массива.\n\n";
	const int size = 10;
	int arr[size]{ 10,20,30,5,45,-15,8,9,80,99 };
	print_arr(arr, size);
	if (neg_element(arr, size) < 0)
		std::cout << "Первый отрицательный элемент в массиве -> " << neg_element(arr, size) << std::endl;
	else
		std::cout << "В массиве нет отрицательных элементов! Выводим первый элемент -> " << neg_element(arr, size) << std::endl;

	std::cout << "\nЗадача 3. Обнуление дублей в массиве.\n\n";

	const int size2 = 10;
	int arr2[size2]{ 10,20,30,40,50,60,70,80,90,100 };

	const int size3 = 10;
	int arr3[size3]{ 10,22,30,42,50,61,70,81,90,101 };
	std::cout << "Первый массив: \n";
	print_arr(arr2, size2);
	std::cout << "Второй массив: \n";
	print_arr(arr3, size3);
	zero_repetitions(arr2, arr3, size2, size3);
	std::cout << "\nМассив после обнуления дублей: \n";
	print_arr(arr3, size3);



	return 0;
}