class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
		//get index of first positive number		
        int r = lower_bound( begin(nums), end(nums), 0 ) - begin(nums);
        vector<int> sqr{};
        
        //negative numbered squares are compared ( r-1 to 0 ) in reverse fashion 
		//with positive squares ( r-1 to nums.size() -1 ) both inclusive
        int i = r-1, j = r;
		while( i >= 0 and j < nums.size() ){  //loop until end of negative numbers or postive numbers
            
            if( nums[i]*nums[i] > nums[j]*nums[j] ){
                
                sqr.push_back( nums[j]*nums[j] );
                j++;
                
            }else{
                
                sqr.push_back( nums[i]*nums[i]  );
                i--;
            }                
        }
        
        //fill up if there are any negative numbers left
        while( i >= 0 ){
            
            sqr.push_back( nums[i]*nums[i]  );
            i--;
            
        }
        
        //fill up if there are any positive numbers left
			while( j < nums.size() ){
                
            sqr.push_back( nums[j]*nums[j] );
            j++;
        }
        
        return sqr;
        
        
    }
};