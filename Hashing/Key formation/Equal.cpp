vector<int> Solution::equal(vector<int> &A) {
    map<int, int> fre;
    for( int i = 0; i < A.size(); i++ ){
        for( int j = i+1; j < A.size(); j++ ){
            fre[A[i]+A[j]]++;
        }
    }
    vector<int> v;
    for( int i = 0; i < A.size(); i++ ){
        for( int j = i+1; j < A.size(); j++ ){
            int sum = A[i] + A[j];
            if( fre[sum] > 1 ){
                for( int I = 0; I < A.size(); I++ ){
                    for( int J = I+1; J < A.size(); J++ ){
                        if( i == I || j == J || i == J || j == I)continue;
                        if( A[I]+A[J] == sum ){
                            v.push_back(i);
                            v.push_back(j);
                            v.push_back(I);
                            v.push_back(J);
                            return v;
                        }
                    }
                }
            }
        }
    }
    return v;
}
