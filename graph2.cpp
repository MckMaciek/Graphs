#include <iostream>
#include <list>

class Graph{
    
private:
    
    bool * visited;
    int vertexes;
    std::list<int>*edges;
public:
    
    Graph(int userMaxVertexes) : vertexes(userMaxVertexes), 
                                 visited(new bool[userMaxVertexes]){
        
        edges = new std::list<int>[vertexes];   // tworzenie macierzy
        visited[vertexes] = {false};  // nie zostaly odwiedzone zadne elementy macierzy
        
    }

    void addEdge(int sourceVertex, int destinationVertex){
        
        if((sourceVertex <= vertexes) && (destinationVertex <= vertexes)){
            edges[sourceVertex].push_back(destinationVertex);    
        }
            
    }
    
    void DFS(int selectedVertex){
    
        visited[selectedVertex] = true;
    
        for(auto i = edges[selectedVertex].begin(); i!= edges[selectedVertex].end(); ++i){
            if(visited[*i] == true) DFS(*i);    // jezeli element zostal odwiedzony, wywolaj rekurencyjnie dla jego sasiadow
            std::cout << *i << " ";
        }
        
    }
    
    ~Graph(){
    delete [] visited;
    delete [] edges;
        
    }
    
};
    

int main(){
    
Graph g1(8);    
g1.addEdge(3,2);
g1.addEdge(3,1);
g1.addEdge(2,1);
g1.addEdge(1,2);
g1.addEdge(2,3);
g1.DFS(3);
    
    
    
return 0;
}
