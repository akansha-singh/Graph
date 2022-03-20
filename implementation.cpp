//Unweighted Graph
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>>adjList; //key of type T, Value is list of type T  
    public:
        Graph(){} // constructor
        void addEdge(T u,T v, bool bidir=true){ 
            adjList[u].push_back(v); // adjList[u] is a list
            if(bidir){
                adjList[v].push_back(u);
            }
        }
        void printList(){ 
            for(auto it:adjList){ // adjList is a map
                cout<<it.first<<"->"; // it.first is a key
                for(auto i:it.second){ // it.second is a list
                    cout<<i<<",";
                }
                cout<<endl;
            }        
        }
        // do theory explaination
        void bfs(T src){ // 
            queue<T>q; 
            map<T,bool>visited;
            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                T node=q.front();
                cout<<node<<" ";
                q.pop(); 
                for(auto i:adjList[node]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                    }                    
                }
            }
        }
        //starting from the source node, we are going to compute shortest paths to all other nodes
        void sssp(T src){ 
            queue<T>q;
            map<T,int>dist;
            for(auto i:adjList){
                dist[i.first]=INT_MAX;
            }
            q.push(src);
            dist[src]=0;
            while(!q.empty()){
                T node=q.front();
                q.pop();
                for(auto i:adjList[node]){
                    if(dist[i]==INT_MAX){
                        q.push(i);
                        dist[i]=dist[node]+1;
                    }                    
                }  
            }
            for(auto it:dist){
                cout<<"Dist of "<<it.first<<" "<<"from "<<src<<" is "<<it.second<<endl;
            }
        }
        void dfsHelper(T node,map<int,bool>&visited){ 
            visited[node]=true;
            cout<<node<<" ";
            //try to find out a node which is neighbour of current node and not yet visited.
            for(T it:adjList[node]){
                if(!visited[it]){
                    dfsHelper(it,visited);
                }
            }
        }
        void dfs(T src){ // it recursively traverse all nodes of graph
            map<int,bool>visited;
            dfsHelper(src,visited);
        }
                       
        void connectedComponentsusingDfs(T src){ // like how many rings in graph
            int components=1; // bcoz there woulld be atleast 1 component 
            map<int,bool>visited; 
            dfsHelper(src,visited); // if there is one component then dfs algo ek bari mai hi sari nodes traverse kr degi and if condition in for loop will not satisfy and ans would be 1. but if there are more than 1 component then for loop will run.
            cout<<endl; 
            for(auto it:adjList){ 
                if(!visited[it.first]){ 
                    dfsHelper(it.first,visited); 
                    components++; 
                } 
            } 
            cout<<"Your graph has "<<components<<" components"<<endl; 
        }
        // bfs algo
        void topologicalSort(){
            map<T,int>indegree;
            map<T,bool>visited;
            queue<T>q;
            for(auto it:adjList){
                indegree[it.first]=0;
                visited[it.first]=false;
            }
            for(auto it:adjList){
                for(auto i:it.second){
                    indegree[i]++;
                }
            }
            // all nodes which have indegree=0, push them into queue
            for(auto it:indegree){
                if(it.second==0){
                    q.push(it.first);
                }
            }
            //start with algorithm
            while(!q.empty()){
                T node=q.front();
                q.pop();
                cout<<node<<" ";
                for(auto i:adjList[node]){
                    --indegree[i];
                    if(indegree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        
        bool cycleDetectionUndirectedBFS(T src){        //bfs
            map<T,bool>visited;
            map<T,int>parent;
            queue<int>q;
            for(auto it:adjList){
                visited[it.first]=false;
            }
            q.push(src);
            parent[src]=src;
            while(!q.empty()){
                T node=q.front();
                q.pop();
                for(auto it:adjList[node]){
                    if(visited[it]==true&&it==parent[node])continue;
                    if(visited[it]==true)return true;
                    q.push(it);
                    visited[it]=true;
                    parent[it]=node;
                }
            }
            return false;
        }
        bool cycleDetectionDirectedDFS(T src){
            
        }
        //sssp(using bfs)-> when graph is not weighted
        //when graph is weighted and can be directed or undirected
        void dijkstrasAlgosssp(T src){
            
        }
};
int main(){
    Graph<string> g;
    g.addEdge("Trump","Modi",false);
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","pope",false);
    g.addEdge("Modi","Trump",false);
    g.addEdge("Modi","yogi",false);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);
    g.printList();
    cout<<endl;

    Graph<int>g2;
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(0,4);
    g2.addEdge(2,4);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    g2.addEdge(6,7);
    g2.printList();
    cout<<endl;

    g2.bfs(1);
    cout<<endl;
    //g2.sssp(0);
    cout<<endl;
    g2.dfs(0);
    cout<<endl;

    cout<<"t";
    g2.connectedComponentsusingDfs(0);
    cout<<"t";

    Graph<int>g3;
    g3.addEdge(0,1);
    //g3.addEdge(1,2);
    //g3.addEdge(0,4);
    g3.addEdge(2,4);
    //g3.addEdge(2,3);
    g3.addEdge(4,3);
    g3.addEdge(1,3);
    g3.sssp(0);
    cout<<"t";
    g3.connectedComponentsusingDfs(0);
    cout<<"t";
    cout<<endl;
    g3.topologicalSort();
    cout<<g3.cycleDetectionUndirectedBFS(0);
    cout<<endl;
    cout<<g3.cycleDetectionDirectedDFS(0);
    cout<<endl;
    g3.dijkstrasAlgosssp(0);
    return 0;
}