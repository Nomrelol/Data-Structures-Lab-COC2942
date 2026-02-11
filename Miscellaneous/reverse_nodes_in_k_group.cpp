#include <iostream>
using namespace std;

/* Node Definition */
class Node{
public:
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr) {}
    Node() : data(0), next(nullptr){}
};

/* Create New Node */
Node* createNode(int x)
{
    Node* n = new Node();
    n->data = x;
    n->next = nullptr;
    return n;
}

/* Reverse in K Groups */
Node* reverseKGroup(Node* head, int k)
{
    if (head == nullptr || k <= 1)
        return head;

    // Dummy node
    Node dummy;
    dummy.next = head;

    Node* prevGroup = &dummy;

    while (true)
    {
        /* Check if k nodes exist */
        Node* temp = prevGroup;
        int count = 0;

        while (temp->next != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }

        if (count < k)
            break;

        /* Reverse k nodes */
        Node* curr = prevGroup->next;
        Node* next = nullptr;
        Node* prev = nullptr;

        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        /* Reconnect */
        Node* first = prevGroup->next;

        prevGroup->next = prev;
        first->next = curr;

        prevGroup = first;
    }

    return dummy.next;
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
    Node* head = nullptr;

    for (int i = 1; i <= 8; i++)
        head = insert(head, i);

    cout << "Original:\n";
    printList(head);

    int k = 3;

    head = reverseKGroup(head, k);

    cout << "After Reverse in K Groups:\n";
    printList(head);

    return 0;
}