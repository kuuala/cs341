#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory>
#include <numeric>

using namespace std;


inline void input_function();
inline void solve();

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input_function();
    solve();
    fclose(stdin);
    fclose(stdout);
}

int H; // count of horizontal words
int V; // count of vertical words
const int INF = numeric_limits<int>::max(); // infinity
int n; // count vertex
vector<pair<int, pair<int, int>>> g; // list of edges
int span_letters_count; // count letters in span graph
int graph_letters_count; // count letters in graph
int all_letters_count; // count letters in web (with re-letters)
vector<int> p;
vector <pair<int,int>> res;

struct word{
    word(int line, int x, int y){
        this->line = line;
        this->x = x;
        this->y = y;
        this->prev_coordinate = -1;
        this->prev_inter = false;
        this->prev_index = -1;
    }
    int line, x, y, prev_coordinate, prev_index;
    bool prev_inter;
};

inline void input_function(){
    int x, y, z;
    cin >> H >> V;
    vector<word> horizontal_words;
    vector<word> vertical_words;
    for(int i = 0; i < H; ++i){
        cin >> x >> y >> z;
        horizontal_words.emplace_back(x, y, z);
        all_letters_count += (z - y) + 1;
    }
    for(int i = 0; i < V; ++i){
        cin >> x >> y >> z;
        vertical_words.emplace_back(z, x, y);
        all_letters_count += (y - x) + 1;
    }
    sort(horizontal_words.begin(), horizontal_words.end(), [](const word& x, const word& y) { return x.line < y.line; });
    sort(vertical_words.begin(), vertical_words.end(), [](const word& x, const word& y) { return x.line < y.line; });
    int point_inter = -1;
    for(auto &h_word: horizontal_words){
        bool flag = false;
        int prev_intersection_point = -1;
        for(auto &v_word: vertical_words){
            if (h_word.line >= v_word.x && h_word.line <= v_word.y && h_word.x <= v_word.line && h_word.y >= v_word.line){
                if (!flag){
                    prev_intersection_point = v_word.line;
                    ++point_inter;
                    flag = true;
                } else {
                    int new_intersection_point = v_word.line;
                    int length = new_intersection_point - prev_intersection_point - 1;
                    graph_letters_count += length;
                    g.emplace_back(length, make_pair(point_inter + 1, point_inter));
                    g.emplace_back(length, make_pair(point_inter, point_inter + 1));
                    ++point_inter;
                    prev_intersection_point = new_intersection_point;
                }
                if (v_word.prev_inter){
                    int length = h_word.line - v_word.prev_coordinate - 1;
                    graph_letters_count += length;
                    g.emplace_back(length, make_pair(v_word.prev_index, point_inter));
                    g.emplace_back(length, make_pair(point_inter, v_word.prev_index));
                }
                v_word.prev_index = point_inter;
                v_word.prev_coordinate = h_word.line;
                v_word.prev_inter = true;
            }
        }
    }
    n = point_inter + 1;
}

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap(a, b);
    if (a != b)
        p[a] = b;
}

void kruskal(){
    span_letters_count = 0;
    sort(g.begin(), g.end());
    p.resize(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    for (int i = 0; i < g.size(); ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            span_letters_count += l;
            res.emplace_back(g[i].second);
            dsu_unite(a, b);
        }
    }
}

void solve(){
    kruskal();
    int result = graph_letters_count - span_letters_count;
    if (result){
        cout << all_letters_count - n - result;
    } else {
        cout << -1;
    }
}