//
//  main.cpp
//  Leetcode-125
//
//  Created by Jing Luo on 5/2/22.
//

#include <iostream>

using namespace std;
    
bool isPalindrome(string s) {
    int n = s.size();
    int start = 0, end = n - 1;
    while (start < end) {
        while (start < n && !isdigit(s[start]) && !isalpha(s[start])) {
            ++ start;
        }
        while (end >= 0 && !isdigit(s[end]) && !isalpha(s[end])) {
            -- end;
        }
        if (start < end) {
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
        }
        ++ start;
        -- end;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::cout << isPalindrome("6:^*^%%^%6,") << "\n";
    return 0;
}


// time: O(n), space: O(1)
