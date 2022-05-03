//
//  main.cpp
//  Leetcode-122
//
//  Created by Jing Luo on 5/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* TLE
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            dp[i][0] = max(dp[i][0], dp[j][1]);
            dp[i][1] = max(dp[i][1], dp[j][0] + max(0, prices[i] - prices[j]));
        }
    }
    return max(dp[n-1][1], dp[n-1][0]);
}*/
    
/*
time: O(n), space: O(n)
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]) max( 选择rest , 选择sell )
解释:今天我没有持有股票，有两种可能: 要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有; 要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]) max( 选择rest , 选择buy )
解释:今天我持有着股票，有两种可能: 要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票; 要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
 
 如果 buy，就要从利润中减去 prices[i]，如果 sell， 就要给利润增加 prices[i]。今天的最大利润就是这两种可能选择中较大的那 个。而且注意 k 的限制，我们在选择 buy 的时候，把 k 减小了 1，很好理解 吧，当然你也可以在 sell 的时候减 1，一样的。
 */
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0)); // 0 代表今天不持有股票， 1 代表今天持有股票
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i ++) {
        dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
    }
    return dp[n-1][0];
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,4,5};
    std::cout << maxProfit(prices) << "\n";
    return 0;
}
