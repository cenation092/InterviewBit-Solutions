int dx[] = {-1, -1, 1, 1, -1, 0, 0, 0, 1};
int dy[] = {-1, 1, -1, 1, 0, -1, 0, 1, 0};

struct line{
    int x1,y1,x2,y2;
    int ass(int a, int b, int c, int d ){
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
};

line left(int x, int y, int A){
    int top_x, top_y;
    int sub = min(x-1, y-1);
    top_x = x-sub;
    top_y = y-sub;
    
    int add = min(A-x, A-y);
    int bot_x, bot_y;
    bot_x = x+add;
    bot_y = y+add;
    line L;
    L.ass(top_x, top_y, bot_x, bot_y);
    return L;
}

line right( int x, int y, int A){
    int top_x, top_y;
    int sub = min(x-1, A-y);
    top_x = x-sub;
    top_y = y+sub;
    int bot_x, bot_y;
    int add = min(A-x, y-1);
    bot_x = x+add;
    bot_y = y-add;
    line L;
    L.ass(top_x, top_y, bot_x, bot_y);
    return L;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    map<pair<int,int>, int> fre;
    map<pair<pair<int,int>, pair<int,int> >, int > s;
    map<int, int> X, Y;
    for( auto it : B ){
        int x = it[0], y = it[1];
        x++, y++;
        if( fre[make_pair(x,y)] > 0 )continue;
        fre[make_pair(x,y)]++;
        X[x]++;
        Y[y]++;
        line a = left(x, y, A);
        s[make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2))]++;
        a = right(x, y, A);
        s[make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2))]++;
    }
    vector<int> ans;
    for( auto it : C ){
        int x = it[0], y = it[1];
        x++, y++;
        pair<pair<int,int>, pair<int,int> > a1;
        pair<pair<int,int>, pair<int,int> > a2;
        line a = left(x, y, A);
        a1 = (make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2)));
        a = right(x, y, A);
        a2 = (make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2)));
        if( s.count(a1) ){
            ans.push_back(1);
        }
        else if( s.count(a2) ){
            ans.push_back(1);
        }
        else if( X.find(x) != X.end() ){
            ans.push_back(1);
        }
        else if( Y.find(y) != Y.end()){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
        for( int i = 0; i < 9; i++ ){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if( xx < 1 || yy < 1 || xx > A || yy > A )continue;
            if( fre.count(make_pair(xx,yy)) > 0 ){
                a = left(xx, yy, A);
                a1 = (make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2)));
                if( s.count(a1) ){
                    s[a1]--;
                    if( s[a1] == 0 )s.erase(a1);
                }
                a = right(xx, yy, A);
                a1 = (make_pair(make_pair(a.x1, a.y1), make_pair(a.x2, a.y2)));
                if( s.count(a1) ){
                    s[a1]--;
                    if( s[a1] == 0 )s.erase(a1);
                }
                X[xx]--;
                Y[yy]--;
                if( X[xx] == 0 )X.erase(xx);
                if( Y[yy] == 0 )Y.erase(yy);
                fre[make_pair(xx,yy)]--;
                if( fre[make_pair(xx,yy)] == 0 )fre.erase(make_pair(xx,yy));
            }
        }
    }
    return ans;
}
