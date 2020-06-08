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
#define N 200005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int n;
int a[N], b[N];
int id1[N], id2[N];
int cnt[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    id1[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    id2[b[i]] =i;
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    int det = (id2[i]-id1[i]+n) % n;
    cnt[det]++;
  }
  int ans=1;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, cnt[i]);
  }
  cout<<ans<<endl;
  return 0;
}
