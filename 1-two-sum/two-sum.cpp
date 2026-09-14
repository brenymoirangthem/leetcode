class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
        int need = target-nums[i];

        if(mp.count(need)){
            return {mp[need],i};
        }
        mp[nums[i]]=i;//store the current node with its index Eg 2-0,7-1
        
    }
    return {};
    }
};