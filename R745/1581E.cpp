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
#define M 12
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int x[N], y[N];
int sum[N];
int cnt[502][502];
int st[N];
void update(int id, int v) {
  sum[id] += v;
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  memset(sum, 0, sizeof(sum));
  memset(cnt, 0, sizeof(cnt));
  memset(st, 0, sizeof(st));
  int bd = (int)sqrt(m);
  int ans=0;
  for (int i = 1; i <= m; ++i) {
    int op, k;
    scanf("%d %d", &op, &k);
    if (op == 1) {
      if (x[k] + y[k] <= bd) {
        int tt = x[k]+y[k];
        int lb = (x[k]+i) % tt;
        int rb = (tt-1+i) % tt;
        if (lb <= rb) {
          for (int j = lb; j <= rb; ++j) {
            cnt[tt][j]++;
          }
        } else {
          for (int j = lb; j < tt; ++j) {
            cnt[tt][j]++;
          }
          for (int j = 0; j <= rb; ++j) {
            cnt[tt][j]++;
          }
        }
      } else {
        for (int j = i + x[k]; j <= m; j += x[k]+y[k]) {
          sum[j]++;
          if (j + y[k] <= m) sum[j+y[k]]--;
        }
      }
      st[k] = i;
    } else {
      if (x[k] + y[k] <= bd) {
        int tt = x[k]+y[k];
        int lb = (x[k]+st[k]) % tt;
        int rb = (tt-1+st[k]) % tt;
     //   cout<<i<<" "<<lb<<" "<<rb<<" "<<cnt[2][0]<<endl;
        if (lb <= rb) {
          for (int j = lb; j <= rb; ++j) {
            cnt[tt][j]--;
          }
        } else {
          for (int j = lb; j < tt; ++j) {
            cnt[tt][j]--;
          }
          for (int j = 0; j <= rb; ++j) {
            cnt[tt][j]--;
          }
        }
      //  cout<<i<<" "<<lb<<" "<<rb<<" "<<cnt[2][0]<<endl;
      } else {
        for (int j = st[k] + x[k]; j <= m; j += x[k]+y[k]) {
          sum[j]--;
          if (j < i) ans--;
          if (j + y[k] <= m) {
            sum[j+y[k]]++;
            if (j+y[k] < i) ans++;
          }
        }
      }
    }

  //  cout<<"x="<<cnt[2][0]<<endl;
    ans += sum[i];
  //  cout<<"i="<<i<<" "<<ans<<endl;
    int tmp=0;
    for (int j = 1; j <= bd; ++j) {
      tmp += cnt[j][i%j];
    }
    printf("%d\n", ans + tmp);
  }
  return 0;
}
