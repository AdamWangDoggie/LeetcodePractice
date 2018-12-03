// https://leetcode-cn.com/problems/reverse-integer/description/

int reverse(int x) {
    int ret = 0; //需要返回的数
    while(x)
    {
        int tmp = ret; //暂存y的值
        ret = ret * 10 + x % 10; //倒序；把x的最低位依次压入y的最低位
        if((ret - x % 10) / 10 != tmp) //反向推，若推不出原值则溢出
        {
            return 0;
        }
        x /= 10;
    }
    return ret;
}

// Highlight: 通过反推是否与原数相等来判断是否越界, 非常棒
// 什么看符号是行不通的, 可能直接越界超过偶数次