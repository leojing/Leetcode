//
//  main.cpp
//  Leetcode-213
//
//  Created by Jing Luo on 10/8/20.
//

#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    int beforePre = nums[0], pre = nums[0] > nums[1] ? nums[0] : nums[1];
    int result = max(beforePre, pre);
    for (int i = 2; i < nums.size(); i ++) {
        int temp = pre;
        pre = max(pre, beforePre + nums[i]);
        beforePre = temp;
        result = max(beforePre, pre);
    }
    return result;
}

int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    int robFirst, notRobFirst;
    // 如果确定抢劫第一户，则默认不抢劫第二户和最后一户，取剩下的住户里面能抢到的最大值+第一户
    vector<int> robFirstNums = {nums.begin() + 2, nums.end() - 1};
    robFirst = nums[0] + helper(robFirstNums);
    
    // 如果确定不抢劫第一户，则取剩下所有住户里面能抢到的最大值
    vector<int> notRobFirstNums = {nums.begin() + 1, nums.end()};
    notRobFirst = helper(notRobFirstNums);
    
    return robFirst > notRobFirst ? robFirst : notRobFirst;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,1,2};
    std::cout << rob(nums) << "\n";
    return 0;
}
