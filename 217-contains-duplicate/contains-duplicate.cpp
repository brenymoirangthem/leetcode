class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        for(int i = 0;i<size;i++){
            if(s.count(nums[i])){
                
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};