//
//  main.cpp
//  Leetcode-33
//
//  Created by JINGLUO on 23/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int helper(std::vector<int>& nums, int start, int end, int target) {
    if (target == nums[start]) {
        return start;
    }
    if (target == nums[end]) {
        return end;
    }
    if (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[start] < nums[mid]) {
            if (target >= nums[start] && target <= nums[mid]) {
                end = mid;
            }
            else {
                start = mid;
            }
        } else {
            if (target >= nums[mid] && target <= nums[end]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return helper(nums, start, end, target);
    }
    return -1;
}

int search(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    return helper(nums, 0, int(nums.size())-1, target);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums = {3,4,0};
    std::cout << search(nums, 4) << "\n";
    return 0;
}
