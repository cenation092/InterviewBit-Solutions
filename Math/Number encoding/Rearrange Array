// max(ar[i) + 1
// ar[i] / N = old number
// ar[i] % N = new number
void Solution::arrange(vector<int> &ar) {
    int N = ar.size();
    for( int i = 0; i < N; i++ ){
        ar[i] *= N;
    }
    for( int i = 0; i < N; i++ ){
        int current = ar[i] / N;
        int replace = ar[current] / N;
        ar[i] = ar[i] + replace;
    }
    for( int i = 0; i < N; i++ ){
        ar[i] %= N;
    }
}
