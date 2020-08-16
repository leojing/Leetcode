//
//  main.cpp
//  Leetcode-274
//
//  Created by Jing Luo on 8/16/20.
//

#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int len = int(citations.size());
    int temp, result = 0;
    for (int i = len-1; i >= 0; i --) {
        if (citations[i] <= len - i) {
            result = max(result, citations[i]); // 注意这里要取最大值，case {2,2,2}的情况
            continue;
        }
        temp = citations[i]-1;
        while (temp) {
            if (find(citations.begin(),citations.end(),temp) != citations.end()) {
                break;
            }
            if (temp == len-i) {
                result = max(result,  temp); // 注意这里要取最大值，case {2,2,2}的情况
            }
            temp --;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> citations = {2,2,2};//{0,0,0};//{3,3,0,6,1,5};//{0,3,5};//{3,4,6,8,2,5,6,9,7,10,0,5};
    std::cout << hIndex(citations) << "\n";
    return 0;
}


/*
 time complex：O(n)
 space: O(1)
 */
