//
//  main.cpp
//  Leetcode-25
//
//  Created by Jing Luo on 6/8/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void helper(ListNode* head, ListNode* curr, int k, int currRound, int round) {
    if (currRound >= round) {
        head->next = curr;
        return;
    }
    ListNode* nextHead = curr;
    ListNode* pre = NULL;
    int tempK = k;
    while (tempK --) {
        ListNode* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    head->next = pre;
    helper(nextHead, curr, k, currRound + 1, round);
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    ListNode* temp = head;
    while (temp) {
        temp = temp->next;
        ++ n;
    }
    int round = n / k;
    ListNode* dummy = new ListNode(0);
    helper(dummy, head, k, 0, round);
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

    std::cout << reverseKGroup(node1, 2) << "\n";
    return 0;
}

// time: O(n), space: O(n/k), recursion memory space
