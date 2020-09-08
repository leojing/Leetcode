//
//  main.cpp
//  Leetcode-1022
//
//  Created by Jing Luo on 9/8/20.
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

int binaryToDecimal(string s) {
    int len = int(s.size());
    int result = 0;
    int k = 1;
    for (int i = len - 1; i >= 0; i --) {
        result += (s[i] - '0') * k;
        k *= 2;
    }
    return result;
}

int sum = 0;

void helper(TreeNode* root, string s) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        s += root->val + '0';
        sum += binaryToDecimal(s);
        return;
    }
    char temp = root->val + '0';
    helper(root->left, s + temp);
    helper(root->right, s + temp);
}

int sumRootToLeaf(TreeNode* root) {
    string s = "";
    helper(root, s);
    return sum;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(0);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(0);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(0);
    TreeNode *node6 = new TreeNode(1);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    std::cout << sumRootToLeaf(root) << "\n";
    return 0;
}


/*
Time O(N)
Space O(H) for recursion
*/
