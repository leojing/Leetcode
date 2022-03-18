//
//  main.cpp
//  Leetcode-141
//
//  Created by Jing Luo on 3/18/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
   if (!head) return false;
   ListNode* slow = head, *fast = head->next;
   while (fast && fast->next) {
       if (slow == fast) {
           return true;
       }
       slow = slow->next;
       fast = fast->next->next;
   }
   return false;
}

int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    std::cout << hasCycle(node1) << "\n";
    return 0;
}
