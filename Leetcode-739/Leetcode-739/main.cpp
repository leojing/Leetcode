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

typedef pair<int, int> Temp;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<Temp> stk;
    int n = temperatures.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; i ++) {
        Temp curr = make_pair(i, temperatures[i]);
        if (stk.empty()) {
            stk.emplace(curr);
            continue;
        }
        Temp top = stk.top();
        while (top.second < curr.second) {
            result[top.first] = curr.first - top.first;
            stk.pop();
            if (stk.empty()) {
                break;
            }
            top = stk.top();
        }
        stk.emplace(curr);
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
