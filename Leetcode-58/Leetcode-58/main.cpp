//
//  main.cpp
//  Leetcode-58
//
//  Created by Jing Luo on 9/16/20.
//

#include <iostream>
#include <string>

using namespace std;

/*
 Test case:
 ""
 " "
 "Hello world"
 "Hello    world"
 "Hello  world "
 "Hello world     "
 */

int lengthOfLastWord(string s) {
        int length = int(s.size()) - 1;
        if (length == -1) {
            return 0;
        }
        int result = 0;
        while (length) {
            if (s[length] != ' ') {
                break;
            }
            length --;
        }
        for (int i = 0; i <= length; i ++) {
            if (s[i] != ' ') {
                result ++;
            } else {
                result = 0;
            }
        }
        return result;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
