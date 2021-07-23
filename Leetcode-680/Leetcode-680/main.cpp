//
//  main.cpp
//  Leetcode-680
//
//  Created by Jing Luo on 7/21/21.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindromic(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left ++;
        right --;
    }
    return true;
}

bool validPalindrome(string s) {
    int length = (int)s.size();
    int left = 0, right = length-1;
    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindromic(s, left+1, right) || isPalindromic(s, left, right-1);
        }
        left ++;
        right --;
    }
    return true;
}
　
int main(int argc, const char * argv[]) {
    string s = "abc";
    std::cout << validPalindrome(s) << "\n";
    return 0;
}
