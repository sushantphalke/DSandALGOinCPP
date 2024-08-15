#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Dynamic Programming Iteration
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item's weight is less than or equal to the current capacity
            if (weights[i - 1] <= w) {
                // Decide whether to include the current item or not
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // If the current item's weight is greater than the current capacity,
                // then we cannot include it in the knapsack
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120,123};
    vector<int> weights = {10, 20, 30,10};
    int capacity = 50;
    
    int maxValue = knapsack(values, weights, capacity);
    
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
