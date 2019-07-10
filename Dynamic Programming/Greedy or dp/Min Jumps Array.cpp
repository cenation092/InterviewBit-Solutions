int Solution::jump(vector<int> &A) {
    int n = A.size();
    if( n <= 1 )return 0;
    int have = A[0];
    int Max = A[0];
    int ans = 1;
    for( int i = 1; i < A.size(); i++ ){
        if( have == 0 )return -1;
        if( i == A.size()-1 )return ans;
        if( Max < i+A[i] ){
            Max = i+A[i];
        }
        have--;
        if( have == 0 ){
            ans++;
            have = Max-i;
        }
        if( have == 0 )return -1;
    }
    return -1;
}