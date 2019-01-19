/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int cmpfunc (const void * a, const void * b)
{
   return ( ((struct Interval*)a)->start - ((struct Interval*)b)->start );
}

int max(int a, int b){
    if(a>b){return a;}return b;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval * ret = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    if(intervalsSize == 0){
        *returnSize = 0;
        return ret;
    }

    qsort(intervals, intervalsSize, sizeof(struct Interval), cmpfunc);
    int index=0;
    ret[index].start = intervals[0].start; ret[index].end = intervals[0].end;
    for(int i = 1; i < intervalsSize; i++){
        struct Interval cur = intervals[i];
        if(cur.start <= ret[index].end){
            ret[index].end = max(ret[index].end , cur.end);
        } else {
            index++;
            ret[index].start = cur.start;
            ret[index].end = cur.end;
        }
    }
    *returnSize = index + 1;
    return ret;
}