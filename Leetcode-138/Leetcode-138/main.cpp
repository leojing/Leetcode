//
//  main.cpp
//  Leetcode-138
//
//  Created by Jing Luo on 3/20/22.
//

#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;
    
    Node* curr = head;
    // copy node and pointer next to original node, 1-1'-2-2'-3-3'
    while (curr) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        Node* temp = curr->next;
        curr->next = newNode;
        curr = temp;
    }
    
    // copy random nodes
    curr = head;
    while (curr && curr->next) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // split copy nodes from original one
    curr = head;
    Node* cloneHead = curr->next;
    while (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        curr = temp;
    }
    return cloneHead;
}

int main(int argc, const char * argv[]) {
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;
    
    Node* result = copyRandomList(node1);
    std::cout << "\n";
    return 0;
}
