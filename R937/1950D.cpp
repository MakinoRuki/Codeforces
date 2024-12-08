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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
vector<int> ds;
bool dp[N];
int main() {
  ds.clear();
  for (int i = 0; i < (1<<6); ++i) {
    vector<int> bs;
    bs.clear();
  //  int num=0;
    for (int j = 5; j >= 0; --j) {
        if ((1<<j)&i) bs.push_back(1);
        else bs.push_back(0);
       // num*=10;
    }
    int x = bs[0]*100000+bs[1]*10000+bs[2]*1000+bs[3]*100+bs[4]*10+bs[5];
    ds.push_back(x);
  }
  memset(dp, false, sizeof(dp));
  for (int i = 0; i < ds.size(); ++i) {
   // cout<<"i="<<ds[i]<<endl;
    dp[ds[i]]=true;
  }
  for (int i = 0; i < N; ++i) {
    if (dp[i]) {
        for (int x : ds) {
            ll res=(ll)x*(ll)i;
            if (res<N) dp[res]=true;
        }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (dp[n]) puts("YES");
    else puts("NO");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

