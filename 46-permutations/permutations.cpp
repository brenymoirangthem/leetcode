class Solution {
public:
    vector<vector<int>>result;
    vector<int>current;
    void backtrack(vector<int>&nums,vector<bool>&used){
        if(current.size()==nums.size()){
            result.push_back(current);
            return ;
        }
        for(int i = 0 ; i<nums.size();i++){
            if(used[i]==true){
                continue;
            }
            current.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,used);
            current.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        backtrack(nums,used);
        return result;
    }
};