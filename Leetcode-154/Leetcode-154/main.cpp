//
//  main.cpp
//  Leetcode-154
//
//  Created by Jing Luo on 1/5/21.
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
            } else if (nums[mid] < nums[s]) {
                helper(s, mid, nums); // 否则低谷在左边
            } else {
                if (nums[s] == nums[e]) { // O()n linear complexity, s、e各缩小一步，不确定低谷在哪边
                    helper(s+1, e-1, nums);
                } else {
                    helper(mid, e, nums);
                }
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
    vector<int> nums = {3,3,3,4,2,3};//{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};//{1,1,1,1,2,0};
    std::cout << findMin(nums) << "\n";
    return 0;
}

/*
 Time: O(logN), worst case O(n)
 */
