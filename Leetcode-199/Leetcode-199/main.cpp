//
//  main.cpp
//  Leetcode-199
//
//  Created by Jing Luo on 6/14/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BFS, 二叉树的层遍历的变形，每一层从右往左放node，只需要将每一层第一个node放入result即可
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode*> q;
    int sz = 0;
    q.push(root);
    while( !q.empty() ) {
        sz = q.size();
        result.push_back(q.front()->val);
        while(sz--) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->right) {
                q.push(curr->right);
            }
            if (curr->left) {
                q.push(curr->left);
            }
        }
    }
    return result;
}*/

void helper(TreeNode* root, int level, vector<int>& res) {
    if (!root) {
        return;
    }
    if (res.size() == level) { // key point, smart 每一层只有当size等于level时即该层的第一个node，才放入res，一旦放入，该层之后的node就不会满足==的条件了
        res.emplace_back(root->val);
    }
    helper(root->right, level+1, res);
    helper(root->left, level+1, res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    helper(root, 0, res);
    return res;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    root->left = node1;
    node1->right = node2;
    std::cout << rightSideView(root).size() << "\n";
    return 0;
}


// time: O(n)
