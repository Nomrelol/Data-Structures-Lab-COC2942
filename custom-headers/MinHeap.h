#ifndef COC2942_MINHEAP_H
#define COC2942_MINHEAP_H

class MinHeap {
private:
    int* data;
    int size;
    int capacity;

    static int parent(const int i) { return (i - 1) / 2; }
    static int leftChild(const int i) { return 2 * i + 1; }
    static int rightChild(const int i) { return 2 * i + 2; }

    static void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // MinHeap comparison
    bool compare(int a, int b) {
        return a < b;
    }

    void heapifyUp(int index) {
        while (index > 0 && compare(data[index], data[parent(index)])) {
            swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int best = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && compare(data[left], data[best]))
            best = left;

        if (right < size && compare(data[right], data[best]))
            best = right;

        if (best != index) {
            swap(data[index], data[best]);
            heapifyDown(best);
        }
    }

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~MinHeap() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) return;
        data[size] = value;
        heapifyUp(size);
        size++;
    }

    void delRoot() {
        if (size == 0) return;
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
    }

    int peek() const {
        return (size > 0) ? data[0] : -1;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    int extractMin() {
        int minVal = peek();
        delRoot();
        return minVal;
    }

    void deleteValue(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                data[i] = data[size - 1];
                size--;
                heapifyDown(i);
                heapifyUp(i);
                break;
            }
        }
    }
};

#endif
