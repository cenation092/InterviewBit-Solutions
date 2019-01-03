#define watch2(x, y) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define watch3(x, y, z) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cerr <<#x<<": "<<x<<endl;
#include <vector> 
#include <queue>
#include<stack>
#include <map> 
#include <set>
#include <utility>
#include <algorithm>
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<string>
#include <limits>
#include<climits>
#define endl "\n"
using namespace std;

int can( vector<int> &ar, int Max, int N){
    int cnt = 0;
    int left = ar.size();
    for( int i = 0; i < ar.size(); ){
        long long sum = ar[i];
        i++; cnt++;left--;
        while( i < ar.size() && sum+ar[i] <= Max && left > N-cnt ){
            left--;
            sum += ar[i];
            i++;
        }
    }
    return cnt;
}

int books(vector<int> &ar, int N) {
    long long l = 0, r = 0;
    for( int i = 0; i < ar.size(); i++ ){
        r += ar[i];
        l = max( (int)l, ar[i]);
    }
    long long ans = 100000000*1LL*100000000;
    while( l <= r ){
        long long mid = (l+r)/2;
        int cnt = can(ar, mid, N);
        if( cnt == N ){
            r = mid-1;
            ans = min( ans, mid);
        }
        else if( cnt < N ){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if( ans == 100000000*1LL*100000000 )return -1;
    return ans;
}

int main(){
    int n, N;
    cin >> n >> N;
    vector<int> ar(n);
    for( int i = 0; i < n; i++ ){
        cin >> ar[i];
    }
    cout << books(ar, N);
}

//97 26 12 67 10 33 79 49 79 21 67 72 93 36 85 45 28 91 94 57 1 53 8 44 68 90 24
// 26