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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int b[N];
string s;
int solve(int cnt) {
  int res=0;
  while(cnt > 2) {
    res++;
    cnt/=2;
  }
  res+=cnt;
  return res;
}
int check(int c) {
  int ans = 0;
  int cnt=0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != c + 'a') {
      cnt++;
    } else {
      ans = max(ans, solve(cnt));
      cnt=0;
    }
  }
  if (cnt>0) ans=max(ans, solve(cnt));
  return ans;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    int ans = n+1;
    for (int c = 0; c < 26; ++c) {
      ans = min(ans, check(c));
      //cout<<"c="<<c<<" "<<ans<<endl;
    }
    printf("%d\n", ans);
  }
  return 0;
}
