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
#define N 200005
#define M 1002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        rk.push_back(make_pair(a[i], i));
    }
    ll ans=0LL;
    sort(rk.begin(), rk.end());
    for (int i = 0; i < n; ++i) {
        ll sum=rk[i].first;
        int lid = -1, rid = -1;
        if (rk[i].second > 1 && rk[i].second < n) {
            for (int j = rk[i].second-1; j >= 1; --j) {
                if (lid < 0 || a[j] > a[lid]) {
                    lid = j;
                }
            }
            for (int j = rk[i].second +1; j <= n; ++j) {
                if (rid < 0 || a[j] > a[rid]) {
                    rid = j;
                }
            }
        }
        if (lid > 0 && rid > 0) {
            if (k == 1) continue;
            sum += a[lid] + a[rid];
            int cnt=0;
            int j = rk.size()-1;
            for (int j = rk.size()-1; j >= 0; --j) {
                if (rk[j].second != rk[i].second && rk[j].second != lid && rk[j].second != rid) {
                    if (cnt < k-2) {
                        sum += rk[j].first;
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        } else {
            int cnt = 0;
            for (int j = rk.size()-1; j >= 0; --j) {
                if (rk[j].second != rk[i].second) {
                    if (cnt < k) {
                        sum += rk[j].first;
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
       // cout<<"i="<<i<<" "<<rk[i].first<<" "<<rk[i].second<<" "<<ans<<endl;
        ans = max(ans, sum);
    }
    printf("%lld\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
