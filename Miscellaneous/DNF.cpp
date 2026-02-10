#include <iostream>
using namespace std;

/* Swap function */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* Dutch National Flag */
void threeWayPartition(int A[], int n, int pivot)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (A[mid] < pivot)
        {
            swap(A[low], A[mid]);
            low++;
            mid++;
        }
        else if (A[mid] == pivot)
        {
            mid++;
        }
        else   // A[mid] > pivot
        {
            swap(A[mid], A[high]);
            high--;
        }
    }
}

int main()
{
    int A[] = {2, 1, 2, 0, 1, 2, 1};
    int n = 7;

    int pivot = 1;

    threeWayPartition(A, n, pivot);

    cout << "After Partition:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}