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
#define N 1002
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &x);
    int on = 0, en = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] % 2) on++;
      else en++;
    }
    bool ok = false;
    for (int i = 1; i <= on; ++i) {
      if ((i % 2) && (x-i >= 0 && x-i<=en)) {
        ok = true;
      }
    }
    if (ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
