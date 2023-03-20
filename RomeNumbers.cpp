#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

std::string ConverterTo(int num)
{
    std::string result;

    if (num >= 1000)
    {
        int MCount = num / 1000;
        for (int i = 0; i < MCount; i++)
        {
            result += "M";
        }
        num %= 1000;
    }

    std::string letters[] = { "D", "C", "L", "X", "V", "I" };
    for (int i = 0; i < 3; i++)
    {
        int n = num % (int)(500 / pow(10, i));

        if (n == num)
        {
            if (400 / pow(10, i) < n)
            {
                result += letters[i * 2 + 1] + letters[i * 2];
            }
            else if (400 / pow(10, i) > n && n >= 100 / pow(10, i))
            {
                int k = n / (100 / pow(10, i));
                for (int j = 0; j < k; j++)
                {
                    result += letters[i * 2 + 1];
                }
            }
        }
        else if (400 / pow(10, i) > n && n >= 100 / pow(10, i))
        {
            int k = n / (100 / pow(10, i));
            result += letters[i * 2];
            for (int j = 0; j < k; j++)
            {
                result += letters[i * 2 + 1];
            }
        }
        else if (400 / pow(10, i) < n)
        {
            result += letters[i * 2 + 1];
        }
        else if (n < 100 / pow(10, i))
        {
            result += letters[i * 2];
        }

        num %= (int)(100 / pow(10, i));
    }

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    while (true)
    {
        std::cin >> a;
        std::cout << ConverterTo(a) << "\n\n";
    }
    return 0;
}