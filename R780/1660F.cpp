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
#define M 202
#define N 1000000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
string s;
int bit[3][N];
int lowbit(int x) {
  return x&(-x);
}
ll query(int id, int pos) {
  ll tot=0LL;
  while(pos) {
    tot += bit[id][pos];
    pos -= lowbit(pos);
  }
  return tot;
}
void update(int id, int pos) {
  while(pos <= 4*n) {
    bit[id][pos]++;
    pos += lowbit(pos);
  }
}
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    ll ans = 0LL;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j <= 4*n; ++j) {
        bit[i][j] = 0;
      }
    }
    int det = 3*n;
    update(0, det);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
     // cout<<"i="<<i<<endl;
      if (s[i-1] == '+') sum--;
      else sum++;
      int r = (det + sum) % 3;
      ans += query(r, det + sum);
      update(r, det + sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
