//
//  main.cpp
//  Leetcode-113
//
//  Created by JINGLUO on 2/6/19.
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

std::vector<std::vector<int>> result = std::vector<std::vector<int>>();

void helper(TreeNode* root, int sum, std::vector<int>* sumArray) {
    sumArray->push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        if (root->val == sum) {
            result.push_back(*sumArray);
        }
        return;
    }
    
    if (root->left != NULL) {
        helper(root->left, sum - root->val, sumArray);
        sumArray->pop_back();
    }
    
    if (root->right != NULL) {
        helper(root->right, sum - root->val, sumArray);
        sumArray->pop_back();
    }
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
    // NULL 判断 优先k考虑
    if (root == NULL) {
        return result;
    }
    std::vector<int>* sumArray = new std::vector<int>();
    helper(root, sum, sumArray);
    return result;
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
    TreeNode* node8 = new TreeNode(5);
    TreeNode* node9 = new TreeNode(1);
    TreeNode* node10 = new TreeNode(4);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    node5->left = node8;
    node5->right = node9;
    
    node9->right = node10;
    
    std::vector<std::vector<int>> result = pathSum(root, 22);
    return 0;
}


/*
 ###算法
 用Recursion实现的traversal遍历
 
 ###代码实现
 - null判断又忘记了
 -     if (root->left != NULL) {
        helper(root->left, sum - root->val, sumArray);
        sumArray->pop_back();
       }
    这里需要判断不为NULL，再进入helper，否则pop_back()会因为进入了NULL而把之前有用的value给pop掉，一定记得要pop_back()，把没用的value pop出去

 ###时空复杂度分析
 Time O(n)
 Space O(1)
 
 ###相关题目
 leetcode 112 437
 */
