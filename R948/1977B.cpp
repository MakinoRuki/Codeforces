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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d", &x);
    vector<int> v;
    v.clear();
    while(x) {
      if (x&1) v.push_back(1);
      else v.push_back(0);
      x/=2;
    }
    int cnt=0;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 1) {
        cnt++;
      } else {
        if (cnt > 1) {
          for (int j = i-cnt; j <= i-1; ++j) {
            v[j] = 0;
          }
          v[i-cnt] = -1;
          v[i] = 1;
          cnt = 1;
        } else {
          cnt=0;
        }
      }
    }
    if (cnt > 1) {
      int sz=(int)v.size();
      for (int j = sz-cnt; j <= sz-1; ++j) {
        v[j] = 0;
      }
      v[sz-cnt] = -1;
      v.push_back(1);
    }
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); ++i) {
      printf("%d ", v[i]);
    }
    cout<<endl;
  }
  return 0;
}
