int Solution::maxProfit(const vector<int> &A) {
    int i = 0;
    int sum = 0;
    while( i < A.size() ){
        while( i < A.size()-1 && A[i] >= A[i+1] )i++;
        int pay = A[i];
        while( i < A.size()-1 && A[i] <= A[i+1] )i++;
        int get = A[i];
        sum += (get-pay);
        i++;
    }
    return sum;
}
