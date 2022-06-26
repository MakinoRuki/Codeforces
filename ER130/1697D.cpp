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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
ll a[N];
int main() {
//   cin>>t;
// //  mt19937 rnd(time(0));
//   for (int cas=1; cas<=t; ++cas) {
//     scanf("%d", &n);

//   }
  cin>>n;
  string ans = "";
  vector<int> ids;
  ids.clear();
  for (int i = 0; i < n; ++i) {
    printf("? 2 1 %d\n", i+1);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res > (int)ids.size()) {
      printf("? 1 %d\n", i+1);
      fflush(stdout);
      string c;
      cin>>c;
      ans.push_back(c[0]);
      ids.push_back(i);
    } else {
      sort(ids.begin(), ids.end());
      int l = 0, r = ids.size()-1;
      while(l < r) {
        int mid=(l+r+1)/2;
        printf("? 2 %d %d\n", ids[mid]+1, i+1);
        fflush(stdout);
        scanf("%d", &res);
        if (res == (int)ids.size()-mid) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      ans.push_back(ans[ids[r]]);
      ids[r] = i;
    }
  }
  cout<<"! "<<ans<<endl;
  return 0;
}
