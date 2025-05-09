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
#define N 1000005
#define M 6000000
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
int dp[N];
int cnt[20];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); ++i) {
        int c=s[i]-'0';
        cnt[c]++;
    }
    string ans="";
    for (int i = 1; i <= 10; ++i) {
        for (int c = 10-i; c <= 9; ++c) {
            if (cnt[c]) {
                ans.push_back(c+'0');
                cnt[c]--;
                break;
            }
        }
    }
    cout<<ans<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
