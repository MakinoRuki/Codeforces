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
#define M 1002
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
vector<pair<pair<int,int>,int>> v;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    v.clear();
    for (int i = 1; i <= n; ++i) {
        int x,y;
        scanf("%d%d", &x, &y);
        v.push_back(make_pair(make_pair(x, y), i));
    }
    sort(v.begin(), v.end());
    sort(v.begin(), v.begin()+n/2, [](const pair<pair<int,int>,int>& x, const pair<pair<int,int>,int>& y) {
        return x.first.second < y.first.second;
    });
    sort(v.begin()+n/2, v.end(), [](const pair<pair<int,int>,int>& x, const pair<pair<int,int>,int>& y) {
        return x.first.second < y.first.second;
    });
    for (int i =0; i < n/2; ++i) {
        printf("%d %d\n", v[i].second, v[n-1-i].second);
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
