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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
long double bit[2][N];
int idx[N];
int idx2[N];
int cnt;
int lowbit(int x) {
  return x&(-x);
}
void update(int id, int pos, long double v) {
  while(pos<=cnt) {
    bit[id][pos] += v;
    pos += lowbit(pos);
  }
}
long double query(int id, int pos) {
  long double res=0;
  while(pos>0) {
    res += bit[id][pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  cin>>n;
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  cnt=0;
  for (int i = 0; i < rk.size(); ++i) {
    if (i == 0 || rk[i].first > rk[i-1].first) {
      cnt++;
    }
    idx[rk[i].second] = cnt;
    idx2[cnt] = rk[i].first;
  }
  long double tot = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= cnt; ++j) {
      bit[i][j] = 0;
    }
  }
  //memset(bit, 0LL, sizeof(bit));
  for (int i = 1; i <= n; ++i) {
    int id1 = idx[i];
    long double res1 = 0;
    long double cnt1=0;
    if (id1-1>=1 && idx2[id1-1] < a[i]-1) {
      res1 = query(1, id1-1);
      cnt1 = query(0, id1-1);
    } else if (id1-2 >=1 && idx2[id1-2] < a[i]-1) {
      res1 = query(1, id1-2);
      cnt1 = query(0, id1-2);
    }
    long double res2 = 0;
    long double cnt2 = 0;
    if (id1+1 <= cnt && idx2[id1+1] > a[i]+1) {
      res2 = query(1, cnt) - query(1, id1);
      cnt2 = query(0, cnt) - query(0, id1);
    } else if (id1+2 <= cnt && idx2[id1+2] > a[i]+1) {
      res2 = query(1, cnt) - query(1, id1+1);
      cnt2 = query(0, cnt) - query(0, id1+1);
    }
  //  if (i == 4) cout<<res1<<" "<<cnt1<<" "<<res2<<" "<<cnt2<<endl;
    // tot += a[i] * cnt1 - res1;
    // tot += a[i] * cnt2 - res2;
    tot -= res1;
    tot -= res2;
    tot += a[i] * cnt1;
    tot += a[i] * cnt2;
  //  cout<<i<<" "<<tot<<endl;
    update(0, id1, 1);
    update(1, id1, a[i]);
  }
  printf("%.0Lf\n", tot);
  return 0;
}
