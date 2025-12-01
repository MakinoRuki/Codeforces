
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
#define N 500005
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
int b[N];
vector<pair<int,pair<int,int>>> qs;
vector<pair<int,int>> cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &k, &q);
    qs.clear();
    for (int i = 1; i <= n; ++i) {
      cnt[i].clear();
    }
    for (int i = 1; i <= q; ++i) {
      int c,l,r;
      scanf("%d%d%d", &c, &l, &r);
      qs.push_back(make_pair(c, make_pair(l, r)));
      cnt[l].push_back(make_pair(c, 0));
      cnt[r].push_back(make_pair(c, 1));
    }
    int cur=0;
    int n1=0,n2=0;
    for (int i = 1; i <= n; ++i) {
      for (auto pr : cnt[i]) {
        if (pr.second == 0) {
          if (pr.first == 1) n1++;
          else n2++;
        }
      }
      if (n1 && n2) {
        a[i] = k+1;
      } else if (n1) {
        a[i]=k;
      } else if (n2) {
        a[i] = cur;
        cur++;
        if (cur >=k) cur=0;
      }
      for (auto pr : cnt[i]) {
        if (pr.second == 1) {
          if (pr.first == 1) n1--;
          else n2--;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
