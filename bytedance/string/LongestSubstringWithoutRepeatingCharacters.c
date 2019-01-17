// 无重复最长子串
// 思路比较巧, 单次遍历即可处理完成
// 守住一个合法区间, 当出现已存在的字母时, 抛弃该字母上次出现的位置及其以前的位置
// 每步遍历尝试更新最大值

int max(int a, int b){
    if(a > b){return a;}else{return b;}
}

int lengthOfLongestSubstring(char* s) {
    int exists[256];
    memset(exists, -1, 256*sizeof(int));

    int index=0, left=-1, ret=0;
    while (s[index] != '\0'){
        char ord_c = s[index];
        left = max(left, exists[ord_c]);
        exists[ord_c] = index;
        ret = max(index-left, ret);
        index++;
    }
    return ret;
}