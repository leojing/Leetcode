//
//  main.cpp
//  Leetcode-116
//
//  Created by Jing Luo on 3/15/22.
//

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/* Solution 1: BFS
Node* connect(Node* root) {
    // edge case, root为NULL时
    if (!root) {
        return root;
    }
    
    queue<Node*> q;
    int sz;
    q.push(root);
    while (!q.empty()) {
        sz = (int)q.size();
        for (int i = 0; i < sz; i ++) {
            Node* curr = q.front();
            q.pop();
            if (curr->left && curr->right) { // 只有不为NULL才push进去，并且要在下面的continue之前
                q.push(curr->left);
                q.push(curr->right);
            }

            if (i == sz-1) {
                curr->next = NULL;
                continue;
            }
            Node* next = q.front();
            curr->next = next;
        }
    }
    return root;
}*/

void connect(Node* current, Node* next) {
    if (current && next) {
        current->next = next;
        
        connect(current->left, current->right);
        connect(current->right, next->left);
        connect(next->left, next->right);
    }
}
Node* connect(Node* root) {
    if (!root) {
        return root;
    }
    
    connect(root->left, root->right);
    return root;
}

int main(int argc, const char * argv[]) {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    Node* result = connect(node1);
    std::cout << "\n";
    return 0;
}
