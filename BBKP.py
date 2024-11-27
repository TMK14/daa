import heapq

class Node:
    def __init__(self, level, value, weight, bound):
        self.level = level
        self.value = value
        self.weight = weight
        self.bound = bound

    def __lt__(self, other):
        return self.bound > other.bound

def bound(node, n, capacity, weights, values):
    if node.weight >= capacity:
        return 0
    bound_value = node.value
    j = node.level + 1
    total_weight = node.weight
    while j < n and total_weight + weights[j] <= capacity:
        total_weight += weights[j]
        bound_value += values[j]
        j += 1
    if j < n:
        bound_value += (capacity - total_weight) * (values[j] / weights[j])
    return bound_value

def knapsack_branch_and_bound(weights, values, capacity):
    n = len(values)
    items = list(zip(values, weights))
    items.sort(key=lambda x: x[0] / x[1], reverse=True)

    values, weights = zip(*items)

    queue = []
    root = Node(-1, 0, 0, 0)
    root.bound = bound(root, n, capacity, weights, values)
    heapq.heappush(queue, root)

    max_value = 0

    while queue:
        current = heapq.heappop(queue)
        if current.bound > max_value:
            if current.level + 1 < n:
                next_level = current.level + 1

                # Take the item
                next_node = Node(next_level, current.value + values[next_level], current.weight + weights[next_level], 0)
                if next_node.weight <= capacity:
                    max_value = max(max_value, next_node.value)
                    next_node.bound = bound(next_node, n, capacity, weights, values)
                    if next_node.bound > max_value:
                        heapq.heappush(queue, next_node)

                # Skip the item
                next_node = Node(next_level, current.value, current.weight, 0)
                next_node.bound = bound(next_node, n, capacity, weights, values)
                if next_node.bound > max_value:
                    heapq.heappush(queue, next_node)

    return max_value


# Example usage
weights = [1, 2, 3]
values = [6, 10, 12]
capacity = 5
print("Knapsack using Branch and Bound:", knapsack_branch_and_bound(weights, values, capacity))
