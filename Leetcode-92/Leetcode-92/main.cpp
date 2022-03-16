//
//  main.cpp
//  Leetcode-92
//
//  Created by Jing Luo on 3/15/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* pre, *dummy = new ListNode(0), *temp;
    dummy->next = head;
    pre = dummy;
    int count = left - 1;
    while (count --) {
        pre = pre->next;
    }
    ListNode* curr = pre->next, *currPre = NULL, *last = curr;
    int dis = right - left + 1;
    while (curr && dis --) {
        temp = curr->next;
        curr->next = currPre;
        currPre = curr;
        curr = temp;
    }
    pre->next = currPre;
    last->next = curr;
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* result = reverseBetween(node1, 2, 4);
    std::cout << "\n";
    return 0;
}
