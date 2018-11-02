#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <limits>
#include <cmath>

#define cut pair<pair<double, double>, pair<double, double>>
const double EPS = 0.001;

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

struct pt {
    double x, y;

    pt() = default;
    pt(double x, double y) : x(x), y(y) {}

    bool operator<(const pt &a) const {
        return (x < (a.x - EPS)) || ((abs(x - a.x) < EPS) && (y < (a.y - EPS)));
    }

    bool operator!=(const pt &a) const {
        return (abs(x - a.x) >= EPS) || (abs(y - a.y) >= EPS);
    }

    bool operator==(const pt &a) const {
        return (abs(x - a.x) < EPS) && (abs(y - a.y) < EPS);
    }
};

struct line {
    double a, b, c;

    line() = default;
    line (pt p, pt q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm() {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z,  b /= z,  c /= z;
    }

    const double dist (pt p) {
        return a * p.x + b * p.y + c;
    }
};

int N;
vector<cut> roads;
vector<set<pt>> roads2;
vector<cut> nodes;
vector<vector<pair<pair<int, double>, pt>>> graph;
vector<double> distances;
bool is_vin = false;
bool is_shpu = false;
pt vintek;
pt shpuntek;
int start, finish;

const double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

inline void input_function() {
    cin >> N;
    roads.reserve(static_cast<unsigned long>(N));
    roads2.resize(static_cast<unsigned long>(N));
    double x1, x2, y1, y2;
    for (int i = 0; i < N; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        roads.emplace_back(make_pair(x1, y1), make_pair(x2, y2));
        roads2[i].insert({x1, y1});
        roads2[i].insert({x2, y2});
    }
    cin >> x1 >> y1;
    vintek = {x1, y1};
    cin >> x1 >> y1;
    shpuntek = {x1, y1};
}

inline bool betw(double l, double r, double x) {
    return (min(l, r) <= x + EPS) && (x <= max(l, r) + EPS);
}

inline bool intersect_1d(double a, double b, double c, double d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return max (a, c) <= min (b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt & left, pt & right) {
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) {
        return false;
    }
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) {
            return false;
        }
        if (b < a) {
            swap(a, b);
        }
        if (d < c) {
            swap(c, d);
        }
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw (a.x, b.x, left.x)
               && betw (a.y, b.y, left.y)
               && betw (c.x, d.x, left.x)
               && betw (c.y, d.y, left.y);
    }
}

inline void cuts_to_pts(cut &ab, cut &cd, pt &a, pt &b, pt &c, pt &d) {
    a.x = ab.first.first;
    a.y = ab.first.second;
    b.x = ab.second.first;
    b.y = ab.second.second;
    c.x = cd.first.first;
    c.y = cd.first.second;
    d.x = cd.second.first;
    d.y = cd.second.second;        
}

inline void find_intersections() {
    for (int i = 0; i < roads.size(); ++i) {
        for (int j = i + 1; j < roads.size(); ++j) {
            pt current_point(0, 0), a, b, c, d;
            cuts_to_pts(roads[i], roads[j], a, b, c, d);
            if (intersect(a, b, c, d, current_point, current_point)) {
                roads2[i].insert(current_point);
                roads2[j].insert(current_point);
            }
        }
    }
}

bool is_point_in_line(cut &l, pt &p) {
    if (abs(l.first.first - l.second.first) < EPS) {
        return (abs(l.first.first - p.x) < EPS) &&
               ((l.first.second - EPS <= p.y && p.y <= l.second.second + EPS) ||
                (l.second.second - EPS <= p.y && p.y <= l.first.second + EPS));
    }
    if (abs(l.first.second - l.second.second) < EPS) {
        return (abs(l.first.second - p.y) < EPS) &&
               ((l.first.first - EPS <= p.x && p.x <= l.second.first + EPS) ||
                (l.second.first - EPS <= p.x && p.x <= l.first.first + EPS));
    }

    return (abs((p.x - l.first.first) / (l.second.first - l.first.first) -
            (p.y - l.first.second) / (l.second.second - l.first.second)) < EPS) &&
            ((p.x - l.first.first) / (l.second.first - l.first.first) < 1. + EPS) &&
            ((p.x - l.first.first) / (l.second.first - l.first.first) > -EPS);
}

double length_line(const pt &a, const pt &b) {
    double delta_x = b.x - a.x;
    double delta_y = b.y - a.y;
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

double angle_into_lines(const pt &a, const pt &b, const pt &c) {
    double ab = length_line(a, b);
    double ac = length_line(a, c);
    double bc = length_line(b, c);
    double cos_value = (ac * ac + bc * bc - ab * ab) / (2 * ac * bc);
    if (abs(cos_value) > 1) {
        return 180;
    }
    return 180 * acos(cos_value) / M_PI;
}

inline void make_nodes() {
    for (auto &i : roads2) {
        for (auto s = i.begin(); s != prev(i.end()); ++s) {
            nodes.emplace_back(make_pair(s->x, s->y), make_pair(next(s)->x, next(s)->y));
        }
    }
}

inline void make_edges() {
    graph.resize(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        if (!is_vin) {
            if (is_point_in_line(nodes[i], vintek)) {
                is_vin = true;
                start = i;
            }
        }
        if (!is_shpu) {
            if (is_point_in_line(nodes[i], shpuntek)) {
                is_shpu = true;
                finish = i;
            }
        }
        for (int j = i + 1; j < nodes.size(); ++j) {
            pt current_point(0, 0), a, b, c, d;          
            cuts_to_pts(nodes[i], nodes[j], a, b, c, d);
            if (intersect(a, b, c, d, current_point, current_point)) {
                double angle = 0.0;
                if (a != current_point) {
                    if (c != current_point) {
                        angle = angle_into_lines(a, c, current_point);
                    } else if (d != current_point){
                        angle = angle_into_lines(a, d, current_point);
                    }
                } else if (b != current_point){
                    if (c != current_point) {
                        angle = angle_into_lines(b, c, current_point);
                    } else if (d != current_point){
                        angle = angle_into_lines(b, d, current_point);
                    }
                }
                graph[i].emplace_back(make_pair(j, 180 - angle), current_point);
                graph[j].emplace_back(make_pair(i, 180 - angle), current_point);
            }
        }
    }
}

inline void dijkstra() {
    vector<bool> used(graph.size(), false);
    distances.assign(graph.size(), numeric_limits<double>::max());
    vector<int> p(graph.size());
    distances[start] = 0;
    vector<pt> last_inters(graph.size(), {numeric_limits<double>::max(), numeric_limits<double>::max()});
    for (int i = 0; i < graph.size(); ++i) {
        int v = -1;
        for (int j = 0; j < graph.size(); ++j) {
            if (!used[j] && (v == -1 || distances[j] < distances[v])) {
                v = j;
            }
        }
        if (abs(distances[v] - numeric_limits<double>::max()) < EPS) {
            break;
        }
        used[v] = true;
        for (int j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first.first;
            if (graph[v][j].second == last_inters[v]) {
                continue;
            }
            double len = graph[v][j].first.second;
            double temp_dist = distances[v] + len;
            if (temp_dist < distances[to]) {
                distances[to] = temp_dist;
                p[to] = v;
                last_inters[to] = graph[v][j].second;
            }
        }
    }
}

inline void solve() {
    find_intersections();
    make_nodes();
    make_edges();
    dijkstra();
}

inline void output_function() {
    if (abs(distances[finish] - numeric_limits<double>::max()) < EPS) {
        cout << -1.0;
    } else {
        cout << distances[finish];
    }
}