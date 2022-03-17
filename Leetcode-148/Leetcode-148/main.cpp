//
//  main.cpp
//  Leetcode-148
//
//  Created by JINGLUO on 14/5/19.
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

/* Solution 1:
// Insertion Sort, same as 147, 插入排序在实现上in-place排序（即只需用到O(1)的额外空间的排序, 平均来说插入排序算法复杂度为O(n^{2})。因而，插入排序不适合对于数据量比较大的排序应用, 在STL的sort算法和stdlib的qsort算法中，都将插入排序作为快速排序的补充，用于少量元素的排序（通常为8个或以下）。
 //
ListNode* sortList(ListNode* head) {
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
*/

// Solution 2:
// Merge Sort, time complexcity is O(nLogN), 这个是符合本题的正解
//

ListNode *mergeNode(ListNode *a, ListNode *b) {
    ListNode *result = new ListNode(-1);
    ListNode *current = result;
    while (a && b) {
        if (a->val < b->val) {
            current->next = a;
            current = current->next;
            a = a->next;
        } else {
            current->next = b;
            current = current->next;
            b = b->next;
        }
    }
    if (a == NULL) {
        current->next = b;
    } else if (b == NULL) {
        current->next = a;
    }
    return result->next;
}

// 也可以用递归去merge
ListNode* mergeList(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val < b->val) {
        a->next = mergeList(a->next, b);
        return a;
    } else {
        b->next = mergeList(a, b->next);
        return b;
    }
}

ListNode* sortList(ListNode* head) {
    if (!head || head->next == NULL) {
        return head;
    }
    ListNode *fast = head, *slow = head;
    if (head->next->next == NULL) { // 2个数的情况要单独处理，直接merge
        fast = head->next;
        slow = head;
        slow->next = NULL;
        return mergeNode(slow, fast);
    }
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    slow = head;
    return mergeNode(sortList(slow), sortList(fast));
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    ListNode *result = sortList(node1);
    std::cout << result << "\n";
    return 0;
}

