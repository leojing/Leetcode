//
//  main.cpp
//  Leetcode-977
//
//  Created by Jing Luo on 2/24/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1: 二分找到负数的平方值应该放的位置
void insertNumber(int number, vector<int>& nums) {
    int n = (int)nums.size();
    int start = 0, end = n-1, mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (nums[mid] >= number) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (nums[end] <= number) {
        if (end + 1 == n) {
            nums.push_back(number);
            return;
        }
        nums.insert(nums.begin() + end + 1, number);
        return;
    }
    if (nums[start] >= number) {
        int position = start - 1 >= 0 ? start - 1 : 0;
        nums.insert(nums.begin() + position, number);
        return;
    }
    if (nums[start] < number && nums[end] > number) {
        nums.insert(nums.begin() + start + 1, number);
        return;
    }
    return;
}

vector<int> sortedSquares(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> result;
    int start = -1;
    for (int i = 0; i < n; i ++) {
        if (nums[i] >= 0) {
            if (start == -1) {
                start = i;
            }
            result.push_back(nums[i] * nums[i]);
        }
    }
    if (start == -1) {
        for (int i = n-1; i >= 0; i --) {
            result.push_back(nums[i] * nums[i]);
        }
        return result;
    }
    for (int i = start - 1; i >= 0; i --) {
        insertNumber(nums[i] * nums[i], result);
    }
    return result;
}*/

// time: O(n), space: O(1)
vector<int> sortedSquares(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> result(n);
    for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
        if (nums[i] * nums[i] < nums[j] * nums[j]) {
            result[pos] = nums[j] * nums[j];
            -- j;
        } else {
            result[pos] = nums[i] * nums[i];
            ++ i;
        }
        -- pos;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {-3,-2,-2,-2,1,3};
    //{-3,-3,-2,1};
    //{-4,-3,-2,-1};
    //{-7,-5,-4,-3,0,1,2,4,6};
    //{-6,-4,-2,-1,0};
    vector<int> result = sortedSquares(nums);
    std::cout << result.size() << "\n";
    return 0;
}
