// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/


int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    for(int i = 0; i< pricesSize -1; i++){
        if(prices[i+1] - prices[i] > 0){
            max += prices[i+1] - prices[i];
        }
    }   
    return max;
}