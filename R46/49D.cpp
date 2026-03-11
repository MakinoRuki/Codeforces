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
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
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
//int ans[N];
int dp[N][2][2];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  // string s2;
  // cin>>s2;
  // cout<<"sz="<<(int)s2.size()<<endl;
  cin>>n;
  string s;
  cin>>s;
  int ans=0;
  string s1 = "0";
  string s2 = "1";
  for (int i = 1; i < n; ++i) {
    s1.push_back(s1[i-1] == '1' ? '0' : '1');
    s2.push_back(s2[i-1] == '1' ? '0' : '1');
  }
  int cnt1=0, cnt2=0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s1[i]) cnt1++;
    if (s[i] != s2[i]) cnt2++;
  }
  cout<<min(cnt1, cnt2)<<endl;
  return 0;
}
 
