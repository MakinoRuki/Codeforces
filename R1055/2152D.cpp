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
#include <stack>
#include <bitset>
#include <chrono>
#define N 300005
#define M 305
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int cnt[N][3];
ll sum[N];
bool check(int x) {
    while((x%2)==0) {
        x/=2;
    }
    if (x == 1) return true;
    return false;
}
int getbs(int x) {
    int res=0;
    while(x>1) {
        res++;
        x/=2;
    }
    return res;
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    cnt[0][0]=cnt[0][1]=cnt[0][2]=0;
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < 3; ++j) {
            cnt[i][j]=cnt[i-1][j];
        }
        if (a[i]%2) {
            if (check(a[i]-1)) {
                cnt[i][1]++;
            } else {
                cnt[i][2]++;
            }
        } else {
            if (check(a[i])) {
                cnt[i][0]++;
            } else {
                cnt[i][2]++;
            }
        }
        sum[i] = sum[i-1] + getbs(a[i]);
    }
    while(q-->0) {
        int l, r;
        scanf("%d%d", &l, &r);
     //   int n0=cnt[r][0]-cnt[l-1][0];
        int n1=cnt[r][1]-cnt[l-1][1];
        int n2=cnt[r][2]-cnt[l-1][2];
        ll ans = sum[r]-sum[l-1]+n1/2+n2;
        printf("%lld\n", ans);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
