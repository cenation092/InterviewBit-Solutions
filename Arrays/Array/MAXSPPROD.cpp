#define watch2(x, y) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define watch3(x, y, z) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cerr <<#x<<": "<<x<<endl;
#include <vector> 
#include<stack>
#include <queue>
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

int maxSpecialProduct(vector<int> &ar){
    stack<pair<int,int> > s;
    s.push(make_pair(ar[0],0));
    int n = ar.size();
    vector<int> left(n, 0);
    for( int i = 1; i < n; i++ ){
        while( !s.empty() && s.top().first <= ar[i] )s.pop();
        if( !s.empty() )left[i] = s.top().second;
        s.push(make_pair(ar[i],i));
    }
    long long ans = 0;
    while( !s.empty() )s.pop();
    s.push(make_pair(ar[n-1],n-1));
    for( int i = n-2; i >= 0; i-- ){
        while( !s.empty() && s.top().first <= ar[i] )s.pop();
        if( !s.empty() )ans = max( ans, left[i]*1LL*s.top().second);
        s.push(make_pair(ar[i],i));
    }
    return (int)(ans%1000000007);
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for( int i = 0; i < n; i++ ){
        cin >> v[i];
    }
    cout << maxSpecialProduct(v);
}

//5 9 6 8 6 4 6 9 5 4 9
//                ^ | ^