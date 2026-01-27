#ifndef COC2942_PRIORITY_QUEUE_H
#define COC2942_PRIORITY_QUEUE_H

#include "MaxHeap.h"
#include "MinHeap.h"

class priority_queue {
private:
    MaxHeap* maxHeap;
    MinHeap* minHeap;
    bool isMinQueue;  // true = MinPQ, false = MaxPQ

public:
    // Constructor: choose type
    priority_queue(const int capacity, bool useMinHeap = false) {
        isMinQueue = useMinHeap;

        if (isMinQueue) {
            minHeap = new MinHeap(capacity);
            maxHeap = nullptr;
        } else {
            maxHeap = new MaxHeap(capacity);
            minHeap = nullptr;
        }
    }

    ~priority_queue() {
        delete maxHeap;
        delete minHeap;
    }

    // Insert element
    void push(const int value) const {
        if (isMinQueue)
            minHeap->insert(value);
        else
            maxHeap->insert(value);
    }

    // Remove the highest priority element
    void pop() const {
        if (isMinQueue)
            minHeap->delRoot();
        else
            maxHeap->delRoot();
    }

    // View the highest priority element
    int top() const {
        if (isMinQueue)
            return minHeap->peek();
        else
            return maxHeap->peek();
    }

    bool empty() const {
        if (isMinQueue)
            return minHeap->isEmpty();
        else
            return maxHeap->isEmpty();
    }

    int size() const {
        if (isMinQueue)
            return minHeap->getSize();
        else
            return maxHeap->getSize();
    }
};

#endif
