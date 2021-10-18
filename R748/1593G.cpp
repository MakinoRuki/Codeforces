#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
int a,b;
string s;
int q;
struct node {
  int l, r;
  int st, len;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].st = ((s[l-1] == '(' || s[l-1] == ')') ? 0 : 1);
    tree[id].len = 1;
  //  cout<<"id="<<id<<" "<<l<<" "<<r<<" "<<tree[id].len<<" "<<tree[id].st<<endl;
    return ;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  if (tree[id*2].len == 0) {
    tree[id].len=tree[id*2+1].len;
    tree[id].st = tree[id*2+1].st;
  } else {
    if (tree[id*2+1].len == 0) {
      tree[id].len=tree[id*2].len;
      tree[id].st = tree[id*2].st;
    } else {
      int ed = tree[id*2].st;
      if (tree[id*2].len % 2== 0) ed = !ed;
      if (ed == tree[id*2+1].st) {
        if (tree[id*2].len >= tree[id*2+1].len) {
          tree[id].len = tree[id*2].len-tree[id*2+1].len;
          tree[id].st = tree[id*2].st;
        } else {
          tree[id].len = tree[id*2+1].len - tree[id*2].len;
          tree[id].st = tree[id*2+1].st;
          if (tree[id*2].len % 2) {
            tree[id].st = !tree[id].st;
          }
        }
      } else {
        tree[id].len = tree[id*2].len + tree[id*2+1].len;
        tree[id].st = tree[id*2].st;
      }
    }
  }
 // cout<<"id="<<id<<" "<<l<<" "<<r<<" "<<tree[id].len<<" "<<tree[id].st<<endl;
}
pair<int,int> query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return make_pair(tree[id].len, tree[id].st);
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    auto p1 = query(id*2, l, mid);
    auto p2 = query(id*2+1, mid+1, r);
    int l1 = p1.first;
    int s1 = p1.second;
    int l2 = p2.first;
    int s2 = p2.second;
    if (l1 == 0) {
      return p2;
    } else {
      if (l2 == 0) return p1;
      int ed = s1;
      if (l1 % 2 == 0) ed = !ed;
      if (ed == s2) {
        int len = max(l1, l2) - min(l1, l2);
        int st;
        if (l1 >= l2) st = s1;
        else {
          st = s2;
          if (l1 % 2) st = !st;
        }
        return make_pair(len, st);
      } else {
        return make_pair(l1+l2, s1);
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    build(1, 1, n);
    scanf("%d", &q);
    while(q-->0) {
      int l, r;
      scanf("%d %d", &l, &r);
      auto res = query(1, l, r);
      printf("%d\n", res.first/2);
    }
  }
  return 0;
}
