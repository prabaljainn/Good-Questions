// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/


class Solution {
public:
    vector<int> p;
    int n;
    int dp[1001][4][101];
    bool checked[1001][4][101];
/*
    // at any point of state either you buy // sell // or leave.
    Nothing done --> 0
    Buy --> 1
    Sell --> 2
*/
    // definition of recursion: the best at this lastMove k transactions and this Index.
    int rec(int index, int lastMove, int k) {
        
        // base case
        if (index == n || k == 0)
            return 0;
       
        // dp check
        if (checked[index][lastMove][k] == true)
            return dp[index][lastMove][k];
       
        // compute and return;
        int ans = 0;;
       
        // DO NOTHING
        ans = max(ans, rec(index + 1, lastMove, k));

        // BUY
        if (lastMove == 0 || lastMove == 2)
            ans = max(ans, (rec(index + 1, 1, k) - p[index]));
        // SELL
        if (lastMove == 1)
            ans = max(ans, (rec(index + 1, 2, k - 1) + p[index]));

        checked[index][lastMove][k] = true;
        
        return dp[index][lastMove][k] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        p = prices;
        memset(checked, false, sizeof(checked));
        return rec(0, 0, k);
    }
};