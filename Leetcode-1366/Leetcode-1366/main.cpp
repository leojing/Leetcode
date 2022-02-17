//
//  main.cpp
//  Leetcode-1366
//
//  Created by Jing Luo on 2/18/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void helper(string validStr, string& result, int rank, int currentRank, vector<vector<int>>& mapping) {
    if (currentRank >= rank) { // 如果出现所有字母vote一样的情况，按字典序取第一个字母放入result
        result += validStr[0];
        return;
    }
    int topVote = INT_MIN;
    string topStr = "";
    for (auto c: validStr) {
        if (result.find(c) == result.npos) {
            if (mapping[currentRank][c - 'A'] > topVote) {
                topStr = "";
                topStr.push_back(c);
                topVote = mapping[currentRank][c - 'A'];
            } else if (mapping[currentRank][c - 'A'] == topVote) {
                topStr.push_back(c);
            }
        }
    }
    if (topStr.length() == 1) {
        result += topStr;
        return;
    }
    helper(topStr, result, rank, currentRank + 1, mapping);
}

string rankTeams(vector<string>& votes) {
    string result = "";
    string validStr = "";
    int rank = (int)votes[0].length();
    vector<vector<int>> mapping(rank, vector<int>(26, 0));
    for (auto s: votes) {
        for (int i = 0; i < rank; i ++) {
            mapping[i][s[i] - 'A'] += 1;
        }
    }
    string startStr = votes[0];
    sort(startStr.begin(), startStr.end());
    for (int i = 0; i < rank; i ++) {
        validStr = startStr;
        helper(validStr, result, rank, 0, mapping);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> votes = {"BCA","CAB","CBA","ABC","ACB","BAC"};//{"ZMNAGUEDSJYLBOPHRQICWFXTVK", "ZOPHRQXTMNAGICWFUEDSJYLBVK","JYLBOPHRNAGUEDQICWFXTZMSVK","PHRGUEDSQICZMNAJYLBOWFXTVK","ZMNEDSJYLBOPHRAGUQICWFXTVK","LBOPHZMNAJYRQICWGUEDSFXTVK"};//{"WXYZ","XYZW"};//{"ABC","ACB","ABC","ACB","ACB"};
    std::cout << rankTeams(votes) << "\n";
    return 0;
}

//Time: O(n*k + n*n), Space: O(n), n = each vote's length, k = votes count
