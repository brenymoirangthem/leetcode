class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;
        for(int num: nums){
            numbers.insert(num);
        }
        int longest = 0;
        for(int num: numbers){
            if(numbers.count(num-1)==0){
                int current = num;
                int length = 1;
                while(numbers.count(current+1)){
                    current++;
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};