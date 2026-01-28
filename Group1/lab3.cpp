/**
Problem : given fruits of t types, in a basket of n size , return the fruit present in majority(> n/2)
 * there can be multiple approaches:
 * 1. nested loop search
 * 2. sort and apply sliding window
 * 3. sort and just check whether middle element is occurring greater than n/2 times
 * 4. Boyer-Moore's Voting Algorithm -> Most Optimal
 * 5. Hash Map and linear search(not acceptable since uses extra space)
 */
#include <iostream>
#include "../custom-headers/quick_sort.h"
using namespace std;
//1.
int naive(const int arr[], const int n) {
    if (n == 0)
        return -1;
    const int m = n/2;
    for (int i = 0; i < n; ++i) {
        int curr_count = 0;
        for (int j = 0; j < n; ++j)
            curr_count += (arr[i] == arr[j])? 1:0;

        if (curr_count > m)
            return arr[i];
    }
    cout << "there is no majority element \n";
    return -1;
}
//2.
int sort_and_SW(int *arr, const int n) {
    if (n == 0)
        return -1;
    quicksort(arr, n);
    int k = n/2;
    for (int i = 0; i + k < n; ++i)
        if (arr[i] == arr[i + k])
            return arr[i];
    cout << "there is no majority element \n";
    return -1;
}
//3.
int sort_and_check(int *arr, const int n) {
    if (n == 0)
        return -1;
    quicksort(arr, n);
    int mid = arr[n/2],
        cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (arr[i] == mid)? 1:0;
    }
    if (cnt > n/2)
        return mid;
    cout << "there is no majority element \n";
    return -1;
}
//4. Most Optimal
int VotingAlgorithm(int *arr, const int n) {
    if (n == 0)
        return -1;
    int count = 0;
    int candidate = -1;

    for (int i = 0; i < n; ++i) {
        if (count == 0)
            candidate = arr[i];
        count += (arr[i] == candidate) ? 1 : -1;
    }

    count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] == candidate) count++;

    if (count > n/2)
        return candidate;

    cout << "there is no majority element \n";
    return -1;
}

int main() {
    int n, t;
    cout << "Enter the total number of fruits in the basket : ";
    cin >> n;
    cout << "How many types of fruits : ";
    cin >> t;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter fruit : ";
        cin >> arr[i];
    }
    int majorityElement = VotingAlgorithm(arr, n);
    if (majorityElement != -1)
        cout << majorityElement << " is the majority fruit \n" << endl;
    else
        cout << "There is no fruit in majority\n";
    delete[] arr;
    return 0;
}