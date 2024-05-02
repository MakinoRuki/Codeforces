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
#include <list>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<string> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      v.push_back(s);
    }
    if (n == 1 || m == 1) {
      if (v[0][0] != v[n-1][m-1]) {
        puts("NO");
      } else {
        puts("YES");
      }
    } else {
      if ((v[0][0] == v[n-1][0]) && (v[0][m-1]==v[n-1][m-1]) && (v[0][0] != v[0][m-1])) {
        bool found=false;
        for (int i = 1; i < n-1; ++i) {
          if (v[i][0] == v[0][m-1] || v[i][m-1] == v[0][0]) {
            found=true;
            break;
          }
        }
        if (found) {
          puts("YES");
        } else {
          puts("NO");
        }
      } else if ((v[0][0]==v[0][m-1]) && (v[n-1][0]==v[n-1][m-1]) && (v[0][0]!=v[n-1][0])) {
        bool found=false;
        for (int j = 1; j < m-1; ++j) {
          if (v[0][j] == v[n-1][0] || v[n-1][j] == v[0][0]) {
            found=true;
            break;
          }
        }
        if (found) {
          puts("YES");
        } else {
          puts("NO");
        }
      } else {
        puts("YES");
      }
    }
  }
  return 0;
}
