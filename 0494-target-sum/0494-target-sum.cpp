class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // totoal ko init karo
        int total =0;
        // total find karo
        for(int x : nums)
            total += x;
        //edge cases
        if(abs(target)> total)
            return 0;
        // odd nhi hona chaiye 
        if((total + target )%2 != 0)
                return 0;
        int sum = (total + target)/2;
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for (int x : nums) {

            // Reverse traversal -> 0/1 Knapsack
            for (int j = sum; j >= x; j--) {

                dp[j] += dp[j - x];
            }
    
        }
        return dp[sum];
    
     }
};