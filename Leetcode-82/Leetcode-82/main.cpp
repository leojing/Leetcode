//
//  main.cpp
//  Leetcode-82
//
//  Created by JINGLUO on 29/4/19.
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
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *n = dummy;
    int val;
    while (n->next && n->next->next) {
        if (n->next->val == n->next->next->val) {
            val = n->next->val;
            while (n->next && n->next->val == val) {
                n->next = n->next->next;
            }
        } else {
            n = n->next;
        }
    }
    return dummy->next;
}

/*
ListNode* deleteDuplicates(ListNode *head) {
    ListNode *result = new ListNode(-1);
    result->next = head;
    ListNode *curr = result;
    while (curr) {
        bool dup = false;
        ListNode *runner = curr->next;
        while (runner && runner->next) {
            if(runner->val == runner->next->val) {
                runner = runner->next;
                dup = true;
            } else {
                break;
            }
        }
        if (dup) {
            curr->next = runner->next;
        } else {
            curr = curr->next;
        }
    }
    return result->next;
}
 */

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
 此题和Leetcode-83的区别在于，这里需要dummy，tricky
 */
