#include<iostream>
#include<cstdlib>

using namespace std;

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

void conquer(int array[], int lhs, int rhs)
{

    if (lhs < rhs)
    {
        int m = (lhs + rhs) / 2;
        conquer(array, lhs, m);
        conquere(array, m + 1, rhs);
        divide(array, lhs, m, rhs);
    }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      arr[i]=(rand()%n);
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
   system("pause");
}