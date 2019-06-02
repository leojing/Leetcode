//
//  main.cpp
//  Leetcode-814
//
//  Created by JINGLUO on 2/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfTree(TreeNode*& root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }
    
    int sum = root->val;
    int left = sumOfTree(root->left);
    if (left == 0) {
        root->left = NULL;
    }
    int right = sumOfTree(root->right);
    if (right == 0) {
        root->right = NULL;
    }
    return sum + left + right;
}

TreeNode* pruneTree(TreeNode* root) {
    int sum = sumOfTree(root);
    if (sum == 0) {
        return NULL;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(0);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(0);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(0);
    TreeNode* node6 = new TreeNode(1);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;

    TreeNode *result = pruneTree(root);
    std::cout << "Hello, World!\n";
    return 0;
}

/*
###算法
divide and conquer
 
###时空复杂度分析
Time O(n)
Space O(1)

###相关题目
leetcode 669
*/
