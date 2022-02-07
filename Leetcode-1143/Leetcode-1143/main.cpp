//
//  main.cpp
//  Leetcode-1143
//
//  Created by Jing Luo on 2/7/22.
//

#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
   int text1Length = (int)text1.length();
   int text2Length = (int)text2.length();
   vector<vector<int>> dp(text1Length+1, vector(text2Length+1, 0));
   for (int i = 1; i <= text1Length; i ++) {
       for (int j = 1; j <= text2Length; j ++) {
           if (text1[i-1] == text2[j-1]) {
               dp[i][j] = dp[i-1][j-1] + 1;
           } else {
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
   }
   return dp[text1Length][text2Length];
}

int main(int argc, const char * argv[]) {
    string text1 = "abc";
    string text2 = "cds";
    std::cout << longestCommonSubsequence(text1, text2) << "\n";
    return 0;
}


// Time: O(nm), n = text1.length, m = text2.length
// Space: O(nm), n = text1.length, m = text2.length
