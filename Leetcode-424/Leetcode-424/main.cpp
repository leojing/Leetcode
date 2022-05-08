//
//  main.cpp
//  Leetcode-424
//
//  Created by Jing Luo on 5/5/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Solution 1: time: O(26*n), space: O(26)
int maxForEachChar(vector<int> count) {
    int maxf = 0;
    for (auto c: count) {
        maxf = max(maxf, c);
    }
    return maxf;
}

int characterReplacement(string s, int k) {
    vector<int> count(26);
    int left = 0, right = 0, result = 0;
    while (right < s.size()) {
        count[s[right] - 'A'] ++;
        while (right - left + 1 - maxForEachChar(count) > k) {
            count[s[left] - 'A'] --;
            ++ left;
        }
        result = max(result, right - left + 1);
        ++ right;
    }
    return result;
}*/

// Solution 2: time: O(n), space: O(26)
int characterReplacement(string s, int k) {
    vector<int> count(26);
    int left = 0, right = 0, result = 0, maxf = 0;
    while (right < s.size()) {
        count[s[right] - 'A'] ++;
        maxf = max(maxf, count[s[right] - 'A']);
        while (right - left + 1 - maxf > k) {
            count[s[left] - 'A'] --;
            ++ left;
        }
        result = max(result, right - left + 1);
        ++ right;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string s = "ABABBCDB";//"AABABBA";//"ABAB";
    std::cout << characterReplacement(s, 2) << "\n";
    return 0;
}
