#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <map>

std::string ConverterTo(int num)
{
    std::string result;

    std::pair<std::pair<std::string, int>, std::pair<std::string, int>> categories[4];
    categories[0].first = std::make_pair("M", 1000);
    categories[0].second = std::make_pair("M", 1000);
    categories[1].first = std::make_pair("C", 100);
    categories[1].second = std::make_pair("D", 500);
    categories[2].first = std::make_pair("X", 10);
    categories[2].second = std::make_pair("L", 50);
    categories[3].first = std::make_pair("I", 1);
    categories[3].second = std::make_pair("V", 5);

    int num_categories[4];
    for (int i = 0, j = 0; i < 4; i++)
    {
        num_categories[i] = num - num % (int)pow(10, 3 - i) - j;
        j += num_categories[i];
    }

    for (int i = 0; i < 4; i++)
    {
        if (i != 0)
        {
            if (num_categories[i] == categories[i - 1].first.second - categories[i].first.second)
            {
                result += categories[i].first.first + categories[i - 1].first.first;
                continue;
            }
            else if (num_categories[i] > categories[i].second.second)
            {
                int k = num_categories[i] / categories[i].first.second - 5;
                result += categories[i].second.first;
                for (int j = 0; j < k; j++)
                {
                    result += categories[i].first.first;
                }
                continue;
            }
            else if (num_categories[i] == categories[i].second.second)
            {
                result += categories[i].second.first;
                continue;
            }
            else if (num_categories[i] == categories[i].second.second - categories[i].first.second)
            {
                result += categories[i].first.first + categories[i].second.first;
                continue;
            }
        }
        int k = num_categories[i] / categories[i].first.second;
        for (int j = 0; j < k; j++)
        {
            result += categories[i].first.first;
        }
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