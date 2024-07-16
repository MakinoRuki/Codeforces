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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int ls[N][2];
int sum[N][2];
int rs[N][2];
int dp[N];
int main() {
  cin>>t;
  int cnt=0;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    ls[0][0] = 0;
    ls[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
      if (s1[i-1] == '1') {
        ls[i][0] = 0;
      } else {
        ls[i][0] = ls[i-1][0]+1;
      }
      if (s2[i-1] == '0') {
        ls[i][1] = 0;
      } else {
        ls[i][1] = ls[i-1][1]+1;
      }
    }
    sum[0][0]=sum[0][1]=0;
    sum[n+1][1]=0;
    for (int i = 1; i <= n; ++i) {
      sum[i][0] = 0;
      if ((s2[i-1] == '1')||(i-1>=1 && s1[i-2]=='0' && i+1<=n && s1[i] == '0')) {
        sum[i][0] = 1;
        if (i-1>= 1 && ((s2[i-2] == '1')||(i-2>=1&&s1[i-3]=='0'&&s1[i-1]=='0'))) {
          sum[i][0] = sum[i-1][0]+1;
        } else if (s1[i-1] == '0') {
          int len = ls[i][0];
          if (len > 1 && s2[i-len] == '1') {
            sum[i][0] = sum[i-len+1][0] + len-1;
          } else {
            sum[i][0] += max(len-2,0);
          }
        }
      }
    }
    rs[n+1][0]=0;
    rs[n+1][1]=0;
    for (int i = n; i >= 1; --i) {
      if (s1[i-1] == '1') {
        rs[i][0] = 0;
      } else {
        rs[i][0] = rs[i+1][0]+1;
      }
      if (s2[i-1] == '0') {
        rs[i][1] = 0;
      } else {
        rs[i][1] = rs[i+1][1]+1;
      }
    }


    for (int i = n; i >= 1; --i) {
      sum[i][1] = 0;
      if ((s2[i-1] == '1')||(i-1>=1 && s1[i-2]=='0' && i+1<=n && s1[i] == '0')) {
        sum[i][1] = 1;
        if (i+1 <= n && ((s2[i] == '1')||(i+2<=n&&s1[i+1]=='0'&&s1[i-1]=='0'))) {
          sum[i][1] = sum[i+1][1]+1;
        } else if (s1[i-1] == '0') {
          int len = rs[i][0];
          if (len > 1 && s2[i+len-2] == '1') {
            sum[i][1] = sum[i+len-1][1] + len-1;
          } else {
            sum[i][1] += max(len-2,0);
          }
        }
      }
    }

    dp[0] = 0;
    for (int i= 1; i <= n; ++i) {
      int len=sum[i][0];
      if (len == 0 || len == 1) {
        dp[i] = dp[i-1];
        if ((s1[i-1] == '1')||(i-1>=1&&i+1<=n&&sum[i-1][0]>0&&sum[i+1][0]>0)) dp[i]++;
      } else {
        dp[i] = dp[i-len]+len-2;
        if ((s1[i-1] == '1')||(i-1>=1&&i+1<=n&&sum[i-1][0]>0&&sum[i+1][0]>0)) dp[i]++;
        if ((s1[i-len] == '1')||(i-len>=1&&i-len+2<=n&&sum[i-len][0]>0&&sum[i-len+2][0]>0)) dp[i]++;
      }
    }
   // cout<<"x="<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<endl;
    scanf("%d", &q);
    while(q-->0) {
      int l, r;
      scanf("%d%d", &l, &r);
      int lb=l,rb=r;
      lb += 2;
      rb -= 2;
      int res=0;
      if (lb <= rb) {
        res=dp[rb]-dp[lb-1];
      }
      if (s1[l-1]=='1') {
        res++;
      }
      if (l+1<=r) {
        if (s1[l] == '1') res++;
        else {
          if (s2[l-1]=='1'&&l+2<=r&&(s2[l+1]=='1'||(l+3<=r&&sum[l+2][0]))) {
            res++;
          }
        }
      }
      if (r != l && r != l+1 && s1[r-1] == '1') {
        res++;
      }
      if (r-1>l+1) {
        if (s1[r-2] == '1') res++;
        else {
          if (s2[r-1] == '1' && r-2>=l&&(s2[r-3]=='1'||(r-3>=l&&sum[r-2][0]))) {
            res++;
          }
        }
      }
      // int len1 = 0;
      // int len2 = 0;
      // if (s2[l-1] == '1' || (l-1>=l&&s1[l-2]=='0'&&l+1<=r&&s1[l]=='0')) {
      //   len1=sum[l][1];
      // }
      // if (s2[r-1]=='1' || (r-1>=l&&s1[r-2]=='0'&&r+1<=r&&s1[r]=='0')) {
      //   len2=sum[r][0];
      // }
      // if (len1 >= r-l+1 && len2==0) {
      //   len1 = r-l;
      // } else if (len2 >= r-l+1 && len1==0) {
      //   len2 = r-l;
      // }
      // int res=0;
      // cout<<"res="<<len1<<" "<<len2<<endl;
      // if (l+len1-1>=r-len2+1) {
      //   if (r-l+1>=2) {
      //     res=r-l+1-2;
      //   }
      //   if (s1[l-1] == '1') res++;
      //   if (l<r&&s1[r-1] == '1') res++;
      // } else {
      //   if (len1>0) {
      //     if (len1>=2) { 
      //       res+=len1-2;
      //     }
      //     if (s1[l-1]=='1') res++;
      //     if (len1>1 && (s1[l+len1-2]=='1')||(l+len1<=r&&l+len1-2>=l&&s2[l+len1-1]=='1'&&s2[l+len2-3]=='1')) res++;
      //   }
      //   if (len2>0) {
      //     if (len2>=2) {
      //       res+=len2-2;
      //     }
      //     if (s1[r-1]=='1') res++;
      //     if (len2>1 && (s1[r-len2]=='1')||(r-len2>=l&&r-len2+2<=r&&s2[r-len2-1]=='1'&&s2[r-len2+1]=='1')) res++;
      //   }
      //   cout<<"res="<<res<<endl;
      //   if (len1>0&&len2>0) {
      //     res += dp[r-len2] - dp[l+len1-1];
      //   } else if (len1>0&&len2==0) {
      //     if (r-1>l+len1-1) {
      //       res += dp[r-1]-dp[l+len1-1];
      //     }
      //     if (s1[r-1]=='1') res++;
      //   } else if (len1==0&&len2>0) {
      //     if (r-len2>l) {
      //       res += dp[r-len2]-dp[l];
      //     }
      //     if (s1[l-1]=='1') res++;
      //   } else {
      //     if (r-1>l) res+=dp[r-1]-dp[l];
      //     if (s1[l-1]=='1')res++;
      //     if (l<r && s1[r-1]=='1') res++;
      //   }
      // }
      // cnt++;
      // if (t == 5460 && cnt==609) {
      //   //cout<<s1+"#"+s2<<endl;
      //   cout<<l*1000000+r<<endl;
      // }
      printf("%d\n", res);
    }
  }
  return 0;
}
