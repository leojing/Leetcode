//
//  main.cpp
//  Leetcode-540
//
//  Created by Jing Luo on 7/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int start = 0, end = int(nums.size()) - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == nums[mid + 1]) {
            if (mid % 2) {
                end = mid;
            } else {
                start = mid + 1;
            }
        } else if (mid - 1 >= 0 && (nums[mid] == nums[mid - 1])) {
            if (mid % 2) {
                start = mid;
            } else {
                end = mid - 1;
            }
        } else {
            return nums[mid];
        }
    }
    if (start == 0) {
        return nums[start];
    }
    if (end == int(nums.size()) - 1) {
        return nums[end];
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    std::cout << singleNonDuplicate(nums) << "\n";
    return 0;
}


/*
 test case:
 1
 1,1,2,2,3,4,4  // in middle
 1,2,2,3,3 // in start
 1,1,2,2,3 // in end
 
 利用index的变化，在single element之前，所有的双数都是第一个数index为偶数，第二个数index为奇数，
                在single element之后，所有的双数都是第一个数index为寄数，第二个数index为偶数，
 由此来判断single element在left part或者在right part
 
 time: O(LogN), space: O(1)
 */
