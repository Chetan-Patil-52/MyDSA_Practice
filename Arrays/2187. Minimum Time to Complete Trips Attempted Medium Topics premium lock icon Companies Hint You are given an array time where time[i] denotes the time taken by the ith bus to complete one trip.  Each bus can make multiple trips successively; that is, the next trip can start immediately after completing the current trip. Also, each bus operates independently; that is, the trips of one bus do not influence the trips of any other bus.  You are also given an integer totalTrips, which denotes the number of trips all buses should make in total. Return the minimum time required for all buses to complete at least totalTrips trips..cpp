// Your current	O(N * answer)	Up to 1e12
// Binary Search	O(N * log(answer))	~40
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long timeReq = 1;
        int tripsCompleted = 0;
        while(true){
            tripsCompleted = 0;
            for(int v : time){
                tripsCompleted += (int)timeReq/v;
            }
            if(tripsCompleted >= totalTrips) break;
            timeReq++;
        }
        return timeReq;
    }
};

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long timeReq = 1;
        

        long long mini = INT_MAX;
        for(long long num : time){
            mini = min(mini,num);
        }

        long long l = 1;
        long long  r = mini * (long long) totalTrips;
        long long result = r;

        while(l<=r){
            long long mid = l + (r-l)/2;
            long long tripsCompleted = 0;
            // timeReq = mid;

            for(auto v : time){
                tripsCompleted += mid/v;
                if(tripsCompleted >= totalTrips) break;
            }
            if(tripsCompleted>=totalTrips){
                result = mid;
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }

        return result;
    }
};
