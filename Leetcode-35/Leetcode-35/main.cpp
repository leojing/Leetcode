//
//  main.cpp
//  Leetcode-35
//
//  Created by Jing Luo on 2/22/22.
//

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = (int)nums.size();
    int start = 0, end = n-1, mid;
    if (target < nums[0]) {
        return 0;
    }
    if (target > nums[n-1]) {
        return n;
    }
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            end = mid;
        } else {
            start = mid;
        }
    }

    if (nums[start] == target) {
        return start;
    }
    return end;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,4,5,8};
    std::cout << searchInsert(nums, 2) << "\n";
    return 0;
}

/*
Test cases:
 {1,2,3,5} 0
 {1,2,3,5} 7
 {1,2,3,5} 4
 {1,2,3,5} 3
*/
