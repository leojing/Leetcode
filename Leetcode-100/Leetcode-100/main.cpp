//
//  main.cpp
//  Leetcode-100
//
//  Created by Jing Luo on 6/7/22.
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

bool isSameTree(TreeNode* p, TreeNode* q) {
   if (!p && !q) {
       return true;
   }
   if ((!p && q) || (p && !q)) {
       return false;
   }
   if (p->val != q->val) {
       return false;
   }
   bool left = isSameTree(p->left, q->left);
   bool right = isSameTree(p->right, q->right);
   return left && right;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);

    root->left = node1;
    root->right = node2;
    
    node3->left = node4;
    std::cout << isSameTree(root, node3) << "\n";
    return 0;
}
