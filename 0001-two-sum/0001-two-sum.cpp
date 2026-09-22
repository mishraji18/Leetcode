class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Just looking, zero memory allocations
            auto it = mp.find(complement);
            if (it != mp.end()) {
                return {it->second, i};
            }
            
            mp[nums[i]] = i;
        }

        return {};
    }
};