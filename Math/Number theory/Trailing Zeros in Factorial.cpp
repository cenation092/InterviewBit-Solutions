int Solution::trailingZeroes(int A) {
    int two = 0, five = 0;
    for( int i = 2; i <= A; i++ ){
        int num = i;
        while( num % 5 == 0 ){
            five++;
            num /= 5;
        }
        while( num % 2 == 0 ){
            two++;
            num /= 2;
        }
    }
    return min(two, five);
}
