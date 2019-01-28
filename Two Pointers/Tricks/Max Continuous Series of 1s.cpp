Tricks
vector<int> Solution::maxone(vector<int> &A, int B) {
    int ans = 0;
    int zero = 0, one = 0;
    int l = 0;
    for( int r = 0; r < A.size(); r++ ){
        if( A[r] )one++;
        else zero++;
        while( zero > B && l <= r ){
            if( A[l] )one--;
            else zero--;
            l++;
        }
        ans = max( ans, one+zero);
    }
    vector<int> v;
    one = 0, zero = 0;
    for( int i = 0; i < ans; i++ ){
         if( A[i] )one++;
         else zero++;
    }
    if( zero <= B && one+zero == ans ){
        for( int i = 0; i < ans; i++)v.push_back(i);
        return v;
    }
    for( int i = 0; i < A.size(); i++ ){
        if( i+ans < A.size() ){
            if( A[i+ans] )one++;
            else zero++;
        }
        else break;
        if( A[i] )one--;
        else zero--;
        if( zero <= B && one+zero == ans ){
            for( int j = i+1; ans > 0 ; j++, ans-- )v.push_back(j);
            return v;
        }
    }
    return v;
}
