//
//  main.cpp
//  Leetcode-17
//
//  Created by Jing Luo on 4/22/22.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(string digits, int numIndex, string curr, vector<string> mapping, vector<string>& result) {
    if (curr.length() == digits.length() && digits.length() > 0) {
        result.emplace_back(curr);
        return;
    }
    for (int i = numIndex; i < digits.length(); i ++) {
        string letters = mapping[digits[i] - '0'];
        int len = (int)letters.length();
        for (int j = 0; j < len; j ++) {
            helper(digits, i+1, curr + letters[j], mapping, result);
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    helper(digits, 0, "", mapping, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> result = letterCombinations("2398");
    std::cout << result.size() << "\n";
    return 0;
}

// time: O(3^n*4^m), n是digits里面mapping出3个字母的数字个数， m是digits里面mapping出4个字母的数字个数
// space: O(n+m)，就是digits的长度
