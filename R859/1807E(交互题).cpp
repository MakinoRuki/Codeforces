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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i]=sum[i-1]+(ll)a[i];
    }
    int l = 1, r = n;
    while(l < r) {
        int mid=(l+r)/2;
        printf("? %d", mid-l+1);
        for (int i = l; i <= mid; ++i) {
            printf(" %d", i);
        }
        printf("\n");
        fflush(stdout);
        ll sum2=0;
        scanf("%lld", &sum2);
        if (sum2 > sum[mid]-sum[l-1]) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    printf("! %d\n", r);
    fflush(stdout);
  }
  return 0;
}
