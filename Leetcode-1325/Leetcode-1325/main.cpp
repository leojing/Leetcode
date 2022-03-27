//
//  main.cpp
//  Leetcode-1325
//
//  Created by Jing Luo on 3/28/22.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (!root) { return root; }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (!root->left && !root->right && root->val == target) {
            return NULL;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(1);
    root->left = node1;
    node1->right = node2;
    std::cout << removeLeafNodes(root, 1) << "\n";
    return 0;
}
