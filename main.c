#include <stdio.h>

int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i += 1) 
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void sortDescending(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i += 1) 
    {
        for (int j = 0; j < size - i - 1; j += 1) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) 
{
    int left = 0, right = size - 1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() 
{
    system("chcp 65001");
    int X[15];
    int A;

    printf("Введіть 15 елементів масиву:\n");
    for (int i = 0; i < 15; i += 1) 
    {
        scanf("%d", &X[i]);
    }

    printf("Введіть елемент для пошуку (A): ");
    scanf("%d", &A);

    int linIndex = linearSearch(X, 15, A);
    if (linIndex != -1)
        printf("Лінійний пошук: Елемент A знайдено на позиції %d\n", linIndex);
    else
        printf("Лінійний пошук: Елемент A не знайдено\n");

    sortDescending(X, 15);
    printf("Відсортований масив за спаданням:\n");
    for (int i = 0; i < 15; i += 1) 
    {
        printf("%d ", X[i]);
    }
    printf("\n");

    int binIndex = binarySearch(X, 15, A);
    if (binIndex != -1)
        printf("Бінарний пошук: Елемент A знайдено на позиції %d\n", binIndex);
    else
        printf("Бінарний пошук: Елемент A не знайдено\n");

    return 0;
}
