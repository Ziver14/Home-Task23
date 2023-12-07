#include<iostream>

void max_three(int& num1, int& num2, int& num3) {
	int max = num1;
	max = max > num2 ? max : num2;
	max = max > num3 ? max : num3;
	num1 = num2 = num3= max;
}

void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << *(arr + i) << ' ';
	std::cout << std::endl;
}

int& neg(int arr[], const int length) {
	int min = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			min = i;
			break;
		}
	return arr[min];
}

void zero(int arr[], const int length, int arr2[], const int length2) {
	for (int i = 0; i < length; i++)			
		for (int j = 0; j < length2; j++)		
			if (*(arr + i) == *(arr2 + j))		
				*(arr2 + j) = 0;
};




int main() {

	setlocale(LC_ALL, "ru");
	
	std::cout << "Задача 1. Максимальное из 3x\n";
	int A = 23, B = 12, C = 17;
	max_three(A, B, C);
	std::cout << A << ' ' << B << ' ' << C << "\n\n";
	
	std::cout << "Задача 2. Негативный элемент \n";
	const int size = 5;
	int arr[size]{5,12,6,-12,9};
	std::cout << "Изначальный массив \n";
	print_arr(arr,size);
	if (neg(arr, size) < 0)
		std::cout << "Первый отрицательный элемент -> " << neg(arr, size)<< "\n\n";
	else
		std::cout << "Отрицательных элементов в массиве нет. Первый элемент -> "<< neg(arr,size)<<"\n\n";

	std::cout << "Задача 2. Обнуление элементов \n";
	const int size2 = 5;
	int arr2[size2]{ 12,5,95,12,3 };
	std::cout << "Изначальный массив 1 ->\n";
	print_arr(arr, size);
	std::cout << "Изначальный массив 2 ->\n";
	print_arr(arr2, size2);
	std::cout << "Итоговый массив ->\n";
	zero(arr,size,arr2,size2);
	print_arr(arr2, size2);
	return 0;
}