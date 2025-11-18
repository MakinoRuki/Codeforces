
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
vector<vector<int>> vv;
vector<int> ans;
int getid(set<pair<int,pair<int,int>>>& ss) {
  set<pair<int,pair<int,int>>> s2;
  while(ss.size() > 1) {
    s2.clear();
    for (auto pr : ss) {
      if (pr.first == (*ss.begin()).first) {
        int id=pr.second.first;
        int cur=pr.second.second;
        if (cur+1>vv[id-1].size()) {
          return id;
        }
        s2.insert(make_pair(vv[id-1][cur], make_pair(id,cur+1)));
      }
    }
    ss = s2;
  }
  return (*ss.begin()).second.first;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ans.clear();
    vv.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      vector<int> v;
      v.clear();
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
      }
      vv.push_back(v);
    }
    set<int> s;
    s.clear();
    for (int i = 1; i <= n; ++i) {
      s.insert(i);
    }
    int cur=1;
    set<pair<int,pair<int,int>>> ss;
    ss.clear();
    while(true) {
      ss.clear();
      vector<int> ids(s.begin(), s.end());
      for (auto id : ids) {
        if ((int)vv[id-1].size()<cur) {
          s.erase(id);
        } else {
          ss.insert(make_pair(vv[id-1][cur-1],make_pair(id, cur)));
        }
      }
      if (ss.empty()) break;
      int id2 = getid(ss);
    //  cout<<"id2="<<id2<<endl;
      for (int i = cur; i <= vv[id2-1].size(); ++i) {
        ans.push_back(vv[id2-1][i-1]);
      }
      cur = vv[id2-1].size()+1;
      s.erase(id2);
     // cout<<"ssize="<<(int)s.size()<<endl;
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
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
