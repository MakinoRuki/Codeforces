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
#define N 200005
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
bool rm[N];
int res;
vector<int> v;
void dfs(int n, int k, int cur, int sum, vector<int>& ids) {
  if (cur > n) {
    if (sum < res) {
      res=sum;
      v.clear();
      for (int i = 0;  i<ids.size(); ++i) {
        v.push_back(ids[i]);
      }
    }
    return;
  }
  dfs(n, k, cur+1, sum+a[cur]+(int)ids.size(), ids);
  if (ids.size()+1<=k) {
    ids.push_back(cur);
    dfs(n, k, cur+1, sum, ids);
    ids.pop_back();
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<pair<ll, int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      rm[i] = false;
      scanf("%d", &a[i]);
     // tot += (ll)a[i];
     // ll dt = (ll)(n-i) - (ll)(k-1);
      rk.push_back(make_pair(-a[i] + n-i, i));
    }
    sort(rk.begin(), rk.end());
    for (int i = 0; i < min((int)rk.size(), k); ++i) {
      rm[rk[i].second]=true;
    }
    ll tot=0LL;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (rm[i]) {
        cnt++;
      } else {
        tot += (ll)a[i] + (ll)cnt;
      }
    }
    // for (int i = n; i >= 1; --i) {
    //   if (rm[i]) {
    //     ll dt = -(ll)a[i] + (ll)(n-i)-(ll)cnt;
    //     if (dt < 0) {
    //       tot += (ll)(n-i)-(ll)cnt;
    //       cnt++;
    //     } else {
    //       tot += (ll)a[i];
    //     }
    //   } else {
    //     tot += (ll)a[i];
    //   }
    // }
    // for (int i = 0; i < rk.size(); ++i) {
    //   cout<<i<<" "<<rk[i]<<endl;
    // }
    // for (int i = 0; i< min((int)rk.size(), k); ++i) {
    //   if (rk[i] < 0) tot+=rk[i];
    //   else break;
    // }
    printf("%lld\n", tot);
  }
  // mt19937 rnd(time(0));
  // for (int n = 5; n <= 10; ++n) {
  //   for (int k = 1; k <= n; ++k) {
  //     for (int i = 1; i <= n; ++i) {
  //       a[i] = rnd()%15+1;
  //     }
  //     vector<int> ids;
  //     res =inf;
  //     dfs(n, k, 1, 0, ids);
  //     cout<<"xnk="<<n<<" "<<k<<endl;
  //     for (int i = 1; i <= n; ++i) {
  //       cout<<a[i]<<" ";
  //     }
  //     cout<<endl;
  //     for (int i = 1; i <= n; ++i) {
  //       cout<<-a[i]+max(0, (n-i)-(k-1))<<" ";
  //     }
  //     cout<<endl;
  //     for (int i = 0; i < v.size(); ++i) {
  //       cout<<v[i]<<" "<<a[v[i]]<<endl;
  //     }
  //   }
  // }
  return 0;
}
