

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