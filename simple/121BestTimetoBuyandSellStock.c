// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/

int max(int a, int b){
    return a > b ? a : b; 
}

int min(int a, int b){
    return a < b ? a : b;
}

// 最低买, 最高卖就完了- -
int maxProfit(int* prices, int pricesSize) {
    
    int minBuy = prices[0];
    int maxPro = 0;
    int i;
    
    // 每次更新最低价, 同时更新最大收益, 在试探最低买入价的同时, 试探收益
    for(i = 0; i < pricesSize; i++){
        minBuy = min(minBuy, prices[i]);
        maxPro = max(maxPro, prices[i] - minBuy);
    }
    
    return maxPro;
}
int main(){
    int prices[6] = {7,1,5,3,6,4};
    int ret = maxProfit(prices, 6);
    return 1;
}