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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      if (a[i] != -1) ids.push_back(i);
    }
    if (ids.empty()) {
      for (int i = 1; i <= n; ++i) {
        if (i%2) printf("1 ");
        else printf("2 ");
      }
      cout<<endl;
      continue;
    }
    bool ok = true;
    for (int i = 1; i < ids.size(); ++i) {
      int x = a[ids[i-1]];
      int y = a[ids[i]];
      vector<int> bx, by;
      bx.clear();
      by.clear();
      while(x) {
        bx.push_back(x%2);
        x/=2;
      }
      while(y) {
        by.push_back(y%2);
        y/=2;
      }
      reverse(bx.begin(), bx.end());
      reverse(by.begin(), by.end());
      int j;
      for (j = 0; j < min(bx.size(), by.size()); ++j) {
        if (bx[j] != by[j]) break;
      }
      int dt = ids[i]-ids[i-1];
      int dt2 = (int)bx.size()-j+(int)by.size()-j;
      if (dt2 > dt) {
        ok=false;
        break;
      }
      if ((dt-dt2)%2) {
        ok=false;
        break;
      }
      int cur = ids[i-1]+1;
      for (int j2 = 1; j2 <= (int)bx.size()-j; ++j2) {
        a[cur] = a[cur-1]/2;
        cur++;
      }
      if (dt-dt2>0) {
        for (int j2 = 1; j2 <= (dt-dt2)/2; ++j2) {
          a[cur] = a[cur-1]*2;
          cur++;
          a[cur] = a[cur-1]/2;
          cur++;
        }
      }
      for (int j2 = j; j2 < by.size(); ++j2) {
        a[cur] = a[cur-1]*2;
        if (by[j2]) a[cur]++;
        cur++;
      }
    }
    if (!ok) puts("-1");
    else {
      if (ids[0]>1) {
        for (int i = ids[0]-1; i >= 1; --i) {
          if (a[i+1]/2 >= 1) a[i] = a[i+1]/2;
          else a[i] = a[i+1]*2;
        }
      }
      if (ids.back() < n) {
        for (int i = ids.back()+1; i <= n; ++i) {
          if (a[i-1]/2 >= 1) a[i] = a[i-1]/2;
          else a[i] = a[i-1]*2;
        }
      }
      for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    }
  }
  return 0;
}
