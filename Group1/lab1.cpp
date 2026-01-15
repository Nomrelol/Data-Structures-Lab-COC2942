#include<iostream>
using namespace std;

bool binary_search(const int *arr, const int target, const int n, int &index) {
    int left = 0, right = n - 1;
    while (left <= right) {
        if (const int mid = left + (right - left)/2; arr[mid] == target) {
            index = mid;
            return true;
        }else if (target > arr[mid]) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return false;
}
//partition function pushes the pivot chosen to its correct place
//as it would be in the sorted array
//and returns the index of the correct place.
int partition(int *arr, const int left, const int right) {
    const int pivot = arr[left];
    int i = left, j = right;

    while (i < j) {
        while (arr[i] <= pivot && i <= right - 1) {
            ++i;
        }
        while (arr[j] > pivot && j >= left + 1) {
            --j;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    return j;
}

// QuickSort function
void quick_sort_helper(int *arr, const int left, const int right){
    if (left < right) {
        const int partition_index = partition(arr, left, right);
        quick_sort_helper(arr, left, partition_index - 1);
        quick_sort_helper(arr, partition_index + 1, right);
    }
}

void quicksort(int *arr, const int n) {
    quick_sort_helper(arr, 0, n - 1);
}
//sort an array and search for an element
int main() {

    int n, target;
    std::cout << "Enter the size of the array : " << '\n';
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, n);
    cout << "\nArray after sorting \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n Enter the element to search for : ";
    cin >> target;
    int found_index = -1;
    if (binary_search(arr, target, n, found_index)) {
        cout << target << " is present in the sorted array at index " << found_index << '\n';
    }else {
        cout << target << " is not present in the array \n";
    }
}