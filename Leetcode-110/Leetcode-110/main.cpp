//
//  main.cpp
//  Leetcode-110
//
//  Created by Jing Luo on 3/8/22.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool result = true;
    
int helper(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left = helper(root->left) + 1;
    int right = helper(root->right) + 1;
    if (abs(left - right) > 1) {
        result = false;
    }
    return max(left, right);
}

bool isBalanced(TreeNode* root) {
    int level = helper(root);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    std::cout << isBalanced(root) << "\n";
    return 0;
}
