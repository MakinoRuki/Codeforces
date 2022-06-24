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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int dp[N][2][2];
int dp1[N][2][2];
void calc(string s) {
  int res=inf,cnt2=inf;
  int sz=(int)s.size();
  for (int i = 0; i < (1<<sz); ++i) {
    int cnt=0;
    int j;
    int pre=-1;
    int num=1;
    int tmp=0;
    for (j = 0; j < sz; ++j) {
      int x=s[j]-'0';
      if ((1<<j) & i) {
        tmp++;
        x^=1;
      }
      if (j == 0 || x == pre) {
        cnt++;
      } else {
        if (cnt % 2) break;
        cnt=1;
        num++;
      }
      pre=x;
    }
    if (j >= sz && cnt%2==0) {
      if (tmp < res) {

        res=tmp;
      //  cout<<"xx="<<tmp<<" "<<num<<endl;
        cnt2=num;
        //cout<<"cnt="<<cnt<<endl;
      } else if (tmp == res && cnt2 > num) {
       // cout<<"yy="<<tmp<<" "<<num<<endl;
        cnt2 = num;
      }
    }
   // cout<<"i="<<i<<" "<<res<<" "<<cnt<<endl;
  }
  cout<<"v="<<res<<" "<<cnt2<<endl;
}
void update(int i, int j, int k, int v1, int v2) {
  if (v1 < dp[i][j][k] || (v1==dp[i][j][k] && v2 < dp1[i][j][k])) {
    dp[i][j][k]=v1;
    dp1[i][j][k]=v2;
  }
}
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    // for (int i = 0; i < n; ++i) {
    //   int res=rnd()%2;
    //   s.push_back('0'+res);
    // }
    // cout<<s<<endl;
 //   calc(s);
    //cout<<calc(s)<<endl;
    vector<pair<int,int>> sg;
    sg.clear();
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        cnt++;
      } else {
        sg.push_back(make_pair(cnt, s[i-1]-'0'));
        cnt = 1;
      }
    }
    if (cnt>0) {
      sg.push_back(make_pair(cnt, s[n-1]-'0'));
    }
    for (int i = 0; i <= sg.size(); ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = inf;
          dp1[i][j][k] = inf;
        }
      }
    }
    if (sg[0].first % 2) {
      if (sg[0].first == 1) {
        dp[1][sg[0].second][1] = 0;
        dp1[1][sg[0].second][1] = 1;
        dp[1][!sg[0].second][1] = 1;
        dp1[1][!sg[0].second][1] = 1;
      } else {
        dp[1][sg[0].second][1] = 0;
        dp1[1][sg[0].second][1] = 1;
        dp[1][!sg[0].second][1] = 1;
        dp1[1][!sg[0].second][1] = 2;
      }
    } else {
      dp[1][sg[0].second][0] = 0;
      dp1[1][sg[0].second][0] = 1;
    }
  //  cout<<dp[1][1][1]<<" "<<dp[1][0][1]<<endl;
    int sz = (int)sg.size();
    for (int i = 1; i < sz; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          int c = sg[i].second;
          int num = sg[i].first;
          int c2 = num%2;
          if (dp[i][j][k] < inf) {
            if (c == j) {
              update(i+1, c, (c2+k)%2, dp[i][j][k], dp1[i][j][k]);
            } else {
              if (!k) {
                update(i+1, c, c2, dp[i][j][k], dp1[i][j][k]+1);
                if (num == 2) {
                  update(i+1, j, k, dp[i][j][k]+2, dp1[i][j][k]);
                }
                if (num == 1) {
                  update(i+1, j, !k, dp[i][j][k]+1, dp1[i][j][k]);
                }
              } else {
                if (num==1) {
                  update(i+1, j, 0, dp[i][j][k]+1, dp1[i][j][k]);
                } else {
                  update(i+1, c, !c2, dp[i][j][k]+1, dp1[i][j][k]+1);
                }
                if (num == 2) {
                  update(i+1, j, k, dp[i][j][k]+2, dp1[i][j][k]);
                }
              }
            }
          }
        }
      }
    }
    int res=inf;
    int res2=inf;
    for (int i = 0; i < 2; ++i) {
      if (dp[sz][i][0] < res) {
        res=dp[sz][i][0];
        res2=dp1[sz][i][0];
      } else if (dp[sz][i][0] ==res && dp1[sz][i][0]<res2) {
        res2=dp1[sz][i][0];
      }
    }
    printf("%d %d\n", res, res2);
  }
  return 0;
}
