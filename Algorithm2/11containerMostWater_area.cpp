class Solution {
public:
    int maxArea(vector<int>& height) {
        long maxi = 0;
        int i= 0;
        int j = height.size()-1;
        while(i < j){
            if(maxi < (j-i)*min(height[i],height[j]))maxi = (j-i)*min(height[i],height[j]);
            if(height[i] > height[j] )j--;
            else i++;
        }
        return maxi;
    }
};