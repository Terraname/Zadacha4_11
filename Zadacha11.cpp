// Zadacha11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

int main()
{
    std::cout << "This program fids diagonal of a cube array with the lowest summ of elments(and the summ).\n";
    std::cout << "a is dioganal starting at x = 0, y = 0; \n";
    std::cout << "b is dioganal starting at x = n-1, y = 0; \n";
    std::cout << "c is dioganal starting at x = 0, y = n-1; \n";
    std::cout << "d is dioganal starting at x = n-1, y = n-1; \n";
    int n, m;
    long long int a, b, c, d;
    int*** array;
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong N!\n";
        std::cout << "Enter N another time\n";
        std::cin >> n;
    }
    array = new int **[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int* [n];
        for (int j = 0; j < n; j++)
        {
            array[i][j] = new int [n];
        }
    }

    std::cout << "Enter elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                std::cin >> array[i][j][k];
                while (std::cin.fail() || array[i][j][k] < 0)
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    std::cout << "Wrong element's value!\n";
                    std::cout << "Enter element № " << (i + 1) << ", " << (j + 1) << ", " << (k + 1) << "  of the array another time\n";
                    std::cin >> array[i][j][k];
                }
            }
        }
    }

    a = 1;
    b = 1;
    c = 1;
    d = 1;
    for (int i = 0; i < n; i++)
    {
        a += array[i][i][i];
        b += array[i][i][n-i-1];
        c += array[i][n-i-1][i];
        d += array[i][n-i-1][n-i-1];
    }

    std::cout << std::min(std::min(a, b), std::min(c, d)) << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
