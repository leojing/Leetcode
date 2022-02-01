//
//  main.cpp
//  Leetcode-300
//
//  Created by Jing Luo on 2/1/22.
//

#include <iostream>
#include <vector>

using namespace std;


/* Solution 1 - time: O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int result = INT_MIN;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}
*/

// Solution 2 - time: O(nLogN)
int lengthOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < n; i ++) {
        if (dp.back() < nums[i]) {
            dp.push_back(nums[i]);
        } else {
            // binary search to find the nums[i] positon
            int s = 0, e = (int)dp.size();
            while (s < e) {
                int mid = s + (e - s)/2;
                if (dp[mid] < nums[i]) {
                    s = mid + 1;
                } else {
                    e = mid;
                }
            }
            dp[s] = nums[i];
        }
    }
    return (int)dp.size();
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,0,3,2,3}; //{10,9,2,5,3,7,101,18}; // {7,7,7,7,7,7,7}
    std::cout << lengthOfLIS(nums) << "\n";
    return 0;
}


// 本题还可以使用二分查找将时间复杂度降低为 O(n log n)。我们定义一个 dp 数组，其中 dp[k] 存储长度为 k+1 的最长递增子序列的最后一个数字。我们遍历每一个位置 i，如果其对应的数字 大于 dp 数组中所有数字的值，那么我们把它放在 dp 数组尾部，表示最长递增子序列长度加 1; 如果我们发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则我们将 b 更新为此数字，使得 之后构成递增序列的可能性增大。以这种方式维护的 dp 数组永远是递增的，因此可以用二分查 找加速搜索。
