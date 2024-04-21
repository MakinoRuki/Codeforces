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
#include <ctime>
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int ln[N], rn[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    ln[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i-1]) ln[i] = ln[i-1];
        else ln[i] = i-1;
    }
    rn[n] = n+1;
    for (int i = n-1; i >= 1; --i) {
        if (a[i] == a[i+1]) rn[i] = rn[i+1];
        else rn[i] = i+1;
    }
    for (int i= 1; i <= n; ++i) {
      //  cout<<"i="<<i<<endl;
        int ans=-1;
        if (i-1>=1 && a[i-1] > a[i]) {
            ans=1;
        } else if (i+1 <= n && a[i+1] > a[i]) {
            ans=1;
        } else {
            int l=1,r=i-1;
            while(l<r) {
                int mid=(l+r+1)/2;
                if (sum[i-1]-sum[mid-1] > a[i]) {
                    l = mid;
                } else {
                    r=mid-1;
                }
            }
         //   cout<<"r1="<<r<<endl;
            if (r >= 1 && sum[i-1]-sum[r-1] > a[i]) {
                if (ln[i-1] > 0) {
                    int id = min(ln[i-1], r);
                    ans = (ans < 0 ? i-id:  min(ans, i-id));
                }
            }
            l = i+1, r = n;
            while(l < r) {
              //  cout<<"lr="<<l<<" "<<r<<endl;
                int mid = (l+r)/2;
                if (sum[mid]-sum[i] > a[i]) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
          //  cout<<"r2="<<r<<endl;
            if (r <= n && sum[r] - sum[i] > a[i]) {
                if (rn[i+1] <= n) {
                    int id = max(rn[i+1], r);
                    ans = (ans < 0 ? id-i : min(ans, id-i));
                }
            }
        }
        printf("%d ", ans);
    }
    cout<<endl;
  }
  return 0;
}
