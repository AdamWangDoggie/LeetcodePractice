# 复原IP地址, 比较蛋疼,  用python
class Solution(object):
    def valid(self, s):
        if len(s) == 1:
            return 0 <= int(s)
        elif len(s) == 2:
            return s[0] != '0' and 0 <= int(s)
        elif len(s) == 3:
            return s[0] != '0' and 0 <= int(s) <= 255
        else:
            return False

    def rec(self, s, pieces):
        if pieces == 1:
            if self.valid(s):
                return [s]
            else:
                return []

        res = []
        for k in range(1, 4):
            nk = s[:k]
            if self.valid(nk):
                rem = s[k:]
                for tmp in self.rec(rem, pieces - 1):
                    res.append(nk + "." + tmp)
        return res

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        return self.rec(s, 4)


if __name__ == "__main__":
    s = Solution()
    inp = "010010"
    res = s.restoreIpAddresses(inp)
    print(res)
