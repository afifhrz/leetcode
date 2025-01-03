class Solution:
    def findCircleNum(self, is_connected) -> int:
        def visit_from(x: int, seen: set[int]) -> bool:
            return seen.add(x) or all(visit_from(y, seen) for y, c in enumerate(is_connected[x]) if y not in seen and c)

        seen = set()
        return sum((x not in seen) and visit_from(x, seen) for x in range(len(is_connected)))
    
create = Solution()
isConnected = [[1,0,0],[0,1,0],[0,0,1]]
print(create.findCircleNum(isConnected))