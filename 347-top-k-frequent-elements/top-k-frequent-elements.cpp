class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for(auto pair: freq){
            buckets[pair.second].push_back(pair.first);
        }
        vector<int>results;
        for(int i = buckets.size()-1;i>=0;i--){
            for(int num : buckets[i]){
                results.push_back(num);
            }
            if(results.size()==k){
                return results;
            }
        }
        return results;
    }
};