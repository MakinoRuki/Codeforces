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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], d[N];
int ln[N], rn[N];
bool exist[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int pw = 0;
    a[0]=a[n+1]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ln[i] = i-1;
      rn[i] = i+1;
      exist[i]=true;
    }
    d[0]=d[n+1]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &d[i]);
    }
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      if (a[ln[i]]+a[rn[i]] > d[i]) {
        ss.insert(i);
      }
    }
    for (int i = 1; i <= n; ++i) {
      int sz=(int)ss.size();
      set<int> s2;
      s2.clear();
      for (auto id : ss) {
        int l = ln[id];
        int r = rn[id];
        if (l > 0) s2.insert(l);
        if (r <= n) s2.insert(r);
        rn[l] = r;
        ln[r] = l; 
        exist[id]=false;
      }
      ss.clear();
      for (auto id : s2) {
       // cout<<"id="<<id<<" "<<ln[id]<<" "<<rn[id]<<endl;
        if (exist[id] && a[ln[id]]+a[rn[id]] > d[id]) {
          ss.insert(id);
        }
      }
      printf("%d ", sz);
    }
    cout<<endl;
  }
  return 0;
}
