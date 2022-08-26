#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 500
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
vector<string> ss;
int nxt[N];
int main() {
  cin>>n>>m>>k;
  int tot=0;
  for (int i = 1; i <= k; ++i) {
    if ((i%n) == 0 && (i%m) == 0) {
      tot++;
    }
  }
  cout<<tot<<endl;
  return 0;
}
