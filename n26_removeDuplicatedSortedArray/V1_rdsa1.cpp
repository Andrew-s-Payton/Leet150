#include <vector>
using namespace std;

class Solution {
public:
// Runs at 0ms
    int removeDuplicates(vector<int>& nums) {
        // Used to hash duplicate values
        vector <int> dupList;

        // Used to build new return statement
        vector <int> cNums;

        // Needs to allow all characters from -100 to 100
        dupList.resize(201, 0);
        int i;
        int k;
        k = 0;

        // Go through the entire vector
        for (i = 0; i < nums.size(); i++) {
            // Index cannot be negative, so add 100 to all, if zero has not been visited
            if (dupList[nums[i]+100] == 0) {
                // Set to visited
                dupList[nums[i]+100] = 1;
                // Increase count
                k++;
                // Add to list
                cNums.push_back(nums[i]);
            }
        }
        // Copy to original 
        nums = cNums;
        return k;
    }
};