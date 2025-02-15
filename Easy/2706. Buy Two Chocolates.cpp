class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int orig = money;
        int smallest=INT_MAX,sSmallest=INT_MAX;
        for(int num : prices){
            if(num < smallest){
                sSmallest = smallest;
                smallest = num;
            }else{
                sSmallest = min(sSmallest,num);
            }
        }
        money -= smallest;
        money -= sSmallest;
        
        return (money >= 0 ? money : orig);

        // sort(begin(prices),end(prices));
        // int orig_money = money;
        // money -= prices[0];
        // money -= prices[1];
        // if(money >= 0){
        //     return money;
        // }
        // return orig_money;
    }
};

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int price = prices[0]+prices[1];
        int leftover = 0;
        if(price <= money){
            leftover = abs(price - money);
        }else{
            return money;
        }
