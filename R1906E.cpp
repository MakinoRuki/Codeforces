/*
Merge的时候必然是连续一段一段地加入C。某一段x在y之前是满足x的所有数都小于y的第一个数。先预处理出一些block。然后背包dp分成两组。
*/

#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
bool dp[2*M][M];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  scanf("%d", &n);
  for (int i = 1; i <= 2*n; ++i) {
    scanf("%d", &a[i]);
  }
  int bg=0,ed=0;
  vector<pair<int,int>> v;
  v.clear();
  for (int i = 1; i <= 2*n; ++i) {
    if (i == 1) {
      bg=i,ed=i;
    } else {
      if (a[i] > a[bg]) {
        v.push_back(make_pair(bg, ed));
        bg=i,ed=i;
      } else {
        ed=i;
      }
    }
  }
  if (bg) v.push_back(make_pair(bg, ed));
  int sz=(int)v.size();
  for (int i = 0; i <= 2*n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = false;
    }
  }
  dp[0][0]=true;
  for (int i = 0; i < sz; ++i) {
    int len=v[i].second-v[i].first+1;
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j]) {
        dp[i+1][j]=true;
        if (j+len<=n) dp[i+1][j+len]=true;
      }
    }
  }
  if (!dp[sz][n]) {
    puts("-1");
    return 0;
  }
  vector<int> v1, v2;
  v1.clear();
  v2.clear();
  int cur=n;
  for (int i = sz; i >= 1; --i) {
    int len=v[i-1].second-v[i-1].first+1;
  //  cout<<"i="<<i<<" "<<cur<<endl;
    if (cur>=len && dp[i-1][cur-len]) {
      for (int j = v[i-1].second; j >= v[i-1].first; --j) {
        v1.push_back(a[j]);
      }
      cur -= len;
    } else {
      for (int j = v[i-1].second; j >= v[i-1].first; --j) {
        v2.push_back(a[j]);
      }
    }
  }
  for (int i = v1.size()-1; i >= 0; --i) {
    printf("%d ", v1[i]);
  }
  cout<<endl;
  for (int i = v2.size()-1; i >= 0; --i) {
    printf("%d ", v2[i]);
  }
  cout<<endl;
  return 0;
}
