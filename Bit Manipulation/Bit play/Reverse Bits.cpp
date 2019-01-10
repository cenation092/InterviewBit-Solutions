unsigned int Solution::reverse(unsigned int A) {
    unsigned int num = 0;
    for( int i = 0; i < 32; i++ ){
        int bit = A&(1<<i);
        if( bit ){
            num = num | (1 << (31-i));
        }
    }
    return num;
}
