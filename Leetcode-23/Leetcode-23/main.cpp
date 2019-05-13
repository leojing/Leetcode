//
//  main.cpp
//  Leetcode-23
//
//  Created by JINGLUO on 7/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <queue>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Solution1: priority_queue: http://x-wei.github.io/heap-summary.html 不管是插入还是删除操作, 每次调整的复杂度为log(n) (堆的高度), 所以算法复杂度为 O(NlgN). 实际使用的时候效率比快速排序/合并排序略差, 以后专门写一篇关于排序算法的文章时再聊.
// Time Complex: O(n2)
// Memory Complex: O(totle Nodes)

struct cmp
{
    bool operator()(ListNode* lhs, ListNode* rhs)
    {
        return lhs->val > rhs->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode *result = new ListNode(-1);
    std::priority_queue<ListNode *, std::vector<ListNode*>, cmp> pq;
    for (int i = 0; i < lists.size(); i ++) {
        ListNode *node = lists[i];
        while (node) {
            pq.push(node);
            node = node->next;
        }
    }
    ListNode *current = result;
    while (!pq.empty()) {
        current->next = pq.top();
        current = pq.top();
        pq.pop();
    }
    current->next = NULL;
    return result->next;
}

/************** BEST ****************/
/* Solution2: Merge sort
// Time Complex: O(nLogn)
// Memory Complex: O(1)
 
ListNode* merge(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    
    if(l1->val < l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }else{
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode* partition(std::vector<ListNode*>& lists, int start, int end){
    if(start == end){
        return lists[start];
    }
    
    if(start < end){
        int mid = (end+start)/2;
        
        ListNode* l1 = partition(lists, start, mid);
        ListNode* l2 = partition(lists, mid+1, end);
        return merge(l1, l2);
    }
    
    return NULL;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    return partition(lists, 0, lists.size()-1);
}
*/

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    
    ListNode *node4 = new ListNode(1);
    ListNode *node5 = new ListNode(3);
    ListNode *node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;

    ListNode *node7 = new ListNode(2);
    ListNode *node8 = new ListNode(6);
    node7->next = node8;
    
    std::vector<ListNode *> lists = {node1, node4, node7};
    ListNode *result = mergeKLists(lists);
    std::cout << result << "\n";
    return 0;
}
