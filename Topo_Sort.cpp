#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int v);

    void addEdges(int u,int w);

    void Topo_sort();
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdges(int u,int w){
    adj[u].push_back(w);
}

void Graph::Topo_sort(){

    vector<int> indegree(V,0);

    for(int i=0;i<V;i++){
        list<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();++it){
            indegree[*it]++;
        }
    }

    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    vector<int>topo_sort;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        topo_sort.push_back(u);

        list<int>::iterator it;

        for(it=adj[u].begin();it!=adj[u].end();++it){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }

        cnt++;


    }
        if(cnt!=V){
            return;
        }

        for(int i=0;i<V;i++){
            cout<<topo_sort[i]<<" ";
        }

}


int main(){

    Graph g1(6);

    g1.addEdges(5,2);
    g1.addEdges(2,3);
    g1.addEdges(3,1);
    g1.addEdges(4,1);
    g1.addEdges(4,0);
    g1.addEdges(5,0);

    g1.Topo_sort();
    return 0;
}