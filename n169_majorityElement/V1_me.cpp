#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int majorityElement(vector <int> &nums);
};

/*
This code was written with the help of outside assistance. Although I could have
created a solution in O(n) time and O(n) space with hash tables, I lacked the knowledge
to apply Boyer-Moore Majority Vote Algorithm. At no point was external code looked at
for this problem.
*/
int Solution::majorityElement(vector <int> &nums) {
    int candidate, counter, i;
    counter = 0;

    // Go through all the elements, ignore last one to prevent edge case
    for (i = 0; i < nums.size()-1; i++) {
        // If counter is zero that means either first element or new majority found
        if (counter == 0) {
            // Set to current element and increment counter to prevent again
            candidate = nums[i];
            counter++;
        }
        // Otherwise
        else {
            // If current tracked majority is founded increase counter
            if (candidate == nums[i]) {
                counter++;
            }
            // Otherwise decrease the counter
            else {
                counter--;
                // If counter reaches zero set new majority
                if (counter == 0) {
                    candidate = nums[i+1];
                }
            }
        }
    }
    return candidate;
}

int main(int argc, char **argv) {
    int i, intBuffer;
    string argvBuffer;
    vector <int> input;

    // Error checking
    if (argc != 2) {
        fprintf(stderr, "usage: ./me {input}\n");
        return 1;
    }

    // Convert to vector of ints
    argvBuffer = argv[1];
    for (i = 0; i < argvBuffer.size(); i++) {
        intBuffer = (int) (argvBuffer[i] - '0');
        input.push_back(intBuffer);
    } 

    Solution S;
    printf("%d\n", S.majorityElement(input));

    return 0;
}