//
//  main.cpp
//  Leetcode-450
//
//  Created by Jing Luo on 4/13/22.
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

/* Solution 1: 替换成最小值
// time: O(height of tree), space: O(1)
int getMin(TreeNode* root) {
    if (root->left == NULL) return root->val;
    return getMin(root->left);
}
    
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (root->val == key) {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        int min = getMin(root->right);
        root->val = min;
        root->right = deleteNode(root->right, min);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}*/

// Solution 2: 将左子树拼接到右子树的最小点的左边，这样也肯定能保证符合BST的特性
// time: O(height of tree), space: O(1)
TreeNode* getMin(TreeNode* root) {
    if (root->left == NULL) return root;
    return getMin(root->left);
}
    
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (root->val == key) {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        TreeNode* min = getMin(root->right);
        min->left = root->left;
        root = root->right;
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
