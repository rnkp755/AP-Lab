// Problem - 1 - Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;

        int prev1 = 3;
        int prev2 = 2;
        int cur = 0;

        for (int i = 3; i < n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;        
    }
};
// Problem - 2 - Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, curr = 0;
        for(int e : nums){
            curr += e;
            maxi = max(maxi, curr);
            curr = max(0, curr);
        }
        return maxi;
    }
};

// Problem - 3 - Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;        
    }
};
