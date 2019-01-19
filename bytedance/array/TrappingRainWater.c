// 接雨水

int trap(int* height, int heightSize) {
    int max = 0, max_index = -1;
    for(int i = 0; i < heightSize; i++){
        if(height[i]>max){max=height[i]; max_index = i;}
    }

    int ret = 0;
    max = 0;
    for(int i = 0; i < max_index; i++){
        if(height[i] > max){ max = height[i]; }
        ret += max - height[i];
    }
    max = 0;
    for(int i = heightSize - 1; i > max_index; i-- ){
        if(height[i] > max){ max = height[i]; }
        ret += max - height[i];
    }

    return ret;
}