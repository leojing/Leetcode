//
//  main.cpp
//  Leetcode-129
//
//  Created by JINGLUO on 29/6/19.
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

int caculateSum(std::vector<int> &path) {
    long base = 1; // 注意int的话极端数据无法过，要用long
    int sum = 0;
    int i, j;
    for (i = 0; i < int(path.size()); i ++) {  // [0,0,0,0,0,0,0,0,0,0,0,2,5,2], 对于这种前面很多0的数据，要先把前面的0去掉，不然后面base *= 10会越界，即使使用long，因为0本来就是无用功，不如先去掉再计算
        if (path[i] != 0) {
            break;
        }
    }
    for (j = int(path.size()) - 1; j >= i; j --) {
        sum += path[j] * base;
        base *= 10;
    }
    return sum;
}

// 这里是普通的找到所有path
void helper(TreeNode* root, int *sum, std::vector<int> &path) {
    path.push_back(root->val);
    
    if (root->left == NULL && root->right == NULL) {
        *sum += caculateSum(path);
        return;
    }
    if (root->left != NULL) {
        helper(root->left, sum, path);
        path.pop_back();
    }
    
    if (root->right != NULL) {
        helper(root->right, sum, path);
        path.pop_back();
    }
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    if (root == NULL) {
        return sum;
    }
    std::vector<int> path;
    helper(root, &sum, path);
    return sum;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    std::cout << sumNumbers(root) << "\n";
    return 0;
}


// [2,1,null,4,null,7,null,4,null,8,null,3,null,6,null,4,null,7] INT_MAX, 所以要用long计算base

/*
###算法
用Recursion实现的traversal遍历+backtracking

###代码实现
***有什么要注意的地方
参考注释代码
***有什么要优化的地方

###时空复杂度分析
Time O(n)
Space O(n)

###相关题目
Leetcode 988. Smallest String Starting From Leaf
*/
