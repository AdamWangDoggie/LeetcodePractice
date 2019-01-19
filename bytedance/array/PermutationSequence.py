# 第K个排列

class Solution:
    def mul(self, n):
        # 阶乘
        ret = 1
        while n:
            ret *= n
            n = n-1
        return ret

    def rec(self, nums, k):
        print(nums)
        n = len(nums)
        if k == 0:
            return list(reversed(nums))
        if k == 1:
            return nums

        poss = self.mul(n-1) #1
        head = (k-1) // poss  # 确定第一个数用哪个 1
        cur = nums[head] 
        nums.remove(cur)  # 去掉该数

        return [cur] + self.rec(nums, k % poss)

    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = [i+1 for i in range(n)]

        seq = self.rec(nums, k)
        return "".join([str(s) for s in seq])
