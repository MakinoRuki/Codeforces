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
#define N 2005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p;
int a[N];
int main() {
  cin>>n>>p;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  vector<int> ans;
  ans.clear();
  for (int i = 1; i <= 2000; ++i) {
    int j = 0;
    bool ok = true;
    for (int k = 1; k <= n; ++k) {
      while(j<=n && a[j]<=i+k-1) j++;
      int x = j-k;
      if (x==0) {
        ok = false;
        break;
      } else if (x % p == 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    ans.push_back(i);
  }
  cout<<ans.size()<<endl;
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
