//
//  main.cpp
//  Leetcode-344
//
//  Created by Jing Luo on 2/25/22.
//

#include <iostream>
#include <vector>

using namespace std;

//void reverseString(vector<char>& s) {
//    int n = (int)s.size();
//    int start = 0, end = n -1;
//    while (start < end) {
//       char temp = s[start];
//       s[start] = s[end];
//       s[end] = temp;
//       start ++;
//       end --;
//    }
//}

int helper(vector<char>& s, int index, int mid) {
    if (index == s.size()-1) {
        swap(s[index], s[0]);
        return 0;
    }
    int reverseIndex = helper(s, index+1, mid) + 1;
    if (reverseIndex <= mid) {
        swap(s[index], s[reverseIndex]);
    }
    return reverseIndex;
}

void reverseString(vector<char>& s) {
    int index = helper(s, 0, ((int)s.size()-1)/2);
}

int main(int argc, const char * argv[]) {
    vector<char> s = {'b', 'a', 's', 'd'};
    reverseString(s);
    std::cout << "\n";
    return 0;
}
