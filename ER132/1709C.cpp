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
#define N 300005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
//int sum[3][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    // for (int i = 0; i < 3; ++i) {
    //   for (int j = 0; j <= n+1; ++j) {
    //     sum[i][j] = 0;
    //   }
    // }
    if (n%2) {
      puts("NO");
      continue;
    }
    int c0=0, c1=0;
    int qs = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(')c0++;
      else if (s[i] == ')') c1++;
      else qs++;
    }
    if (c0 > n/2 || c1 > n/2) {
      puts("NO");
      continue;
    }
    int cnt=0;
    bool ok = false;
    int sum=0;
    if (c0 == n/2 || c1 == n/2) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == '(') sum++;
        else if (s[i] == ')') sum--;
        else {
          if (c0==n/2) sum--;
          else sum++;
        }
        if (sum < 0) break;
      }
      if (sum != 0) {
        puts("NO");
        
      } else {
        puts("YES");
      }
      continue;
    }
    string res="";
    int id0=-1, id1 = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') res += "(";
      else if (s[i] == ')') res += ")";
      else {
        if (cnt < n/2-c0) {
          res += "(";
          cnt++;
          id0=i;
        } else {
          res += ")";
          if (id1 < 0) id1 = i;
        }
      }
    }
    swap(res[id0], res[id1]);
    sum=0;
   // cout<<res<<endl;
    for (int i = 0; i < n; ++i) {
      if (res[i] == '(') sum++;
      else sum--;
      if (sum < 0) {
        ok=true;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
