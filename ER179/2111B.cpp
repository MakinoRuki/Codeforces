
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
#include <bitset>
#include <chrono>
#define N 500005
#define M 105
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int w[N], l[N], h[N];
int f[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d%d", &w[i], &l[i], &h[i]);
    }
    set<int> ss;
    ss.clear();
    ss.insert(1);
    ss.insert(2);
    int f1=1, f2=2;
    f[1]=1;
    f[2]=2;
    for (int i=3; i <= n; ++i) {
      f[i] = f[i-1]+f[i-2];
    }
    string ans="";
    for (int i = 1; i <= m; ++i) {
   //   if (i == 3) cout<<"fn="<<f[n]<<" "<<w[i]<<" "<<h[i]<<" "<<l[i]<<endl;
      if (f[n] <= w[i] && f[n] <= h[i] && f[n] <= l[i]) {
        int dw = w[i]-f[n];
        int dl = l[i]-f[n];
        int dh = h[i]-f[n];
      //  if (i == 3) cout<<"dt="<<dw<<" "<<dl<<" "<<dh<<endl;
        if (dw >= f[n-1] || dh >= f[n-1] || dl >= f[n-1]) {
          ans += "1";
        } else {
          ans += "0";
        }
      } else {
        ans += "0";
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
