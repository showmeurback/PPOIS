#include "OrientedGraph.h"

template<typename T>
OrientedGraph<T>::OrientedGraph() {}

template<typename T>
OrientedGraph<T>::~OrientedGraph() {
    vertices.clear();
    adjacencyList.clear();
}

template<typename T>
void OrientedGraph<T>::addVertex(const T& value) {
    vertices.push_back(value);
    adjacencyList.push_back(std::list<size_t>());
}

template<typename T>
void OrientedGraph<T>::addEdge(size_t from, size_t to) {
    if (from >= vertices.size() || to >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    adjacencyList[from].push_back(to);
}

template<typename T>
void OrientedGraph<T>::removeVertex(size_t index) {
    if (index >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }

    adjacencyList.erase(adjacencyList.begin() + index);

    for (auto& neighbors : adjacencyList) {
        neighbors.remove(index);
    }

    vertices.erase(vertices.begin() + index);
}

template<typename T>
void OrientedGraph<T>::removeEdge(size_t from, size_t to) {
    if (from >= vertices.size() || to >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    adjacencyList[from].remove(to);
}

template<typename T>
bool OrientedGraph<T>::hasVertex(size_t index) const {
    return index < vertices.size();
}

template<typename T>
bool OrientedGraph<T>::hasEdge(size_t from, size_t to) const {
    if (from >= vertices.size() || to >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    const auto& neighbors = adjacencyList[from];
    return std::find(neighbors.begin(), neighbors.end(), to) != neighbors.end();
}

template<typename T>
size_t OrientedGraph<T>::vertexCount() const {
    return vertices.size();
}

template<typename T>
size_t OrientedGraph<T>::edgeCount() const {
    size_t count = 0;
    for (const auto& neighbors : adjacencyList) {
        count += neighbors.size();
    }
    return count;
}

template<typename T>
size_t OrientedGraph<T>::inDegree(size_t index) const {
    if (index >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    size_t degree = 0;
    for (const auto& neighbors : adjacencyList) {
        degree += std::count(neighbors.begin(), neighbors.end(), index);
    }
    return degree;
}

template<typename T>
size_t OrientedGraph<T>::outDegree(size_t index) const {
    if (index >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return adjacencyList[index].size();
}

template<typename T>
class OrientedGraph<T>::VertexIterator {
public:
    VertexIterator(OrientedGraph<T>* graph, size_t index) : graph(graph), index(index) {}

    VertexType& operator*() {
        return graph->vertices[index];
    }

    VertexIterator& operator++() {
        ++index;
        return *this;
    }

    bool operator!=(const VertexIterator& other) const {
        return index != other.index;
    }

private:
    OrientedGraph<T>* graph;
    size_t index;
};

template<typename T>
class OrientedGraph<T>::ConstVertexIterator {
public:
    ConstVertexIterator(const OrientedGraph<T>* graph, size_t index) : graph(graph), index(index) {}

    const VertexType& operator*() const {
        return graph->vertices[index];
    }

    ConstVertexIterator& operator++() {
        ++index;
        return *this;
    }

    bool operator!=(const ConstVertexIterator& other) const {
        return index != other.index;
    }

private:
    const OrientedGraph<T>* graph;
    size_t index;
};

template<typename T>
class OrientedGraph<T>::EdgeIterator {
public:
    EdgeIterator(OrientedGraph<T>* graph, size_t vertexIndex, typename std::list<size_t>::iterator current)
        : graph(graph), vertexIndex(vertexIndex), current(current) {
    }

    Edge operator*() const {
        return { vertexIndex, *current };
    }

    EdgeIterator& operator++() {
        ++current;
        return *this;
    }

    bool operator!=(const EdgeIterator& other) const {
        return current != other.current;
    }

private:
    OrientedGraph<T>* graph;
    size_t vertexIndex;
    typename std::list<size_t>::iterator current;
};

template<typename T>
class OrientedGraph<T>::ConstEdgeIterator {
public:
    ConstEdgeIterator(const OrientedGraph<T>* graph, size_t vertexIndex, typename std::list<size_t>::const_iterator current)
        : graph(graph), vertexIndex(vertexIndex), current(current) {
    }

    Edge operator*() const {
        return { vertexIndex, *current };
    }

    ConstEdgeIterator& operator++() {
        ++current;
        return *this;
    }

    bool operator!=(const ConstEdgeIterator& other) const {
        return current != other.current;
    }

private:
    const OrientedGraph<T>* graph;
    size_t vertexIndex;
    typename std::list<size_t>::const_iterator current;
};

template<typename T>
typename OrientedGraph<T>::VertexIterator OrientedGraph<T>::begin() {
    return VertexIterator(this, 0);
}

template<typename T>
typename OrientedGraph<T>::VertexIterator OrientedGraph<T>::end() {
    return VertexIterator(this, vertices.size());
}

template<typename T>
typename OrientedGraph<T>::ConstVertexIterator OrientedGraph<T>::cbegin() const {
    return ConstVertexIterator(this, 0);
}

template<typename T>
typename OrientedGraph<T>::ConstVertexIterator OrientedGraph<T>::cend() const {
    return ConstVertexIterator(this, vertices.size());
}

template<typename T>
typename OrientedGraph<T>::EdgeIterator OrientedGraph<T>::edgeBegin(size_t vertexIndex) {
    if (vertexIndex >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return EdgeIterator(this, vertexIndex, adjacencyList[vertexIndex].begin());
}

template<typename T>
typename OrientedGraph<T>::EdgeIterator OrientedGraph<T>::edgeEnd(size_t vertexIndex) {
    if (vertexIndex >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return EdgeIterator(this, vertexIndex, adjacencyList[vertexIndex].end());
}

template<typename T>
typename OrientedGraph<T>::ConstEdgeIterator OrientedGraph<T>::edgeBegin(size_t vertexIndex) const {
    if (vertexIndex >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return ConstEdgeIterator(this, vertexIndex, adjacencyList[vertexIndex].cbegin());
}

template<typename T>
typename OrientedGraph<T>::ConstEdgeIterator OrientedGraph<T>::edgeEnd(size_t vertexIndex) const {
    if (vertexIndex >= vertices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return ConstEdgeIterator(this, vertexIndex, adjacencyList[vertexIndex].cend());
}

template<typename T>
void OrientedGraph<T>::display() const {
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << vertices[i] << ": ";
        for (const auto& neighbor : adjacencyList[i]) {
            std::cout << vertices[neighbor] << " ";
        }
        std::cout << std::endl;
    }
}