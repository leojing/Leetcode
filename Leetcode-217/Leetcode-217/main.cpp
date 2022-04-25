//
//  main.cpp
//  Leetcode-217
//
//  Created by Jing Luo on 4/26/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
   unordered_set<int> distinctNums;
   for (auto num: nums) {
       if (distinctNums.find(num) != distinctNums.end()) {
           return true;
       }
       distinctNums.insert(num);
   }
   return false;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,1};
    std::cout << containsDuplicate(nums) << "\n";
    return 0;
}

// time: O(n)
// space: o(n)
