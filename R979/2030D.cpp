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
#define N 500005
#define M 325
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
int idx[N];
set<int> ss;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      idx[a[i]] = i;
    }
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      int mn = min(i, idx[i]);
      int mx = max(i, idx[i]);
      v.push_back(make_pair(mn, mx));
    }
    sort(v.begin(), v.end());
    ss.clear();
    vector<pair<int,int>>sg;
    sg.clear();
    int bg=-1,ed=-1;
    for (int i = 0; i < v.size(); ++i) {
      if (i == 0) {
        bg=v[i].first,ed=v[i].second;
      } else {
        if (v[i].first<=ed && v[i].second>=bg) {
          bg=min(bg,v[i].first);
          ed=max(ed,v[i].second);
        } else {
          ss.insert(ed);
          bg=v[i].first;
          ed=v[i].second;
        }
      }
    }
    string s;
    cin>>s;
    int cnt=0;
    for (int i = 0; i < n-1; ++i) {
      if (s[i]=='L' && s[i+1]=='R') {
        if (ss.find(i+1) == ss.end()) {
          cnt++;
        }
      }
    }
    while(q-->0) {
      int id;
      scanf("%d", &id);
      if (id-1>=1) {
        if ((s[id-2] == 'L') && (s[id-1] == 'R') && (ss.find(id-1) == ss.end())) {
          cnt--;
        }
      }
      if (id+1<=n) {
        if ((s[id-1]=='L') && (s[id] == 'R') && (ss.find(id) == ss.end())) {
          cnt--;
        }
      }
      s[id-1] = (s[id-1] == 'L' ? 'R' : 'L');
      if (id-1>=1) {
        if ((s[id-2] == 'L') && (s[id-1] == 'R') && (ss.find(id-1) == ss.end())) {
          cnt++;
        }
      }
      if (id+1<=n) {
        if ((s[id-1]=='L') && (s[id] == 'R') && (ss.find(id) == ss.end())) {
          cnt++;
        }
      }
      if (cnt==0) puts("YES");
      else puts("NO");
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

