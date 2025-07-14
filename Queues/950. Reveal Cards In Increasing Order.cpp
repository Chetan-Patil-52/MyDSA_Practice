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


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        vector<int> result(n);
        queue<int> que;

        for(int i=0;i<n;i++){
            que.push(i);
        }

        sort(begin(deck),end(deck));

        for(int i=0;i<n;i++){
            int idx = que.front();
            que.pop();

            result[idx] = deck[i];

            if(!que.empty()){
                que.push(que.front());
                que.pop();
            }

        }
        return result;
    }
};
