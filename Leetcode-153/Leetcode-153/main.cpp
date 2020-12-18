//
//  main.cpp
//  Leetcode-153
//
//  Created by Jing Luo on 12/18/20.
//

#include <iostream>
#include <vector>

using namespace std;

int result = -1;

void helper(int s, int e, vector<int>& nums) {
    if (s + 1 < e) {
        int mid = s + (e - s) / 2;
        if (nums[s] < nums[e]) { // 说明是顺序排列，最小值肯定在左边，即可判定为nums[s]为最小值
            result = nums[s];
        } else {
            // 说明是有山峰⛰️排列
            if (nums[mid] > nums[s]) { // 如果左边为顺序排列，说明低谷在右边
                helper(mid+1, e, nums);
            } else {
                helper(s, mid, nums); // 否则低谷在左边
            }
        }
    } else {
        result = nums[s] < nums[e] ? nums[s] : nums[e];
    }
}

int findMin(vector<int>& nums) {
    helper(0, (int)nums.size()-1, nums);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,6,0,1,2,3};
    std::cout << findMin(nums) << "\n";
    return 0;
}


/*
 Time：O(logN),二分
 */
