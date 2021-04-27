/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include "MutablePriorityQueue.h"
using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
    T info;						// content of the vertex
    std::vector<Edge<T> > adj;		// outgoing edges

    double dist = 0;
    Vertex<T> *path = NULL;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    bool visited = false;		// auxiliary field
    bool processing = false;	// auxiliary field

    void addEdge(Vertex<T> *dest, double w);

public:
    Vertex(T in);
    T getInfo() const;
    double getDist() const;
    Vertex *getPath() const;

    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
    friend class Graph<T>;
    friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
    return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


/*************************** Graph  **************************/

template <class T>
class Graph {
    std::vector<Vertex<T> *> vertexSet;    // vertex set
    std::vector<std::vector<size_t>> nextFloydWarshall; //floyddist
    std::vector<std::vector<size_t>> matrixFloydWarshall; //floydpath
public:
    Vertex<T> *findVertex(const T &in) const;
    bool addVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex<T> *> getVertexSet() const;

    // Fp06 - single source
    void unweightedShortestPath(const T &s);    //TODO...
    void dijkstraShortestPath(const T &s);      //TODO...
    void bellmanFordShortestPath(const T &s);   //TODO...
    std::vector<T> getPath(const T &origin, const T &dest) const;   //TODO...

    // Fp06 - all pairs
    void floydWarshallShortestPath();   //TODO...
    std::vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

};

template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
    // TODO (7 lines)
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
        vertex->path = NULL;
    }
    Vertex<T>*vertex = findVertex(orig);
    queue<Vertex<T>*> queue1;
    vertex->visited = true;
    queue1.push(vertex);
    while(!queue1.empty()){
        vertex = queue1.front();
        queue1.pop();
        for(auto edge : vertex->adj){
            if(!edge.dest->visited){
                edge.dest->dist = vertex->dist + 1;
                edge.dest->visited = true;
                edge.dest->path = vertex;
                queue1.push(edge.dest);
            }
        }
    }
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    Vertex<T>*vertex = findVertex(origin);
    if(vertex == NULL) return;

    MutablePriorityQueue<Vertex<T>> mutablePriorityQueue;
    for(auto &vertex : vertexSet){
        vertex->dist = INT_MAX;
        vertex->path = NULL;
        vertex->visited = false;
    }
    vertex->dist = 0;
    vertex->visited = true;
    mutablePriorityQueue.insert(vertex);
    while(!mutablePriorityQueue.empty()){
        vertex = mutablePriorityQueue.extractMin();
        for(auto edge : vertex->adj){
            if(edge.dest->dist > vertex->dist + edge.weight){
                edge.dest->dist = vertex->dist + edge.weight;
                edge.dest->path = vertex;
                if(!edge.dest->visited){
                    edge.dest->visited = true;
                    mutablePriorityQueue.insert(edge.dest);
                }
                else{
                    mutablePriorityQueue.decreaseKey(edge.dest);
                }
            }

        }
    }
}

template<class T>

void Graph<T>::bellmanFordShortestPath(const T &orig) {
    Vertex<T> *vertex = findVertex(orig);
    if(vertex == NULL) return;
    for(auto &v : vertexSet){
        v->dist = INF;
        v->path = NULL;
    }
    vertex->dist = 0;
    for(int i = 0; i < vertexSet.size() - 1; i++){
        for(auto &vertex : vertexSet){
            for(auto &edge : vertex->adj){
                if(edge.dest->dist > vertex->dist + edge.weight){
                    edge.dest->dist = vertex->dist + edge.weight;
                    edge.dest->path = vertex;
                }
            }
        }
    }
    for(auto &vertex : vertexSet){
        for(auto &edge : vertex->adj){
            if(vertex->dist + edge.weight < edge.dest->dist){
                return;
            }
        }
    }

}


template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    std::vector<T> res;
    auto current = findVertex(dest);
    while(current->info != origin){
        res.push_back(current->info);
        current = current->path;
    }
    res.push_back(current->info);
    std::reverse(res.begin(),res.end());
    return res;
}



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
    int v = vertexSet.size();
    nextFloydWarshall = vector<std::vector<size_t>>(vertexSet.size(), vector<size_t>(vertexSet.size(), INF));
    matrixFloydWarshall = vector<vector<size_t>>(vertexSet.size(), vector<size_t>(vertexSet.size(), NULL));

    for(int i = 0; i < v ; i++){
        matrixFloydWarshall[i][i] = v;
        for(auto & edge : vertexSet.at(i)->adj){
            for(int j = 0; j < v ; j++){
                if(edge.dest == vertexSet.at(j)){
                    nextFloydWarshall[i][j] = edge.weight;
                    matrixFloydWarshall[i][v] = v;
                }
            }
        }
    }
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v ; j++){
            for(int k = 0; k < v ; k++){
                if(nextFloydWarshall[j][k] > nextFloydWarshall[j][i] + nextFloydWarshall[i][k]){
                    nextFloydWarshall[j][k] = nextFloydWarshall[j][i] + nextFloydWarshall[i][k];
                    matrixFloydWarshall[j][k] = matrixFloydWarshall[j][i];
                }
            }
        }
    }

}


template<class T>
std::vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
    vector<T> res;
    Vertex<T> *orig_vertex = findVertex(orig);
    if(orig_vertex == NULL) return res ;
    Vertex<T> *dest_vertex = findVertex(dest);
    if(dest_vertex == NULL) return res;
    int v = vertexSet.size();
    int index_orig;
    int index_dest;
    for(int i = 0; i < v ; i++){
        if(vertexSet.at(i) == orig_vertex) index_orig = i;
        else if(vertexSet.at(i) == dest_vertex) index_dest = i;
    }
    if(matrixFloydWarshall[index_orig][index_dest] == NULL) return res;
    res.push_back(vertexSet.at(index_orig)->info);
    while(index_orig != index_dest){
        index_orig = matrixFloydWarshall[index_orig][index_dest];
        res.push_back(vertexSet.at(index_orig)->info);
    }
    return res;


    /*std::vector<T> res;

    auto currentVertex = findVertex(orig);
    auto destinationVertex = findVertex(dest);
    auto currentVertexIt = std::find(vertexSet.begin(), vertexSet.end(), currentVertex);
    auto destinationVertexIt = std::find(vertexSet.begin(), vertexSet.end(), destinationVertex);

    if(currentVertexIt == vertexSet.end() || destinationVertexIt == vertexSet.end()) return res;

    size_t currentIndex = std::distance(vertexSet.begin(), currentVertexIt);
    size_t destinationIndex = std::distance(vertexSet.begin(),destinationVertexIt);

    if(matrixFloydWarshall[currentIndex][destinationIndex] == INT_MAX) return res;

    for(; currentIndex != destinationIndex; currentIndex = nextFloydWarshall[currentIndex][destinationIndex]){
        res.push_back(vertexSet.at(currentIndex)->info);
    }

    res.push_back(vertexSet.at(destinationIndex)->info);
    return res;*/
}



#endif /* GRAPH_H_ */