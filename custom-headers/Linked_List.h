#ifndef COC2942_LINKED_LIST_H
#define COC2942_LINKED_LIST_H
constexpr int INF = -2147483648;
#include <iostream>
/* ================= LIST NODE CLASS ================= */
template<typename T>
class ListNode {
public:
    T val;
    ListNode<T>* next;
    ListNode(T value) : val(value), next(nullptr) {}
};

/* ================= LIST CLASS ================= */
template <typename T>
class List {
private:
    ListNode<T>* head;

public:
    List() : head(nullptr) {}

    // Destructor to prevent memory leaks
    ~List() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Add value at given position (0-based)
    void add(T value, const int position) {
        auto newNode = new ListNode<T>(value);

        if (position <= 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        ListNode<T>* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove first occurrence of value
    void remove(T value) {
        if (head == nullptr) return;

        if (head->val == value) {
            ListNode<T>* del = head;
            head = head->next;
            delete del;
            return;
        }

        ListNode<T>* temp = head;
        while (temp->next != nullptr && temp->next->val != value) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            ListNode<T>* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    // Create list by taking n user inputs
    void create(const int n) {
        for (int i = 0; i < n; i++) {
            T x;
            std::cin >> x;
            add(x, i);
        }
    }
    // Display list
    void display() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    // Helper to support Queue
    T getHeadValue() const {
        if (head == nullptr) return T();
        return head->val;
    }
};

#endif
