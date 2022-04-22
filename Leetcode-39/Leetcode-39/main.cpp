//
//  main.cpp
//  Leetcode-39
//
//  Created by Jing Luo on 4/22/22.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& candidates, int target, int index, vector<int> curr, int sum, vector<vector<int>>& result) {
    if (sum == target) {
        result.emplace_back(curr);
        return;
    }
    if (sum > target) {
        return;
    }
    for (int i = index; i < candidates.size(); i ++) {
        curr.emplace_back(candidates[i]);
        helper(candidates, target, i, curr, sum + candidates[i], result);
        curr.pop_back();
    }
}
    
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    helper(candidates, target, 0, {}, 0, result);
    return vector(result.begin(), result.end());
}

int main(int argc, const char * argv[]) {
    vector<int> candidates = {1,2,3,6};
    vector<vector<int>> result = combinationSum(candidates, 8);
    std::cout << result.size() << "\n";
    return 0;
}


// time: O(s)，n是可行解的长度
// space: O(target)，递归深度
