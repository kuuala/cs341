#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// n - количество провинций
// k - количество игроков
// d - количество соседей для провинции
int n, k, d;

//переменная для нахождения минимального расстояния
int mini = numeric_limits<int>::max();

//вектор стартовых позиций игроков
vector<int> start_pos;

//вектор расстояний от игрока i (индекс строки/столбца) до j (индекс стоблца/строки)
vector<vector<int>> out;

//список смежных вершин
vector<vector<int> > g;

//пара игроков
pair<int, int> ind;

//bfs возвращает вектор дистанций
vector<int> bfs(int s){
    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
            }
        }
    }
    return d;
}

void in_fun(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> d;
        vector<int> temp = vector<int>(d);
        for(int j = 0; j < d; ++j){
            cin >> temp[j];
        }
        g.push_back(temp);
    }
    start_pos = vector<int>(k);
    for (int i = 0; i < k; ++i)
        cin >> start_pos[i];
}

void out_fun(){
    for(int i = 0; i < out.size(); ++i){
        for(int j = 0; j < out[i].size(); ++j)
            cout << out[i][j] << ' ';
        cout << endl;
    }
    cout << ind.first << ' ' << ind.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    in_fun();

    for(int i = 0; i < start_pos.size(); ++i){
        vector<int> dop = bfs(start_pos[i]);
        vector<int> tempvec(start_pos.size());
        for (int j = 0; j < start_pos.size(); ++j) {
            tempvec[j] = dop[start_pos[j]];
            if(i != j){
                if (tempvec[j] < mini){
                    mini = tempvec[j];
                    ind = make_pair(i, j);
                    }
            }
        }
        out.push_back(tempvec);
    }

    out_fun();

    fclose(stdin);
    fclose(stdout);

    return 0;
}