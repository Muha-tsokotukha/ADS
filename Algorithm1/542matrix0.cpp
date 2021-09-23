class Solution { // dp
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};



class Solution2 { // time limit
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        for(int i = 0; i < mat.size(); i++){
            vector<int> row;
            for(int j = 0; j < mat[i].size(); j++){
                if( mat[i][j] == 0 )row.push_back(0); 
                else{
                    queue<pair<int,int>> q;
                    map<pair<int,int>, bool > used;
                    q.push(make_pair(i,j));
                    
                    int p,w;
                    while( !q.empty() ){
                        
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        int f,s;
                        f = x + 1; s = y;
                        
                        if(  f >=  0 && s >= 0 && f < mat.size() && s < mat[0].size() && !used[make_pair(f,s)]   ){
                            if( mat[f][s] == 0 ){
                            p = f;
                            w = s;
                            break;}
                            q.push(make_pair(f,s));
                            used[make_pair(f,s)] = true;
                        }
                        f = x ; s = y+1;
                                                    
                        if(  f >=  0 && s >= 0 && f < mat.size() && s < mat[0].size() &&  !used[make_pair(f,s)]   ){
                            if( mat[f][s] == 0 ){
                            p = f;
                            w = s;
                            break;}
                            q.push(make_pair(f,s));
                            used[make_pair(f,s)] = true;
                        }
                        f = x - 1; s = y;
                        
                        if(  f >=  0 && s >= 0 && f < mat.size() && s < mat[0].size() && !used[make_pair(f,s)]   ){
                            if( mat[f][s] == 0 ){
                            p = f;
                            w = s;
                            break;}
                            q.push(make_pair(f,s));
                            used[make_pair(f,s)] = true;
                        }
                        f = x ; s = y-1;
                        
                        if(  f >=  0 && s >= 0 && f < mat.size() && s < mat[0].size()  && !used[make_pair(f,s)]   ){
                            if( mat[f][s] == 0 ){
                            p = f;
                            w = s;
                            break;}
                            q.push(make_pair(f,s));
                            used[make_pair(f,s)] = true;
                        }
                        
                    }   
                    int cnt = abs(p - i) + abs(w - j);
                    row.push_back(cnt);
                }
                
            }
            ans.push_back(row);
        }
        return ans;
    }
};