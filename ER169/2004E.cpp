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
#define M 10000005
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
int sg[M];
void init() {
    for (int i = 1; i < M; ++i) {
        sg[i] = -1;
    }
    int cnt=0;
    for (int i = 1; i < M; ++i) {
        if (i == 1) sg[i] = 1;
        else {
            if (sg[i] < 0) {
                cnt++;
                if (i == 2) sg[i] = 0;
                else sg[i] = cnt;
                for (int j = 2*i; j < M; j += i) {
                    if (sg[j] < 0) sg[j] = sg[i];
                }
            } else {
                if ((i%2)==0) sg[i] = 0;
            }
        }
    }
}
int main() {
  init();
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int res=0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        res ^= sg[x];
    }
    if (res) puts("Alice");
    else puts("Bob");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
