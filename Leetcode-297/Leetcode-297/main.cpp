//
//  main.cpp
//  Leetcode-297
//
//  Created by Jing Luo on 6/21/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serializeHelper(TreeNode* root, string& res) {
    if (!root) {
        res += "*$";
        return;
    }
    res += to_string(root->val) + "$";
    serializeHelper(root->left, res);
    serializeHelper(root->right, res);
}

string serialize(TreeNode* root) {
    string res = "";
    serializeHelper(root, res);
    return res;
}

int i = 0;

TreeNode* deserializeHelper(vector<string>& nodes) {
    if (nodes[i] == "*" || i == nodes.size()) {
        return NULL;
    }
    TreeNode* node = new TreeNode(stoi(nodes[i]));
    i += 1;
    node->left = deserializeHelper(nodes);
    i += 1;
    node->right = deserializeHelper(nodes);
    return node;
}

vector<string> parseFromString(string data) {
    vector<string> res;
    string temp = "";
    for (int i = 0; i < data.size(); i ++) {
        if (data[i] == '$') {
            res.emplace_back(temp);
            temp = "";
            continue;
        }
        temp += data[i];
    }
    return res;
}

TreeNode* deserialize(string data) {
    vector<string> nodes = parseFromString(data);
    return deserializeHelper(nodes);
}

    
int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    
    node3->left = node4;
    node3->right = node5;
    
    string result = serialize(node1);
    std::cout << result << "\n";
    
    TreeNode* root = deserialize(result);
    
    return 0;
}
