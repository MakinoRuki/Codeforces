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
#define N 300005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> lst;
    lst.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      lst[a[i]] = i;
    }
    set<pair<int,int>> mx;
    set<pair<int,int>> mn;
    mx.clear();
    mn.clear();
    set<int> ss;
    ss.clear();
    set<int> vis;
    vis.clear();
    for (auto itr : lst) {
      ss.insert(itr.second);
    }
    int res = (int)lst.size();
    int id = 1;
    int lb = 1;
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= res; ++i) {
      int cur = *ss.begin();
      while(id <= cur) {
        mn.insert(make_pair(a[id], id));
        mx.insert(make_pair(-a[id], id));
        id++;
      }
      while(!mn.empty() && ((vis.find((*mn.begin()).first) != vis.end()) || ((*mn.begin()).second < lb))) {
        mn.erase(mn.begin());
      }
      while(!mx.empty() && ((vis.find(-(*mx.begin()).first) != vis.end()) || ((*mx.begin()).second < lb))) {
        mx.erase(mx.begin());
      }
      if (i%2) {
        ans.push_back((*mx.begin()).second);
      } else {
        ans.push_back((*mn.begin()).second);
      }
      lb = ans.back()+1;
      vis.insert(a[ans.back()]);
      ss.erase(lst[a[ans.back()]]);
    }
    printf("%d\n", res);
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", a[ans[i]]);
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

