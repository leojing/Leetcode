//
//  main.cpp
//  Leetcode-77
//
//  Created by Jing Luo on 9/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(int n, int k, int index, vector<int> current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    for (int i = index; i <= n; i ++) {
        if (find(current.begin(), current.end(), i) == current.end()) {
            current.push_back(i);
            helper(n, k, i+1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    helper(n, k, 1, current, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> result = combine(4, 2);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 time: O(k * n!), space: O(n+k)=O(n)
 */
