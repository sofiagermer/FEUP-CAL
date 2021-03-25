/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** Provided structures  ********************/

template <class T>
class Vertex {
	T info;                // contents
	std::vector<Edge<T> > adj;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	bool processing;       // auxiliary field used by isDAG
	int indegree;          // auxiliary field used by topsort

	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);
public:
	Vertex(T in);
	friend class Graph<T>;
};

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
class Graph {
    std::vector<Vertex<T> *> vertexSet;    // vertex set

	void dfsVisit(Vertex<T> *v,  std::vector<T> & res) const;
	Vertex<T> *findVertex(const T &in) const;
	bool dfsIsDAG(Vertex<T> *v) const;
public:
	int getNumVertex() const;
	bool addVertex(const T &in);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const T &sourc, const T &dest);
    std::vector<T> dfs() const;
    std::vector<T> bfs(const T &source) const;
    std::vector<T> topsort() const;
	int maxNewChildren(const T &source, T &inf) const;
	bool isDAG() const;
};

/****************** Provided constructors and functions ********************/

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
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

/****************** 1a) addVertex ********************/

/*
 *  Adds a vertex with a given content/info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
        if ( findVertex(in) != NULL)
            return false;
        vertexSet.push_back(new Vertex<T>(in));
        return true;
}

/****************** 1b) addEdge ********************/

/*
 * Adds an edge to a graph (this), given the contents of the source (sourc) and
 * destination (dest) vertices and the edge weight (w).
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

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}


/****************** 1c) removeEdge ********************/

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    // TODO (5 lines)
    // HINT: Use "findVertex" to obtain the actual vertices.
    // HINT: Use the next function to actually remove the edge.
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if(v1 == NULL || v2 == NULL) return false;
    if(v1 -> removeEdgeTo(v2)) return true;
    return false;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    // TODO (6 lines)
    // HINT: use an iterator to scan the "adj" vector and then erase the edge.
    for(int i = 0; i < adj.size(); i++){
        if(adj.at(i).dest->info == d->info) {
            adj.erase(adj.begin()+i);
            return true;
        }
    }
    return false;
}


/****************** 1d) removeVertex ********************/

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
    // TODO (10 lines)
    auto vertex = findVertex(in);
    if(vertex == NULL) return false;
    for(int i = 0; i < vertexSet.size(); i++){
        if(vertexSet.at(i) == vertex) {
            vertexSet.at(i)->removeEdgeTo(vertexSet.at(i));
            vertexSet.erase(vertexSet.begin() +i);
        }
    }
    return true;
}


/****************** 2a) dfs ********************/

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
std::vector<T> Graph<T>::dfs() const {
    // TODO (7 lines)
    std::vector<T> res;
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
    }
    for(auto &vertex : vertexSet){
        if(!vertex->visited){
            vertex->visited = true;
            res.push_back(vertex->info);
            dfsVisit(vertex, res);
        }
    }
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, std::vector<T> & res) const {
    // TODO (7 lines)
    for(auto edge : v->adj) {
        if (!edge.dest->visited) {
            edge.dest->visited = true;
            res.push_back(edge.dest->info);
            dfsVisit(edge.dest,res);
        }
    }
}

/****************** 2b) bfs ********************/

/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
std::vector<T> Graph<T>::bfs(const T & source) const {
    // TODO (22 lines)
    // HINT: Use the flag "visited" to mark newly discovered vertices .
    // HINT: Use the "queue<>" class to temporarily store the vertices.
    vector<T> res;
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
    }
    Vertex<T>*vertex = findVertex(source);
    queue<Vertex<T>*> queue1;
    vertex->visited = true;
    res.push_back(vertex->info);
    //Por na queue nos filhos diretos do primeiro nó a analisar
    for(auto edge : vertex -> adj){
        edge.dest->visited = true;
        res.push_back(edge.dest->info);
        queue1.push(edge.dest);
    }
    while(!queue1.empty()){
        vertex = queue1.front();
        queue1.pop();
        for(auto edge : vertex -> adj){
            if(!edge.dest->visited){
                edge.dest->visited = true;
                res.push_back(edge.dest->info);
                queue1.push(edge.dest);
            }
        }
    }
    return res;
}

/****************** 2c) toposort ********************/

/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template<class T>
std::vector<T> Graph<T>::topsort() const {
    // TODO (26 lines)
    vector<T> res;
    int numVertex = 0;
    bool possible = true;
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
        numVertex++;
    }
    for(int i = 0; i < vertexSet.size();i++) {
        possible = true;
        if (!vertexSet.at(i)->visited) {
            for (int j = 0; j < vertexSet.size(); j++) {
                if (!vertexSet.at(j)->visited) {  //aqui estou a ver se o vértice de origem está visitado; se estiver o edge não interessa
                    for (auto edge : vertexSet.at(j)->adj) {
                        if (!edge.dest->visited) {
                            if (edge.dest->info == vertexSet.at(i)->info) {
                                possible = false;
                            }
                        }
                    }
                }
            }
            if(possible) {
                res.push_back(vertexSet.at(i)->info);
                vertexSet.at(i)->visited = true;
                numVertex--;
                i = 0;
            }
        }
    }
    if(numVertex == 0)return res;
    res.clear();
    return res;
}

/****************** 3a) maxNewChildren (HOME WORK)  ********************/

/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex (inf) and the number of new children (return value).
 */

template <class T>
int Graph<T>::maxNewChildren(const T & source, T &inf) const {
    vector<T> res;
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
    }
    int numNews = 0;
    int tempnumNews = 0;
    Vertex<T>*vertex = findVertex(source);
    queue<Vertex<T>*> queue1;
    vertex->visited = true;
    res.push_back(vertex->info);
    //Por na queue nos filhos diretos do primeiro nó a analisar
    for(auto edge : vertex -> adj){
        edge.dest->visited = true;
        res.push_back(edge.dest->info);
        queue1.push(edge.dest);
        numNews++;
    }
    inf = vertex->info;
    while(!queue1.empty()){
        vertex = queue1.front();
        queue1.pop();
        tempnumNews = 0;
        for(auto edge : vertex -> adj){
            if(!edge.dest->visited){
                tempnumNews++;
                edge.dest->visited = true;
                res.push_back(edge.dest->info);
                queue1.push(edge.dest);
            }
        }
        if(tempnumNews > numNews){
            numNews = tempnumNews;
            inf = vertex->info;
        }
    }
    return numNews;
}


/****************** 3b) isDAG   (HOME WORK)  ********************/

/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool Graph<T>::isDAG() const {
    // TODO (9 lines, mostly reused)
    // HINT: use the auxiliary field "processing" to mark the vertices in the stack.
    std::vector<T> res;
    for(auto &vertex : vertexSet) {
        vertex->visited = false;
    }
    for(auto &vertex : vertexSet){
        if(!vertex->visited){
            vertex->processing = true;
            res.push_back(vertex->info);
            if(dfsIsDAG(vertex)) return true;
            vertex->visited = true;
            vertex->processing = false;
        }
    }
    return false;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
    // TODO (12 lines, mostly reused)
    for(auto edge : v->adj) {
        if(edge.dest->processing) return true;
        if (!edge.dest->visited) {
            edge.dest->processing = true;
            edge.dest->visited = true;
            dfsIsDAG(edge.dest);
        }
    }
    return false;
}

#endif /* GRAPH_H_ */
