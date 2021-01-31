#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
string s;
int len[2][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d",&n);
    cin>>s;
    for (int i = 0; i < n; ++i) {
      if (i == 0) len[0][i] = 1;
      else {
        if (s[i] == s[i-1]) {
          len[0][i] = 1;
        } else {
          len[0][i] = len[0][i-1]+1;
        }
      }
    }
    for (int i = n-1; i >= 0; --i) {
      if (i == n-1) len[1][i] = 1;
      else {
        if (s[i] == s[i+1]) {
          len[1][i] = 1;
        } else {
          len[1][i] = len[1][i+1]+1;
        }
      } 
    }
    for (int i = 0; i <= n; ++i) {
      int cur = 1;
      if (i -1 >=0 && s[i-1] == 'L') {
        cur += len[0][i-1];
      }
      if (i<n && s[i] == 'R') {
        cur += len[1][i];
      }
      printf("%d", cur);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
