int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int vis[21][21];

int isSafe(int x, int y, vector<vector<int> > &A ){
    int n = A.size();
    int m = A[0].size();
    if( x < 0 || y < 0 || x >= n || y >= m )return 0;
    return 1;
}

int go(int x, int y, vector<vector<int>> &A ){
    if( A[x][y] == 2 ){
        int flag = 1;
        for( int i = 0; i < A.size(); i++ ){
            for( int j = 0; j < A[0].size(); j++ ){
                if( A[i][j] == 0 && !vis[i][j] )flag = 0;
            }
        }
        return flag;
    }
    int cnt = 0;
    for( int i = 0; i < 4; i++ ){
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if( isSafe(X, Y, A) && !vis[X][Y] && A[X][Y] != -1 ){
            vis[X][Y] = 1;
            cnt += go(X, Y, A);
            vis[X][Y] = 0;
        }
    }
    return cnt;
}

int Solution::solve(vector<vector<int> > &A) {
    memset(vis, 0, sizeof(vis));
    int x,  y;
    for( int i = 0; i < A.size(); i++ ){
        for( int j = 0; j < A[0].size(); j++ ){
            if( A[i][j] == 1 )x = i, y = j;
        }
    }
    vis[x][y] = 1;
    return go(x, y, A);
}
