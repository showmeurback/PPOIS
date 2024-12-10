#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>

template<typename T>
class OrientedGraph {
public:
    using VertexType = T;
    using Edge = std::pair<size_t, size_t>; // (from, to)

    OrientedGraph();
    ~OrientedGraph(); 

    void addVertex(const T& value);
    void addEdge(size_t from, size_t to);
    void removeVertex(size_t index);
    void removeEdge(size_t from, size_t to);
    bool hasVertex(size_t index) const;
    bool hasEdge(size_t from, size_t to) const;
    size_t vertexCount() const;
    size_t edgeCount() const;
    size_t inDegree(size_t index) const;
    size_t outDegree(size_t index) const;

    class VertexIterator;
    class ConstVertexIterator;
    class EdgeIterator;
    class ConstEdgeIterator;

    VertexIterator begin();
    VertexIterator end();
    ConstVertexIterator cbegin() const;
    ConstVertexIterator cend() const;

    EdgeIterator edgeBegin(size_t vertexIndex);
    EdgeIterator edgeEnd(size_t vertexIndex);
    ConstEdgeIterator edgeBegin(size_t vertexIndex) const;
    ConstEdgeIterator edgeEnd(size_t vertexIndex) const;

    void display() const;

private:
    std::vector<VertexType> vertices;
    std::vector<std::list<size_t>> adjacencyList; 
};

#include "OrientedGraph.cpp" 
#endif // ORIENTEDGRAPH_H
