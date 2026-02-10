#include <iostream>
using namespace std;

void multiply(int a[2][2], int b[2][2], int c[2][2]) {
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
}

void matrixPower(int a[2][2], int n, int res[2][2]) {
    // identity matrix
    res[0][0] = 1; res[0][1] = 0;
    res[1][0] = 0; res[1][1] = 1;

    int temp[2][2];

    while (n > 0) {
        if (n & 1) {
            multiply(res, a, temp);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i][j] = temp[i][j];
        }

        multiply(a, a, temp);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = temp[i][j];

        n >>= 1;
    }
}

int fibonacci(const int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    int q[2][2] = {{1,1},{1,0}};
    int res[2][2];

    matrixPower(q, n - 2, res);
    return res[0][0];
}
