//
//  main.cpp
//  Leetcode-83
//
//  Created by JINGLUO on 30/4/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *n = head;
    int val;
    while (n && n->next) {
        if (n->val == n->next->val) {
            val = n->val;
            while (n->next && n->next->val == val) {
                n->next = n->next->next;
            }
        } else {
            n = n->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    std::cout << deleteDuplicates(node1) << "\n";
    return 0;
}

/*
 Single-LinkedList:
 此题和Leetcode-82的区别在于，这里需要dummy，tricky
 */
