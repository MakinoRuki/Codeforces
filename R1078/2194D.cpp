
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
#define N 500005
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
vector<int> mp;
int dp[N][2];
int sum[N];
int dt;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    mp.clear();
    dt = n*m;
    int tot=0;
    for (int i =1 ; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int x;
        scanf("%d", &x);
        mp.push_back(x);
        sum[(i-1)*m+j] = 0;
        tot += x;
      }
    }
    if (tot / 2 == 0) {
      puts("0");
      string ans=string(n,'D')+string(m,'R');
      cout<<ans<<endl;
      continue;
    }
 //   cout<<"tot="<<tot<<endl;
    int cx=-1, cy=-1;
    int cnt=0;
    for (int i = n-1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        
        cnt+=mp[i*m+j];
     //   cout<<"ij="<<i<<" "<<j<<" "<<mp[i*m+j]<<" "<<cnt<<endl;
        if (cnt == tot/2) {
          cx=i;
          cy=j;
          break;
        }
      }
      if (cx >=0) break;
    }
//    cout<<"cxy="<<cx<<" "<<cy<<endl;
    string ans="";
    for (int i = n-1; i > cx; --i) {
      ans += "D";
    }
    int dt = m-1-cy;
    ans += string(dt, 'R');
    ans += "D" + string(cy+1, 'R');
    for (int i = cx-1; i >= 0; --i) {
      ans += "D";
    }
    reverse(ans.begin(), ans.end());
    printf("%lld\n", (ll)cnt*(ll)(tot-cnt));
    cout<<ans<<endl;
  }
  return 0;
}

