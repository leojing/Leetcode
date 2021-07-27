//
//  main.cpp
//  Leetcode-81
//
//  Created by Jing Luo on 7/27/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& nums, int start, int end, int target) {
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
        }
        // 如果左边是升序，判断target的位置
        if (nums[start] < nums[mid]) {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        // 如果右边是升序，判断target的位置
        else if (nums[mid] < nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid;
            } else {
                end = mid;
            }
        } else {
            return binarySearch(nums, start, mid, target) || binarySearch(nums, mid, end, target);
        }
    }
    if (nums[start] == target || nums[end] == target) {
        return true;
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, int(nums.size())-1, target);
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};//{1,0,1,1,1}; // start，mid，end 都是 1
    std::cout <<  search(nums, 13) << "\n";
    return 0;
}


/*
 time: O(N) worst case, O(logN) best case, where N is the length of the input array.
 space: O(1)
 */
