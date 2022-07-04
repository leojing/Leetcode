//
//  main.cpp
//  Leetcode-230
//
//  Created by Jing Luo on 7/4/22.
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<TreeNode*, tuple<int, int>> nodeCount;

int helper(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        nodeCount[root] = make_tuple(0, 0);
        return 1;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    nodeCount[root] = make_tuple(left, right);
    return left + right + 1;
}

int kthHelper(TreeNode* root, int k) {
    int left = get<0>(nodeCount[root]);
    if (left == k - 1) {
        return root->val;
    }
    if (left > k - 1) {
        return kthHelper(root->left, k);
    }
    return kthHelper(root->right, k - 1 - left);
}

int kthSmallest(TreeNode* root, int k) {
    helper(root);
    return kthHelper(root, k);
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(2);
    
    root->left = node1;
    root->right = node2;
    node1->right = node3;

    std::cout << kthSmallest(root, 1) << "\n";
    return 0;
}


// time: O(n) 遍历整颗树得到每个点的左右子节点个数，O(h)去查找第k个数
// space: O(n)
