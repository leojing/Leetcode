//
//  main.cpp
//  Leetcode-257
//
//  Created by Jing Luo on 10/7/21.
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

void dfs(TreeNode* root, vector<string>& paths, string path) {
    if (root == NULL) {
        return;
    }
    path += to_string(root->val);
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(path);
        return;
    }
    path += "->";
    // left
    dfs(root->left, paths, path);
    // right
    dfs(root->right, paths, path);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    dfs(root, paths, "");
    return paths;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    root->left = node1;
    vector<string> result = binaryTreePaths(root);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 时间复杂度：O(N^2)，其中 NN 表示节点数目。在深度优先搜索中每个节点会被访问一次且只会被访问一次，每一次会对 path 变量进行拷贝构造，时间代价为 O(N)，故时间复杂度为 O(N^2)。

 空间复杂度：O(N^2)，其中 N 表示节点数目。除答案数组外我们需要考虑递归调用的栈空间。在最坏情况下，当二叉树中每个节点只有一个孩子节点时，即整棵二叉树呈一个链状，此时递归的层数为N，此时每一层的 path 变量的空间代价的总和为 O(\sum_{i = 1}^{N} i) = O(N^2),空间复杂度为 O(N^2)。最好情况下，当二叉树为平衡二叉树时，它的高度为logN，此时空间复杂度为 O((logN)^2)。
 */
