//
//  main.cpp
//  Leetcode-4
//
//  Created by Jing Luo on 7/29/21.
//

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = int(nums1.size()), n = int(nums2.size());
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int left = 0, right = m, i, j, num1, num2, mid = (m + n + 1) >> 1;
    while (left <= right) {
        i = (left + right) >> 1;
        j = mid - i;
        if (i > 0 && nums1[i-1] > nums2[j]) {
            right = i - 1;
        } else if (i < m && nums2[j-1] > nums1[i]) {
            left = i + 1;
        } else {
            // i is perfect index
            if (i == 0) {
                num1 = nums2[j-1];
            } else if (j == 0) {
                num1 = nums1[i-1];
            } else {
                num1 = max(nums1[i-1], nums2[j-1]);
            }
            break;
        }
    }
    if ((m + n) & 1) {
        return num1;
    }
    if (i == m) {
        num2 = nums2[j];
    } else if (j == n) {
        num2 = nums1[i];
    } else {
        num2 = min(nums1[i], nums2[j]);
    }
    return (num1 + num2) / 2.;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {};
    std::cout << findMedianSortedArrays(nums1, nums2) << "\n";
    return 0;
}


/*
 Solution:
 https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
 
 
 time: O(min(m,n)), space: O(1)
 
 test cases:
 {1,2,3,4,5}, {1,2,3}
 
 {1,2,3,4,5}, {1}
 
 {1,2,3,4,5}, {2,3}
 
 {1,2,3} {}
 */
