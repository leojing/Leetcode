//
//  main.cpp
//  Leetcode-167
//
//  Created by Jing Luo on 2/25/22.
//

#include <iostream>
#include <vector>

using namespace std;

// time: O(n), space: O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
    int n = (int)numbers.size();
    int left = 0, right = n-1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left+1, right+1};
        }
        if (sum < target) {
            left ++;
        } else {
            right --;
        }
    }
    return {left+1, right+1};
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {0,2,4,6,8};
    vector<int> result = twoSum(numbers, 10);
    std::cout << "\n";
    return 0;
}
