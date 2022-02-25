//
//  main.cpp
//  Leetcode-283
//
//  Created by Jing Luo on 2/25/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*Solution 1: Time: O(n), space: O(1)
void moveZeroes(vector<int>& nums) {
    int n = (int)nums.size();
    int zeroPoint = 0, numberPoint = 0;
    while (zeroPoint < n && numberPoint < n) {
        while (zeroPoint < n && nums[zeroPoint] != 0) {
            zeroPoint ++;
        }
        numberPoint = zeroPoint;
        while (numberPoint < n && nums[numberPoint] == 0) {
            numberPoint ++;
        }
        if (numberPoint >= n) {
            return;
        }
        swap(nums[zeroPoint], nums[numberPoint]);
    }
}*/

// Time: O(n), space: O(1)
void moveZeroes(vector<int>& nums) {
    int n = (int)nums.size();
    int left = 0, right = 0;
    while (right < n) {
        if (nums[right]) {
            swap(nums[right], nums[left]);
            left ++;
        }
        right ++;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,0};//{1,2,0,5,0,2,0,0};//{0,1,0,3,12};
    moveZeroes(nums);
    std::cout << "\n";
    return 0;
}
