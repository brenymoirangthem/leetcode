class Solution {
public:
    string longestPalindrome(string s) {
       if(s.empty()){
        return "";
       }    
       int maxlength =1;
       int start =0;
       // odd length
       for(int i = 0;i<s.length();i++){
              int left = i;
              int right= i;
              while(left>=0 && right<s.length() && s[left]==s[right]){
                if(right-left+1>maxlength){
                    maxlength = right-left+1;
                    start=left;
                }
                right++;
                left--;
              }
               left = i;
               right =i+1;
              while(left>=0 && right<s.length() && s[left]==s[right]){
                if(right-left+1>maxlength){
                    maxlength = right-left+1;
                    start=left;
                }
                right++;
                left--;
              }

       }
     return s.substr(start,maxlength);
    }

};