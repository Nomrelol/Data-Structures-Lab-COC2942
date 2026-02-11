#include <iostream>
using namespace std;

/* Your Node Class */
class Node{
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

/* Get Length of List */
int getLength(Node* head)
{
    int count = 0;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

/* Find Intersection */
Node* getIntersection(Node* head1, Node* head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    // Align both lists
    if (len1 > len2)
    {
        diff = len1 - len2;

        while (diff--)
            head1 = head1->next;
    }
    else
    {
        diff = len2 - len1;

        while (diff--)
            head2 = head2->next;
    }

    // Move together
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1 == head2)
            return head1;   // intersection found

        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

/* Insert at End */
Node* insert(Node* head, int x)
{
    Node* n = new Node(x);

    if (head == nullptr)
        return n;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;

    return head;
}

/* Print List */
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

/* Main (Demo) */
int main()
{
    // First List: 1->2->3->4->5
    Node* head1 = nullptr;

    head1 = insert(head1, 1);
    head1 = insert(head1, 2);
    head1 = insert(head1, 3);
    head1 = insert(head1, 4);
    head1 = insert(head1, 5);

    // Second List: 9->8->(3->4->5)
    Node* head2 = new Node(9);
    head2->next = new Node(8);

    // Make intersection at node "3"
    Node* temp = head1;

    while (temp->data != 3)
        temp = temp->next;

    head2->next->next = temp;

    cout << "List 1:\n";
    printList(head1);

    cout << "List 2:\n";
    printList(head2);

    Node* inter = getIntersection(head1, head2);

    if (inter != nullptr)
        cout << "Intersection at node with data = " << inter->data;
    else
        cout << "No intersection";
    delete head2;
    return 0;
}