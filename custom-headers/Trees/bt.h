#ifndef COC2942_BT_H
#define COC2942_BT_H

class BTNode {
public :
    int val;
    BTNode* left;
    BTNode* right;
    BTNode(): val(0), left(nullptr), right(nullptr) {}
    BTNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //COC2942_BT_H