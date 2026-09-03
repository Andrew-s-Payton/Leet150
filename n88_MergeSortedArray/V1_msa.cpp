#include <iostream>
#include <vector>

using namespace std;

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pointer1, pointer2, i, j;
    vector<int> numsR;
    pointer1 = 0;
    pointer2 = 0;

    // Go through the total length of the final array O(m+n)
    for (i = 0; i < (m + n); i++) {
        printf("A: %d, B: %d", pointer1, pointer2);
        // If pointer is greater or equal to size cap 3->2 0, 1, 2
        if (pointer1 >= m) {
            numsR.push_back(nums2[pointer2]);
            pointer2++;
        } 
        else if (pointer2 >= n) {
            numsR.push_back(nums1[pointer1]);
            pointer1++;
        }
        // If the element of the first vector is less than the element of
        // the second
        else if (nums1[pointer1] < nums2[pointer2]) {
            // Add smaller element to tempoary vector
            numsR.push_back(nums1[pointer1]);
            pointer1++;
        } 
        else {
            numsR.push_back(nums2[pointer2]);
            pointer2++;
        }
    }
    // O(n+m), work on a faster version without a second loop
    nums1 = numsR;
}