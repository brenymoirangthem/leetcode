class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>results(nums.size(),1);
        int prefix = 1;
        for(int i = 0 ;i<nums.size();i++){
            results[i]=prefix;
            prefix *=nums[i];
        }
        int suffix=1;
        for(int i =nums.size()-1;i>=0;i--){
            results[i]*=suffix;
            suffix *=nums[i];
        }
        return results;
        
    }
};