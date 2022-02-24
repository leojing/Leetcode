//
//  main.cpp
//  Leetcode-189
//
//  Created by Jing Luo on 2/24/22.
//

#include <iostream>
#include <vector>

using namespace std;

// Solution 1: Time: O(n), space: O(1)
void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start ++;
        end --;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = (int)nums.size();
    k = k % n;
    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
}

// Solution 2: 数组拷贝，Time: o(n), space: O(n)
// Solution 3: 找规律swap，Time: o(n), space: O(1)

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 23);
    std::cout << "\n";
    return 0;
}
