//
//  main.cpp
//  Leetcode-15
//
//  Created by Jing Luo on 5/2/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* solution 1: 先固定两个数，再二分去找第三个数
int helper(vector<int>& nums, int target, int j, int k) {
    int start = 0, end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + ((end - start ) >> 1);
        if (nums[mid] == target && mid != j && mid > k) { // mid > k, 可以避免很多重复，保证第三个数总是取大于第二个数的index
            return mid;
        }
        if (nums[mid] <= target) { // 考虑到[0,0,0]的case，等于的时候需要取后半部分
            start = mid;
        } else {
            end = mid;
        }
    }
    if (nums[start] == target && start != j && start > k) { // start > k, 可以避免很多重复
        return start;
    }
    if (nums[end] == target && end != j && end > k) {
        return end;
    }
    return -1;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> result;
    sort(nums.begin(), nums.end());
    // make sure there is only 3 '0' in nums at max
    int numOfZero = 0;
    vector<int> newNums;
    for (auto num: nums) {
        if (num == 0) {
            if (numOfZero >= 3) {
                continue;
            }
            numOfZero ++;
        }
        newNums.emplace_back(num);
    }
    int n = newNums.size();
    for (int i = 0; i < n; i ++) {
        for (int j = i+1; j < n; j ++) {
            int k = helper(newNums, 0 - (newNums[i] + newNums[j]), i, j);
            if (k != -1) {
                vector<int> curr(3);
                curr[0] = newNums[i];
                curr[1] = newNums[j];
                curr[2] = newNums[k];
                result.insert(curr);
            }
        }
    }
    return vector(result.begin(), result.end());
}
 */

// solution 2: 先固定1个数，用2sum去找剩下的，注意去重, time: O(n*n), space: O(logN)排序的空间
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i ++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int left = i + 1, right = n - 1;
        int target = 0 - nums[i];
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                vector<int> temp = {nums[i], nums[left], nums[right]};
                result.emplace_back(temp);
                ++ left;
                -- right;
                while (left < n && nums[left] == nums[left - 1]) {
                    ++ left;
                }
                while (right >= 0 && nums[right] == nums[right + 1]) {
                    -- right;
                }
            } else if (sum < target) {
                ++ left;
            } else {
                -- right;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1,0,0,0,0,1}; // -4,-1,-1,0,1,2
    vector<vector<int>> result = threeSum(nums);
    std::cout << result.size()<< "\n";
    return 0;
}
