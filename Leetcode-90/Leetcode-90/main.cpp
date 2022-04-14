//
//  main.cpp
//  Leetcode-90
//
//  Created by Jing Luo on 4/14/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;

void helper(vector<int>& nums, int index, vector<int>& curr) {
    result.emplace_back(curr);
    for (int i = index; i < nums.size(); i ++) {
        if (i != index && nums[i] == nums[i-1]) {
            continue;
        }
        curr.emplace_back(nums[i]);
        helper(nums, i+1, curr);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> curr = {};
    sort(nums.begin(), nums.end());
    helper(nums, 0, curr);
    return vector(result.begin(), result.end());
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,4,4,1,2,3};
    vector<vector<int>> result = subsetsWithDup(nums);
    std::cout << result.size() << "\n";
    return 0;
}

//Time: O(2^N * N), where N <= 10 is length of nums array.
//Space: O(2^N)
