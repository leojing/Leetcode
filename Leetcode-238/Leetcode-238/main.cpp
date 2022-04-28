//
//  main.cpp
//  Leetcode-238
//
//  Created by Jing Luo on 4/28/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* time: o(n), space: O(n), 开辟了除result以外的额外空间
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> forward, backward(n);
    int ans = 1;
    for (auto num: nums) {
        ans *= num;
        forward.emplace_back(ans);
    }
    ans = 1;
    for (int i = n-1; i >= 0; i --) {
        ans *= nums[i];
        backward[i] = ans;
    }
    vector<int> result;
    result.emplace_back(backward[1]);
    for (int i = 1; i < n-1; i ++) {
        result.emplace_back(forward[i-1] * backward[i+1]);
    }
    result.emplace_back(forward[n-2]);
    return result;
}
 */
   
// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

// time: o(n), space: O(1), 直接适用result去存forward，未开辟除result以外的额外空间
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    int temp = 1;
    for (auto num: nums) {
        temp *= num;
        result.emplace_back(temp);
    }
    result[n-1] = result[n-2];
    temp = nums[n-1];
    for (int i = n-2; i >= 1; i --) {
        int curr = nums[i] * temp;
        result[i] = result[i-1] * temp;
        temp = curr;
    }
    result[0] = temp;
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    std::cout <<  result.size() << "\n";
    return 0;
}
