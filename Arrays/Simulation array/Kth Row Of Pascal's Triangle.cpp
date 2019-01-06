vector<int> Solution::getRow(int n) {
    vector<int> a, b;
    b.push_back(1);
    b.push_back(1);
    if( n == 0 ){
        a.push_back(1);
        return a;
    }
    for( int i = 2; i <= n; i++ ){
        a.push_back(1);
        for( int j = 1; j < i; j++ ){
            a.push_back(b[j-1]+b[j]);
        }
        b.clear();
        a.push_back(1);
        b = a;
        a.clear();
    }
    return b;
}
