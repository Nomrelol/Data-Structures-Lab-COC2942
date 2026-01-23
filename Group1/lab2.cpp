#include <iosfwd>
#include <iostream>
#include "../custom-headers/Linked_List.h"
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr ll LINF = 1e18;

//Implement stack using Linked List
class Stack {
    ListNode<int>* top;
    int size = 0;
public:
    Stack() {
        top = NULL;
    }
    ~Stack() {
        while (top != NULL) {
            pop();
        }
    }

    void push(const int value) {
        auto newNode = new ListNode<int>();
        newNode->val = value;
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed to the stack \n";
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << '\n';
            return ;
        }
        const ListNode<int> *temp = top;
        cout << top->val << " popped from the stack \n";
        top = top->next;
        delete temp;
        size--;
    }
    int Size() const{
        return size;
    }
    int Top() const{
        if (top == NULL) {
            cout << "\nStack is empty\n";
            return -1;
        }
        return top->val;
    }

    void printStack() const {
        if (top == NULL) {
            cout << "\nStack is empty \n";
            return;
        }
        ListNode<int> *temp = top;
        cout << "Stack Elements \n";
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};


int main() {
    fastio;
    //take the input of number of test cases if required
    //write your solution here
    Stack s{};
    s.push(10);
    s.push(20);
    s.pop();
    s.printStack();
    s.push(1234565);
    s.push(14);
    cout << s.Top() << '\n';
    s.push(134);
    s.printStack();
    return 0;
}
