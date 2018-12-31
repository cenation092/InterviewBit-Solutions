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

void Max_pal(string s, int &l, int &r){
    while( l >= 0 && r < s.size() && s[l] == s[r] ){
        l--, r++;
    }
    if(r-l+1 > 1)l++, r--;
}

string longestPalindrome(string s){
    int L = 0, R = 0;
    for( int i = 0; i < s.size(); i++ ){
        int l = i, r = i;
        Max_pal(s, l, r);
        if( r-l+1 > R-L+1 ){
            R = r, L = l;
        }
        l = i, r = i+1;
        Max_pal(s, l, r);
        if( r-l+1 > R-L+1 ){
            R = r, L = l;
        }
    }
    string ans = "";
    for( int i = L; i <= R; i++ ){
        ans += s[i];
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}