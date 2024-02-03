//  Лабораторная работа 2 "Битовые операции", Вариант 6
#include <iostream>
#include <math.h>

int main()
{
	std::setlocale(LC_ALL, "Rus");
	// Заготовки чисел
//unsigned char x = 32;
//unsigned char x = 254;
	unsigned char x = 70;
	unsigned short i;
	std::cout << "Введите номер i бита который нужно узнать \n";
	std::cin >> i;
	unsigned short mask_1 = pow(2, (i - 1));
	bool result1 = x & mask_1;
	std::cout << "Бит под номером  " << i << " равен " << (result1) << ".\n\n";
}