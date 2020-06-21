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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, k;
int b[N];
int main() {
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int ans=n;
  vector<int> rk;
  rk.clear();
  for (int i = 2; i <= n; ++i) {
    if (b[i]-b[i-1]>1) rk.push_back(b[i] - b[i-1]-1);
  }
  sort(rk.begin(), rk.end());
  int det = max(0, (int)rk.size()-(k-1));
  for (int i = 0; i < det; ++i) {
    ans += rk[i];
  }
  cout<<ans<<endl;
  return 0;
}
