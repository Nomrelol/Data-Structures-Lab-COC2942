#ifndef COC2942_QUEUE_H
#define COC2942_QUEUE_H
#include <iostream>
#include "Linked_List.h"

template <typename T>
class Queue {
    ListNode<T>* front;
    ListNode<T>* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Add element to rear end
    void enqueue(const T& x) {
        auto* newNode = new ListNode<T>(x);

        // If queue becomes empty
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        ++count;
        std::cout << "Enqueued: " << x << '\n';
    }

    // Remove element from front
    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow! Queue is empty.\n";
            return T{};
        }

        ListNode<T>* temp = front;
        T value = front->val;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        --count;
        return value;
    }

    T top() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return T{};
        }
        return front->val;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int size() const {
        return count;
    }

    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }

        std::cout << "Queue elements (front to rear): ";
        ListNode<T>* temp = front;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};

#endif // COC2942_QUEUE_H
