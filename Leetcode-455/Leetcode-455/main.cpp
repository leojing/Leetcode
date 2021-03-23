//
//  main.cpp
//  Leetcode-455
//
//  Created by Jing Luo on 3/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int i = 0, j = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int gSize = int(g.size());
    int sSize = int(s.size());
    
    int result = 0;
    while (i < gSize && j < sSize) {
        if (g[i] <= s[j]) {
            result ++;
            i ++;
            j ++;
        } else {
            j ++;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> g = {1,2,3,4};
    vector<int> s = {1,0,4,3};
    std::cout << findContentChildren(g, s) << "\n";
    return 0;
}


/*
 贪心，time：O(NLogN),因为有排序，space：O(1)
 */
