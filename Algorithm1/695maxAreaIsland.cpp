class Solution1 { 
public:
      int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
        return max_area;
    }
    
    int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
        }
        return 0;
    }
};


class Solution2 {  //  1364 ms, 575 MB
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        bool fst = true;
        int maxi = 0;
        int cur = 0;
        for(int i =0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size();j++){
                if(  grid[i][j] == 1 ){
                    cur = explore(grid,i , j);
                    if(fst){fst = false;maxi = 1;}
                }
                if( cur > maxi )maxi = cur;
            }
        }
        return maxi;
    }
    int explore(vector<vector<int>> a,int i , int j){
        int m = a.size();
        int n = a[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        int area = 0; 
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int x = i+1; int y = j;
            if(  x >= 0 && y >= 0 && x < m && y < n && a[x][y] ==  1  ){
                a[x][y] = 0;
                q.push(make_pair(x,y));
                area++;
            }
            x = i; y = j + 1;
            if(  x >= 0 && y >= 0 && x < m && y < n && a[x][y] ==  1  ){
                a[x][y] = 0;
                q.push(make_pair(x,y));
                area++;
            }
            x = i - 1; y = j;
            if(  x >= 0 && y >= 0 && x < m && y < n && a[x][y] ==  1  ){
                a[x][y] = 0;
                q.push(make_pair(x,y));
                area++;
            }
            x = i; y = j - 1;
            if(  x >= 0 && y >= 0 && x < m && y < n && a[x][y] ==  1  ){
                a[x][y] = 0;
                q.push(make_pair(x,y));
                area++;
            }
        }
        return area;
    }
};