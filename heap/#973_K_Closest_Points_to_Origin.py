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
# can be further optimized with max heap or quick select
