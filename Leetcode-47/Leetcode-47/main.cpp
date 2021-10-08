//
//  main.cpp
//  Leetcode-47
//
//  Created by Jing Luo on 10/8/21.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

void dfs(vector<int>& nums, int index, vector<int> current, unordered_set<int> visited, vector<vector<int>>& result) {
    if (visited.size() == nums.size()) {
        result.emplace_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i ++) {
        // 如果i已经访问过，或者i-1和i相等并且i-1还被访问，那就跳过，不然会导致重复答案，保证相等的数都要从小到大被访问，这样就能保证没有重复
        if (visited.find(i) != visited.end() || (i > 0 && nums[i] == nums[i-1] && visited.find(i-1) == visited.end())) {
            continue;
        }
        current.emplace_back(nums[i]);
        visited.insert(i);
        dfs(nums, i+1, current, visited, result);
        visited.erase(i);
        current.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, {}, {}, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2};
    vector<vector<int>> result = permuteUnique(nums);
    std::cout << result.size() << "\n";
    return 0;
}

/*
 test cases:
 [1]
 
 [1,1,2]
 
 [2,2,2,4]
 
 [1,2,3]
 
 
 加上 !vis[i - 1]来去重主要是通过限制一下两个相邻的重复数字的访问顺序

 举个栗子，对于两个相同的数11，我们将其命名为1a1b, 1a表示第一个1，1b表示第二个1； 那么，不做去重的话，会有两种重复排列 1a1b, 1b1a， 我们只需要取其中任意一种排列； 为了达到这个目的，限制一下1a, 1b访问顺序即可。 比如我们只取1a1b那个排列的话，只有当visit nums[i-1]之后我们才去visit nums[i]， 也就是如果!visited[i-1]的话则continue
 
 
 time: O(n * n!), space: O(n)
 
 backtrack 的调用次数是O(n!) 的。

 而对于 backtrack 调用的每个叶结点（最坏情况下没有重复数字共 n! 个），我们需要将当前答案使用O(n) 的时间复制到答案数组中，相乘得时间复杂度为O(n×n!)。

 因此时间复杂度为O(n×n!)。

 空间复杂度：O(n)。我们需要 O(n) 的标记数组，同时在递归的时候栈深度会达到 O(n)，因此总空间复杂度为 O(n + n)=O(2n)=O(n)。
 */
