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
#define N 200005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
      scanf("%d", &a[i]);
    }
    bool found=false;
    vector<int> v;
    v.clear();
    string ans="";
    for (int i = 1; i <= q; ++i) {
      if (!found) {
        if (v.empty() || a[i] >= v.back()) {
          v.push_back(a[i]);
          ans += "1";
        } else {
          if (a[i] <= v[0]) {
            found=true;
            v.push_back(a[i]);
            ans += "1";
          } else {
            ans += "0";
          }
        }
      } else {
        if (a[i] > v[0]) {
          ans += "0";
        } else {
          if (a[i] >= v.back()) {
            ans += "1";
            v.push_back(a[i]);
          } else {
            ans += "0";
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
