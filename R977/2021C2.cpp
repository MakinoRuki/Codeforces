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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int idx[N];
set<int> ss[N];
int check(vector<int>& v) {
  int tot=0;
  for (int i =1 ; i < v.size(); ++i) {
    int id1 = *ss[a[v[i-1]]].begin();
    int id2 = *ss[a[v[i]]].begin();
    if (id1 <= id2) tot++;
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss[a[i]].clear();
      ss[a[i]].insert(m+1);
      idx[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      ss[b[i]].insert(i);
    }
    bool ok=true;
    int cnt=0;
    for (int i = 2; i <= n; ++i) {
      int id2 = *ss[a[i]].begin();
      int id1 = *ss[a[i-1]].begin();
      if (id1 <= id2) {
        cnt++;
      }
    }
    if (cnt == n-1) puts("YA");
    else puts("TIDAK");
   // cout<<"cnt1="<<cnt<<endl;
    while(q-->0) {
      int s, x;
      scanf("%d%d", &s, &x);
      if (b[s] != x) {
        int id1 = idx[b[s]];
        int id2 = idx[x];
        set<int> tmp;
        tmp.clear();
        if (id1 > 1) tmp.insert(id1-1);
        tmp.insert(id1);
        if (id1 < n) tmp.insert(id1+1);
        if (id2 > 1) tmp.insert(id2-1);
        tmp.insert(id2);
        if (id2 < n) tmp.insert(id2+1);
        vector<int> v(tmp.begin(), tmp.end());
        int s1 = check(v);
        ss[b[s]].erase(s);
        b[s] = x;
        ss[x].insert(s);
        int s2 = check(v);
        cnt += s2 - s1;
      }
      if (cnt == n-1) puts("YA");
      else puts("TIDAK");

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

