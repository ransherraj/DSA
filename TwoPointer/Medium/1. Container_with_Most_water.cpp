int calculateArea(int i, int j, int hi, int hj){
        return ((j - i) * min(hj, hi));
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1, maxArea = 0;
        while(i < j){
            maxArea = max(maxArea, calculateArea(i, j, height[i], height[j]));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
