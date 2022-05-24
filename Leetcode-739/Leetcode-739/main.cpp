//
//  main.cpp
//  Leetcode-739
//
//  Created by Jing Luo on 5/22/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
typedef pair<int, int> Temp;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<Temp> stk;
    int n = temperatures.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; i ++) {
        Temp curr = make_pair(i, temperatures[i]);
        while (!stk.empty() && stk.top().second < curr.second) {
            result[stk.top().first] = curr.first - stk.top().first;
            stk.pop();
        }
        stk.emplace(curr);
    }
    return result;
}*/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stk; // 优化成存放index
    int n = temperatures.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; i ++) {
        while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
            result[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.emplace(i);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(temperatures);
    std::cout << result.size() << "\n";
    return 0;
}

// time: O(n), space: O(n)
