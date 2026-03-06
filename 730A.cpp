/* 经典结论:mx<=tot-mx */

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
#define N 1000005
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int cnt[2][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);

  // }
  cin>>n;
  int mn=inf;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mn = min(mn, a[i]);
  }
  //sort(a+1, a+n+1);
  int ans=0;
  for (int i = mn; i >= 0; --i) {
    int tot=0;
    int mx=0;
    for (int j = 1; j <= n; ++j) {
      if (a[j] >= i) {
        tot += a[j]-i;
        mx = max(mx, a[j]-i);
      }
    }
    if (mx <= tot-mx) {
      ans = i;
      break;
    }
  }
  set<pair<int,int>> ss;
  ss.clear();
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > ans) {
      tot += a[i]-ans;
      ss.insert(make_pair(a[i]-ans, i));
    }
  }
  cout<<ans<<endl;
  if (ss.empty()) {
    puts("0");
    return 0;
  }
  vector<string> v;
  v.clear();
  while(!ss.empty()) {
    string tmp(n, '0');
    // 先讨论ss的size，再看tot
    if (ss.size() <= 2) {
      auto pr = *ss.rbegin();
      ss.erase(pr);
      int n1 = pr.first;
      int id1= pr.second;
      int n2=0,id2=0;
      if (!ss.empty()) {
        auto pr2 = *ss.begin();
        n2 = pr2.first;
        id2 = pr2.second;
      }
      for (int i = 1; i <= min(n1, n2); ++i) {
        string tmp(n, '0');
        tmp[id1-1] = '1';
        tmp[id2-1] = '1';
        v.push_back(tmp);
      }
      for (int i = 1; i <= n1-n2; ++i) {
        string tmp(n, '0');
        tmp[id1-1] = '1';
        if (id1 == 1) tmp[n-1] = '1';
        else tmp[0] = '1';
        v.push_back(tmp);
      }
      break;
    }
    if (tot <= 3) {
      while(!ss.empty()) {
        auto pr = *ss.begin();
        ss.erase(pr);
        tmp[pr.second-1] = '1';
      }
    } else {
      auto pr = *ss.rbegin();
      ss.erase(pr);
      auto pr2 = *ss.rbegin();
      ss.erase(pr2);
      pr.first--;
      pr2.first--;
      tot -= 2;
      tmp[pr.second-1] = '1';
      tmp[pr2.second-1] = '1';
      if (pr.first) ss.insert(pr);
      if (pr2.first) ss.insert(pr2);
    }    
  //  cout<<"tmp="<<tmp<<endl;
    v.push_back(tmp);
  }
  cout<<(int)v.size()<<endl;
  for (auto s : v) {
    cout<<s<<endl;
  }
  return 0;
}
 
