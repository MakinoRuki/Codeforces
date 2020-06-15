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
#define N 100002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t,n,x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>x;
    int ans = -1;
    int id = -1;
    int sum=0;
    for (int i = 1; i <= n; ++i) {
      int a;
      scanf("%d", &a);
      sum += a;
      if (sum % x == 0) {
        if (id >= 0) {
          ans = max(ans, i - id);
        }
      } else {
        ans = max(ans, i);
      }
      if (id < 0 && (sum%x)>0) id = i;
    }
    cout<<ans<<endl;
  }
  return 0;
}
