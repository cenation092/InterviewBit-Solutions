
int go(int have){
    if( have == 0 )return 1;
    if( have < 0 )return 0;
    int Ans = go(have-1) + go(have-2);
    return Ans;
}

int Solution::climbStairs(int A) {
    return go(A);
}
