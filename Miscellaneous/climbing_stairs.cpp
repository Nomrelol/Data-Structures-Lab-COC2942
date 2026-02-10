#include <memory>
using namespace std;


//1. brute force: recursion
int recursionHelper(const int i, const int n) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return recursionHelper(i + 1, n) + recursionHelper(i + 2, n);
}
int recursion(const int n) {
    return recursionHelper(0, n);
}
//2. recursion with memoization
int memoize(const int i, const int n, int *memo) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0)
        return memo[i];
    memo[i] = memoize(i + 1, n, memo) + memoize(i + 2, n, memo);
    return memo[i];
}
int climbMemoize(const int n) {
    auto memo = new int[n+1];
    return memoize(0, n, memo);
}
//3. DP, dp[i] = dp[i-1] + dp[i-2]
int climbDP(const int n) {
    if (n == 1) {
        return 1;
    }
    unique_ptr<int []> dp = make_unique<int[]>(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++ )
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
//4. fibonacci number but with, fib(1) = 1 and fib(2) = 2;
// TC : O(n), SC : O(1)
int ClimbFibonacci(const int n) {
    if (n == 1) {
        return 1;
    }
    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

//5. Binet's Method
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
            //multiplying res and a and storing the result in temp
            multiply(res, a, temp);
            // copy temp -> res
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
int ClimbStairsBinetsMethod(int n) {
    if (n == 0) return 1;

    int q[2][2] = {{1,1},{1,0}};
    int res[2][2];

    matrixPower(q, n, res);
    return res[0][0];
}

//total steps to climb == n, we can either take 1 step or 2 steps at a time
int main() {

}