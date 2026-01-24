#ifndef COC2942_STACK_H
#define COC2942_STACK_H
#include <iostream>
#include "Linked_List.h"
class Stack {
    ListNode<int>* top;
    int size = 0;
public:
    Stack() {
        top = NULL;
    }
    ~Stack() {
        while (top != NULL) {
            const ListNode<int>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const int value) {
        auto newNode = new ListNode<int>();
        newNode->val = value;
        newNode->next = top;
        top = newNode;
        size++;
        std::cout << value << " pushed to the stack \n";
    }
    int pop() {
        if (top == NULL) {
            std::cout << "Stack Underflow" << '\n';
            return INF;
        }
        const ListNode<int> *temp = top;
        const int value = top->val;
        std::cout << value << " popped from the stack \n";
        top = top->next;
        delete temp;
        size--;
        return value;
    }
    int Size() const{
        return size;
    }
    int Top() const{
        if (top == NULL) {
            std::cout << "\nStack is empty\n";
            return INF;
        }
        return top->val;
    }
    bool isEmpty() const {
        return top == NULL;
    }
    void printStack() const {
        if (top == NULL) {
            std::cout << "\nStack is empty \n";
            return;
        }
        const ListNode<int> *temp = top;
        std::cout << "Stack Elements \n";
        while (temp != NULL) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};


#endif //COC2942_STACK_H