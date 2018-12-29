#define watch2(x, y) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define watch3(x, y, z) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cerr <<#x<<": "<<x<<endl;
#include <vector> 
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

int mice(vector<int> &mice, vector<int> &hole) {
    sort(mice.begin(), mice.end());
    sort(hole.begin(), hole.end());
    int Time = 0;
    for( int i = 0; i < mice.size(); i++ ){
        Time = max( Time, abs(mice[i]-hole[i]));
    }
    return Time;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for( int i = 0; i < n; i++ )cin >> A[i];
    for( int i = 0; i < m; i++ )cin >> B[i];
    cout << mice(A, B);
}