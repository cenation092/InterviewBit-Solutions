int ar[100][100];
int n;
vector<vector<string> > ans;

bool safe( int x, int y ){
    for( int j = 0; j < n; j++ ){
        if( ar[x][j] == 1 )return 0;
    }
    for( int i = 0; i < n; i++ ){
        if( ar[i][y] == 1 )return 0;
    }
    int i = x, j = y;
    while( i >= 0 && j >= 0 ){
        if( ar[i][j] == 1 )return 0;
        i--, j--;
    }
    i = x, j = y;
    while( i < n && j < n ){
        if( ar[i][j] == 1 )return 0;
        i++, j++;
    }
    i = x, j = y;
    while( i >= 0 && j < n ){
        if( ar[i][j] == 1 )return 0;
        i--, j++;
    }
    i = x, j = y;
    while( i < n && j >= 0 ){
        if( ar[i][j] == 1 )return 0;
        i++, j--;
    }
    return 1;
}

void go( int x, int y, int left ){
    if( left == 0 ){
        vector<string> v;
        for( int i = 0; i < n; i++ ){
            string s = "";
            for( int j = 0; j < n; j++ ){
                if( ar[i][j] == 0 )s += '.';
                else s += 'Q';
            }
            v.push_back(s);
        }
        ans.push_back(v);
        return;
    }
    for( int i = x; i < n; i++ ){
        for( int j = y; j < n; j++ ){
            if( ar[i][j] == 0 && safe(i, j) ){
                //cout << "safe\n";
                ar[i][j] = 1;
                go(i+1, 0, left-1);
                ar[i][j] = 0;
            }
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    memset(ar, 0, sizeof(ar));
    ans.clear();
    n = A;
    go(0, 0, A);
    return ans;
}
