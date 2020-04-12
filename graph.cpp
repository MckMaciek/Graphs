#include <iostream>
#include <list>
#include <queue>

//template<typename T>
class Graph{

private:
       
std::list<int>*ptr;
int vertex;

public:
    
    Graph(int inpVertex) : vertex(inpVertex){
        ptr = new std::list<int>[inpVertex];
        // 2 wymiarowa macierz
        
    }   
    
    void addEdge(int whichVertex_source, int vertexConnection){
        ptr[whichVertex_source].push_back(vertexConnection);
    }
    
    
    void BFS(int startingVertex){
        bool visited[vertex] = {false};
        
        std::queue<int>que;
        visited[startingVertex] = true;
        que.push(startingVertex); //dodajemy do kolejki
        
        while(!que.empty()){
            startingVertex = que.front();  // pobieramy z poczatku
            que.pop();
            
            for(auto i = ptr[startingVertex].begin(); i != ptr[startingVertex].end(); ++i){
                if (!(visited[*i])){   // petla iteruje po ptr[startingVertex][0,1...] sprawdzajac wszystkie polaczenia  
                std::cout << *i << " ";    
                visited[*i] = true;
                que.push(*i);  // sprawdza kolejne polaczenia dla kolejnego elementu
                }
            
            }
            
        }
    }
    
};

int main(){
    
Graph g1(6);
g1.addEdge(0,1);
g1.addEdge(0,2);    
g1.addEdge(1,2);
g1.addEdge(1,0);    
g1.addEdge(2,0);
g1.addEdge(2,1);    
g1.addEdge(3,4);
g1.addEdge(4,2); 
g1.addEdge(5,3); 

g1.BFS(3);



return 0;
}
