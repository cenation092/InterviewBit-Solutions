bool isPrime( int num ){
    for( int i = 2; i*i <= num; i++ ){
        if( num % i == 0 )return 0;
    }
    return 1;
}

vector<int> Solution::primesum(int A) {
    for( int i = 2; i <= A; i++ ){
        int a = i, b = A-i;
        if( isPrime(a) && isPrime(b) ){
            vector<int> v = {a,b};
            return v;
        }
    }
}
