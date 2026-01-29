#ifndef COC2942_STACK_H
#define COC2942_STACK_H

#include <iostream>
#include "Linked_List.h"

template <typename T>
class Stack {
    ListNode<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (top != nullptr) {
            ListNode<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const T& value) {
        auto* newNode = new ListNode<T>();
        newNode->val = value;
        newNode->next = top;
        top = newNode;
        ++size;

        std::cout << value << " pushed to the stack\n";
    }

    T pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow\n";
            return T{};
        }

        ListNode<T>* temp = top;
        T value = top->val;

        top = top->next;
        delete temp;
        --size;

        std::cout << value << " popped from the stack\n";
        return value;
    }

    int Size() const {
        return size;
    }

    T Top() const {
        if (top == nullptr) {
            std::cout << "Stack is empty\n";
            return T{};
        }
        return top->val;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void printStack() const {
        if (top == nullptr) {
            std::cout << "Stack is empty\n";
            return;
        }

        std::cout << "Stack Elements:\n";
        ListNode<T>* temp = top;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};

#endif // COC2942_STACK_H
