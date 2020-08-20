//
//  main.cpp
//  Leetcode-967
//
//  Created by Jing Luo on 8/20/20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tempResult;

int convertToInt(vector<int> num) {
    int result = 0;
    int size = int(num.size());
    int round = 1;
    for (int i = size-1; i >= 0; i --) {
        result += round * num[i];
        round *= 10;
    }
    return result;
}

void helper(int N, int K, vector<int> &current) {
    int size = int(current.size());
    if (size == N) {
        if (find(tempResult.begin(), tempResult.end(), current) != tempResult.end()) { // 如果已经存在了，就不要再加入了，针对K=0的情况，如111，222，333
            return;
        }
        tempResult.push_back(current);
        return;
    }
    int last = current[size-1];
    if (last - K >= 0 && last - K <= 9) {
        current.push_back(last-K);
        helper(N, K, current);
        current.erase(current.end()-1, current.end());
    }
    if (last + K >= 0 && last + K <= 9) {
        current.push_back(last+K);
        helper(N, K, current);
        current.erase(current.end()-1, current.end());
    }
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> result;
    for (int i = 1; i <= 9; i ++) {
        vector<int> current;
        current.push_back(i);
        helper(N, K, current);
    }
    for (int i = 0; i < tempResult.size(); i ++) {
        result.push_back(convertToInt(tempResult[i]));
    }
    if (N == 1) { // 注意为1的特殊情况，需要有0
        result.push_back(0);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = numsSameConsecDiff(3, 0);
    std::cout << result.size() << "\n";
    return 0;
}



//Time Complexity : O(N*2^N)
//Space Complexity : O(2^N)
