//
//  main.cpp
//  Leetcode-46
//
//  Created by Jing Luo on 8/30/21.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int index, vector<vector<int>> &result, vector<int> current) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i ++) {
        if (find(current.begin(), current.end(), nums[i]) == current.end()) {
            current.push_back(nums[i]);
            helper(nums, i, result, current);
            current.erase(current.end()-1);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    helper(nums, 0, result, current);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = permute(nums);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 题解： https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
 
 time: O(n * n!), space: O(n)
 */
