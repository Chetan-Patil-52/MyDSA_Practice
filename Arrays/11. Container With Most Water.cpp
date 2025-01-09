class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        // Bruteforce TLE O(n^2)
        // int w=0,h=0,area=0;
        // for(int i =0;i<n;i++){
        //     for(int j=n-1;j>0;j--){
        //         w = j-i;
        //         h = min(height[i],height[j]);
        //         area = max(area,w*h);
        //     }
        // }
        // Approach-2 O(n)
        int i = 0;
        int j = n-1;
        int h=0,w=0,a=0;
        while(i<j){
            w = j-i;
            h = min(height[i],height[j]);
            a = max(a,h * w);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }         
        }
        return a;
    }
};
