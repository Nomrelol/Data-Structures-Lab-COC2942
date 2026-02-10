#include<iostream>
using namespace std;

//1. with buffer in one of the arrays
void mergeWithBuffer(int A[], int m, int B[], int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (A[i] > B[j])
        {
            A[k] = A[i];
            i--;
        }
        else
        {
            A[k] = B[j];
            j--;
        }
        k--;
    }

    // Copy remaining B elements if any
    while (j >= 0)
    {
        A[k] = B[j];
        j--;
        k--;
    }
}

//2. merge without buffer
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void mergeGap(int A[], int m, int B[], int n)
{
    int gap = m + n;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        int i, j;

        // Compare in A[]
        for (i = 0; i + gap < m; i++)
        {
            if (A[i] > A[i + gap])
            {
                int temp = A[i];
                A[i] = A[i + gap];
                A[i + gap] = temp;
            }
        }

        // Compare A and B
        for (j = (gap > m ? gap - m : 0);
             i < m && j < n;
             i++, j++)
        {
            if (A[i] > B[j])
            {
                int temp = A[i];
                A[i] = B[j];
                B[j] = temp;
            }
        }

        // Compare in B[]
        if (j < n)
        {
            for (j = 0; j + gap < n; j++)
            {
                if (B[j] > B[j + gap])
                {
                    int temp = B[j];
                    B[j] = B[j + gap];
                    B[j + gap] = temp;
                }
            }
        }
    }
}
int main()
{
    int A[10] = {1, 3, 5, 7};
    int B[3] = {2, 4, 6};

    int m = 4;
    int n = 3;

    mergeWithBuffer(A, m, B, n);

    for (int i = 0; i < m + n; i++)
        cout << A[i] << " ";

    return 0;
}