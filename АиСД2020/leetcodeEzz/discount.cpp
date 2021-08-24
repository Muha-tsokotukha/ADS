class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        for(int i = 0; i < prices.size(); i++){
            bool dsc = 0;
            for(int j = i+1; j < prices.size(); j++){
                if( prices[i] >= prices[j] ){
                    ans[i] = prices[i] - prices[j];
                    dsc = 1;
                    break;
                }
            }
            if(  !dsc )ans[i] = prices[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return prices;
    }
};
//Approach-2(3) (Using stack and an improvement over 2nd approach)
//You can do it in one Pass. How ?
/*
	prices = {8,   4,   6,   2,   3}
	Start from i = 0th index, stack is empty so put index of 0th element on stack
	stack = {0}
	------------------------
	i = 1
	Check stack's top element. Since prices[stack.top()] >= prices[i]
	It means it's the next smaller element for stack.top() element.
	So, decrement prices[stack.top()] by prices[i]. And then pop from stack for other elements
	if present. Then put i = 1 on stack for future operations
	prices = {4, 4, 6, 2, 3}
	
	so on.
*/