//
//  main.cpp
//  Leetcode-2320
//
//  Created by Jing Luo on 6/26/22.
//

#include <iostream>
#include <vector>

using namespace std;

// TLE超时了
int countHousePlacements(int n) {
    if (n == 1) {
        return 4;
    }
    vector<vector<long>> dp(n+1, vector<long>(n+1, 0));
    long result = 0;
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        if (i == n) {
            result += dp[i][0] + dp[i][1];
        }
        int maxPlot = (n % 2) ? (n/2+1) : (n/2);
        for (int j = 2; i >= 2 && j <= maxPlot; j ++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % 1000000007;
            if (i == n) {
                result += dp[i][j];
            }
        }
    }
    int ans = result % 1000000007;
    return (ans * ans) % 1000000007;
}

int main(int argc, const char * argv[]) {
    std::cout << countHousePlacements(30) << "\n";
    return 0;
}
