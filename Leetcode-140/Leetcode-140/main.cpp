//
//  main.cpp
//  Leetcode-140
//
//  Created by Jing Luo on 10/15/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

/* BFS, 会TLE
class Sentence {
public:
    vector<string> words;
    int index;
    Sentence(int index, vector<string> words): index(index), words(words) {}
};

bool isExsit(string word, vector<string>& wordDict) {
    return find(wordDict.begin(), wordDict.end(), word) != wordDict.end();
}

vector<string> validWordsFrom(int index, string s, vector<string>& wordDict, int maxLengthOfWord) {
    vector<string> result;
    string tempS = "";
    int length = int(s.size());
    for (int i = index; i < length; i ++) {
        if (tempS.size() < maxLengthOfWord) {
            tempS += s[i];
            if (isExsit(tempS, wordDict)) {
                result.push_back(tempS);
            }
        }
    }
    return result;
}

string join(vector<string> words) {
    string result = words[0];
    for (int i = 1; i < words.size(); i ++) {
        result += " " + words[i];
    }
    return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> result;
    int maxLengthOfWord = 0;
    for (auto word: wordDict) {
        maxLengthOfWord = max(maxLengthOfWord, int(word.length()));
    }
    queue<Sentence> q, tempQ;
    vector<string> words = validWordsFrom(0, s, wordDict, maxLengthOfWord);
    for (auto w: words) {
        vector<string> temp;
        temp.push_back(w);
        Sentence sentence = Sentence(int(w.size())-1, temp);
        q.push(sentence);
    }
    while (!q.empty()) {
        Sentence sentence = q.front();
        q.pop();
        vector<string> words = sentence.words;
        int index = sentence.index;
        if (index == s.length()-1) {
            result.push_back(join(words));
            continue;
        }
        vector<string> newWords = validWordsFrom(index+1, s, wordDict, maxLengthOfWord);
        for (auto w: newWords) {
            vector<string> temp = words;
            temp.push_back(w);
            Sentence sentence = Sentence(index + int(w.size()), temp);
            q.push(sentence);
        }
    }
    return result;
}*/


// DFS + memorise
unordered_map<string, vector<string>> dp;

vector<string> wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) {
        return {""};
    }
    
    if (dp.find(s) != dp.end()) {
        return dp[s];
    }
    
    vector<string> sub, whole;
    for (string word: wordDict) {
        string subS = s.substr(0, word.length());
        if (subS != word) {
            continue;
        } else {
            sub = wordBreak(s.substr(word.length()), wordDict);
        }
        
        for (string ss: sub) {
            string space = ss.length() == 0 ? "" : " ";
            whole.push_back(word + space + ss);
        }
    }
    return dp[s] = whole;
}

int main(int argc, const char * argv[]) {
    string s = "catsanddog";//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//"pineapplepenapple";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};//{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};//{"apple", "pen", "applepen", "pine", "pineapple"};
    std::cout << wordBreak(s, wordDict).size() << "\n";
    return 0;
}


/* test cases:
 ["cat", "cats", "and", "sand", "dog"]
 "uiwhivf"
 "catandsand"
 "catsanddo"
 "tcaanddog"
 
 
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
 ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 */
