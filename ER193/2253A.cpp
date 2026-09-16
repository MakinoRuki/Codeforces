
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int n;
int t;
int vis[N];

int main() {
  vis[0] = vis[1] = 1;

  for (int i = 2; i * i < N; ++i) {
    if (!vis[i]) {
      for (int j = i * i; j < N; j += i) {
        vis[j] = 1;
      }
    }
  }

  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    if (!vis[n + 1]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
