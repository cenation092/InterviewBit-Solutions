//L = find incorrect placed smallest number form left
//R = find incorrect placed largest number form right
vector<int> Solution::subUnsort(vector<int> &A) {
    int i = 1;
    int l = 0, r = 0;
    int Min = INT_MAX;
    int L = -1, R = -1;
    for( ;i < A.size(); i++ ){
        if( A[i] < A[i-1] ){
            L = i, r = i-1;
            for( int j = i; j < A.size(); j++ ){
                Min = min( Min, A[j]);
            }
            break;
        }
    }
    for( int i = 0; i <= r; i++ ){
        if( A[i] > Min ){
            L = i;
            break;
        }
    }
    i = A.size()-2;
    int Max = -1;
    for( ;i >= 0; i-- ){
        if( A[i] > A[i+1] ){
            l = i+1, R = i;
            for( int j = 0; j <= i; j++ ){
                Max = max(Max, A[j]);
            }
            break;
        }
    }
    for( int i = A.size()-1; i >= l; i-- ){
        if( A[i] < Max ){
            R = i;
            break;
        }
    }
    vector<int> v;
    if( L == -1 ){
        v.push_back(-1);
    }
    else{
        v.push_back(L);
        v.push_back(R);
    }
    return v;
}
