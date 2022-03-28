//
//  main.cpp
//  Leetcode-136
//
//  Created by Jing Luo on 3/28/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
原理：
异或操作 ^
a=0^a=a^0
0=a^a
*/

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (auto num: nums) {
        result = result ^ num;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,4,3,2,5,4,6,3,2,5,1};
    std::cout << singleNumber(nums) << "\n";
    return 0;
}
