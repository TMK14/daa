import pprint
profit = [10, 15, 10, 12, 8]
weight = [3, 3, 2, 5, 1]
n = len(profit)
SizeofBuck = 10
currSize = 0
sumofProfit = 0
PWRatio = []

for i in range(n):
    PWRatio.append(profit[i] / weight[i])

Dict1 = {}
for i in range(n):
    Dict1[i] = {
        'fraction': PWRatio[i],
        'profit': profit[i],
        'weight': weight[i]
    }

pprint.pprint(Dict1, sort_dicts=False)

def knapsack(Dict1, currSize, sumofProfit):
    if not Dict1 or currSize >= SizeofBuck:
        return sumofProfit

    M = max(Dict1, key=lambda k: (Dict1[k]['fraction'], Dict1[k]['profit']))
    if currSize + Dict1[M]['weight'] <= SizeofBuck:
        currSize += Dict1[M]['weight']
        sumofProfit += Dict1[M]['profit']
    else:
        remainSize = SizeofBuck - currSize
        fraction = (remainSize / Dict1[M]['weight']) * Dict1[M]['profit']
        currSize += remainSize
        sumofProfit += fraction

    Dict1.pop(M)
    return knapsack(Dict1, currSize, sumofProfit)  # Recursive call

maxProfit = knapsack(Dict1, currSize, sumofProfit)



print(f"Maximum Profit Possible is {maxProfit} with a maximum weight of {SizeofBuck}")
