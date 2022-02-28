//
//  main.cpp
//  Leetcode-19
//
//  Created by Jing Luo on 2/28/22.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Solution 1: time: O(n), space: O(n)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    stack<ListNode*> nodes;
    ListNode* temp = dummy;
    while(temp) {
        nodes.push(temp);
        temp = temp->next;
    }
    while (n--) {
        nodes.pop();
    }
    temp = nodes.top();
    temp->next = temp->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
 }*/

// Solution 2: 快慢指针，让快指针提前跑n步，当快指针到达结尾时，此时慢指针的位置即为要删节点的前一个节点。
// time: O(n), space: O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = head;
    ListNode* slow = head;
    while (n--) {
        fast = fast->next;
    }
    if (!fast) {
        dummy->next = dummy->next->next;
        return dummy->next;
    }
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
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

    ListNode* result = removeNthFromEnd(head, 5);
    std::cout << "\n";
    return 0;
}
