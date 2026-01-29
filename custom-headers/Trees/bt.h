#ifndef COC2942_BT_H
#define COC2942_BT_H

class Tree {
public :
    int val;
    Tree* left;
    Tree* right;
    Tree(): val(0), left(nullptr), right(nullptr) {}
    Tree(const int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //COC2942_BT_H