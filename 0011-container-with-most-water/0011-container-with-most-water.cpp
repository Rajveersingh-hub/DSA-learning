class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int l=j-i;
            int area=h*l;
            maxarea=max(area,maxarea);
            if(height[i]<=height[j]){
                i++;
            }
            else{
            j--;
            }
        }
return maxarea;
    }
};