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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int x[N];
int main() {
  int a,b,c;
  cin>>a>>b>>c;
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
  }
  sort(x+1, x+n+1);
  ll tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    if (x[i] > b && x[i] < c) {
      tot++;
    }
  }
  cout<<tot<<endl;
  return 0;
}
