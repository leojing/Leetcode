//
//  main.cpp
//  Leetcode-198
//
//  Created by Jing Luo on 9/16/20.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1: Time O(n), Space(n)
int rob(vector<int>& nums) {
    int result = 0;
    vector<int> dp(nums.size());
    for (int i = 0; i < nums.size(); i ++) {
        if (i < 3) {
            dp[i] = nums[i];
            if (i == 2) {
                dp[i] = max(dp[i], dp[i-2] + nums[i]);
            }
            result = max(result, dp[i]);
            continue;
        }
        dp[i] = max(dp[i-3]+nums[i], dp[i-2] + nums[i]);
        result = max(result, dp[i]);
    }
    return result;
}*/

/* Solution 2: Time O(n!), Space(n)
int rob(vector<int>& nums) {
    int result = 0;
    vector<int> dp(nums.size());
    for (int i = 0; i < nums.size(); i ++) {
        if (i < 2) {
            dp[i] = nums[i];
            result = max(result, dp[i]);
            continue;
        }
        int index = i-2;
        dp[i] = nums[i];
        while (index >= 0) {
            dp[i] = max(dp[i], dp[index] + nums[i]);
            index --;
        }
        result = max(result, dp[i]);
    }
    return result;
}*/

// Solution 3: Time O(n), Space(n)
int rob(vector<int>& nums) {
    int result = 0;
    vector<int> dp(nums.size());
    for (int i = 0; i < nums.size(); i ++) {
        if (i < 2) {
            dp[i] = nums[i];
            if (i == 1) {
                dp[i] = max(dp[0], dp[1]);
            }
            result = max(result, dp[i]);
            continue;
        }
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        result = max(result, dp[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,2,3};//{2,1,1,2};//{1,2,3,1};
    std::cout << rob(nums) << "\n";
    return 0;
}
