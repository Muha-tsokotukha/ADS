//Imagine mat as how it would be stored in computer memory (strip of 1-D array)
        /*
            [[1,2]
             [3,4]]
            
            Can be visualized as :
            
	element		              1      2      3     4
    Address                [0][0], [0][1], [1][0], [1][1]
    visualization index       0      1       2       3
               
            Notice that in 2-D matrix, column starts from 0, goes till some limit,
            and then starts from 0 and then goes till limit
            So, whenever you notice a scenario where a value
            is doing a cycle (0 to 1 and back to 0 and then to 1 and so on)
            modulo operation comes to rescue (%). It helps
            to rewind the value from where it satarted after reaching limit.
            
            Similarly, we can assume the reshaped matrix as 1-d visualiztion
            
            So, for finding the column, it's easy just do a modulo operation
			on index where you are right now.
            And for rows, notice that the visualized 1-d array is actually
			cut by number of columns. So, when we divide (/) index by
			number of column, we get the row number
            
            This is an important concept which is used in many other questions.
            
            mat[0][0] can be written  = mat[i/n][i%n]
            
            Similarly, newMat[0][0] = newMat[i/c][i%c]
        */
       
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(n*m != r*c)return mat;
        vector<vector<int>>v(r, vector<int>(c,0));
        for(int i = 0; i<r*c; i++)        
            v[i/c][i%c] = mat[i/n][i%n];
        return v;
    }
};