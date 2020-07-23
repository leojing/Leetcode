//
//  main.cpp
//  Leetcode-518
//
//  Created by Jing Luo on 7/23/20.
//

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
    int dp[amount+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i ++) {
        for (int j = coins[i]; j <= amount; j ++) { // 关键是j的start，必须得是coins[i]，这样可以避免重复计算已经加过的值
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amount];
}

int main(int argc, const char * argv[]) {
    vector<int> coins = {1,2,5};
    std::cout << change(5, coins) << "\n";
    return 0;
}

/*
 time complex：O(n*m), n is amount, m is coins's size
 space: O(n), n is amount
 */
