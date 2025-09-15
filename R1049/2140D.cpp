
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
#define N 600005
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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> sg;
    sg.clear();
    set<pair<int,int>> ss;
    ss.clear();
    ll s1=0LL, s2=0LL;
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      int l,r;
      scanf("%d%d", &l, &r);
      sg.push_back(make_pair(l, r));
      ss.insert(make_pair(l+r, i));
      s1 += r;
      sum += (ll)(r-l);
    }
   // cout<<"sum="<<sum<<" "<<1000000000-1<<" "<<sum + 1000000000-1<<endl;
    set<pair<int,int>> ss2;
    ss2.clear();
    for (int i = 1; i <= n/2; ++i) {
      auto pr = *ss.begin();
      ss.erase(pr);
      ss2.insert(pr);
      s2 += pr.first;
     // cout<<"ss="<<s1<<" "<<1000000000<<" "<<s2<<" "<<1000000001<<endl;
    }
    if (n%2) {
      ll tmp = 0LL;
      for (int i = 1; i <= n; ++i) {
        int l = sg[i-1].first;
        int r = sg[i-1].second;
        if (ss2.find(make_pair(l+r, i)) == ss2.end()) {
          tmp = max(tmp, s1-s2-r);
        } else {
          auto pr = *ss.begin();
          int id = pr.second;
          int l2 = sg[id-1].first;
          int r2 = sg[id-1].second;
         // if (l==2 && r == 7) cout<<" "<<l2<<" "<<r2<<" "<<s1-s2<<endl;
          tmp = max(tmp, s1-s2+l+r-r - (l2+r2));
        }
      }
      printf("%lld\n", tmp + sum);
    } else {
      printf("%lld\n", sum + s1 - s2);
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
