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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
vector<pair<int,int>> ab;
bool check(ll a, ll b, set<pair<int,int>> sa, set<pair<int,int>> sb) {
  // cout<<a<<" "<<b<<endl;
  for (int i = 1; i < n; ++i) {
    if (!sa.empty() && !sb.empty() && (*sa.rbegin()).first == a && (*sb.rbegin()).first == b) {
      return false;
    } else if (!sa.empty() && (*sa.rbegin()).first == a) {
      int id = (*sa.rbegin()).second;
      sa.erase(make_pair(ab[id-1].first, id));
      sb.erase(make_pair(ab[id-1].second, id));
      b -= ab[id-1].second;
    } else if (!sb.empty() && (*sb.rbegin()).first == b) {
      int id = (*sb.rbegin()).second;
      sa.erase(make_pair(ab[id-1].first, id));
      sb.erase(make_pair(ab[id-1].second, id));
      a -= ab[id-1].first;
    } else {
      return false;
    }
   // cout<<"i="<<i<<" "<<a<<" "<<b<<endl;
  }
  int id=(*sa.begin()).second;
  if (ab[id-1].first == a && ab[id-1].second == b) {
    return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ab.clear();
    set<pair<int,int>> sa;
    set<pair<int,int>> sb;
    sa.clear();
    sb.clear();
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      int a,b;
      scanf("%d%d", &a, &b);
      tot += (ll)a * (ll)b;
      ab.push_back(make_pair(a, b));
      sa.insert(make_pair(a, i));
      sb.insert(make_pair(b, i));
    }
    if (n == 1) {
      puts("1");
      printf("%d %d\n", ab[0].first, ab[0].second);
    } else {
      vector<pair<ll,ll>> ans;
      ans.clear();
      ll a1=(*sa.rbegin()).first;
      int id1=(*sa.rbegin()).second;
      if ((tot % a1) == 0) {
        ll b1 = tot/a1;
        if(check(a1, b1, sa, sb)) {
          ans.push_back(make_pair(a1, b1));
        }
      }
      ll b1=(*sb.rbegin()).first;
      int id2=(*sb.rbegin()).second;
      if ((tot%b1) == 0) {
        ll a1 = tot/b1;
        if(check(a1, b1, sa, sb)) {
          ans.push_back(make_pair(a1, b1));
        }
      }
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%lld %lld\n", ans[i].first, ans[i].second);
      }
    }
  }
  return 0;
}
