#include<bits/stdc++.h>

using namespace std;

int comp1, comp2;
int min1, max1;
int naive(int *arr,int size);
int divconq(int *arr, int size);
int create_arr(int size);
int divide(int *arr, int low, int high);
int conquer( int num);

int naive(int *arr,int size)
{
    int min, max;
    if(arr[0]>arr[1])
    {
        comp1++;
        max=arr[0];
        min=arr[1];
    }
    else
    {
        comp1++;
        max=arr[1];
        min=arr[0];   
    }
    for(int i=2;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        comp1++;
        if(arr[i<min])
        {
            min=arr[i];
        }
        comp1++;
    }
    cout<<"\n The Maximum element using the Naive 's method is "<<max;
    cout<<"\n The Minimum element using the Naive 's method is "<<min;
    cout<<"\n The no. of commparisons Naive 's method take:"<<comp1;
    return 0;
}

int divconq(int *arr,int size)
{
    if(arr[0]>arr[1])
    {
        comp2++;
        max1=arr[0];
        min1=arr[1];
    }
    else
    {
        comp2++;
        max1=arr[1];
        min1=arr[0];   
    }
    divide(arr, 0, size-1);
    cout<<"\n The Maximum element using the Divide and Conquer method is "<<max1;
    cout<<"\n The Minimum element using the Divide and Conquer method is "<<min1;
    cout<<"\n The no. of commparisons Divide and Conquer method take:"<<comp2;
    return 0;
}

int divide(int *arr, int low, int high)
{
    if(low>high)
    return 0;
    if(high==low)
    {
        conquer(arr[low]);
    }
    int mid;
    mid=(low+high)/2;
    divide(arr, low,mid);
    divide(arr, mid+1, high);
    return 0;
}

int conquer(int num)
{
    if(num>max1)
    {
        max1=num;
    }
    else if(num<min1)
    {
        comp2++;
        min1=num;
    }
    comp2++;
    return 0;
}

int create_arr(int size)
{
    int *dataset= new int[size];
    for(int i=0;i<size;i++)
    {
        dataset[i]=rand()%size;
    }
    cout<<"\n\t\t\tNAIVE 'S METHOD:\n";
    comp1=0;
    naive(dataset, size);   
    cout<<"\n\t\t\tDIVIDE AND CONQUER METHOD:\n";
    comp2=0;
    divconq(dataset, size);
    system("pause");
    return 0;
}

int main()
{
    two:
    system("cls");
    int x = 0;
    cout << "\n\n\n\t\t-----MIN MAX PROBLEM------ \n";
    cout << "\t\t\t\t \n Select a type of dataset you want to apply the algos on on:\n";
    cout << "\t\t\t\t \n1-> Big Data (millions of entries)\n";
    cout << "\t\t\t\t \n2-> One Lakh entries.\n";
    cout << "\t\t\t\t \n3-> Thousand entries. \n";
    cout << "\t\t\t\t \n4-> Ten entries. \n";
    cout << "\n\n\t\t\t\t \n0-> Exit the program. \n";
    cin >> x;
    switch (x)
    {
    case 1:
        create_arr(5000000);
        break;
    case 2:
        create_arr(100000);
        break;
    case 3:
        create_arr(1000);
        break;

    case 4:
        create_arr(10);
        break;

    case 0:
        system("pause");
        break;
    default:
        cout << "Re-enter a valid option.";
        goto two;
    }
    return 0;
}
