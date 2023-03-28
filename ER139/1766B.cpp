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
#define N 1000005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    map<string, int> idx;
    idx.clear();
    cin>>s;
    bool found=false;
    for (int i = 0; i < n-1; ++i) {
      string tmp = s.substr(i, 2);
      if (idx.find(tmp) == idx.end()) {
        idx[tmp] = i;
      } else {
        int j = idx[tmp];
        if (j <= i-2) {
          found=true;
          break;
        }
      }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
