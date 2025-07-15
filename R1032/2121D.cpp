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
int row[N], col[N];
vector<pair<int,int>> ans;
void move(int r1, int c1, int r2, int c2) {
    if (r1 != r2) {
        ans.push_back(make_pair(3, c1));
        swap(row[a[c1]], row[b[c1]]);
        swap(a[c1], b[c1]);
        r1 = r2;
    }
    for (int i = c1-1; i >= c2; --i) {
        ans.push_back(make_pair(r2, i));
        if (r2 == 1) {
           swap(col[a[i]], col[a[i+1]]);
           swap(a[i], a[i+1]);
        } else {
            swap(col[b[i]], col[b[i+1]]);
            swap(b[i], b[i+1]);
        }
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        row[a[i]] = 1;
        col[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        row[b[i]] = 2;
        col[b[i]] = i;
    }
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        int r = row[i];
        int c = col[i];
        move(r, c, 1, i);
        r = row[i+n];
        c = col[i+n];
        move(r, c, 2, i);
    }
    int sz=(int)ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
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
