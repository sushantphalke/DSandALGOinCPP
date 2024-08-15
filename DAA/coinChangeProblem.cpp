#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
  vector<int> dp(amount + 1, INT_MAX);  
  dp[0] = 0;                            
  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}


int main() {
  vector<int> coins = {1, 2, 5, 20, 25};
  int amount = 40;
  int minCoinCount = minCoins2d(coins, amount);

  if (minCoinCount != -1) {
    cout << "Minimum number of coins needed to make change for " << amount << " is: " << minCoinCount << endl;
  } else {
    cout << "It is not possible to make change for " << amount << " with the given coins." << endl;
  }

  return 0;
}
