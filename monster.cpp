#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>
#define mn 1005
using namespace std;

int N, M;
queue<pii> q;
int paths[mn][mn];
pii from[mn][mn];
int oo = INT_MAX;
pii A;
string ans;
bool possible = false;

void retrace(pii node){ 
	pii origin = from[node.first][node.second];
	if(origin ==  pii(0,0)) return;
	if(origin.first == node.first+1) ans.push_back('U');
	if(origin.first == node.first-1) ans.push_back('D');
	if(origin.second == node.second+1) ans.push_back('L');
	if(origin.second==node.second-1) ans.push_back('R');
	retrace(origin);

}
void check(pii origin, pii dest){ 
	int pl = paths[origin.first][origin.second];
	if(pl+1<paths[dest.first][dest.second]){
		paths[dest.first][dest.second]  = pl+1;
		q.push(dest);
		from[dest.first][dest.second] = origin;
	}
}
bool mora = false; 
void bfs(){
	while(!q.empty()){
		pii loc = q.front(), next; q.pop();
		next = loc; next.first++; check(loc, next); 
		next = loc; next.first--; check(loc, next);
		next = loc; next.second++; check(loc, next);
		next = loc; next.second--; check(loc, next);
		if(mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			retrace(loc);
			possible = true;
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= M; j++){
			paths[i][j] = 1e9;
			if(s[j-1] == '#') paths[i][j] = 0;
			if(s[j-1] == 'M') {q.push(pii(i,j)); paths[i][j]  = 0;}
			if(s[j-1] == 'A') {A.first = i; A.second = j;}
		}
	}
	bfs(); 
	mora = true;
	from[A.first][A.second] = pii(0,0); 
	paths[A.first][A.second] = 0; q.push(A); 
	bfs(); 
	if(possible){
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	else cout << "NO" << endl;
}
