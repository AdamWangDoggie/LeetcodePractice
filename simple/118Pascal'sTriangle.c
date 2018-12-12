// https://leetcode-cn.com/problems/pascals-triangle/description/
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



#include <stdlib.h>

int** generate(int numRows, int** columnSizes) {
    int ** ret = (int **)malloc(sizeof(int *)*numRows);
    int * sizes = (int *)malloc(sizeof(int)*numRows);
    if(numRows >= 1){
        sizes[0] = 1; 
        ret[0] = (int *)malloc(sizeof(int));
        ret[0][0] = 1;
    }
    for(int i = 1; i < numRows; i++){
        sizes[i] = i+1;
        ret[i] = (int*)malloc(sizeof(int)*(i+1));
        ret[i][0] = 1; ret[i][i] = 1;
        for(int j = 1; j < i; j++){
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    *columnSizes = sizes; 
    return ret;
}