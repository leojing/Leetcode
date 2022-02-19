//
//  main.cpp
//  Leetcode-704
//
//  Created by Jing Luo on 2/19/22.
//

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int n = (int)nums.size();
    int start = 0, end = n-1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    if (nums[start] == target) {
        return start;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,3,4,5};
    std::cout << search(nums, 5) << "\n";
    return 0;
}
