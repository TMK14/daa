def knapsack_dynamic_programming(weights, values, capacity):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    return dp[n][capacity]


# Example usage
weights = [1, 2, 3]
values = [6, 10, 12]
capacity = 5
print("Knapsack using Dynamic Programming:", knapsack_dynamic_programming(weights, values, capacity))
