//
//  main.cpp
//  Leetcode-112
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

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        if (root->val == sum) {
            return true;
        }
        return false;
    }
    
    bool left = hasPathSum(root->left, sum - root->val);
    bool right = hasPathSum(root->right, sum - root->val);
    return left || right;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(8);
    TreeNode* node3 = new TreeNode(11);
    TreeNode* node4 = new TreeNode(13);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(2);
    TreeNode* node8 = new TreeNode(1);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    node5->right = node8;
    
    std::cout << hasPathSum(root, 22) << "\n";
    return 0;
}



/*
 ###算法
 用Recursion实现的divide and conquer
 
 ###时空复杂度分析
 Time O(n)
 Space O(1)
 
 ###相关题目
 leetcode 113 437
 */
