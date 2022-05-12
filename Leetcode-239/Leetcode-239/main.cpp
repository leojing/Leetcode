//
//  main.cpp
//  Leetcode-239
//
//  Created by Jing Luo on 5/9/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void removeFromPQ(priority_queue<int>& pq, int num) {
    int top = pq.top();
    if (top == num) {
        pq.pop();
        return;
    }
    pq.pop();
    int second = pq.top();
    if (second == num) {
        pq.pop();
    } else {
        pq.push(top);
    }
}

void addToPQ(priority_queue<int>& pq, int num) {
    if (pq.size() < 2) {
        pq.push(num);
    } else {
        int top = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop(); 
        pq.push(top);
        if (num < second) {
            pq.push(second);
        } else {
            pq.push(num);
        }
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<int> pq;
    for (int i = 0; i < k; i ++) {
        addToPQ(pq, nums[i]);
    }
    result.emplace_back(pq.top());
    for (int i = k; i < nums.size(); i ++) {
        removeFromPQ(pq, nums[i-k]);
        addToPQ(pq, nums[i]);
        result.emplace_back(pq.top());
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
