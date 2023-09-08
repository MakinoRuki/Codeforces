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
#define N 200000
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int c[N];
int deg[N];
bool mk[N];
int par[N];
int id[N];
int find(int x) {
  return x== par[x] ? x : par[x] =find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i] = 0;
      mk[i]=false;
      par[i]=i;
      id[i] = i;
    }
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      deg[a[i]]++;
    }
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
      tot += (ll)c[i];
    }
    tot *= 2;
    queue<int> q;
    for (int i =1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
      }
    }
    while(!q.empty()) {
      auto x = q.front();
      mk[x] = true;
      ans.push_back(x);
      q.pop();
      deg[a[x]]--;
      if (deg[a[x]] == 0) {
        q.push(a[x]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!mk[i]) {
        int x = a[i];
        int id = i;
        while(x != i) {
        //  cout<<"x="<<x<<endl;
          if (c[x] < c[id]) {
            id = x;
          }
          x= a[x];
        }
        x = a[id];
        while(x != id) {
          ans.push_back(x);
          mk[x] = true;
          x=a[x];
        }
        mk[id]=true;
        ans.push_back(id);
      }
    }

    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ",ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
