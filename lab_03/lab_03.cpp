#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

inline void input_function();
inline void solve();
inline void output_function();

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input_function();
    solve();
    output_function();
    fclose(stdin);
    fclose(stdout);
}

struct query;
int N; // count of nodes
int M; // count of highways
int D; // count of sabotages
int Q; // count of query
int s; // city data-center
int t; // octavius lab
int last_query_day;
long long max_bandwidth;
vector<vector<pair<int, long long>>> graph;
vector<query> queries;
vector<long long> responses;
vector<long long> capacities_of_vertex;
vector<bool> used;

struct query{
    int day;
    int in_edge;
    int out_edge;
    int initial_number;
    query(int d, int in, int out, int init){
        this->day = d;
        this->in_edge = in;
        this->out_edge = out;
        this->initial_number = init;
    }
};

bool compare_query_by_increase_day(const query &a, const query &b){
    return a.day < b.day;
}

inline void input_function(){
    int x, y, d;
    long long c;
    cin >> N >> M >> D >> Q;
    cin >> s >> t;
    graph.resize(static_cast<unsigned long>(N));
    queries.reserve(static_cast<unsigned long>(Q));
    responses.assign(Q, 0);
    for(int i = 0; i < M; ++i){
        cin >> x >> y >> c;
        graph[x].emplace_back(y, c);
    }
    for(int i = 0; i < Q; ++i){
        cin >> d >> x >> y;
        queries.emplace_back(d, x, y, i);
    }
}

void dfs(int v){
    used[v] = true;
    for(auto &i: graph[v]){
        int to = i.first;
        long long to_cap = i.second;
        if(to != t){
            if (!used[to]){
                dfs(to);
            }
        }
        capacities_of_vertex[v] = max(capacities_of_vertex[v], min(to_cap, capacities_of_vertex[to]));
    }
}

inline void sabotage() {
    used.assign(N, false);
    capacities_of_vertex.assign(N, -1);
    capacities_of_vertex[t] = numeric_limits<long long>::max();
    dfs(s);
    int current_vertex_index = s;
    max_bandwidth = capacities_of_vertex[s];
    while(current_vertex_index != t){
        for(auto &i: graph[current_vertex_index]){
            if(min(capacities_of_vertex[i.first], i.second) >= max_bandwidth){
                i.second /= 2;
                current_vertex_index = i.first;
                break;
            }
        }
    }
}


inline void lexis_sort(){
    for(auto &x: graph){
        sort(x.begin(), x.end());
    }
}

bool lb_comp(const pair<int, int> &a, int b){
    return a.first < b;
}

inline void solve(){
    int current_query_index = 0;
    sort(queries.begin(), queries.end(), compare_query_by_increase_day);
    lexis_sort();
    last_query_day = queries[queries.size()-1].day;
    for(int i = 1; i <= last_query_day; ++i){
        sabotage();
        while (queries[current_query_index].day == i) {
            query &current_query = queries[current_query_index];
            const int in = current_query.in_edge;
            const int out = current_query.out_edge;
            auto destination_edge = lower_bound(graph[in].begin(), graph[in].end(), out, lb_comp);
            if((destination_edge != graph[in].end()) && (destination_edge->first == out)){
                responses[current_query.initial_number] = destination_edge->second;
            } else {
                destination_edge = lower_bound(graph[out].begin(), graph[out].end(), in, lb_comp);
                if((destination_edge != graph[out].end()) && (destination_edge->first == in)){
                    responses[current_query.initial_number] = destination_edge->second;
                }
            }
            ++current_query_index;
        }
    }
}

inline void output_function(){
    for(auto x: responses){
        cout << x << endl;
    }
}
