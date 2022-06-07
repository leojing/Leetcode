//
//  main.cpp
//  Leetcode-543
//
//  Created by Jing Luo on 6/7/22.
//

#include <iostream>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int result = 0;
    
int helper(TreeNode* root, int level) {
    if (!root) {
        return level;
    }
    int left = helper(root->left, level + 1);
    int right = helper(root->right, level + 1);
    int maxLen = max(left, right);
    return maxLen;
}

void traversal(TreeNode* root) {
    if (!root) {
        return;
    }
    int left = helper(root->left, 0);
    int right = helper(root->right, 0);
    result = max(left + right, result);
    
    traversal(root->left);
    traversal(root->right);
}

int diameterOfBinaryTree(TreeNode* root) {
    traversal(root);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    std::cout << diameterOfBinaryTree(root) << "\n";
    return 0;
}

// time: O(n^2), space: O(height), 递归栈的空间
