//
//  main.cpp
//  Leetcode-75
//
//  Created by Jing Luo on 8/16/21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Solution 1: 类似桶排序的思想，time: O(n), space: O(1), 虽然space只有O(1), 但还是开辟了新的空间的，有内存消耗
void sortColors(vector<int>& nums) {
    unordered_map<int, int> colors;
    for (auto num: nums) {
        colors[num] ++;
    }
    int k = 0;
    for (int i = 0; i <= 2; i ++) {
        int n = colors[i];
        for (int j = k; j < k + n; j ++) {
            nums[j] = i;
        }
        k += n;
    }
}
 */

// Solution 2: in-place换位置，遇到0就往前换，遇到2就往后换，time: O(n), space: O(1)
void sortColors(vector<int>& nums) {
    int i = 0, left = 0, right = int(nums.size()) - 1;
    while (i >= left && i <= right) {
        if (nums[i] == 0) {
            swap(nums[left ++], nums[i++]);
        }
        if (nums[i] == 2) {
            swap(nums[right --], nums[i]);
        } else {
            i ++;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,0,2,1,1,0}; // {1,2,0}
    sortColors(nums);
    std::cout << "\n";
    return 0;
}
