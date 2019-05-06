//
//  main.cpp
//  Leetcode-142
//
//  Created by JINGLUO on 6/5/19.
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

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    std::cout << detectCycle(node1) << "\n";
    return 0;
}
