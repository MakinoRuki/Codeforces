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
#define N 105
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1 ; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]%3]++;
    }
    int tot=cnt[0];
    if (cnt[1] > cnt[2]) {
      tot += cnt[2];
      int det =cnt[1]-cnt[2];
      tot += det/3;
    } else {
      tot += cnt[1];
      int det = cnt[2]-cnt[1];
      tot += det/3;
    }
    cout<<tot<<endl;
  }
  return 0;
}
