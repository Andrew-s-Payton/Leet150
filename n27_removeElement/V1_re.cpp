#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, rSize, rv;
        rSize = nums.size();
        rv = 0;
        for (i = 0; i < rSize; i++) {
            while (nums[i] == val) {
                if (rSize == 0) {
                    return rv;
                }
                if (rSize > i) {
                    nums[i] = nums[rSize-1];
                }
                rSize--;
            }
            if (nums[i] != val) {
                rv++;
            }
        }
        cout << rv;
        return rv;
    }
};