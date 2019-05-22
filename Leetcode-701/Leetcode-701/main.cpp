//
//  main.cpp
//  Leetcode-701
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

/*
 Too much duplicated codes. Not neat
 
void helper(TreeNode* root, int val) {
    if (root == NULL) {
        return;
    }
    if (val > root->val) {
        if (root->right != NULL) {
            helper(root->right, val);
        } else {
            TreeNode *insertNode = new TreeNode(val);
            root->right = insertNode;
            return;
        }
    } else {
        if (root->left != NULL) {
            helper(root->left, val);
        } else {
            TreeNode *insertNode = new TreeNode(val);
            root->left = insertNode;
            return;
        }
    }
}
*/


// 必须使用指针的引用*&， 才能保证直接赋值给root（might be left node or right node）后，外面的root也被改变
void helper(TreeNode*& root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    }
    if (val > root->val) {
        helper(root->right, val);
    } else {
        helper(root->left, val);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    helper(root, val);
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    std::cout << insertIntoBST(root, 5) << "\n";
    return 0;
}


/*
 指针的引用，指针它也是一个变量，*&就和普通变量的引用一样，也可以理解为指针变量的别名。如LZ的例子之中，int*& a，那么在函数里面对a的值进行改变，那么在调用函数时传入的参数的指针值也会改变   再实际点的例子，LZ的void*& fun(int*& a);调用时，有一个指针int* pointer = NULL;，然后fun(pointer)，在fun里面对a重新赋值，a = &other，那样子外面pointer的值也就变成了&other
 */
 
