# 最长连续子序列, 要用hash, 所以用pyhton做
# 用C也能做, 只是hash会比较难确定, 而用基数数组(用值作为索引的数组)的话, 对负数又要额外处理, 且会浪费空间
# 用链表的话, 查找需要遍历, 最坏会到O(n^2)

# 思路1: 用字典维护该数字所处的连续序列的长度, 遍历时对每个点, 取到其左右的数, 左边长度+右边长度+1 = 新序列的长度
class Solution(object):
    def longestConsecutive(self, nums):
        hash_dict = dict()
        max_length = 0
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num - 1, 0)
                right = hash_dict.get(num + 1, 0)
                
                # 每个数字均代表其所处连续子序列的长度就ok
                cur_length = 1 + left + right
                if cur_length > max_length:
                    max_length = cur_length
                
                hash_dict[num] = cur_length
                # 只更新头尾, 因为新元素加入连续子序列 只会接触到头尾
                hash_dict[num - left] = cur_length
                hash_dict[num + right] = cur_length
                
        return max_length

# 思路2: 用set当作hash, 且做了去重; 只处理连续序列的头, 找到头则向后遍历至尾, 记录并更新长度
# 对于非头的数字, 仅做判断, 无处理
# 时间复杂度O(n + k); k为所有连续子序列长度之和(k <= n), 故符合O(n)
# 用C写的话借鉴这种思路比较棒
class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums=set(nums)
        ma=0
        for x in nums:
            if x-1 not in nums:
                y=x+1
                while y in nums:
                    y+=1
                ma=max(ma,y-x)
        return ma