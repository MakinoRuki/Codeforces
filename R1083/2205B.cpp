
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
ll a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
  //  int x,y;
    scanf("%d", &n);
    vector<pair<int,int>> ps;
    ps.clear();
    ll x = n;
    for (ll i = 2; i * i <= x; ++i) {
      if (x%i) continue;
      int cnt=0;
      while((x%i)==0) {
        cnt++;
        x/=i;
      }
      ps.push_back(make_pair(i, cnt));
    }
    if (x>1) ps.push_back(make_pair(x, 1));
    ll res=1LL;
    for (auto pr : ps) {
      int p2 = (((ll)pr.second+(ll)n-1)/n);
     // cout<<"pr="<<pr.first<<" "<<pr.second<<" "<<p2<<endl;
      for (int i = 1; i <= p2; ++i) {
        res *= pr.first;
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}

