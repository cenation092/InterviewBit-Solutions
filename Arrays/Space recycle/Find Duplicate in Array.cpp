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

int repeatedNumber(const vector<int> &A) {
    int n = A.size();
    n = sqrt(n) + 1;
    if( A.size() <3 ){
        if( A.size() == 2 && A[0] == A[1] )return A[0];
        return -1;
    }
    vector<int> ar(n,0);
    for( auto it : A ){
        int num = ceil((float)it/(float)n);
        watch2(it, num);
        ar[num]++;
    }
    int idx = -1;
    for( int i = 0; i < n; i++ ){
        cout << ar[i] << " ";
        if( ar[i] > n )idx = i;
        ar[i] = 0;
    }
    for( auto it : A ){
        int num = ceil((float)it/(float)n);
        if( num == idx ){
            if( ar[it%n] )return it;
            ar[it%n]++;
            
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for( int i = 0; i < n; i++ ){
        cin >> ar[i];
    }
    cout << repeatedNumber(ar);
}