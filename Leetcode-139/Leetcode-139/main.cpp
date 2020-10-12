//
//  main.cpp
//  Leetcode-139
//
//  Created by Jing Luo on 10/11/20.
//

#include <iostream>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int length = int(s.size());
    if (length == 0) {
        return false;
    }
    bool dp[length];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < length; i ++) {
        for (int j = i; j >= 0; j --) {
            string subS = s.substr(j, i-j+1); // time: O(n)
            if (find(wordDict.begin(), wordDict.end(), subS) != wordDict.end()) {
                if (j == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[j-1];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
    }
    return dp[length-1];
}

int main(int argc, const char * argv[]) {
    string s = "catsdog";
    vector<string> wordDict = {"cats", "dog"};
    std::cout << wordBreak(s, wordDict) << "\n";
    return 0;
}


/*
 DP, time: O(n^3), DP takes O(n^2) and subStr takes O(n), space: O(n)
 */
