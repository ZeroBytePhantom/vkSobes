#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
const int INF = 1e9;


vector<int> bfs(const vector<vector<int>>& graf, int start) {
    vector<int> dist(graf.size(), INF); 
    queue<int> q;                      

    dist[start] = 0; 
    q.push(start);   

    while (!q.empty()) {
        int v = q.front(); 
        q.pop();

        
        for (int to : graf[v]) {
            if (dist[to] == INF) { 
                dist[to] = dist[v] + 1;
                q.push(to); 
            }
        }
    }
    return dist;
}

int main() {
    setlocale(LC_ALL, "ru");
    ifstream in("graph.txt"); 

    if (!in.is_open()) {
        cerr << "Ошибка открытия файла graph.txt!" << endl;
        return 1;
    }

    int vertex_count, edge_count, start;
    in >> vertex_count; 
    in >> edge_count;  

    vector<vector<int>> graf(vertex_count); 


    for (int i = 0; i < edge_count; i++) {
        int a, b;
        in >> a >> b;
        graf[a].push_back(b); 
        graf[b].push_back(a); 
    }

    in >> start; 
    in.close(); 

    vector<int> dist = bfs(graf, start);

    for (int i = 0; i < vertex_count; i++) {
        cout <<  dist[i] << endl;
    }

    return 0;
}