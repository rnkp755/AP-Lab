// Problem - 1 - Max Units on a Truck
class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	    //custom sort (in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units )
        sort(boxTypes.begin(),boxTypes.end(),myfunction);
		//greedily pick boxes till capacity is full
        int ans=0;
        for(auto box: boxTypes){
            int x=min(box[0],truckSize);  //choose minimum boxes from available boxes and capacity left
            ans+=(x*box[1]);  //adding units in ans
            truckSize-=x;  //reduce the capacity
            if(!truckSize) break;  //capacity full
        }
        return ans;
    }
};

// Problem - 2 - Min Operations to make array increasing
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int counter = 0; 
        for(int i = 0; i < nums.size() -1; i++)
        {
            while(nums[i] >= nums[i+1])
            {
                nums[i+1]++;
                counter++;
            }
        }
        return counter;
    }
};

// Problem - 3 - Max Score from removing substrings
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        // Removing first top substrings cause they give more points
        vector<char> stack;
        for (char ch : s) {  // Changed 'char' to 'ch'
            if (ch == top[1] && !stack.empty() && stack.back() == top[0]) {
                res += top_score;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        // Removing bot substrings cause they give less or equal amount of scores
        vector<char> new_stack;
        for (char ch : stack) {  // Changed 'char' to 'ch'
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                res += bot_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }

        return res;
    }
};
