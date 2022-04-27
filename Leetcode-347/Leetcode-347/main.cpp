//
//  main.cpp
//  Leetcode-347
//
//  Created by Jing Luo on 8/11/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
typedef pair<int, int> Num;

struct Cmp {
    bool operator()(const Num& lhs, const Num& rhs) {
       if (lhs.second == rhs.second) {
           return lhs.first < rhs.first;
       }
       return lhs.second > rhs.second;
   }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); // time: O(NLogN)
    priority_queue<Num, vector<Num>, Cmp> q;
    int element = -1;
    int startIndex = -1;
    int count = -1;
    int i = 0;
    // time: O(K) + O((N-k)logK), N-k times for each time takes O(logK) for pop()&push(), adding both path, it taks O(NLogK)
    for (i = 0; i < int(nums.size()); i ++) {
        if (i == 0) {
            element = nums[i];
            startIndex = i;
            count = 1;
        } else {
            if (nums[i] != element) {
                int len = i - startIndex;
                if (count <= k) {
                    count += 1;
                    q.push(Num(element, len));
                } else {
                    Num top = q.top();
                    if (top.second < len) {
                        q.pop();
                        q.push(Num(element, len));
                    }
                }
                element = nums[i];
                startIndex = i;
            }
        }
    }
    // handle for last Num
    int len = i - startIndex;
    if (count <= k) {
        q.push(Num(element, len));
    } else {
        Num top = q.top();
        if (top.second < len) {
            q.pop();
            q.push(Num(element, len));
        }
    }
    // time: O(KLogK), K(elements) times for each time push() need O(LogK)
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.top().first);
        q.pop();
    }
    return result;
}
*/

// time: O(n*logK), priority_queu
// space: O(n)

struct cmp {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second; // priority_queue 需要反过来，因为priority_queue的队首指向vector的结尾，如果想从小到大排，那就要 >
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occ;
    for (auto num: nums) {
        occ[num] ++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto& [num, count]: occ) {
        if (pq.size() == k) {
            if (pq.top().second < count) {
                pq.pop();
                pq.push(make_pair(num, count));
            }
            continue;
        }
        pq.push(make_pair(num, count));
    }
    vector<int> result;
    while (!pq.empty()) {
        result.emplace_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {5,2,5,3,5,3,1,1,3};//{1};//{1,1,2,2,4,3,2,6,4,2,2,6,6,4,1};
    vector<int> result = topKFrequent(nums, 2);
    std::cout << result.size() << "\n";
    return 0;
}


//C++ 中的priority_queue 用的数据结构是Heap
//简单的理解堆，它是在完全二叉树的基础上，要求树中所有的父节点和子节点之间，都要满足既定的排序规则：
//如果排序规则为从大到小排序，则表示堆的完全二叉树中，每个父节点的值都要不小于子节点的值，这种堆通常称为大顶堆；
//如果排序规则为从小到大排序，则表示堆的完全二叉树中，每个父节点的值都要不大于子节点的值，这种堆通常称为小顶堆；
//
//Heap可以用vector 和 deque来存储，vector 和 deque是用来存储元素的容器，而堆Heap是一种数据结构，其本身无法存储数据
