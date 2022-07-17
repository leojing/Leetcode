//
//  main.cpp
//  Leetcode-621
//
//  Created by Jing Luo on 7/17/22.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct Task {
    char name;
    int count;
};

struct Cmp {
    bool operator()(Task* const& t1, Task* const& t2)
    {
        return t1->count < t2->count;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    priority_queue<Task*, vector<Task*>, Cmp> pq;
    stack<Task*> temp;
    unordered_map<char, int> taskCount;
    for (int i = 0; i < tasks.size(); ++ i) {
        taskCount[tasks[i]] ++;
    }
    for (int i = 0; i < 26; ++ i) {
        if (taskCount[i + 'A'] > 0) {
            Task* task = new Task();
            task->name = i + 'A';
            task->count = taskCount[task->name];
            pq.push(task);
        }
    }
    int result = 0;
    int k;
    while (!pq.empty()) {
        k = n+1;
        while (k --) {
            if (pq.empty()) {
                result ++;
                continue;
            }
            Task* top = pq.top();
            top->count --;
            pq.pop();
            if (top->count > 0) {
                temp.push(top);
            }
            result ++;
            if (temp.empty() && pq.empty()) {
                return result;
            }
        }
        while (!temp.empty()) {
            pq.push(temp.top());
            temp.pop();
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<char> tasks = {'A','A','A','B','B','B'};
    std::cout << leastInterval(tasks, 2) << "\n";
    return 0;
}

// time: O(N*Log(T=26)) ~ O(n), log(T)是pq排序需要的时间，但是这里只有26个字母，所以可以约等于O(1)
// space: O(26)
