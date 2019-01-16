#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int * cpy(int * org, int size){
    int *ret = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        ret[i] = org[i];
    }
    return ret;
}

bool vld(int * char_cnt, int size, char * s){
    int * tmp = cpy(char_cnt, 256);
    for(int i = 0; i < size; i++){
        char c = s[i];
        if(c == '\0' || tmp[s[i]] <= 0){ 
            return false; 
        }
        tmp[s[i]]--;
    }
    return true;
}

bool MycheckInclusion(char* s1, char* s2) {
    int char_cnt[256]; int size=0;
    memset(char_cnt, 0, sizeof(int)*256);
    for(int t = 0; s1[t] != '\0'; t++){
        char_cnt[s1[t]]++; size++;
    }
    for(int t = 0; s2[t]!= '\0'; t++){
        if(vld(char_cnt, size, s2+t)){
            return true;
        }
    }
    return false;
}


bool checkInclusion(char* s1, char* s2) {
    if(NULL == s1 || NULL == s2)
        return false;
    int book[26] = {0};
    int have[26] = {0};
    memset(have, 0, 26*sizeof(int));
    memset(book, 0, 26*sizeof(int));
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    int sign=0;
    for (int i=0;i<sz1;i++)
    {
        book[s1[i]-'a']+=1;
        have[s1[i]-'a']+=1;
    }
    for (int i=0;i<sz2;i++)
    {
        int letter_index = s2[i] - 'a';
        if(book[letter_index] != 0){
            // 如果在book中存在该字符, sign+1, book中对该字母的计数-1
            sign++; book[letter_index]--;
        }
        else if(have[letter_index] == 0){
            // 如果have中该字母的计数为0, 代表根本不存在该字母, 重置sign, 并将book中的计数还原
            for(;sign>0;sign--){
                // 对s2从当前位置逐个倒退, 将book中的计数加回来
                book[s2[i-sign]-'a']++;
            }
        }
        else if(book[letter_index] == 0 && have[letter_index] != 0){
            // book中该字母的计数已经为0, 但have中不为0, 即原s2中的确有该字母
            while(s2[i-sign] != s2[i]) {
                // 从上次计数开始(sign第一次+1的位置), 找到该字母上次出现的位置, 将中间的所有字母撤销
                book[s2[i-sign]-'a']++; 
                sign--;
            }
        }
        if(sz1 == sign)
            return true;
    }
    return false;
}
/*
三种情形决策:
1. s2中存在该字母, 且仍有可用计数, 则正常计数 
2. s1中根本不存在该字母, 回退到初始状态
3. s1中存在该字母, 但s2中已无可用计数, 则从第一次计数的起点(i-sign)开始, 撤到该字母下一次出现的地方
则一次遍历s2即可完成
*/


int main(){
    char a[4] = "abc";
    char b[9] = "caafdaab";
    bool c = checkInclusion(a, b);
    return 1;
}