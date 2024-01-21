#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int r, c;
    cin>>n>>k>>r>>c;
    for (int i= 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j]=0;
        }
    }
    int cc=c-1;
    while(true) {
      //  cout<<r-1<<" "<<cc<<endl;
        a[r-1][cc]=1;
        cc = (cc + k) % n;
        if (cc == c-1) break;
    }
    for (int i = r-2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (a[i+1][(j-1+n)%n]);
        }
    }
    for (int i = r; i < n; ++i) {
        for (int j =0; j < n; ++j) {
            a[i][j] = (a[i-1][(j+1)%n]);
        }
    }
    for (int i = 0; i < n; ++i) {
        string ss="";
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) ss += "X";
            else ss += ".";
        }
        cout<<ss<<endl;
    }
  }
  return 0;
}
