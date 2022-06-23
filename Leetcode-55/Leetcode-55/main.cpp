//
//  main.cpp
//  Leetcode-55
//
//  Created by Jing Luo on 6/24/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return true;
    
    vector<int> zeros;
    for (int i = 0; i < n; i ++) {
        if (nums[i] == 0) {
            zeros.emplace_back(i);
        }
    }
    for (int i = 0; i < zeros.size(); i ++) {
        bool flag = false;
        for (int j = zeros[i] - 1; j >= 0; j --) {
            //对于最后一个位置的0，可以直接跳到它的位置或者跳过它都行
            if (zeros[i] == n-1 && nums[j] >= (zeros[i]-j)) {
                flag = true;
                break;
            }
            //对于中间的0，必须跳过它
            if (nums[j] > (zeros[i]-j)) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,0,0};
//    vector<int> nums = {2,0,3,1,0,1,4};
    std::cout << canJump(nums) << "\n";
    return 0;
}
