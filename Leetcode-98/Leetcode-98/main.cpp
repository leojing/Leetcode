//
//  main.cpp
//  Leetcode-98
//
//  Created by JINGLUO on 20/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long min, long max) {
    if (root == NULL) {
        return true;
    }
    if (root->val > min && root->val < max) {
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    return false;
}

bool isValidBST(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isValidBST(root->left, LONG_MIN, root->val) && isValidBST(root->right, root->val, LONG_MAX);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(0);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    node4->right = node7;

    node2->left = node5;
    node2->right = node6;

    std::cout << isValidBST(root) << "\n";
    return 0;
}


/* Solution:
 Binary Search Tree的另一个重要定义，就是
 
 左边所有的孩子的大小一定要比root.val小
 右边所有的孩子的大小一定要比root.val大
 
 不光光是当前left < root, right > root, 要保证所有left的孩子都小于root，所有right的孩子都大于root
 所以，本题不需要单独去判断root->val > root->left->val && root->val < root->right->val, 只需要保证每一层的root都在min-max这个区间内，就是变相进行左右子节点的大小判断。
 
 */
