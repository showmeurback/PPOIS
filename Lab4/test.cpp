#include "pch.h"
#include <gtest/gtest.h>
#include "D:\BSUIR\2 êóðñ\ÏÏÎÈÑ\ËÐ 4\PPOISLab4\OrientedGraph.h"

class OrientedGraphTest : public ::testing::Test {
protected:
    OrientedGraph<std::string> graph;

    void SetUp() override {
        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("C");
    }
};

TEST_F(OrientedGraphTest, AddVertex) {
    graph.addVertex("D");
    EXPECT_EQ(graph.vertexCount(), 4);
    EXPECT_TRUE(graph.hasVertex(3));
}

TEST_F(OrientedGraphTest, AddEdge) {
    graph.addEdge(0, 1);
    EXPECT_TRUE(graph.hasEdge(0, 1));
    EXPECT_EQ(graph.outDegree(0), 1);
    EXPECT_EQ(graph.inDegree(1), 1);
}

TEST_F(OrientedGraphTest, RemoveEdge) {
    graph.addEdge(0, 1);
    graph.removeEdge(0, 1);
    EXPECT_FALSE(graph.hasEdge(0, 1));
}

TEST_F(OrientedGraphTest, CheckVertexPresence) {
    EXPECT_TRUE(graph.hasVertex(0));
    EXPECT_FALSE(graph.hasVertex(3));
}

TEST_F(OrientedGraphTest, CheckEdgePresence) {
    graph.addEdge(0, 1);
    EXPECT_TRUE(graph.hasEdge(0, 1));
    EXPECT_FALSE(graph.hasEdge(1, 0));
}

TEST_F(OrientedGraphTest, DisplayGraph) {
    testing::internal::CaptureStdout();
    graph.addEdge(0, 1);
    graph.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("A: B"), std::string::npos);
}

TEST_F(OrientedGraphTest, VertexCount) {
    EXPECT_EQ(graph.vertexCount(), 3);
}

TEST_F(OrientedGraphTest, EdgeCount) {
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    EXPECT_EQ(graph.edgeCount(), 2);
}

TEST_F(OrientedGraphTest, InDegree) {
    graph.addEdge(0, 1);
    graph.addEdge(2, 1);
    EXPECT_EQ(graph.inDegree(1), 2);
}

TEST_F(OrientedGraphTest, OutDegree) {
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    EXPECT_EQ(graph.outDegree(0), 2);
}

TEST_F(OrientedGraphTest, EdgeIterator) {
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    size_t count = 0;
    for (auto it = graph.edgeBegin(0); it != graph.edgeEnd(0); ++it) {
        count++;
    }
    EXPECT_EQ(count, 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}