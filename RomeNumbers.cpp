#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <map>

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

int ConverterOut(std::string num)
{
    for (char letter : num)
    {
        if (!(letter == 'M' || letter == 'D' || letter == 'C' || letter == 'L' || letter == 'X' || letter == 'V' || letter == 'I'))
        {
            throw std::exception("Неверный формат числа");
        }
    }

    std::map<char, int> letters;
    letters.emplace('M', 1000);
    letters.emplace('D', 500);
    letters.emplace('C', 100);
    letters.emplace('L', 50);
    letters.emplace('X', 10);
    letters.emplace('V', 5);
    letters.emplace('I', 1);

    int result = 0;

    for (int i = 0; i < num.length(); i++)
    {
        short m = 1;
        if (i != num.length() - 1 && letters[num[i + 1]] > letters[num[i]])
        {
            m = -1;
        }
        result += letters[num[i]] * m;
    }

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string a;
    while (true)
    {
        std::cin >> a;
        try
        {
            int b = std::stoi(a);
            std::cout << ConverterTo(b) << "\n\n";
        }
        catch (...)
        {
            try
            {
                std::cout << ConverterOut(a) << "\n\n";
            }
            catch (std::exception ex)
            {
                std::cout << ex.what() << "\n\n";
            }
        }
    }
    return 0;
}