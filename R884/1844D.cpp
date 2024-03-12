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
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
bool vis[30];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int mx=n+1;
    for (int i = 1; i <= n; ++i) {
      if (n%i) {
        mx=i;
        break;
      }
    }
    if (mx > n) {
      string ans="";
      for (int i = 0; i < n; ++i) {
        ans.push_back('a'+i);
      }
      cout<<ans<<endl;
      continue;
    }
    string tmp="";
    for (int i = 0; i < mx; ++i) {
      tmp.push_back('a'+i);
    }
    string ans="";
    while((int)ans.size() + mx <= n) {
      ans += tmp;
    }
    int dt = n-(int)ans.size();
    for (int i = 0; i < dt; ++i) {
      ans.push_back('a'+i);
    }
    cout<<ans<<endl;
  }
  return 0;
}
