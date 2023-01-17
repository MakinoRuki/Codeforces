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
#define N 100005
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
map<int, int> cnt;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cnt.clear();
    vector<vector<int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      vector<int> tmp;
      tmp.clear();
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        tmp.push_back(x);
        cnt[x]++;
      }
      v.push_back(tmp);
    }
  //  cout<<"??"<<endl;
    bool ok = true;
    int num=0;
    for (int i = 0; i < v.size(); ++i) {
      int j;
    //  cout<<"i="<<i<<endl;
      for (j = 0; j < v[i].size(); ++j) {
      //  cout<<j<<" "<<cnt[v[i][j]]<<endl;
        if (cnt[v[i][j]] == 1) {
          break;
        }
      }
      if (j < v[i].size()) {
        num++;
      }
    }
    if (num == n) {
      ok=false;
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
