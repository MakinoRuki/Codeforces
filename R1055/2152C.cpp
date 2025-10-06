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
#define N 600005
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
int id[N];
int cnt[N][2];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    cnt[0][0]=0,cnt[0][1]=0;
    for (int i =1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1] = cnt[i-1][1];
        if (a[i]) cnt[i][1]++;
        else cnt[i][0]++;
    }
    id[0]=-1;
    id[1]=-1;
    for (int i = 2; i <= n; ++i) {
        id[i] = id[i-1];
        if (a[i] == a[i-1]) {
            id[i] = i;
        }
    }
    while(q-->0) {
       int l, r;
       scanf("%d%d", &l, &r);
       int n0=cnt[r][0]-cnt[l-1][0];
       int n1=cnt[r][1]-cnt[l-1][1];
       if ((n0%3)||(n1%3)) {
           puts("-1");
       } else {
           int res=n0/3+n1/3;
           if (id[r]<= l) {
               res++;
           }
           printf("%d\n", res);
       }
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
