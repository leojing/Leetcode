//
//  main.cpp
//  Leetcode-94
//
//  Created by JINGLUO on 28/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result = std::vector<int>();
    // edge case判断
    if (root == NULL) {
        return result;
    }
    if (root->left == NULL && root->right == NULL) {
        result.push_back(root->val);
        return result;
    }
    
    // Divide Conquer
    std::vector<int> left = inorderTraversal(root->left);
    for (int i = 0; i < left.size(); i ++) {
        // Merge
        result.push_back(left[i]);
    }
    
    // Merge
    result.push_back(root->val);
    
    // Divide Conquer
    std::vector<int> right = inorderTraversal(root->right);
    for (int i = 0; i < right.size(); i ++) {
        // Merge
        result.push_back(right[i]);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(8);
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(10);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(14);
    TreeNode* node8 = new TreeNode(13);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node4->left = node5;
    node4->right = node6;
    
    node2->right = node7;
    
    node7->left = node8;
    
    std::vector<int> result = inorderTraversal(root);
    return 0;
}


/*
 二叉树上的递归 Recursion in Binary Tree
 • 遍历法 Traverse
 • 分治法 Divide Conquer
 
 本题使用分治法，大部分Binary Tree问题都可以使用分治法，能用分治解决的，不一定能用Traverse解决，所以一般首选分治
 
 Time complexity is O(nLog(n))
 */
