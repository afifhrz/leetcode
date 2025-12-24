class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse=True)
        totalApples = sum(apple)
        boxesUsed = 0
        for cap in capacity:
            totalApples -= cap
            boxesUsed += 1
            if totalApples <= 0:
                return boxesUsed