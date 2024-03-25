#include <iostream>


void inclusionSort(int* num, int size, int& comparison, int& swap)
{
    for (int i = 1; i < size; i++)
    {
        int value = num[i]; 
        int index = i;     
        while ((index > 0) && (num[index - 1] > value))
        {   
            comparison++;
            num[index] = num[index - 1];
            swap++;
            index--;    
        }
        if (num[index] != value) {
            num[index] = value;
            swap++;
        }
    }
}

void selectionSort(int* num, int size, int& comparison, int& swap)
{
    int min, temp; 
    for (int i = 0; i < size - 1; i++)
    {
        min = i; 
        for (int j = i + 1; j < size; j++)  
        {
            comparison++;
            if (num[j] < num[min]) 
                min = j;       
        }
        if (num[i] != num[min]) {
            temp = num[i];      
            num[i] = num[min];
            num[min] = temp;
            swap++;
        }
    }
}

void bubbleSort(int* num, int size, int& comparison, int& swap)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            comparison++;
            if (num[j - 1] > num[j]) 
            {
                swap++;
                int temp = num[j - 1]; 
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}


void shellSort(int* num, int size, int& comparison, int& swap)
{
    int increment = 4;   
    while (increment > 0) 
    {
        for (int i = 0; i < size; i++)  
        {
            int j = i;          
            int temp = num[i];
            while ((j >= increment) && (num[j - increment] > temp))
            {  
                comparison++;
                num[j] = num[j - increment]; 
                swap++;
                j = j - increment;       
            }
            if (num[j] != temp) {
                num[j] = temp;
                swap++;
            }
        }
        if (increment > 1)    
            increment = increment / 2;
        else if (increment == 1)  
            break;  
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
