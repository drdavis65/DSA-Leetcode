class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        minPrice = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
                continue
            prof = prices[i] - minPrice
            if prof > res:
                res = prof
        return res

