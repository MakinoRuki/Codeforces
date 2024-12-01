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
#define N 2000005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
vector<int> edges[N];
int dep[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
        dep[i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &a[i]);
        edges[a[i]].push_back(i);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = n; i >= 1; --i) {
        if (edges[i].empty()) continue;
        for (int j = 0; j < edges[i].size(); ++j) {
            int v = edges[i][j];
            q.push(dep[v]);
        }
        while(q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push(y+1);
        }
        if (edges[i].size() <= 1) {
            dep[i] = q.top()+1;
        } else {
            dep[i] = q.top();
        }
        q.pop();
    }
    printf("%d\n", dep[1]);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

