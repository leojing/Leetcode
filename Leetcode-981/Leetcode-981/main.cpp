//
//  main.cpp
//  Leetcode-981
//
//  Created by Jing Luo on 5/28/22.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
private:
    typedef pair<int, string> Stamp;
    
    unordered_map<string, vector<Stamp>> timeMap;
    
    int helper(vector<Stamp>& timestamps, int target) { // 注意这里要用reference&，不然会超时
        int n = timestamps.size();
        if (n == 0 || target < timestamps[0].first) {
            return -1;
        }
        int start = 0, end = n - 1;
        while ( start + 1 < end) {
            int mid = start + ((end - start) >> 1);
            if (timestamps[mid].first == target) {
                return mid;
            }
            if (timestamps[mid].first <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (timestamps[end].first <= target) {
            return end;
        }
        return start;
    }
    
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int index = helper(timeMap[key], timestamp);
        if (index == -1) {
            return "";
        }
        return timeMap[key][index].second;
    }
};

int main(int argc, const char * argv[]) {
    TimeMap* obj = new TimeMap();
    obj->set("foo","bar",1);
    string param_2 = obj->get("foo",1);
    std:cout << param_2 << "\n";
    return 0;
}

// set: time: O(1)
// get: time: O(logN)
// space: O(n)
