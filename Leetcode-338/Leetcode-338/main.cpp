//
//  main.cpp
//  Leetcode-338
//
//  Created by Jing Luo on 3/30/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> result;
    for (int i = 0; i <= n; i ++) {
        int temp = i;
        int count = 0;
        while (temp) {
            temp = temp & (temp-1);
            count ++;
        }
        result.emplace_back(count);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = countBits(5);
    std::cout << "\n";
    return 0;
}

// time: O(nLogN), space: O(1)
