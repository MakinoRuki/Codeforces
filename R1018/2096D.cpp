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
#define M 1005
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
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> xy;
    xy.clear();
    map<int, int> mx;
    map<int, int> mxy;
    mx.clear();
    mxy.clear();
    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d%d", &x, &y);
        xy.push_back(make_pair(x, y));
        mx[x]++;
        mxy[x+y]++;
    }
    int ansx=0,ansy=0;
    for (auto itr : mx) {
        if (itr.second & 1) {
            ansx = itr.first;
            break;
        }
    }
    for (auto itr : mxy) {
        if (itr.second & 1) {
            ansy = itr.first - ansx;
            break;
        }
    }
    printf("%d %d\n", ansx, ansy);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
