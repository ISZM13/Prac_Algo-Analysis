
#include <bits/stdc++.h>
using namespace std;
int count_comp;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            count_comp++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Enter the number of elements in dataset:\t\n";
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand() % num;
    }
    cout << "\nData has been enetered";
    cout << "\n Do you want to view the dataset?";
    cout << "\n 1 for yes || 0 for no";
    int choice = 2;
    while (choice != 0 && choice != 1)
    {
        cin >> choice;
        if (choice != 0 && choice != 1)
            cout << "Enter valid number";
    }
    if (choice == 1)
    {
        printArray(arr, num);
    }
    quickSort(arr, 0, num - 1);
    cout << "Sorted array: \n";
    printArray(arr, num);
    cout << "\n The number of comparisons in the sorting is : " << count_comp;
    return 0;
}