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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int rk,ck,rd,cd;
    scanf("%d%d%d%d", &rk, &ck, &rd, &cd);
    if (rk == rd) {
        if (ck == cd) {
            puts("0");
        } else if (ck < cd) {
            printf("%d\n", cd);
        } else {
            printf("%d\n", n-cd);
        }
    } else if (rk < rd) {
        if (ck == cd) {
            printf("%d\n", rd);
        } else if (ck < cd) {
            printf("%d\n", max(rd, cd));
        } else {
            printf("%d\n", max(rd, n-cd));
        }
    } else {
        if (ck == cd) {
            printf("%d\n", n-rd);
        } else if (ck < cd) {
            printf("%d\n", max(n-rd, cd));
        } else {
            printf("%d\n", max(n-rd, n-cd));
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
