//
//  main.cpp
//  Leetcode-133
//
//  Created by Jing Luo on 3/23/22.
//

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/* solution 1: BFS, time: O(n), space: O(n)
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> copyMap;
    unordered_set<Node*> visited;
    stack<Node*> s;
    s.push(node);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        visited.insert(curr);
        
        Node* temp;
        if (copyMap.find(curr) == copyMap.end()) {
            temp = new Node(curr->val);
            copyMap[curr] = temp;
        } else {
            temp = copyMap[curr];
        }
        
        for (auto t: curr->neighbors) {
            if (visited.find(t) == visited.end()) {
                visited.insert(t);
                s.push(t);
            }
            Node* newNode;
            if (copyMap.find(t) == copyMap.end()) {
                newNode = new Node(t->val);
                copyMap[t] = newNode;
            } else {
                newNode = copyMap[t];
            }
            temp->neighbors.push_back(newNode);
        }
    }
    return copyMap[node];
}
 */

// Solution 2: DFS, time: O(n), space: O(n)

Node* helper(Node* node, unordered_map<Node*, Node*>& copyMap, unordered_set<Node*>& visited) {
    if (!node) return node;
    if (visited.find(node) != visited.end()) return copyMap[node];
    
    visited.insert(node);
    
    Node* newNode;
    if (copyMap.find(node) == copyMap.end()) {
        newNode = new Node(node->val);
        copyMap[node] = newNode;
    } else {
        newNode = copyMap[node];
    }
    
    for (auto t: node->neighbors) {
        newNode->neighbors.push_back(helper(t, copyMap, visited));
    }
    return newNode;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> copyMap;
    unordered_set<Node*> visited;
    return helper(node, copyMap, visited);
}


int main(int argc, const char * argv[]) {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    Node* result = cloneGraph(node1);
    std::cout << "\n";
    return 0;
}
