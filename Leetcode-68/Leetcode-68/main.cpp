//
//  main.cpp
//  Leetcode-68
//
//  Created by Jing Luo on 4/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

void addExtraSpace(vector<pair<string, int>>& currLine, int maxWidth, int tempWidth) {
    int space = maxWidth - tempWidth;
    if (currLine.size() == 1) {
        currLine[0].second = space;
    } else {
        int avg = space / (currLine.size()-1);
        int mod = space % (currLine.size()-1);
        for (int j = 1; j < currLine.size(); j ++) {
            currLine[j].second += avg + (mod > 0 ? 1 : 0);
            mod --;
        }
    }
}

string joinWords(vector<pair<string, int>> currLine) {
    string currResult;
    if (currLine.size() == 1) {
        currResult += currLine[0].first;
        currResult += string(currLine[0].second, ' ');
    } else {
        for (auto curr: currLine) {
            currResult += string(curr.second, ' ');
            currResult += curr.first;
        }
    }
    return currResult;
}

string joinWordsForLastLine(vector<pair<string, int>> currLine, int space) {
    string currResult;
    for (auto curr: currLine) {
        currResult += string(curr.second, ' ');
        currResult += curr.first;
    }
    currResult += string(space, ' ');
    return currResult;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int tempWidth = 0;
    vector<pair<string, int>> currLine;
    vector<string> result;
    int i;
    for (i = 0; i < words.size(); i ++) {
        if (tempWidth == 0) {
            if (words[i].length() > maxWidth) continue;
            tempWidth += words[i].length();
            currLine.emplace_back(make_pair(words[i], 0));
        } else {
            if (tempWidth + words[i].length() + 1 <= maxWidth) {
                tempWidth += words[i].length() + 1;
                currLine.emplace_back(make_pair(words[i], 1));
            } else {
                addExtraSpace(currLine, maxWidth, tempWidth);
                result.emplace_back(joinWords(currLine));
                tempWidth = 0;
                currLine.clear();
                i -= 1;
            }
        }
    }
 
    if (i == words.size()) {
        result.emplace_back(joinWordsForLastLine(currLine, maxWidth - tempWidth));
    }
     
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> result = fullJustify(words, 20);
    std::cout << result.size() << "\n";
    return 0;
}
