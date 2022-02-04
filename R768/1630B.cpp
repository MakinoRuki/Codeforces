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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int sum[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; ++i) {
      sum[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      //a[i] = rand()%n+1;
     // cout<<a[i]<<" ";
      sum[a[i]]++;
    }
    cout<<endl;
    for (int i = 2; i <= n; ++i) {
      sum[i] += sum[i-1];
    }
    int ax = 1, ay = n;
    for (int i = 1; i <= n; ++i) {
      int l = i, r = n;
      while(l < r) {
        int mid=  (l+r)/2;
        if (sum[mid] - sum[i-1] >= (n-k+1)/2+k) {
          r = mid;
        } else {
          l = mid+1;
        }
      }
      if (sum[r] - sum[i-1] >= (n-k+1)/2+k && r - i < ay - ax) {
       // cout<<"x="<<i<<" "<<r<<endl;
        ax = i;
        ay = r;
      }
    }
    printf("%d %d\n", ax, ay);
    int cur = 1;
    for (int i = 1; i <= k; ++i) {
      int j;
      int cnt=0;
      for (j = cur; j <= n; ++j) {
        if (a[j] >= ax && a[j] <= ay) {
          cnt++;
        }
        if (cnt > (j-cur+1-cnt)) {
          break;
        }
      }
      if (i < k) printf("%d %d\n", cur, j);
      else printf("%d %d\n", cur, n);
      cur = j+1;
    }
  }
  return 0;
}
