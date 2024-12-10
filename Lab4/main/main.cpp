#include <iostream>
#include "OrientedGraph.h"

void menu() {
    std::cout << "1. Add Vertex\n";
    std::cout << "2. Add Edge\n";
    std::cout << "3. Remove Vertex\n";
    std::cout << "4. Remove Edge\n";
    std::cout << "5. Check Vertex Presence\n";
    std::cout << "6. Check Edge Presence\n";
    std::cout << "7. Display Graph\n";
    std::cout << "8. Get Vertex Count\n";
    std::cout << "9. Get Edge Count\n";
    std::cout << "10. Get In-Degree\n";
    std::cout << "11. Get Out-Degree\n";
    std::cout << "12. Use Iterators\n";
    std::cout << "13. Exit\n";
}

int main() {
    OrientedGraph<std::string> graph;
    int choice;

    while (true) {
        menu();
        std::cout << "Choose an action: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string value;
            std::cout << "Enter vertex value: ";
            std::cin >> value;
            graph.addVertex(value);
            break;
        }
        case 2: {
            size_t from, to;
            std::cout << "Enter from vertex index and to vertex index: ";
            std::cin >> from >> to;
            try {
                graph.addEdge(from, to);
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            size_t index;
            std::cout << "Enter vertex index to remove: ";
            std::cin >> index;
            try {
                graph.removeVertex(index);
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            size_t from, to;
            std::cout << "Enter from vertex index and to vertex index to remove edge: ";
            std::cin >> from >> to;
            try {
                graph.removeEdge(from, to);
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            size_t index;
            std::cout << "Enter vertex index to check: ";
            std::cin >> index;
            std::cout << (graph.hasVertex(index) ? "Vertex exists." : "Vertex does not exist.") << std::endl;
            break;
        }
        case 6: {
            size_t from, to;
            std::cout << "Enter from vertex index and to vertex index to check edge: ";
            std::cin >> from >> to;
            std::cout << (graph.hasEdge(from, to) ? "Edge exists." : "Edge does not exist.") << std::endl;
            break;
        }
        case 7: {
            std::cout << "Graph:" << std::endl;
            graph.display();
            break;
        }
        case 8: {
            std::cout << "Vertex count: " << graph.vertexCount() << std::endl;
            break;
        }
        case 9: {
            std::cout << "Edge count: " << graph.edgeCount() << std::endl;
            break;
        }
        case 10: {
            size_t index;
            std::cout << "Enter vertex index to get in-degree: ";
            std::cin >> index;
            try {
                std::cout << "In-degree: " << graph.inDegree(index) << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 11: {
            size_t index;
            std::cout << "Enter vertex index to get out-degree: ";
            std::cin >> index;
            try {
                std::cout << "Out-degree: " << graph.outDegree(index) << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 12: {
            size_t vertexIndex;
            std::cout << "Enter vertex index to iterate edges: ";
            std::cin >> vertexIndex;
            if (vertexIndex < graph.vertexCount()) {
                std::cout << "Edges from vertex " << vertexIndex << ":\n";
                for (auto it = graph.edgeBegin(vertexIndex); it != graph.edgeEnd(vertexIndex); ++it) {
                    auto edge = *it;
                    std::cout << "Edge: " << edge.first << " -> " << edge.second << std::endl;
                }
            }
            else {
                std::cout << "Invalid vertex index.\n";
            }
            break;
        }
        case 13:
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}
