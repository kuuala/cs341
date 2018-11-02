#include <iostream>
#include <vector>
#include <limits>

using namespace std;

inline void input_function();
inline void create_graph();
inline void ford_fulckerson();
inline void output_function();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input_function();
	create_graph();
    ford_fulckerson();
	output_function();
	fclose(stdin);
	fclose(stdout);
}

struct edge;

int N;
int K;
int s;
int t;
int max_flow = 0;
vector<int> pvktrans_raw;
vector<int> pvktrans_col;
vector<int> pins_raw;
vector<int> pins_col;
vector<vector<edge>> graph;
vector<bool> used;


struct edge {
	int to;
	int capacity;
	int flow;
	edge(int to, int capacity, int flow): to(to), capacity(capacity), flow(flow) {}
};


inline void input_function() {
	cin >> N >> K;
	pvktrans_col.resize(static_cast<unsigned long>(K));
	pvktrans_raw.resize(static_cast<unsigned long>(K));
	pins_col.resize(static_cast<unsigned long>(K));
	pins_raw.resize(static_cast<unsigned long>(K));
	used.assign(static_cast<unsigned long>(2 * N * N + 2), false);
	for (int i = 0; i < K; ++i) {
		cin >> pvktrans_raw[i];
	}
	for (int i = 0; i < K; ++i) {
		cin >> pvktrans_col[i];
	}
	for (int i = 0; i < K; ++i) {
		cin >> pins_raw[i];
	}
	for (int i = 0; i < K; ++i) {
		cin >> pins_col[i];
	}
}

int calc_position(int level, int i, int j) {
	return N * N * level + i * N + j;
}

inline void create_graph() {
	graph.resize(static_cast<unsigned long>(2 * N * N + 2));
	s = 2 * N * N;
	t = s + 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int lower_ind = calc_position(0, i, j);
			graph[calc_position(1, i, j)].emplace_back(lower_ind, 1, 0);
			graph[lower_ind].emplace_back(calc_position(1, i, j), 0, 0);
			if (i > 0) {
				graph[lower_ind].emplace_back(calc_position(1, i - 1, j), 1, 0);
				graph[calc_position(1, i - 1, j)].emplace_back(lower_ind, 0, 0);
			}
			if (i < N - 1) {
				graph[lower_ind].emplace_back(calc_position(1, i + 1, j), 1, 0);
				graph[calc_position(1, i + 1, j)].emplace_back(lower_ind, 0, 0);
			}
			if (j > 0) {
				graph[lower_ind].emplace_back(calc_position(1, i, j - 1), 1, 0);
				graph[calc_position(1, i, j - 1)].emplace_back(lower_ind, 0, 0);
			}
			if (j < N - 1) {
				graph[lower_ind].emplace_back(calc_position(1, i, j + 1), 1, 0);
				graph[calc_position(1, i, j + 1)].emplace_back(lower_ind, 0, 0);
			}
		}
	}
	for (int i = 0; i < pins_raw.size(); ++i) {
		int calc = calc_position(1, pins_raw[i], pins_col[i]);
		graph[s].emplace_back(calc, 1, 0);
		graph[calc].emplace_back(s, 0, 0);
	}
	for (int i = 0; i < pvktrans_raw.size(); ++i) {
		int calc = calc_position(0, pvktrans_raw[i], pvktrans_col[i]);
		graph[calc].emplace_back(t, 1, 0);
		graph[t].emplace_back(calc, 0, 0);
	}

}

int dfs_ff(int u, int current_bw) {
	if (u == t) {
		return current_bw;
	}
	used[u] = true;
	for (edge &child: graph[u]) {
		if (!used[child.to] && (child.flow < child.capacity)) {
			int delta = dfs_ff(child.to, min(current_bw, child.capacity - child.flow));
			if (delta > 0) {
				child.flow += delta;
				for (auto &back_child: graph[child.to]) {
					if (back_child.to == u) {
						back_child.flow -= delta;
						break;
					}
				}
				return delta;
			}
		}
	}
	return 0;
}

void dfs(int v) {
    if (v < (N * N)) {
        cout << v << ' ';
	}
	for (edge &child: graph[v]) {
		if (child.flow == 1) {
			dfs(child.to);
		}
	}
}

inline void ford_fulckerson() {
    int iter_result = 0;
    while ((iter_result = dfs_ff(s, numeric_limits<int>::max())) > 0) {
        fill(used.begin(), used.end(), false);
        max_flow += iter_result;
    }
}

inline void output_function() {
	if (max_flow != K) {
		cout << -1;
	} else {
		for (edge &child: graph[s]) {
			dfs(child.to);
			cout << endl;
		}
	}
}
