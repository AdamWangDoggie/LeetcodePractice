# https://leetcode-cn.com/problems/happy-number/submissions/

class Solution:
    @staticmethod
    def next_(n):
        ret = 0
        while n:
            ret += (n % 10) ** 2
            n //= 10
        return ret
        
        
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        a = set()
        while n:
            if n == 1:
                return True
            if n in a:
                return False
            a.add(n)
            n = self.next_(n)
            