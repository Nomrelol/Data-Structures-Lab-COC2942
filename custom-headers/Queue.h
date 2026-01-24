#ifndef COC2942_QUEUE_H
#define COC2942_QUEUE_H
#include <iostream>
#include "Linked_List.h"

class Queue {
    ListNode<int> *front;
    ListNode<int> *rear;
    int count;
public:
    Queue(): front(nullptr), rear(nullptr), count(0) {}
    ~Queue() {
        while (not isEmpty()) {
            dequeue();
        }
    }
    //add element to rear end
    void enqueue(int x) {
        auto *newNode = new ListNode<int>(x);
        ///if queue becoems empty, both front and rear point to new node
        if (isEmpty()) {
            front = rear = newNode;
        }else {
            //add newnode at the end and updtae rear
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
        std::cout << "Enqueued: " << x << '\n';
    }
    //delete element from front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow! Queue is Empty.\n";
            return INF;
        }
        const ListNode<int> *temp = front;
        const int value = front->val;
        //move front to next node
        front = front->next;
        //if queue becomes empty, update rear as well
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        --count;
        return value;
    }
    int top() const {
        if (isEmpty()) {
            std::cout << "queue is empty!! " <<'\n';
            return INF;
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
            std::cout << "Queue is empty!! " << '\n';
            return;
        }
        std::cout << "Queue elements (front to rear): ";
        const ListNode<int> *temp = front;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};

#endif //COC2942_QUEUE_H