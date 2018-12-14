

vector<int> Solution::flip(string A) {
    int Max = 0;
    int n = A.size();
    for( int i = 0; i < n; i++ ){
        Max += (A[i] == '1');
    }
    int l = 0;
    int L = 0, R = 0;
    int ans = Max;
    int one = 0, zero = 0;
    for( int i = 0; i < n; i++ ){
        if( A[i] == '1' )one++;
        else zero++;
        while( one > zero && l <= i ){
            if( A[l] == '1' )one--;
            else zero--;
            l++;
        }
        int sum = Max - one + zero;
        if( sum > ans ){
            ans = sum;
            L = l, R = i;
        }
    }
    L++, R++;
    vector<int> ar;
    if( ans > Max ){
        ar.push_back(L);
        ar.push_back(R);
    }
    return ar;
}
