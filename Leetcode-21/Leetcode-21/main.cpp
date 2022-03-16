//
//  main.cpp
//  Leetcode-21
//
//  Created by Jing Luo on 3/16/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution 1: 迭代， time: O(n+m), space: O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* curr = new ListNode(1), *result = curr;
    while (list1 && list2) {
        if (list1->val > list2->val) {
            curr->next = list2;
            list2 = list2->next;
        } else {
            curr->next = list1;
            list1 = list1->next;
        }
        curr = curr->next;
    }
    if (list1) {
        curr->next = list1;
    }
    if (list2) {
        curr->next = list2;
    }
    return result->next;
}*/

// Solution 2: 递归, time: O(n+m), space: O(n+m) 递归func的stack memory
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(13);
    ListNode* node2 = new ListNode(7);
    ListNode* node3 = new ListNode(8);
    node1->next = node2;
    node2->next = node3;
    
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    node4->next = node5;
    node5->next = node6;

    ListNode* result = mergeTwoLists(node1, node2);
    std::cout << "\n";
    return 0;
}
