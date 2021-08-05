//
//  main.cpp
//  Leetcode-215
//
//  Created by Jing Luo on 8/5/21.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int start, int end, int k) {
    int n = int(nums.size());
    if (start < 0 || start > n || end < 0 || end > n || start >= end) {
        return;
    }
    int pivot = nums[end];  // 取end的值为pivot最容易，因为前面的swap不会影响最后一个数，这样在循环结束后，将end和最后的pivotindexswap
    int pivotIndex = start;
    int i = start;
    while (pivotIndex < end && i < end) {  // 因为pivot是end，所以不可以等于end
        if (nums[i] < pivot) {
            swap(nums[i], nums[pivotIndex++]);
        }
        i ++;
    }
    swap(nums[end], nums[pivotIndex]);
    // 根据k的位置，决定要将哪一边排序，因为非k所在的区域就没必要排序了
    if (pivotIndex < k) {
        helper(nums, pivotIndex + 1, end, k);
    } else if (pivotIndex > k) {
        helper(nums, start, pivotIndex - 1, k);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    int n = int(nums.size());
    helper(nums, 0, n - 1, n - k);
    return nums[n - k];
}

int main(int argc, const char * argv[]) {
//    vector<int> nums = {3,2,3,1,2,5,4,5,6};
//    vector<int> nums = {2,4,1,3,1,3};
    vector<int> nums = {2,1,3,9,6};
    std::cout << findKthLargest(nums, 4) << "\n";
    return 0;
}


/*
 quick sort， time: expected O(N), worst O(N^2), space: O(1)
 */
