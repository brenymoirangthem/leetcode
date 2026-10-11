class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    void backtrack(vector<int>&candidates,int remaining,int start){
        if(remaining==0){
            result.push_back(current);
        }
        for(int i = start;i<candidates.size();i++){
            if(candidates[i]>remaining){
                break;
            }
            current.push_back(candidates[i]);
            backtrack(candidates,remaining-candidates[i],i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return result;
    }
};