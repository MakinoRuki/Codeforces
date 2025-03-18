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
#define M 750
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
int dp1[N];
int dp2[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s1,s2;
    cin>>s1>>s2;
    int n = (int)s1.size();
    for (int i = n; i >= 1; --i) {
        if (i == n) {
            dp1[i] = i;
            dp2[i] = i;
        } else {
            if (s1[i-1] == s1[i]) {
                dp1[i] = dp1[i+1];
            } else {
                dp1[i] = i;
            }
            if (s2[i-1] == s2[i]) {
                dp2[i] = dp2[i+1];
            } else {
                dp2[i] = i;
            }
        }
    }
    int cur = 1;
    int ed = dp1[1];
    int ans=0;
    int cc = s1[cur-1]-'0';
    while(cur <= n) {
       // cout<<"cur="<<cur<<" "<<ed<<" "<<cc<<endl;
        if (cc != s2[cur-1]-'0') {
            int nxt = ed+1;
            if (nxt > n) {
                ans=-1;
                break;
            }
            int len1 = dp1[nxt]-nxt+1;
            int len2 = dp2[cur]-cur+1;
            int nnxt=-1;
            if (dp1[nxt]+1<=n) {
                nnxt=dp1[nxt]+1;
            }
            if (len1 > len2) {
                ans=-1;
                break;
            }
            ans++;
            cur += len1;
            ed += len1;
            if (nnxt>=0) {
                ed = dp1[nnxt];
            }
        } else {
            int len1=ed-cur+1;
            int len2 = dp2[cur]-cur+1;
            if (len1 > len2) {
                ans=-1;
                break;
            }
          //  cout<<"len="<<len1<<" "<<len2<<endl;
            cur = ed+1;
            ed = dp1[cur];
            cc = s1[cur-1]-'0';
          //  cout<<cur<<" "<<ed<<" "<<cc<<endl;
        }
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
