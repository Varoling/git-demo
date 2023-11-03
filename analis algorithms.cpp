#include <iostream>

// Функция сортировки прямыми включениями
void inclusionSort(int* num, int size, int& comparison, int& swap)
{
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        int value = num[i]; // запоминаем значение элемента
        int index = i;     // и его индекс
        while ((index > 0) && (num[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            comparison++;
            num[index] = num[index - 1];
            swap++;
            index--;    // смещаем просмотр к началу массива
        }
        if (num[index] != value) {
            num[index] = value;
            swap++;// рассматриваемый элемент помещаем на освободившееся место
        }
    }
}

// Функция сортировки прямым выбором
void selectionSort(int* num, int size, int& comparison, int& swap)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            comparison++;
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        if (num[i] != num[min]) {
            temp = num[i];      // меняем местами i-ый и минимальный элементы
            num[i] = num[min];
            num[min] = temp;
            swap++;
        }
    }
}

// Функция сортировки прямым обменом (метод "пузырька")
void bubbleSort(int* num, int size, int& comparison, int& swap)
{
    // Для всех элементов
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
            comparison++;
            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
            {
                swap++;
                int temp = num[j - 1]; // меняем их местами
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

// Функция сортировки Шелла
void shellSort(int* num, int size, int& comparison, int& swap)
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
                comparison++;
                num[j] = num[j - increment]; // перемещаем его на текущую позицию
                swap++;
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            if (num[j] != temp) {
                num[j] = temp;
                swap++;// на выявленное место помещаем сохранённый элемент
            }
        }
        if (increment > 1)      // делим приращение на 2
            increment = increment / 2;
        else if (increment == 1)   // последний проход завершён,
            break;  // выходим из цикла
    }
}

int main()
{
    int comparison = 0;
    int swap = 0;
    int arr[20]{ 16,5,17,4,15,6,14,7,13,18,12,9,11,10,20,1,19,2,8,3 };
    inclusionSort(arr, 20, comparison, swap);
    for (int i = 0; i < 20; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "comparison = " << comparison << std::endl << "swap = " << swap;
    return 0;
}