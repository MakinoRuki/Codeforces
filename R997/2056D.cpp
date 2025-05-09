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
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    // ll n2 = (n+2)/2;
    // ll n1 = (n+1)/2;
    ll tot = (ll)n*(ll)(n+1)/2LL;
    map<pair<int,int>,int> cnt;
   // cout<<"tot="<<tot<<endl;
    for (int s = 1; s <= 10; ++s) {
        for (int i = 0; i <= n; ++i) {
            sum[i] = 0;
        }
        cnt.clear();
        int pre=0;
        for (int i = 1; i <= n; ++i) {
            int bt=i&1;
            sum[i] = sum[i-1];
            if (a[i] <= s) sum[i]--;
            else sum[i]++;
          //  if (s==3) cout<<"ssssssss=="<<i<<" "<<sum[i]<<endl;
            if (a[i] == s) {
                while(pre < i) {
                    int pt=(pre&1);
                    cnt[make_pair(sum[pre],pt)]++;
                    pre++;
                }
            }
         //   if (s == 3 && i == 8) cout<<"sum="<<sum[i]<<" "<<bt<<" "<<cnt[make_pair(sum[i], bt)]<<endl;
            if (cnt.find(make_pair(sum[i],bt)) != cnt.end()) {
                tot -= cnt[make_pair(sum[i],bt)];
            }
            // if (s == 3) cout<<"i="<<i<<" "<<tot<<" "<<pre<<endl;
            // if (s==3 && sum[i]==-2&& bt==0) cout<<"i====="<<i<<endl;
        }
       // cout<<"s="<<s<<" "<<tot<<endl;
    }
    printf("%lld\n", tot);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
