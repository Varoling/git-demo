#include <iostream>

int comparison = 0;
int swap = 0;

// Функция сортировки прямыми включениями
void inclusionSort(int* num, int size) 
{
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        int value = num[i]; // запоминаем значение элемента
        int index = i;     // и его индекс
        while ((index > 0) && (num[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            num[index] = num[index - 1];
            index--;    // смещаем просмотр к началу массива
        }
        num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
    }
}

// Функция сортировки прямым выбором
void selectionSort(int* num, int size)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = temp;
    }
}

// Функция сортировки прямым обменом (метод "пузырька")
void bubbleSort(int* num, int size)
{
    // Для всех элементов
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
            {
                int temp = num[j - 1]; // меняем их местами
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

// Функция сортировки Шелла
void shellSort(int* num, int size)
{
    int increment = 4;    // начальное приращение сортировки
    while (increment > 0)  // пока существует приращение
    {
        for (int i = 0; i < size; i++)  // для всех элементов массива
        {
            int j = i;          // сохраняем индекс и элемент
            int temp = num[i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (num[j - increment] > temp))
            {  // пока отстоящий элемент больше текущего
                num[j] = num[j - increment]; // перемещаем его на текущую позицию
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            num[j] = temp; // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1)      // делим приращение на 2
            increment = increment / 2;
        else if (increment == 1)   // последний проход завершён,
            break;  // выходим из цикла
    }
}

int main()
{
    int arr[20]{16,5,17,4,15,6,14,7,13,18,12,9,11,10,20,1,19,2,8,3};
    shellSort(arr, 20);
    for (int i = 0; i < 20; i++) {
        std::cout << arr [i] << " ";
    }
    return 0;
}
