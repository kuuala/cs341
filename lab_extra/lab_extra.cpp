#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N, R1, C1, R2, C2;
vector<vector<int>> tecey_lab;
vector<vector<int>> perfey_lab;
pair<pair<int, int>, pair<int, int>> block(make_pair(-1, -1), make_pair(-1, -1)); // заглушка
queue<pair<pair<int, int>, pair<int, int>>> q;
vector<vector<vector<vector<bool>>>> used;
using vvv = vector<vector<vector<bool>>>;
using vv = vector<vector<bool>>;
using v = vector<bool>;

inline void input() {
	cin >> N >> R1 >> C1 >> R2 >> C2;
	tecey_lab.resize(N);
	perfey_lab.resize(N);
	for (int i = 0; i < N; ++i) {
		tecey_lab[i].resize(N);
		perfey_lab[i].resize(N);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> tecey_lab[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> perfey_lab[i][j];
		}
	}
}

bool in_lab(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < N;
}

bool can_go_tecey(int i, int j) {
	if (!in_lab(i, j)) {
		return false;
	}
	else {
		return tecey_lab[i][j] == 0;
	}
}

bool can_go_prefey(int i, int j) {
	if (!in_lab(i, j)) {
		return false;
	}
	else {
		return perfey_lab[i][j] == 0;
	}
}

bool is_block(pair<pair<int, int>, pair<int, int>> v) {
	return v.first.first == -1 && v.first.second == -1 && v.second.first == -1 && v.second.second == -1;
}

bool is_finish(pair<pair<int, int>, pair<int, int>> v) {
	return v.first.first == 0 && v.first.second == 0 && v.second.first == 0 && v.second.second == 0;
}

void push_queue(pair<pair<int, int>, pair<int, int>> v, int i, int j) {
	pair<int, int> tes = v.first;
	pair<int, int> pe = v.second;
	if (can_go_tecey(tes.first + i, tes.second + j)) {
		if (can_go_prefey(pe.first + i, pe.second + j)) {
			if (!used[tes.first + i][tes.second + j][pe.first + i][pe.second + j]) {
				used[v.first.first + i][v.first.second + j][v.second.first + i][v.second.second + j] = true;
				q.push(make_pair(make_pair(tes.first + i, tes.second + j), make_pair(pe.first + i, pe.second + j)));
			}
		}
		else {
			if (!used[tes.first + i][tes.second + j][pe.first][pe.second]) {
				used[v.first.first + i][v.first.second + j][v.second.first][v.second.second] = true;
				q.push(make_pair(make_pair(tes.first + i, tes.second + j), make_pair(pe.first, pe.second)));
			}
		}
	}
	else {
		if (can_go_prefey(pe.first + i, pe.second + j)) {
			if (!used[tes.first][tes.second][pe.first + i][pe.second + j]) {
				used[v.first.first][v.first.second][v.second.first + i][v.second.second + j] = true;
				q.push(make_pair(make_pair(tes.first, tes.second), make_pair(pe.first + i, pe.second + j)));
			}
		}
	}
}

int bfs(int r1, int c1, int r2, int c2) {
	used.assign(N, vvv(N, vv(N, v(N, false))));
	int res = 0;
	q.push(make_pair(make_pair(r1, c1), make_pair(r2, c2)));
	q.push(block);
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> v = q.front();
		q.pop();
		if (is_block(v)) {
			++res;
			q.push(block);
			continue;
		}
		else {
			if (is_finish(v)) {
				break;
			}
			else {
				push_queue(v, 0, -1);
				push_queue(v, 0, 1);
				push_queue(v, 1, 0);
				push_queue(v, -1, 0);
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	cout << bfs(R1, C1, R2, C2);
	fclose(stdin);
	fclose(stdout);
}

