// Problem 1: Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;   // Value, Index
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i; 
        }

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i], req = target - curr;
            if(mp.find(req) != mp.end() && mp[req] != i){
                ans.emplace_back(i); 
                ans.emplace_back(mp[req]); 
                break;
            }
        }
        return ans;
    }
};

// Problem 2: Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;
        int l = 0, r = 0, jumps = 0;
        while(r < n - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            ++jumps; 
        }
        return jumps;
    }
};

// Problem 3: Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        stringstream ss(path);
        string comp;
        while (getline(ss, comp, '/')) {
            if (comp == "" || comp == ".") {
                continue;
            }

            if (comp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(comp);
            }
        }

        stringstream simplifiedPath;
        for (const string& s : st) {
            simplifiedPath << "/" << s;
        }

        return simplifiedPath.str().empty() ? "/" : simplifiedPath.str();        
    }

private:
    vector<string> st;    
};
