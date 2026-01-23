#ifndef COC2942_LINKED_LIST_H
#define COC2942_LINKED_LIST_H
constexpr int INF = -2147483648;
template<typename T>
class ListNode {
public:
    T val;
    ListNode<T> *next;

    ListNode(T val) : val(val), next(nullptr) {}
    ListNode() : val(INF), next(nullptr) {}
    void add_node() {
        ListNode<T> *temp = new ListNode<T>;
        temp->next = nullptr;
        temp->val = INF;
        this->next = temp;
    }
};

#endif //COC2942_LINKED_LIST_H