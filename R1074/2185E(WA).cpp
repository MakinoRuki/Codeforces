
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
#define M 10002
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
int c[N];
int ls[N], rs[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>m>>k;
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ls[i] = -1;
      rs[i] = -1;
      rk.push_back(make_pair(a[i], i));
      c[i]=1;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    sort(b+1, b+m+1);
    sort(rk.begin(), rk.end());
    set<pair<int,int>> s1;
    set<pair<int,int>> s2;
    int j = 1;
    for (int i = 1; i <= n; ++i) {
      int pos = rk[i-1].first;
      int id=rk[i-1].second;
      while(j <= m && b[j] <= pos) {
        j++;
      }
      if (j > 1 && b[j-1]<=pos) {
        ls[id] = pos-b[j-1];
        s1.insert(make_pair(pos-b[j-1], id));
      }
    }
    j = m;
    for (int i = n; i >= 1; --i) {
      int pos = rk[i-1].first;
      int id=rk[i-1].second;
      while(j >= 1 && b[j] >= pos) {
        j--;
      }
      if (j<n && b[j+1]>=pos) {
        rs[id] = b[j+1]-pos;
        s2.insert(make_pair(b[j+1]-pos, id));
      }
    }
    string s;
    cin>>s;
    int tot=n;
    int l = 0, r = 0;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == 'L')cur--;
      else cur++;
      l = min(l, cur);
      r = max(r, cur);
    //  cout<<"i="<<i<<" "<<l<<" "<<r<<endl;
      while(!s1.empty() && (*s1.begin()).first<=abs(l)) {
       // cout<<"???1"<<endl;
        auto pr = *s1.begin();
        int id = pr.second;
        s1.erase(pr);
        c[id] = 0;
        tot--;
        if (s2.find(make_pair(rs[id], id)) != s2.end()) {
          s2.erase(make_pair(rs[id], id));
        }
      }
      while(!s2.empty() && (*s2.begin()).first <= abs(r)) {
       // cout<<"???2"<<endl;
        auto pr = *s2.begin();
        int id = pr.second;
        s2.erase(pr);
        c[id] = 0;
        tot--;
        if (s1.find(make_pair(ls[id], id)) != s1.end()) {
          s1.erase(make_pair(ls[id], id));
        }
      }
      printf("%d ", tot);
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
