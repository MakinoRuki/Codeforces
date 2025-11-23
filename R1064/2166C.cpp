
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
#define N 2000005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int l[N], r[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
      }
      set<pair<int,pair<int,int>>> ss;
      ss.clear();
      for (int i = 1; i <= n; ++i) {
        if (i < n) ss.insert(make_pair(max(a[i], a[i+1]), make_pair(i, i+1)));
        else ss.insert(make_pair(max(a[n], a[1]), make_pair(n, 1)));
        if (i-1>=1) l[i]=i-1;
        else l[i]=n;
        if (i+1<=n) r[i] = i+1;
        else r[i]=1;
      }
      ll ans=0LL;
      int cnt=n+1;
      for (int i = 1; i < n; ++i) {
        auto pr = *ss.begin();
        ss.erase(pr);
        ll v = pr.first;
        ans += pr.first;
        int ll = pr.second.first;
        int rr = pr.second.second;
    //    cout<<"v="<<v<<" "<<ll<<" "<<rr<<endl;
        ss.erase(make_pair(max(a[l[ll]], a[ll]), make_pair(l[ll], ll)));
        ss.erase(make_pair(max(a[rr], a[r[rr]]), make_pair(rr, r[rr])));
        a[cnt] = v;
        int l1=l[ll], r1=r[rr];
        r[l1] = cnt;
        l[cnt]=l1;
        l[r1] = cnt;
        r[cnt] = r1;
        ss.insert(make_pair(max(a[cnt], a[l1]), make_pair(l1, cnt)));
        ss.insert(make_pair(max(a[cnt], a[r1]), make_pair(cnt, r1)));
        cnt++;
      }
      printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
