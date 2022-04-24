//Unweighted Graph
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>>adjList; //key of type T, Value is list of pairs of type T and int
    public:
        Graph(){} // constructor 
        void addEdge(T u,T v,int dist,bool bidir=true){
            adjList[u].push_back(make_pair(v,dist));// adjList[u] is a list
            if(bidir){
                adjList[v].push_back(make_pair(u,dist));
            }
        } 
        void printList(){
            for(auto it:adjList){ // adjList is a map
                cout<<it.first;
                for(auto i:it.second){
                    cout<<"->"<<"("<<i.first<<","<<i.second<<")";
                }
                cout<<endl;
            }
        }        
        //sssp-> when graph is not weighted
        //when graph is weighted and can be directed or undirected
        void dijkstrasAlgosssp(T src){
            unordered_map<T,int>dist;
            for(auto it:adjList){
                dist[it.first]=INT_MAX;
            }
            dist[src]=0;
            //make a set to find a out node with the minimum distance
            set<pair<int,T>>s;
            //sorting according to the first parameter
            s.insert(make_pair(0,src));
            while(!s.empty()){
                auto p=*(s.begin());
                T node=p.second;
                int nodeDist=p.first;
                s.erase(s.begin());
                //iterate over neighbours of this popped/current node
                for(auto i:adjList[node]){
                    if(dist[i.first]>i.second+nodeDist){
                        //in the set updation of a particular node is not possible, 
                        //soo we have to remove the old pair and and insert the new pair to simulation updation
                        auto f=s.find(make_pair(dist[i.first],i.first));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        //insert new node
                        dist[i.first]=nodeDist+i.second;
                        s.insert(make_pair(dist[i.first],i.first));
                    }
                }
            }
            //lets print distance of each node from the given node
            for(auto it:dist){
                cout<<"distance of "<<it.first<<" from the "<<src<< " is "<<it.second<<endl;
            }
        }
        void bellmanford(T src){
            
        }
        void shortestpathinDirectedAcyclicGraph(){
            
        }
        // to find out minimum spanning tree // minimize the wire length and make sure that all computers are connected maybe through intermediate computer
        //given a weighted connected undirected graph
        //spanning tree connects all the vertices
        //spanning tree is something that is defined for unweighted graph
        //is a greedy algo which maintains two sets 
        //1st set of vertices are set f vertices which are already incuded in the msp, and other set is remaining vertices 
        //and the idea of the prism algo is to find that connects the current mst with the other edges.
        void prismsAlgo(T src){
            
        }
        void kosaraju(){

        }
        void kruskalAlgo(){

        }
        void BridgesinGraph(){

        }
        void TarjansAlgo(){

        }
};
int main() {
    Graph<int>g;
    Graph<string>india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    india.printList();
    india.dijkstrasAlgosssp("Amritsar");
    
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printList();
    g.dijkstrasAlgosssp(1);
    return 1;
}
