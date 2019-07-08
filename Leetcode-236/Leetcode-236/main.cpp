//
//  main.cpp
//  Leetcode-236
//
//  Created by JINGLUO on 8/7/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ResultType {
public:
    TreeNode *node;
    bool exsit;
    ResultType(TreeNode *node, bool exsit) {
        this->node = node;
        this->exsit = exsit; // 用来记录当前node及他的子节点中是否存在p或者q
    }
};

TreeNode *resultNode = NULL;

ResultType helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return ResultType(root, false);
    }
    
    if (root->left == NULL && root->right == NULL) {
        if (root->val == p->val || root->val == q->val) {
            return ResultType(root, true);
        } else {
            return ResultType(root, false);
        }
    }
    
    ResultType left = helper(root->left, p, q);
    ResultType right = helper(root->right, p, q);
    if ((root->val == p->val || root->val == q->val)) {
        if (left.exsit || right.exsit) {
            resultNode = root; // 记录结果
        }
        return ResultType(root, true);
    }
    
    if (left.exsit && right.exsit) {
        resultNode = root; // 记录结果
        return ResultType(root, true);
    }
    return ResultType(root, left.exsit || right.exsit);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    helper(root, p, q);
    return resultNode;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(6);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(0);
    TreeNode *node6 = new TreeNode(8);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(4);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    node4->left = node7;
    node4->right = node8;

    std::cout << lowestCommonAncestor(root, node1, node2);
    return 0;
}



/*
###算法
递归遍历二叉树

###代码实现
***有什么要注意的地方
参考注释代码
***有什么要优化的地方

###时空复杂度
time O(n)
space O(1)

###相关的题目有哪些
*/

