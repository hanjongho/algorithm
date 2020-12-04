#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
struct Point {
    int x, y;
};
 
int dist(Point &p, Point &q){
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool cmpx(Point &p1, Point &p2){
    return p1.x < p2.x;
}

bool cmpy(Point &p1, Point &p2){
    return p1.y < p2.y;
}

int closest_pair(vector<Point>::iterator it, int n) {
    if (n == 2)
        return dist(it[0], it[1]);
    if (n == 3)
        return min({dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0])});
     
    int line = (it[n/2 - 1].x + it[n/2].x) / 2;
    int d = min(closest_pair(it, n/2), closest_pair(it + n/2, n/2));
    
    vector<Point> mid;
    mid.reserve(n);

    for(int i = 0; i < n; i++) {
        int t = line - it[i].x;
        if (t * t < d) // 제곱하면 좌우상관없음
            mid.push_back(it[i]);
    }

    sort(mid.begin(), mid.end(), cmpy); // y축 정렬
    
    int mid_sz = mid.size();
    for (int i = 0; i < mid_sz - 1; i++)
        for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y) < d; j++)
            d = min(d, dist(mid[i], mid[j]));
    return (d);
}
 
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;

    vector<Point> points(n);
    for (vector<Point>::iterator it = points.begin(); it != points.end(); it++)
        cin >> it->x >> it->y;
     
    sort(points.begin(), points.end(), cmpx); // x축 정렬
    cout << closest_pair(points.begin(), n);
    return (0);
}
