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
#define N 300005
#define M 510
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x[N];
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &x[i]);
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &c[i]);
    }
    int cur=0;
    string ans="";
    int cur2=2;
    for (int i = 1; i <= k; ++i) {
      if (i == 1) {
        if (x[i] < c[i]) {
          ans.clear();
          break;
        }
        ans += "abc";
        if (c[i] > 3) {
          cur2++;
        }
        for (int j = 0; j < c[i]-3; ++j) {
          ans.push_back('a' + cur2);
        }
        for (int j = 0; j < x[i]-c[i]; ++j) {
          ans.push_back('a'+cur);
          cur = (cur+1)%3;
        }
      } else {
        int dt = x[i]-x[i-1];
        if (c[i-1] + dt < c[i]) {
          ans.clear();
          break;
        }
        if (c[i] > c[i-1]) {
          cur2++;
        }
        for (int j = c[i-1] + 1; j <= c[i]; ++j) {
          ans.push_back('a' + cur2);
        }
        for (int j = 1; j <= dt - (c[i]-c[i-1]); ++j) {
          ans.push_back('a'+cur);
          cur = (cur+1)%3;
        }
      }
    }
    if (ans.empty()) {
      puts("NO");
    } else {
      puts("YES");
      cout<<ans<<endl;
    }
  }
  return 0;
}
