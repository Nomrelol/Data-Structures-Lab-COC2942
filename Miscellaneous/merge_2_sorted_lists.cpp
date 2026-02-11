#include <iostream>
using namespace std;

/* Node Definition */
class Node{
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

/* Create New Node */
Node* createNode(int x)
{
    auto n = new Node();
    n->data = x;
    n->next = nullptr;
    return n;
}

/* Insert at End */
Node* insert(Node* head, int x)
{
    Node* n = createNode(x);

    if (head == nullptr)
        return n;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;

    return head;
}

/* Merge Two Sorted Lists */
Node* mergeSorted(Node* L1, Node* L2)
{
    // If one list is empty
    if (L1 == nullptr)
        return L2;

    if (L2 == nullptr)
        return L1;

    Node* head = nullptr;   // head of merged list
    Node* tail = nullptr;   // last node

    /* Initialize head */
    if (L1->data <= L2->data)
    {
        head = L1;
        L1 = L1->next;
    }
    else
    {
        head = L2;
        L2 = L2->next;
    }

    tail = head;

    /* Merge */
    while (L1 != nullptr && L2 != nullptr)
    {
        if (L1->data <= L2->data)
        {
            tail->next = L1;
            L1 = L1->next;
        }
        else
        {
            tail->next = L2;
            L2 = L2->next;
        }

        tail = tail->next;
    }

    /* Attach remaining */
    if (L1 != nullptr)
        tail->next = L1;
    else
        tail->next = L2;

    return head;
}

/* Print List */
void printList(const Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

/* Main */
int main()
{
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    // List1: 1 3 5 7
    L1 = insert(L1, 1);
    L1 = insert(L1, 3);
    L1 = insert(L1, 5);
    L1 = insert(L1, 7);

    // List2: 2 4 6 8
    L2 = insert(L2, 2);
    L2 = insert(L2, 4);
    L2 = insert(L2, 6);
    L2 = insert(L2, 8);

    cout << "List 1:\n";
    printList(L1);

    cout << "List 2:\n";
    printList(L2);

    Node* merged = mergeSorted(L1, L2);

    cout << "Merged List:\n";
    printList(merged);

    return 0;
}