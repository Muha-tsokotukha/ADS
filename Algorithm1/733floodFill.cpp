class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if( image[sr][sc] == newColor   )return image;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int fstColor = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int x = i+1; int y = j;
            if(  x >= 0 && y >= 0 && x < m && y < n && image[x][y] ==  fstColor  ){
                image[x][y] = newColor;
                q.push(make_pair(x,y));
            }
            x = i; y = j + 1;
            if(  x >= 0 && y >= 0 && x < m && y < n && image[x][y] ==  fstColor  ){
                image[x][y] = newColor;
                q.push(make_pair(x,y));
            }
            x = i - 1; y = j;
            if(  x >= 0 && y >= 0 && x < m && y < n && image[x][y] ==  fstColor  ){
                image[x][y] = newColor;
                q.push(make_pair(x,y));
            }
            x = i; y = j - 1;
            if(  x >= 0 && y >= 0 && x < m && y < n && image[x][y] ==  fstColor  ){
                image[x][y] = newColor;
                q.push(make_pair(x,y));
            }
        }
        return image;
    }
};