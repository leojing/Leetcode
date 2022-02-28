//
//  main.cpp
//  Leetcode-876
//
//  Created by Jing Luo on 2/28/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next == NULL) {
            return slow;
        }
        fast = fast->next;
    }
    return slow;
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* result = middleNode(head);
    std::cout << result->val << "\n";
    return 0;
}
