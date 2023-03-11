#include <iostream>
#include <conio.h>
#include <Windows.h>

int NumberLenth(int num) {
    int result = 0;
    while (num > 0) {
        num /= 10;
        result++;
    }
    return result;
}

std::string Converter(int num) {
    std::string result;
    int temp = num;
    int categoriesCount = 0;

    int* categories = new int[NumberLenth(num)];

    delete[] categories;
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
}