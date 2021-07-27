//
//  main.cpp
//  Leetcode-34
//
//  Created by Jing Luo on 7/27/21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int size = int(nums.size());
    if (size == 0) {
        return {-1, -1};
    }
    // Find first element
    int first = -1;
    int start = 0, end = size - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (nums[start] == target) {
        first = start;
    } else if (nums[end] == target) {
        first = end;
    }
    
    // Find last element
    int last = -1;
    start = 0;
    end = size - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] <= target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (nums[end] == target) {
        last = end;
    } else if (nums[start] == target) {
        last = start;
    }
    return vector<int>{first, last};
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {};//{5,7,7,8,8,10};
    vector<int> range = searchRange(nums, 8);
    std::cout <<  range.size() << "\n";
    return 0;
}


/*
 binary search, time: O(logN), space: O(1)
 */
