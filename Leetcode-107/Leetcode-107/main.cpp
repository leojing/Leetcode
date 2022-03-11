//
//  main.cpp
//  Leetcode-107
//
//  Created by Jing Luo on 3/11/22.
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

void reverse(vector<vector<int>>& result) {
        int start = 0, end = (int)result.size()-1;
        while (start < end) {
            vector<int> temp = result[start];
            result[start] = result[end];
            result[end] = temp;
            start ++;
            end --;
        }
    }
    
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode*> q;
    vector<int> levelNodes;
    int sz = 0;
    q.push(root);
    while( !q.empty() ) {
        sz = (int)q.size();
        while(sz--) {
            TreeNode *curr = q.front();
            q.pop();
            levelNodes.push_back(curr->val);
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        result.push_back(levelNodes);
        levelNodes.clear();
    }
    reverse(result);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> result = levelOrderBottom(root);
    std::cout << result.size() << "\n";
    return 0;
}
