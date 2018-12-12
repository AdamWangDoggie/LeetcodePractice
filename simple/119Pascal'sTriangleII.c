// https://leetcode-cn.com/problems/pascals-triangle-ii/description/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

// 原地写就完事了
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* num = (int*) malloc((rowIndex + 1) * sizeof (int));
    for (int i = 0; i <= rowIndex; i++){
        for (int j = i; j >= 0; j--){
            if (j == 0 || j == i)
                num[j] = 1;
            else
                num[j] = num[j] + num[j - 1];
        }
    }
    return num;
}
