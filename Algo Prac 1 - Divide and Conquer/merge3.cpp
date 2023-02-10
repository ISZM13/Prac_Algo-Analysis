#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count3 = 0;
int count1 = 0;
int count4 = 0;
// merge sort
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void divide(int array[], int lhs, int mid, int rhs)
{
    int i, f, size_l, size_r, new_size;
    size_l = mid - lhs + 1;
    size_r = rhs - mid;
    int larr[size_l], rarr[size_r];
    for (i = 0; i < size_l; i++)
    {
        larr[i] = array[lhs + i];
    }
    for (f = 0; f < size_r; f++)
    {
        rarr[f] = array[mid + 1 + f];
    }

    i = 0;
    f = 0;
    new_size = lhs;

    while (i < size_l && f < size_r)
    {
        if (larr[i] <= rarr[f])
        {
            array[new_size] = larr[i];
            i++;
            count3++;
        }
        else
        {
            array[new_size] = rarr[f];
            f++;
            count3++;
        }
        new_size++;
    }

    while (i < size_l)
    {
        array[new_size] = larr[i];
        i++;
        new_size++;
    }
    while (f < size_r)
    {
        array[new_size] = rarr[f];
        f++;
        new_size++;
    }
}

void conquere(int array[], int lhs, int rhs)
{

    if (lhs < rhs)
    {
        int m = (lhs + rhs) / 2;
        conquere(array, lhs, m);
        conquere(array, m + 1, rhs);
        divide(array, lhs, m, rhs);
    }
}

// quick sort
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count2 = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count2++;
    }

    int pivotIndex = start + count2;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
            count1++;
        }

        while (arr[j] > pivot)
        {
            j--;
            count1++;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);

}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
                count4++;
            }
        }
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
level:
    system("cls");
    int input;
    int *randArray;
    int siz;
    int n,option;

    cout << "Enter the number of elements of the randArray which needs to be sorted: \n"
         << "11) Ten thousand \n"
         << "12) Hundred Thousand \n"
         << "13) 1 Million \n"
         << "14) 1 Thousand. \n"
         << "15) Leave this menu \n";
    cout << "Choice: ";
    cin >> n;

    switch (n)
    {
    case 11:
    {
        siz = 10000;
        randArray = new int[siz];
        for (int i = 0; i < siz; i++)
        {
            randArray[i] = (rand() % siz);
        }
        break;
    }

    case 12:
    {
        siz = 100000;
        randArray = new int[siz];
        for (int i = 0; i < siz; i++)
        {
            randArray[i] = (rand() % siz);
        }
        break;
    }

    case 13:
    {
        siz = 1000000;
        randArray = new int[siz];
        for (int i = 0; i < siz; i++)
        {
            randArray[i] = (rand() % siz);
        }
        break;
    }

    case 14:
    {
        siz = 1000;
        randArray = new int[siz];
        for (int i = 0; i < siz; i++)
        {
            randArray[i] = (rand() % siz);
        }
        break;
    }
    case 15:
    {
        goto last;
    }
    }

    system("cls");

    cout << "Please select a choice from this submenu.\n"
         << "1) Sort using Merge sort.\n"
         << "2) Sort using Quick sort.\n"
         << "3) Sort using Selection sort.\n"
         << "\nChoice: ";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        conquere(randArray, 0, siz - 1);
        display(randArray, siz);
        delete randArray;
        cout << "\nTotal number of comparisons: ";
        cout << count3 << endl;

        cout<<"\nGenerate table for the following method?? "
            <<"\n ---Enter '1' for yes"
            <<"\n ---Enter '0' for no"
            <<"\n ---Choice: ";
        cin>> option;

        if(option==1)
        {
            cout<<"\n|    Size of data    |    Type of sorting method    |    No. of comparisons    |";
            cout<<"\n|     "<<siz<<"          |             Merge              |        "<<count3<<endl;
        }
        count3=0;
    }
    break;

    case 2:
    {
        quickSort(randArray, 0, siz - 1);
        display(randArray, siz);
        delete randArray;
        cout << "\nTotal number of comparisons: ";
        cout << count1 << endl;

        cout<<"\nGenerate table for the following method?? "
            <<"\n ---Enter '1' for yes"
            <<"\n ---Enter '0' for no"
            <<"\n ---Choice: ";
        cin>> option;

        if(option==1)
        {
            cout<<"\n|    Size of data    |    Type of sorting method    |    No. of comparisons    |";
            cout<<"\n|     "<<siz<<"          |             Merge              |        "<<count1<<endl;
        }
        count1=0;
    }
    break;

    case 3:
    {
        selectionSort(randArray, siz);
        display(randArray, siz);
        delete randArray;
        cout << "\nTotal number of comparisons: ";
        cout << count4 << endl;

        cout<<"\nGenerate table for the following method?? "
            <<"\n ---Enter '1' for yes"
            <<"\n ---Enter '0' for no"
            <<"\n ---Choice: ";
        cin>> option;

        if(option==1)
        {
            cout<<"\n|    Size of data    |    Type of sorting method    |    No. of comparisons    |";
            cout<<"\n|     "<<siz<<"          |             Merge              |        "<<count4<<endl;
        }
        count3=0;
    }
    }
    system("pause");
    goto level;
last:
    return 0;
}