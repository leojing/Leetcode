//
//  main.cpp
//  Leetcode-2
//
//  Created by JINGLUO on 1/5/19.
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int t = 0;
    // Alloc method 1
//    ListNode result(-1);
//    ListNode* current = &result;
    // Alloc method 2
    ListNode* result = new ListNode(-1);
    ListNode* current = result;
    while (l1 || l2 || t) {
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (t) {
            sum += t;
            t = 0;
        }
        t = sum / 10;
        sum = sum % 10;
        current->next = new ListNode(sum);
        current = current->next;
        sum = 0;
    }
//    return result.next;
    return result->next;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    
    node4->next = node5;
    node5->next = node6;
    std::cout << addTwoNumbers(node1, node4) << "\n";
    return 0;
}
