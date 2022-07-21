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
#define N 100
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s(m, 'B');
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] < m+1-a[i]) {
        if (s[a[i]-1] == 'B') {
          s[a[i]-1] = 'A';
        } else {
          s[m+1-a[i]-1] = 'A';
        }
      } else {
        if (s[m+1-a[i]-1] == 'B') {
          s[m+1-a[i]-1] = 'A';
        } else {
          s[a[i]-1] = 'A';
        }
      }
    }
    cout<<s<<endl;
  }
  return 0;
}
