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
#define N 300005
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
vector<string> mp;
int sum[2][N][27];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    string s1, s2;
    cin>>s1>>s2;
    for (int i = 0; i <= 27; ++i) {
        sum[0][0][i]=0;
        sum[1][0][i]=0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            sum[0][i+1][j] = sum[0][i][j];
            sum[1][i+1][j] = sum[1][i][j];
            if (s1[i] == 'a'+j) sum[0][i+1][j]++;
            if (s2[i] == 'a'+j) sum[1][i+1][j]++;
        }
    }
    while(q-->0) {
        int l,r;
        scanf("%d%d", &l, &r);
        int tot=0;
        for (int i = 0; i < 26; ++i) {
            int dt = (sum[0][r][i]-sum[0][l-1][i]) - (sum[1][r][i]-sum[1][l-1][i]);
            if (dt > 0) tot += dt;
        }
        printf("%d\n", tot);
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

