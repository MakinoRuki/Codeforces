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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int x,y;
		scanf("%d%d", &x, &y);
		if ((x+y)%2) {
			printf("%d %d\n", -1, -1);
		} else {
			if ((x%2==0) && (y%2 == 0)) {
				printf("%d %d\n", x/2, y/2);
			} else {
				printf("%d %d\n", (x+1)/2, (y-1)/2);
			}
		}
	}
  return 0;
}

