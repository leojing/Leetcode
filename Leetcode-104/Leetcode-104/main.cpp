//
//  main.cpp
//  Leetcode-104
//
//  Created by Jing Luo on 3/8/22.
//

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int level) {
    if (root == NULL) {
        return level;
    }
    int left = helper(root->left, level+1);
    int right = helper(root->right, level+1);
    return max(left, right);
}

int maxDepth(TreeNode* root) {
    return helper(root, 0);
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    std::cout << maxDepth(root) << "\n";
    return 0;
}
