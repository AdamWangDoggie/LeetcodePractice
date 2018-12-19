//https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/

int trailingZeroes(int n) {
    int i2=0, i5=0;
    
    for(int t = n/2; t > 0 ; t/=2){
        i2+=t;
    }
    for(int t = n/5; t > 0; t/=5){
        i5+=t;
    }

    int ret = 0;
    if(i2 > i5){ ret += i5; }
    else {ret += i2;}
    return ret;
}