//
//  main.cpp
//  Leetcode-260
//
//  Created by Jing Luo on 3/29/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int sum = 0;
    for (auto num: nums) {
        sum ^= num;
    }
    int lastOne = sum == INT_MIN ? sum : sum & (-sum); // 这里需要判断是否为最小值，不然回runtime error
    int result1 = 0, result2 = 0;
    for (auto num: nums) {
        if (num & lastOne) {
            result1 ^= num;
        } else {
            result2 ^= num;
        }
    }
    return {result1, result2};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
Line 8: Char 30: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:17:30
*/
