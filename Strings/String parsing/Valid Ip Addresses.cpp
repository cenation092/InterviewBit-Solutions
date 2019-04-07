vector<vector<int> > ar;
vector<int> ip(4);

int toInt( string s ){
    int num = 0;
    for( auto it : s ){
        num = num * 10 + (it - '0');
    }
    return num;
}

void go( string s, int dot, int idx ){
    if( dot == 4 ){
        if( ip[3] == s.size()-1 )ar.push_back(ip);
        return;
    }
    for( int i = 0; i < 3; i++ ){
        if( idx+i < s.size() ){
            ip[dot] = idx+i;
            go( s, dot+1, idx+i+1);
        }
    }
}


vector<string> Solution::restoreIpAddresses(string A) {
    ar.clear();
    go(A, 0, 0);
    vector<string> v;
    for( int i = 0; i < ar.size(); i++ ){
        int idx = 0;
        int flag = 1;
        string s = "";
        for( int j = 0; j < 4; j++ ){
            if( A[idx] == '0' && idx < ar[i][j] ){
                flag = 0;
                break;
            }
            string cur = "";
            for( ; idx <= ar[i][j]; idx++ ){
                cur += A[idx];
            }
            int num = toInt(cur);
            if( num > 255 )flag = 0;
            s += cur;
            if( j != 3 )s += '.';
        }    
        if( flag ){
            v.push_back(s);
        }
    }
    return v;
}
