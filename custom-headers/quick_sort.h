#ifndef COC2942_QUICK_SORT_H
#define COC2942_QUICK_SORT_H

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
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

#endif //COC2942_QUICK_SORT_H