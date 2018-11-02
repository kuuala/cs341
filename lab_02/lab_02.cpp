#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n - количество клиентов
// d - количество рейсов из аэропорта
int n, d;
// цены в аэропорте i-го клиента
vector<pair<int, int>> p;
// список смежных вершин исходного, транспонированного, конденсации
vector<vector<int>> gr;
// минимальная цена для каждого клиента
vector<int> min_cost;
// использованные вершины при обходе графа
vector<bool> used;

void dfs(int v, int f){
    used[v] = true;
    if (min_cost[v] > f)
        min_cost[v] = f;
    for (int i=0; i<gr[v].size(); ++i)
        if (!used[gr[v][i] ])
            dfs (gr[v][i], f);
}

inline void in_fun(){
    cin >> n;
    p.reserve(n);
    gr.assign(n,{});
    int cost;
    for(int i = 0; i < n; ++i){
        cin >> cost;
        p.push_back(make_pair(i, cost));
    }
    for(int i = 0; i < n; ++i){
        cin >> d;
        vector<int> temp;
        temp.reserve(d);
        for(int j = 0; j < d; ++j){
            cin >> temp[j];
            gr[temp[j]].push_back(i);
        }
    }
    used.assign(n, false);
    min_cost.assign(n, numeric_limits<int>::max());
}

inline void out_fun(){
    for(int i = 0; i < n; ++i)
        cout << min_cost[i] << ' ';
}

bool comparator (pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

inline void find_answ(){
    sort(p.begin(), p.end(), comparator);
    for(vector<pair<int,int>>::const_iterator i = p.begin(); i != p.end(); ++i){
        dfs(i->first, i->second);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    in_fun();
    find_answ();
    out_fun();

    fclose(stdin);
    fclose(stdout);
    return 0;
}