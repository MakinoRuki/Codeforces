/*
直接贪心。把每个list分成一些block，依次看prefix_sum，当出现当前sum>0时，记录之前所有sum的最小值mn，分成一个block为(mn,sum)。然后sum清0，继续。
用set维护，每次找个mn最大的更新x。再把所取list的下一个block放入set。
*/

#include <iostream>
#include <sstream>
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
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
vector<vector<pair<ll,ll>>> vv;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  ll x;
  cin>>x>>k;
  vv.clear();
  priority_queue<pair<ll,pair<int,int>>, vector<pair<ll, pair<int,int>>>> pq;
  for (int i= 1; i <= k; ++i) {
    vector<int> v;
    v.clear();
    scanf("%d", &n);
    for (int j = 1; j <= n; ++j) {
      int z;
      scanf("%d", &z);
      v.push_back(z);
    }
    vector<pair<ll,ll>> tmp;
    tmp.clear();
    ll mn=0, sum=0;
    for (int j = 1; j <= n; ++j) {
      sum += v[j-1];
      mn=min(mn, sum);
      if (sum > 0) {
        tmp.push_back(make_pair(mn, sum));
        //pq.push(make_pair(mn, -sum));
        mn=0,sum=0;
      }
    }
    if (!tmp.empty()) vv.push_back(tmp);
  }
  k = (int)vv.size();
  for (int i = 1; i <= k; ++i) {
 //   cout<<"i="<<i<<endl;
    pq.push(make_pair(vv[i-1][0].first, make_pair(i-1, 0)));
   // cout<<"i2="<<i<<endl;
  }
 // cout<<"??????"<<endl;
  ll ans = x;
  while(!pq.empty()) {
  //  cout<<"???"<<endl;
    auto tp = pq.top();
    pq.pop();
    if (ans + tp.first <0 ) break;
    int id=tp.second.first;
    int id2=tp.second.second;
    ans += vv[id][id2].second;
   // cout<<"id="<<id<<" "<<id2<<endl;
    id2++;
    
    if (id2 < vv[id].size()) {
      pq.push(make_pair(vv[id][id2].first, make_pair(id, id2)));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
