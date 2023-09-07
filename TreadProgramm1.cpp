#include <iostream>
#include <thread>  
#include <numeric>
#include <atomic>
#include <vector>

using namespace std;

int n, m, ** a;
int sum = 0;

//Создать двумерный массив размерности n×m. Найти сумму элементов массива.

void get_Matrix()
{
    cout << "Введите размерность матрицы (n x m) : " << endl;
    cin >> n >> m;
    cout << "Введите матрицу : " << endl;
    a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < m; j++)
        {
            cout << "[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
    cout << "Ваша матрица А : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        for (int j = 0; j < m; j++)
        {
            cout << "\t";
            cout << a[i][j];
        }
    }

    cout << "\n";

}



void get_Sum()
{
    cout << "Сумма элементов в матрице А : " << endl;

    std::vector<std::thread> vt;
    int const threadCount = 4;
    std::atomic_int sum{ 0 };

    for (int i = 0; i < threadCount; ++i)
    {
        vt.emplace_back([&sum, arr = a + i, threadCount]() mutable
            {
                while (arr - a < n)
                {
                    sum += std::accumulate(*arr, *arr + m, 0);
                    arr += threadCount;
                }
            });
    }
    for (auto& t : vt)
    {
        t.join();
    }

    cout << sum << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");

    get_Matrix();

    get_Sum();

    return 0;
}