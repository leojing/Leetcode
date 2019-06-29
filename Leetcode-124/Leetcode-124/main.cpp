//
//  main.cpp
//  Leetcode-124
//
//  Created by JINGLUO on 27/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

int maxSum = INT_MIN;

int helper(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    // 这里就是常规的根据root，left，right，寻找最大值
    int sum = root->val;
    int left = helper(root->left);
    int right = helper(root->right);
    if (left > 0) {
        sum += left;
    }
    if (right > 0) {
        sum += right;
    }
    maxSum = std::max(maxSum, sum);
    
    // tricky thing is here，so smart
    // 因为是寻找path，所以其实并不是像寻找subtree一样，左右两边都可以作为答案返回，
    // 只可取root+left和root，root+right和root中的最大值，这样就是变相的取得了path，而不是subtree
    int t = std::max(left, right);
    if (t > 0) {
        return root->val + t;
    }
    return root->val;
}

int maxPathSum(TreeNode* root) {
    helper(root);
    return maxSum;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(-5);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;

    std::cout << maxPathSum(root) << "\n";
    return 0;
}



/*
 ###算法
 DFS, 遍历binary tree
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方

 ###时空复杂度分析
 Time O(n)
 Space O(1)
 
 ###相关题目
 Leetcode 687. Longest Univalue Path
 */

