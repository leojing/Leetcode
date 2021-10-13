//
//  main.cpp
//  Leetcode-40
//
//  Created by Jing Luo on 10/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& candidates, int target, int index, int sum, vector<int> visited, vector<int> current, vector<vector<int>>& result) {
    if (sum == target) {
        result.emplace_back(current);
        return;
    }
    for (int i = index; i < (int)candidates.size(); i ++) {
        //剪枝，如果已经超过目标值，则因为是递增排序，后面的数会越来越大，肯定超过目标值了，就没必要查找了，直接return
        if (sum + candidates[i] > target) {
            return;
        }
        // 这里是去重的关键，如果前后相等，那么只取第一个可以作为开头，如果第一个未被访问，则表示后面是重复开头，没有必要查找了
        if (i > 0 && candidates[i-1] == candidates[i] && (find(visited.begin(), visited.end(), i-1) == visited.end())) {
            continue;
        }
        if (find(visited.begin(), visited.end(), i) != visited.end()) {
            continue;
        }
        current.emplace_back(candidates[i]);
        visited.emplace_back(i);
        dfs(candidates, target, i + 1, sum + candidates[i], visited, current, result);
        current.pop_back();
        visited.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, 0, {}, {}, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> result = combinationSum2(candidates, 8);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 time: O(n*n!),backtrack调用次数是O(n!),另外还需要O(n)的时间将答案复制到数组中
 space: O(n), visited的空间
 */
