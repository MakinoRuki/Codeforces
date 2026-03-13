
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
int a[N];
vector<vector<int>> v;
bool vis[N];
bool vis2[N];
bool calc(const vector<int>& v1, const vector<int>& v2, const vector<int>& v11, const vector<int>& v22) {
  int sz = (int)v1.size() + (int)v2.size();
  int c1 = 0, c2 = 0;
  for (int i= 0; i < sz; ++i) {
    int x=0,y=0;
    if (c1 < v1.size()) x = v1[c1];
    else x = v2[c1-(int)v1.size()];
    if (c2 < v11.size()) y = v11[c2];
    else y = v22[c2-(int)v11.size()];
    if (x!=y) return x< y;
  }
  return 1;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d", &n);
    v.clear();
    for (int i =1; i <= n; ++i) {
      vector<int> tmp;
      tmp.clear();
      scanf("%d", &k);
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        vis[x]= false;
        tmp.push_back(x);
      }
      reverse(tmp.begin(), tmp.end());
      for (auto x : tmp) {
        vis2[x]=false;
      }
      vector<int> tmp2;
      tmp2.clear();
      for (auto x : tmp) {
        if (!vis2[x]) tmp2.push_back(x);
        vis2[x]=true;
      }
      v.push_back(tmp2);
    }
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      // sort(v.begin(), v.end(), [](const vector<int>& v1, const vector<int>& v2) {
      //   return calc(v1, v2, v2, v1);
      // });
      sort(v.begin(), v.end());
      if (v.empty()) break;
      for (auto x : v[0]) {
      //  cout<<"x="<<x<<endl;
        // if (!vis[x]) ans.push_back(x);
        vis[x] = true;
        ans.push_back(x);
      }
    //  cout<<endl;
      vector<vector<int>> vv;
      vv.clear();
      for (int j = 1; j < v.size(); ++j) {
        vector<int> tmp;
        tmp.clear();
       // for (auto x : v[j]) vis2[x]=false;
        for (auto x : v[j]) {
          if (!vis[x]) {
            tmp.push_back(x);
           // vis2[x]=true;
          }
        }
        vv.push_back(tmp);
      }
      v = vv;
    }
    for (auto x : ans) {
      printf("%d ", x);
    }
    cout<<endl;
  }
  return 0;
}

