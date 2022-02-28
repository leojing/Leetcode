//
//  main.cpp
//  Leetcode-344
//
//  Created by Jing Luo on 2/25/22.
//

#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int n = (int)s.size();
    int start = 0, end = n -1;
    while (start < end) {
       char temp = s[start];
       s[start] = s[end];
       s[end] = temp;
       start ++;
       end --;
    }
}

int main(int argc, const char * argv[]) {
    vector<char> s = {'d', 'd', '2', 's', 'd'};
    reverseString(s);
    std::cout << "\n";
    return 0;
}
