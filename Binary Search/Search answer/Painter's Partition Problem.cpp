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

bool can( long long Max, vector<int> &ar , int N , int T){
    for( int i = 0; i < ar.size();){
        long long sum = 0;
        while(i < ar.size() && (sum + ar[i]*1LL*T) <= Max ){
            sum += ar[i]*1LL*T;
            i++;
        }
        if( sum == 0 )return 0;
        N--;
        if( N < 0 )return 0;
    }
    return 1;
}

int paint(int N, int T, vector<int> &ar) {
    long long l = ar[0] * 1LL * T;
    long long r = 0;
    for( auto it : ar )r += it;
    r = r * T;
    long long ans = 100000000*1LL*100000000;
    while( l <= r ){
        long long mid = (l+r)/2;
        if( can(mid, ar, N, T) ){
           r = mid-1;
           ans = min( ans, mid);
        } 
        else l = mid+1;
    }
    return ans % 10000003;
}

int main(){
    int N, T, n;
    cin >> N >> T >> n;
    vector<int> ar(n);
    for( int i = 0; i < n; i++ )cin >> ar[i];
    cout << paint(N, T, ar);
}