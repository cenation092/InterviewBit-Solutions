int Solution::repeatedNumber(const vector<int> &A) {
    int sq = sqrt(A.size()-1);
    int num_ranges = ceil((A.size()-1)/(double)sq);
    vector<int> hash(num_ranges+1,0);
    for(int i=0;i<A.size();i++){
        int r_num = ceil(A[i]/(double)sq);
        hash[r_num]++;
    }
    int i;
    for(i=1;i<hash.size();i++){
        if(hash[i]>sq)break;
    }
    int loc = i;
    if(i==hash.size())loc = i-1;
    int beg = sq*(loc-1)+1;
    int end = min(sq*(loc),(int)A.size()-1);
    vector<int> hash1(sq,0);
    for(int i=0;i<A.size();i++){
        if(A[i]<=end && (A[i]-beg) >= 0){
            hash1[A[i]-beg]++;
        }
    }
    for(int i=0;i<hash1.size();i++){
        if(hash1[i]>1)return beg+i;
    }
    return -1;
}