vector<int> Solution::maxset(vector<int> &ar) {
    int n = ar.size();
    int l = 0;
    int L = -1, R = -1;
    vector<int> v;
    long long Max_sum = 0, sum = 0;;
    for( int i = 0; i < n; i++ ){
        l = i, sum = 0;
        if( ar[i] >= 0 ){
            while( ar[i] >= 0 && i < n){
                sum += ar[i];
                i++; 
            }
            i--;
            if( Max_sum <= sum ){
                Max_sum = sum;
                L = l, R = i;
            }
            else if( Max_sum == sum ){
                if( i-l > R-L ){
                    R = i, L = l;
                }
            }
        }
    }
    if( R == -1 )return v;
    for( int i = L; i <= R; i++){
        v.push_back(ar[i]);
    }
    return v;
}
