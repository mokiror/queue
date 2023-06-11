#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <WINDOWS.H>
#include <list>
#include <vector>
#include <deque>
#include <queue>
#include <stdio.h>
#include <stdlib.h>


int F00(const void* num01, const void* num02)
{
	return (*(int*)num02 - *(int*)num01);
}

void ForQueue(std::queue <int>& numbers, int& size)
{
	int* arr = new int[size];
	int j = 0;
	std::cout << "\nДанные в очереди: \n";

	while (!numbers.empty())
	{
		std::cout << numbers.front() << " ";
		arr[j] = numbers.front();
		numbers.pop();
		++j;
	}

	std::cout << "\n" << std::endl;

	std::qsort(arr, size, sizeof(int), F00);

	for (int i = 0; i < size; i++)
	{
		numbers.emplace(arr[i]);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");


	std::queue <int> numbers;
	int size = 10, count = 0;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите " << i + 1 << " число: ";
		std::cin >> count;
		numbers.push(count);
	}

	ForQueue(numbers, size);

	std::cout << "Данные в отсортированной очереди: \n";
	while (!numbers.empty())
	{
		std::cout << numbers.front() << " ";
		numbers.pop();
	}
	

	return 0;
}