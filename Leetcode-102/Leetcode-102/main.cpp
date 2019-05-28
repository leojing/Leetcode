//
//  main.cpp
//  Leetcode-102
//
//  Created by JINGLUO on 28/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>();
    std::queue<TreeNode*> queue = std::queue<TreeNode*>();
    std::vector<int> levelNodes = std::vector<int>();

    if (root == NULL) {
        return result;
    }
    queue.push(root);
    while (!queue.empty()) {
        int size = int(queue.size());
        while (size--) {
            TreeNode *first = queue.front();
            levelNodes.push_back(first->val);
            if (first->left != NULL) {
                queue.push(first->left);
            }
            if (first->right != NULL) {
                queue.push(first->right);
            }
            queue.pop();
            if (size == 0) {
                result.push_back(levelNodes);
                levelNodes = std::vector<int>();
            }
        }
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

    std::vector<std::vector<int>> result = levelOrder(root);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 利用queue先进先出的特性，模拟分层，并取值, time complexity is O(n) as we use extra space O(n/2)-[the maximum number of nodes we push to queue at a given depth is the total number nodes/2] which can to help reduce the time
 */
