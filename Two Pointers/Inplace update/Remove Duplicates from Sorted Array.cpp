int Solution::removeDuplicates(vector<int> &A) {
   int l = 1;
   for( int i = 1; i < A.size(); i++ ){
        if(A[i] != A[i-1] ){
            A[l++] = A[i];
        }
   }
   return l;
}
