# O(k*logn)
# min heap
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def getDistance(point):
            return math.sqrt(point[0] ** 2 + point[1] ** 2)
        heap = [(getDistance(point), point) for point in points]
        heapq.heapify(heap)
        res = []
        for _ in range(k):
            res.append(heapq.heappop(heap)[1])
        return res
# O(n*logk)
# max heap
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def getDistance(point):
            return math.sqrt(point[0] ** 2 + point[1] ** 2)
        heap = []
        for point in points:
            heapq.heappush(heap, (-getDistance(point), point))
            if len(heap) > k:
                heapq.heappop(heap)
        res = []
        for _ in range(k):
            res.append(heapq.heappop(heap)[1])
        return res

# can be further optimized quick select
