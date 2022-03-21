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
#define M 202
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
struct node {
  int l, r;
  int cnt;
  int mn;
} tree[N<<2];
vector<pair<int,int>> sg;
void build(int id, int l, int r, vector<int>& v) {
  tree[id].l= l;
  tree[id].r = r;
  if (l == r) {

    tree[id].mn = v[l-1];
   // cout<<"id="<<id<<" "<<tree[id].l<<" "<<tree[id].r<<" "<<tree[id].mn<<endl;
   // if (l == 1) cout<<"v="<<tree[id].mn<<endl;
    return ;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid, v);
  build(id*2+1, mid+1, r, v);
  tree[id].mn = min(tree[id*2].mn, tree[id*2+1].mn);
}
int query(int id, int l, int r) {
  if (tree[id].l == tree[id].r) {
   // cout<<"id2="<<id<<" "<<tree[id].l<<" "<<tree[id].r<<" "<<tree[id].mn<<endl;
    //cout<<"l="<<l<<" "<<tree[id].mn<<endl;
    return tree[id].mn;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) return query(id*2, l, r);
  else if (l > mid) return query(id*2+1, l, r);
  else {
    return min(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int main() {
  cin>>n;
  sg.clear();
  map<int,int> mp;
  mp.clear();
  for (int i= 1; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    sg.push_back(make_pair(l, r));
    mp[l]++;
    mp[r+1]--;
  }
  m = (int)mp.size();
  vector<int> v1, v2;
  v1.clear();
  v2.clear();
  for (auto itr : mp) {
    v1.push_back(itr.first);
    v2.push_back(itr.second);
  }
  for (int i = 1; i < v2.size(); ++i) {
    v2[i] += v2[i-1];
  }
  // for (int i = 0; i < v1.size(); ++i) {
  //   cout<<"i="<<i<<" "<<v1[i]<<" "<<v2[i]<<endl;
  // }
  build(1, 1, m-1, v2);
  for (int i = 0; i < sg.size(); ++i) {
    int l = sg[i].first;
    int r = sg[i].second;
    int id1 = lower_bound(v1.begin(), v1.end(), l) - v1.begin();
    int id2 = upper_bound(v1.begin(), v1.end(), r) - v1.begin();
  //  if (i == 0) cout<<"id="<<id1+1<<" "<<id2+1<<endl;
    int res = query(1, id1+1, id2);
    if (res > 1) {
      printf("%d\n", i+1);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
