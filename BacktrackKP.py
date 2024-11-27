def knapsack_backtracking(weights, values, capacity):
    def backtrack(i, remaining_capacity, current_value):
        if i == len(weights):
            return current_value
        if weights[i] > remaining_capacity:
            return backtrack(i + 1, remaining_capacity, current_value)
        else:
            include_item = backtrack(i + 1, remaining_capacity - weights[i], current_value + values[i])
            exclude_item = backtrack(i + 1, remaining_capacity, current_value)
            return max(include_item, exclude_item)

    return backtrack(0, capacity, 0)


# Example usage
weights = [1, 2, 3]
values = [6, 10, 12]
capacity = 5
print("Knapsack using Backtracking:", knapsack_backtracking(weights, values, capacity))
