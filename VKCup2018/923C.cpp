/* 01 trie树 */

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
#define M 105
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int ans[N];
struct node {
  int l, r;
  int cnt;
} tree[30*N];
int top=0;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);
    
  // }
  cin>>n;
 // cout<<"n="<<n<<endl;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  tree[0].l=0;
  tree[0].r=0;
  for (int i = 1; i <= n; ++i) {
    int cur=0;
    for (int j = 29; j >= 0; --j) {
      int bt = ((1<<j)&b[i])>0;
      if (bt) {
        if (!tree[cur].r) {
          tree[cur].r = ++top;
          tree[top].l=0;
          tree[top].r=0;
          tree[top].cnt=0;
        }
        cur = tree[cur].r;
        tree[cur].cnt++;
      } else {
        if (!tree[cur].l) {
          tree[cur].l = ++top;
          tree[top].l=0;
          tree[top].r=0;
          tree[top].cnt=0;
        }
        cur = tree[cur].l;
        tree[cur].cnt++;
      }
    }
  }
  for (int i  = 1; i <= n; ++i) {
    int res=0;
    int cur=0;
    for (int j = 29; j >= 0; --j) {
      int bt = ((1<<j)&a[i])>0;
    //  if (i==1 && j <= 4) cout<<"bt="<<bt<<endl;
      if (bt) {
        if (tree[cur].r && tree[tree[cur].r].cnt) {
        //  if (i==1 && j <= 4)cout<<"11"<<endl;
          cur = tree[cur].r;
          res += (1<<j);
        } else {
        //  if (i==1 && j <= 4)cout<<"10"<<endl;
          cur = tree[cur].l;
        }
      } else {
        if (tree[cur].l && tree[tree[cur].l].cnt) {
       //   if (i==1 && j <= 4)cout<<"00"<<endl;
          cur = tree[cur].l;
        } else {
       //   if (i==1 && j <= 4)cout<<"01"<<endl;
          cur = tree[cur].r;
          res += (1<<j);
        }
      }
      tree[cur].cnt--;
    }
    ans[i] = a[i] ^ res;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  cout<<endl;
  return 0;
}
