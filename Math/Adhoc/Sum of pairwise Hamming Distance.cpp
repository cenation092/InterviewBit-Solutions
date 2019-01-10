int Solution::hammingDistance(const vector<int> &A) {
    int bit[32][2];
    int n = A.size();
    for( int i = 0; i < 32; i++ )bit[i][0] = bit[i][1] = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < 32; j++ ){
            int b = (A[i]&(1<<j));
            if( b == 0 )bit[j][0]++;
            else bit[j][1]++;
        }
    }
    long long ans = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < 32; j++ ){
            int b = (A[i] &(1<<j));
            if( b == 0 )ans += bit[j][1];
            else ans += bit[j][0];
        }
    }
    return ans % 1000000007;
}
