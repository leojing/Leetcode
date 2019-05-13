//
//  main.cpp
//  Leetcode-147
//
//  Created by JINGLUO on 13/5/19.
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

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *result = new ListNode(head->val);
    head = head->next;
    while (head) {
        ListNode *first = result;
        ListNode *second = first->next;
        ListNode *temp = new ListNode(head->val);
        if (first->val > head->val) {
            temp->next = first;
            result = temp;
            head = head->next;
            continue;
        }
        while (first->val < head->val && second) {
            if (second->val > head->val) {
                break;
            }
            first = first->next;
            second = first->next;
        }
        if (second == NULL) {
            first->next = temp;
        } else {
            temp->next = second;
            first->next = temp;
        }
        head = head->next;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    ListNode *result = insertionSortList(node1);
    std::cout << result << "\n";
    return 0;
}

