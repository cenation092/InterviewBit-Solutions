vector<int> Solution::equal(vector<int> &ar) {
    map<int, int> fre;
    for( int i = 0; i < ar.size(); i++ ){
        for( int j = i+1; j < ar.size(); j++ ){
            fre[ar[i]+ar[j]]++;
        }
    }
    vector<int> v;
    for( int i = 0; i < ar.size(); i++ ){
        for( int j = i+1; j < ar.size(); j++ ){
            int sum = ar[i] + ar[j];
            if( fre[sum] > 1 ){
                for( int I = 0; I < ar.size(); I++ ){
                    for( int J = I+1; J < ar.size(); J++ ){
                        if( i == I || j == J || i == J || j == I)continue;
                        if( ar[I]+ar[J] == sum ){
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
