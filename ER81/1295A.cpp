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
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		if (n%2) {
			printf("7");
			int x = n/2;
			x--;
			for (int i = 1; i <= x; ++i) {
				printf("1");
			}
			cout<<endl;
		} else {
			int x = n/2;
			for (int i = 1; i <= x; ++i) {
				printf("1");
			}
			cout<<endl;
		}
	}
	return 0;
}
