//
//  main.cpp
//  Leetcode-143
//
//  Created by Jing Luo on 8/25/20.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void reorderList(ListNode* head) {
    if (head == NULL) {
        return;
    }
    ListNode *mid = findMid(head);
    
    queue<ListNode*> firstHalf;
    stack<ListNode*> secondHalf;
    while (head) {
        if (head == mid) {
            firstHalf.push(head);
            break;
        }
        firstHalf.push(head);
        head = head->next;
    }
    head = mid->next;
    mid->next = NULL;
    while (head) {
        secondHalf.push(head);
        head = head->next;
    }
    while (!secondHalf.empty()) {
        ListNode *first = firstHalf.front();
        ListNode *second = secondHalf.top();
        ListNode *temp = first->next;
        
        first->next = second;
        second->next = temp;
        
        firstHalf.pop();
        secondHalf.pop();
    }
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
    reorderList(node1);
    std::cout << node1 << "\n";
    return 0;
}

/*
 优化方法：找到中间点，将后半部分reverse，将前半部分和反转后的后半部分join，这样space就是O(1)
 
 time: O(n)
 space: O(n)
 */
