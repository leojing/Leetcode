//
//  main.cpp
//  Leetcode-234
//
//  Created by Jing Luo on 3/20/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMid(ListNode* head) {
    ListNode* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    while (head) {
        ListNode* temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
    }
    return pre;
}

bool isEqual(ListNode* a, ListNode* b) {
    if (!a || !b) return false;
    while (b) { // a will include the mid node, so b is always the smaller one
        if (a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

// time: O(n), space: O(1)
bool isPalindrome(ListNode* head) {
    if (!head->next) return true;
    ListNode* mid = findMid(head);
    ListNode* rightHalf = reverseList(mid->next);
    mid->next = NULL;
    ListNode* leftHalf = head;
    return isEqual(leftHalf, rightHalf);
}

int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
//    node2->next = node3;

    std::cout << isPalindrome(node1) << "\n";
    return 0;
}

/* test case:
 [1]
 [1,1] // 这个数据wrong了，因为找mid的时候如果用slow=head，fast=head，2个数的情况会找到第二个数为中间点，
          那后半段取mid->next的时候就为空了，所以以后找mid都要取fast=head→next;
 [1,2,1]
 [1,2,2,1]
 [1,3,2,1];
*/
