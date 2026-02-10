#include <iostream>
using namespace std;

/* Manual Binary Search */
int lowerBound(int tail[], int len, int key)
{
    int left = 0;
    int right = len - 1;
    int ans = len;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (tail[mid] >= key)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

/* LIS Function */
int LIS(int A[], int n, int lis[])
{
    int tail[1000];   // stores LIS ends
    int pos[1000];    // stores positions
    int prev[1000];   // for reconstruction

    int len = 0;

    for (int i = 0; i < n; i++)
        prev[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int k = lowerBound(tail, len, A[i]);

        tail[k] = A[i];
        pos[k] = i;

        if (k > 0)
            prev[i] = pos[k - 1];

        if (k == len)
            len++;
    }

    /* Reconstruct LIS */
    int index = pos[len - 1];

    for (int i = len - 1; i >= 0; i--)
    {
        lis[i] = A[index];
        index = prev[index];
    }

    return len;
}

int main()
{
    int A[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    int lis[1000];

    int length = LIS(A, n, lis);

    cout << "Length = " << length << endl;

    cout << "LIS = ";
    for (int i = 0; i < length; i++)
        cout << lis[i] << " ";

    return 0;
}