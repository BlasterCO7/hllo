#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph{

int V;

list<int> *adj;

bool CycleUtils(int v,bool visited[],int parent);

public:

    Graph(int V);

    void addEdges(int u,int w);

    bool Cyclic();


};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdges(int u,int w){
    adj[u].push_back(w);
    adj[w].push_back(u);

}

bool Graph::CycleUtils(int v,bool visited[],int parent){

    visited[v]=true;

    list<int>::iterator i;

    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            if(CycleUtils(*i,visited,v))
                return true;
        }
        else if(*i!=parent){
            return true;
        }
    }
    return false;
}


bool Graph::Cyclic(){
    bool *visited=new bool[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
    }    


    for(int i=0;i<V;i++){
        if(!visited[i]){
            if( CycleUtils(i,visited,-1))
                return true;
        }
    }
    return false;

}
int main(){

    Graph g1(5);

    g1.addEdges(1,0);
    g1.addEdges(0,2);
    g1.addEdges(2,1);
    g1.addEdges(0,3);
    g1.addEdges(3,4);

    g1.Cyclic() ? cout<<"The Graph is Cyclic\n"
                : cout<<"The Graph is not Cyclic";
    Graph g2(3);

    g2.addEdges(0,1);
    g2.addEdges(1,2);

    g2.Cyclic() ? cout<<"The Graph is Cyclic\n"
                : cout<<"The Graph is not Cyclic";


    return 0;
}