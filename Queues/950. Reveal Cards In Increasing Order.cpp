class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n =deck.size();
        int j =0,i=0;
        vector<int> result(n,0);
        sort(begin(deck),end(deck));

        bool flag = false;

        while(i<n){

            if(deck[j]==0){

                if(flag==false){
                    result[j] = deck[i];
                    i++;
                }
                flag = !flag;

            }
            j = (j+1)%n;
        }
        return result;
    }
};
