#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph{
int V;
list<int> * adj;

bool CycleUtils(int v,bool visited[],bool recStack[]);

public:
    Graph(int v);
    void addEdges(int u,int w);
    bool Cyclic();
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdges(int v,int w){
    adj[v].push_back(w);
}

bool Graph::CycleUtils(int v,bool visited[],bool recStack[]){

    visited[v]=true;
    recStack[v]=true;

    list<int>::iterator i;

    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            if(CycleUtils(*i,visited,recStack))
                return true;
        }
        else if(recStack[*i]){
            return true;
        }
    }
    recStack[v]=false;
    return false;
}

bool Graph::Cyclic(){

    bool *visited=new bool[V];
    bool *recStack=new bool[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
        recStack[i]=false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(CycleUtils(i,visited,recStack))
                return true;
        }   
    }
    return false;
}

int main(){


    Graph g1(4);
    g1.addEdges(0,1);
    g1.addEdges(1,2);
    // g1.addEdges(2,0);
    g1.addEdges(0,2);
    g1.addEdges(2,3);
    g1.addEdges(3,3);


    g1.Cyclic() ? cout<<"CYCLIC\n"
                :cout<<"NOT CYCLIC\n";
    return 0;
}