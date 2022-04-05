//
//  main.cpp
//  Leetcode-95
//
//  Created by Jing Luo on 4/5/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> helper(int start, int end) {
    if (start == end) {
        TreeNode* root = new TreeNode(start);
        return {root};
    }
    if (start > end) {
        return {NULL};
    }
    vector<TreeNode*> result;
    for (int i = start; i <= end; i ++) {
        TreeNode* root = new TreeNode(i);
        vector<TreeNode*> leftNodes = helper(start, i-1);
        vector<TreeNode*> rightNodes = helper(i+1, end);
        for (int j = 0; j < leftNodes.size(); j ++) {
            for (int k = 0; k < rightNodes.size(); k ++) {
                root->left = leftNodes[j];
                root->right = rightNodes[k];
                result.emplace_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);
}

int main(int argc, const char * argv[]) {
    vector<TreeNode*> result = generateTrees(3);
    std::cout << "\n";
    return 0;
}


/*
 关键点是找到所有可能的左右子节点的数组，然后排列组合
 time: O(C0+C1+...Cn), Ci表示卡特兰数
 Catalan number，初始值：f(0) = f(1) = 1
 递推公式：f(n) = f(0) * f(n - 1) + f(1) * f(n - 2) + …… + f(n - 1) * f(0)
 
 space: O(n*Cn)
 */
