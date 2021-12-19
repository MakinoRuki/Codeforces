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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> av;
    av.clear();
    for (int i =1 ; i <= n; ++i) {
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] >= 1 && a[i] <= n) {
        if (!vis[a[i]]) {
          vis[a[i]] = true;
        } else {
          av.push_back(a[i]);
        }
      } else {
        av.push_back(a[i]);
      }
    }
  //  cout<<"??"<<endl;
    vector<int> bv;
    bv.clear();
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) bv.push_back(i);
    }
    sort(av.begin(), av.end());
    int ans=0;
    for (int i = 0; i < bv.size(); ++i) {
      if ((av[i]-1)/2 < bv[i]) {
        ans=-1;
        break;
      }
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
