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
#include <stack>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    string s;
    cin>>s;
    int nq = 0, n0 = 0, n1 = 0;
    int mnq = 0;
    for (int i = 2; i <= n; ++i) {
      if (edges[i].size() == 1) {
        if (s[i-1] == '?') nq++;
        else if (s[i-1] == '0') n0++;
        else n1++;
      } else {
        if (s[i-1] == '?') mnq++;
      }
    }
    int ans=0;
    if (s[0] != '?') {
      ans = (nq+1)/2 + (s[0]=='1'?n0:n1);
    } else {
      if (n0 == n1) {
        if (nq%2) {
          if (mnq%2) ans = (nq+1)/2+n1;
          else ans = nq/2+n1;
        } else {
          ans = nq/2+n1;
        }
      } else {
        ans = max(n0,n1)+nq/2;
      }
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

