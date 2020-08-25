//
//  main.cpp
//  Leetcode-824
//
//  Created by Jing Luo on 8/25/20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

string helper(string s, int index) {
    string result = "";
    if (find(vowels.begin(), vowels.end(), s[0]) == vowels.end()) {
        char first = s[0];
        s.erase(s.begin()+0);
        s += first;
    }
    result += s;
    result += "ma";
    while (index--) {
        result += "a";
    }
    return result;
}

string toGoatLatin(string S) {
    string result = "";
    string temp = "";
    int index = 1;
    for (int i = 0; i < S.size(); i ++) {
        if (S[i] == ' ') {
            if (!temp.empty()) {
                result += helper(temp, index ++);
                result += S[i];
            }
            temp = "";
        } else {
            temp += S[i];
        }
    }
    if (!temp.empty()) { //最后一个单词不要忘记
        result += helper(temp, index ++);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << toGoatLatin("I sew atw   tag") << "\n";
    return 0;
}


/*
 time: O(n)
 space: O(1)
 */
