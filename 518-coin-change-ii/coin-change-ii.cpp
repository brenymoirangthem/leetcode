class Solution{ 
    public:
     int change(int amount, vector<int>& coins) {
         if (amount == 0)
          return 1;
           int g = 0;
            for (int coin : coins) { 
                g = gcd(g, coin);
            }
            if (amount % g != 0)
             return 0;
            vector<int> dp(amount + 1, 0); 
            dp[0] = 1;
             for (int coin : coins) {
                 for (int j = coin; j <= amount; j++) {
                     long long ways = (long long)dp[j] + dp[j - coin]; 
                     dp[j] = (int)min(ways, (long long)INT_MAX);
                    }
                 }
                return dp[amount]; 
                }
             };