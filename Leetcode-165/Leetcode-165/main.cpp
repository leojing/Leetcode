//
//  main.cpp
//  Leetcode-165
//
//  Created by Jing Luo on 9/9/20.
//

#include <iostream>
#include <string>

using namespace std;

/* Test case:
 7.0 - 7.0.0.1
 1.2.3 - 1.2.03
 4.1 - 5.2
*/

int compareVersion(string version1, string version2) {
    int v1Length = int(version1.size());
    int v2Length = int(version2.size());
    int i = 0, j = 0;
    int v1 = 0, v2 = 0;
    string v1Str = "", v2Str = "";
    while (i < v1Length || j < v2Length) {
        v1 = v2 = 0;
        while (i < v1Length) {
            if (version1[i] != '.') {
                v1Str += version1[i];
            } else {
                v1 = stoi(v1Str);
                v1Str = "";
                i ++;
                break;
            }
            i ++;
        }
        if (!v1Str.empty()) {
            v1 = stoi(v1Str);
            v1Str = "";
        }
        while (j < v2Length) {
            if (version2[j] != '.') {
                v2Str += version2[j];
            } else {
                v2 = stoi(v2Str);
                v2Str = "";
                j ++;
                break;
            }
            j ++;
        }
        if (!v2Str.empty()) {
            v2 = stoi(v2Str);
            v2Str = "";
        }
        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    std::cout << compareVersion("7.1.0.0.1", "7.1") << "\n";
    return 0;
}
