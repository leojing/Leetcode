//
//  main.cpp
//  Leetcode-128
//
//  Created by Jing Luo on 3/27/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    int result = INT_MIN;
    int n = (int)nums.size();
    if (n == 0) { return 0; }

    // 将nums存在set中，这样寻找nums[i]是否存在O(1)的时候，比直接在vector中要快O(n)
    unordered_set<int> exist;
    for (int i =0; i < n; i ++) {
        exist.insert(nums[i]);
    }
    
    for (int i = 0; i < n; i ++) {
        if (exist.count(nums[i]+1)) { continue; } // 这里是不会TLE的关键，如果当前值存在比它大1的数，那么意味着以nums[i]+1开始向下寻找会比nums[i]更优，直接跳过nums[i]

        int curr = nums[i];
        int count = 1;
        while (exist.count(curr-1)) { // O(1), 不能直接find vector，这样time是O(n), 加上外面的for循环，会造成time变O(n^2)，需要将所有num存入unordered_set中，查找就是O(1)
            curr -= 1;
            count += 1;
        }
        result = max(result, count);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {100,2,5,3,2,1,4,7,99,500};
    std::cout << longestConsecutive(nums) << "\n";
    return 0;
}


/*
 time: O(n), space: O(n)
 */
