#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100001;
const ll MAX = 0x3f3f3f3f3f3f3f3f;
const int MOD = int(1e9) + 7;

vector<pair<ll, int>> edge[MAXN];
ll dist[MAXN]; // minimum distance
ll num[MAXN]; // number of ways with the minimum distance
int minf[MAXN]; // minimum flights with minimum distance
int maxf[MAXN]; // maximum flights with minimum distance
bool v[MAXN]; // if a node is visited

void djikstra(int s) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	pq.push({dist[s] = 0, s});
	num[s] = 1;
	while (!pq.empty()) {
		int vert = pq.top().second; pq.pop();

		if (v[vert])
			continue;
		v[vert] = true;
		for (auto [cost, next] : edge[vert]) {
			ll alt = cost + dist[vert];

			if (alt == dist[next]) {
				num[next] = (num[next] + num[vert]) % MOD;
				minf[next] = min(minf[next], minf[vert] + 1);
				maxf[next] = max(maxf[next], maxf[vert] + 1);
			} else if (alt < dist[next]) {
				num[next] = num[vert];
				minf[next] = minf[vert] + 1;
				maxf[next] = maxf[vert] + 1;
				pq.push({dist[next] = alt, next});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0, start, end, cost; i < m; i++) {
		cin >> start >> end >> cost;
		edge[start].push_back({cost, end});
	}
	memset(dist + 1, 0x3f, n * sizeof(long long));
	djikstra(1);
	cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n];
}
