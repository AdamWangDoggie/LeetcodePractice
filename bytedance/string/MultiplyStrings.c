// 字符串相乘, 比较简单
// 全部转化为一位数相乘, 加到目标字符串上, 处理好进位

#include <strings.h>
#include <stdlib.h>
#include <memory.h>

int value(char a){
    return a - '0';
}

void single_add(char* target, int index, char a){
    int add = 0;
    int result = value(target[index]) + value(a);
    add = result / 10; target[index] = '0' + result % 10;
    index--;
    while(add){
        result = value(target[index]) + 1;
        add = result / 10; target[index] = '0' + result % 10;
        index--;
    }
}

char * multiply(char* num1, char* num2) {
    int sz1 = strlen(num1);
    int sz2 = strlen(num2);
    int szres = sz1 + sz2;
    char * res = (char * )malloc((szres+1)*sizeof(char));
    memset(res, '0', sizeof(char)*(szres));
    res[szres] = '\0';
    for(int i = 0; i < sz1; i++){
        int index1 = sz1 - i - 1;
        char cur_char1 = num1[index1];
        for(int j = 0; j < sz2; j++){
            int index2 = sz2 - j - 1;
            char cur_char2 = num2[index2];
            int to_add_index = szres - i - j - 1;
            int multi_res = value(cur_char1) * value(cur_char2);
            while(multi_res){
                single_add(res, to_add_index, '0' + multi_res % 10);
                multi_res = multi_res / 10;
                to_add_index--;
            }
        }
    }
    while(*res == '0' && *(res+1)!='\0'){
        res++;
    }
    return res;
}


int main(){
    char a[2] = "0", b[2] = "0";
    char* res = multiply(a, b);
    return 1;
}