//
//  main.cpp
//  Leetcode-337
//
//  Created by Jing Luo on 10/9/20.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode *root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->val;
    }
    int robCurrent = root->val;
    if (root->left) {
        if (root->left->left) {
            robCurrent += helper(root->left->left);
        }
        if (root->left->right) {
            robCurrent += helper(root->left->right);
        }
    }
    if (root->right) {
        if (root->right->left) {
            robCurrent += helper(root->right->left);
        }
        if (root->right->right) {
            robCurrent += helper(root->right->right);
        }
    }
    
    int notRobCurrent = 0;
    if (root->left) {
        notRobCurrent += helper(root->left);
    }
    if (root->right) {
        notRobCurrent += helper(root->right);
    }
    
    return max(robCurrent, notRobCurrent);
}

int rob(TreeNode* root) {
    return helper(root);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(1);

    root->left = node1;
    root->right = node2;
    
    node1->right = node3;
    node2->right = node4;
    std::cout << rob(root) << "\n";
    return 0;
}
