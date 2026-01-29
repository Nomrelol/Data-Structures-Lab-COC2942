#ifndef COC2942_BT_H
#define COC2942_BT_H

template<typename T>
class Tree {
public:
    T val;
    Tree* left;
    Tree* right;

    Tree() : val(T{}), left(nullptr), right(nullptr) {}
    Tree(const T& x) : val(x), left(nullptr), right(nullptr) {}
    Tree(const T& x, Tree* l, Tree* r) : val(x), left(l), right(r) {}

    bool isLeaf() const {
        return left == nullptr && right == nullptr;
    }
};

#endif // COC2942_BT_H
