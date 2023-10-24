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
#define N 1000005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
bool vis[N];
int main() {
  //cout<<pr[4]<<endl;
  cin>>t;
  string ans="";
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i < n; ++i) {
      vis[i] = false;
    }
    ll p;
    scanf("%lld", &p);
    ll tot=0LL;
    int cnt;
    for (cnt = 0; cnt < n; ++cnt) {
      if (tot + n-cnt >= p) {
        break;
      }
      tot += n-cnt;
    }
    p -= tot;
    set<pair<int,int>> ss;
    ss.clear();
  //  cout<<"p="<<p<<endl;
    for (int i = 0; i < n; ++i) {
      if (cnt == 0) break;
      while (cnt > 0 && !ss.empty() && (*ss.rbegin()).first > s[i]-'a') {
        auto itr = ss.rbegin();
        vis[itr->second] = true;
        ss.erase(*itr);
        cnt--;
      }
      ss.insert(make_pair(s[i]-'a', i));
    }
    while(cnt > 0) {
      auto itr = ss.rbegin();
      vis[itr->second]=true;
      ss.erase(*itr);
      cnt--;
    }
    int num=0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        num++;
        if (num == p) {
          ans.push_back(s[i]);
          break;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
