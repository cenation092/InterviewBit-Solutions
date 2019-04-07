
int Solution::compareVersion(string A, string B) {
    vector<string> a, b;
    for( int i = 0; i < A.size(); i++ ){
        string temp = "";
        while(i < A.size() && A[i] != '.' ){
            if( temp.size() == 0 && A[i] == '0'){}
            else temp += A[i];
            i++;
        }
        if( temp.size() > 0 )a.push_back(temp);
    }
    for( int i = 0; i < B.size(); i++ ){
        string temp = "";
        while(i < B.size() && B[i] != '.' ){
            if( temp.size() == 0 && B[i] == '0'){}
            else temp += B[i];
            i++;
        }
        if( temp.size() > 0 )b.push_back(temp);
    }
    for( int i = 0; i < min(a.size(), b.size()); i++ ){
        if( a[i].size() > b[i].size() )return 1;
        else if( a[i].size() < b[i].size() )return -1;
        else{
            for( int j = 0; j < a[i].size(); j++ ){
                if( a[i][j] > b[i][j] )return 1;
                else if( a[i][j] < b[i][j] )return -1;
            }
        }
    }
    if( a.size() == b.size() )return 0;
    if( a.size() > b.size() )return 1;
    return -1;
}
