//
//  main.cpp
//  Leetcode-86
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

ListNode* partition(ListNode* head, int x) {
    ListNode* smallDummy = new ListNode(1);
    ListNode* small = smallDummy;
    ListNode* largeDummy = new ListNode(2);
    ListNode* large = largeDummy;

    while (head) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    large->next = NULL; // 这里是关键，large有可能原来后面还有next，因为large是最后一个了，为了避免指向同一个内存地址造成内存溢出或者什么原因，必须把large->next = NULL
    small->next = largeDummy->next;
    return smallDummy->next;
}

int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    ListNode* result = partition(node1, 3);
    std::cout << "\n";
    return 0;
}
