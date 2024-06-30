class Solution {
public:
    
    int maxHeight(int red, int blue){
        int height = 0;
        int currRow = 1;
        
        while(true){
            if(currRow % 2 != 0){
                if(red >= currRow){
                    red = red - currRow;
                    height ++;
                }
                else{
                    break;
                }
            }
            else{
                if(blue >= currRow){
                    blue = blue - currRow;
                    height++;
                }
                else{
                    break;
                }
            }
            currRow ++;
        }
        return height;
    }
    
    
    int maxHeightOfTriangle(int red, int blue) {
        
        return max(maxHeight(blue, red), maxHeight(red, blue));
       
    }
};