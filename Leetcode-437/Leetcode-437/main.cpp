//
//  main.cpp
//  Leetcode-437
//
//  Created by Jing Luo on 8/9/20.
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

// 这个方法是查找以node为起点的所有path的可能，需要左边+右边，因为两边都可能有path
int helper(TreeNode *node, int sum) {
    if (node == NULL) {
        return 0;
    }
    int result = 0;
    if (node->val == sum) {
        result += 1;
    }
    result += helper(node->left, sum - node->val);
    result += helper(node->right, sum - node->val);
    return result;
}

int pathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }
    // 这里需要注意的是，不光从root的所有路径和，还要加上以左右节点分别为root的路径和，因为题目中说不一定是root为start，如果是root为start，则不需要加左右的
    return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(10);
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(-3);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(11);
    TreeNode *node6 = new TreeNode(3);
    TreeNode *node7 = new TreeNode(-2);
    TreeNode *node8 = new TreeNode(1);

    root->left = node1;
    root->right = node2;
    
    // test case 1:
    node1->left = node3;
    node1->right = node4;

    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    node4->right = node8;
    
    // test case 2:
//    node1->left = node7;
//    node2->left = node8;
    
    std::cout << pathSum(root, 8) << "\n";
    return 0;
}




/*
 ###算法
 递归recursion
 
 ###代码实现
 ***有什么要注意的地方
 参照代码，已注释
 ***有什么要优化的地方
 
 ###时空复杂度
 time: Worst-case complexity is O(N^2), when the tree is unbalanced, for balanced tree we get O(N*log(N)).
 space: O(1)
 
 ###相关的题目有哪些
 
 */
