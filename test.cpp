#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}