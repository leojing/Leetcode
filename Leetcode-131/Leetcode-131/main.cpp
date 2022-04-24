//
//  main.cpp
//  Leetcode-131
//
//  Created by Jing Luo on 4/24/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* soultion: backtracking
bool isPalindrome(string s) {
    int len = s.length();
    for (int i = 0; i < len/2; i ++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }
    return true;
}

void helper(string s, int index, vector<string> curr, vector<vector<string>>& result) {
    int len = s.length();
    if (index == len) {
        result.emplace_back(curr);
        return;
    }
    for (int i = 1; i <= len, index+i <= len; i ++) {
        string tempS = s.substr(index, i);
        if (isPalindrome(tempS)) {
            curr.emplace_back(tempS);
            helper(s, index+i, curr, result);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    helper(s, 0, {}, result);
    return vector(result.begin(), result.end());
}*/

// Solution 2: backtracking + 记忆化搜索
vector<vector<int>> f;

int isPalindrome(string s, int i, int j) {
    if (i >= j) {
        return f[i][j] = 1;
    }
    if (f[i][j]) {
        return f[i][j];
    }
    return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i+1, j-1) : -1);
}

void helper(string s, int index, vector<string> curr, vector<vector<string>>& result) {
    int len = s.length();
    if (index == len) {
        result.emplace_back(curr);
        return;
    }
    for (int i = index; i < len; i ++) {
        string tempS = s.substr(index, i - index + 1);
        if (isPalindrome(s, index, i) == 1) {
            curr.emplace_back(tempS);
            helper(s, i+1, curr, result);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<vector<string>> result;
    f.assign(n, vector<int>(n));
    helper(s, 0, {}, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> result = partition("aab");
    std::cout << result.size() << "\n";
    return 0;
}


// time: O(n * 2^n)
// space: O(n^2)
