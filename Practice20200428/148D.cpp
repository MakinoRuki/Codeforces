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
#include <queue>
#define N 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
double pr[N][N][2];
int w,b;
int main() {
	cin>>w>>b;
	for (int i = 0; i <= w; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k < 2; ++k) {
				pr[i][j][k] = 0.0;
			}
		}
	}
	for (int i = 0; i <= w; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (i == 0) pr[i][j][k] = 0.0;
				else if (j==0) {
					if (!k) pr[i][j][k] = 1.0;
					else pr[i][j][k] = 0.0;
				} else {
					if (k==0) {
						if (i>0) pr[i][j][k] += (double)i/(double)(i+j);
						if (j>0) pr[i][j][k] += pr[i][j-1][!k]*(double)j/(double)(i+j);
					} else {
						if (j>0) {
							if (i>0) pr[i][j][k] += pr[i-1][j-1][!k]*(double)i/(double)(i+j-1);
							if (j>1) pr[i][j][k] += pr[i][j-2][!k]*(double)(j-1)/(double)(i+j-1);
							pr[i][j][k] *= (double)j/(double)(i+j);
						}
					}
				}
			}
		}
	}
	printf("%.10lf\n", pr[w][b][0]);
	return 0;
}
