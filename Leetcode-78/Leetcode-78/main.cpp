//
//  main.cpp
//  Leetcode-78
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
        curr.emplace_back(nums[i]);
        helper(nums, i+1, curr);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curr = {};
    helper(nums, 0, curr);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    std::cout << result.size() << "\n";
    return 0;
}
