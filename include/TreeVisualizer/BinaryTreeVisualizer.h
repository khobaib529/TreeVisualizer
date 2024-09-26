/*
 * BinaryTreeVisualizer.h
 * 
 * This file defines a template class `BinaryTreeVisualizer` which provides functionality 
 * for visualizing binary tree structures using the Graphviz library. It generates graphical 
 * representations of a binary tree and outputs the result in various formats such as SVG.
 * 
 * The class operates by recursively traversing the binary tree, converting its nodes 
 * and edges into a directed graph format that is suitable for visualization through Graphviz's 
 * "dot" layout engine.
 * 
 * Usage:
 * - Initialize the visualizer with a binary tree node.
 * - Call `visualize()` to generate and export the tree visualization in the desired format.
 * 
 * Dependencies:
 * - Graphviz (for layout and rendering)
 * - A user-defined `Node` class with the following properties:
 *      - `left` and `right` pointers to child nodes.
 *      - A `repr()` method that returns a string representation of the node.
 */

#ifndef BINARY_TREE_VISUALIZER_H_
#define BINARY_TREE_VISUALIZER_H_

#include<string>
#include <graphviz/gvc.h>

namespace TreeVisualizer {

// Template class for visualizing a binary tree structure using Graphviz
template<class Node>
class BinaryTreeVisualizer {
public:
    // Constructor that initializes the Graphviz context
    BinaryTreeVisualizer() {
        gvc = gvContext(); // Create a new Graphviz context
    }

    // Function to visualize the binary tree starting from the root
    // Parameters:
    // - root: Pointer to the root node of the binary tree
    // - output_file_format: Format for the output file (default is "svg")
    // - output_filename: Name of the output file (default is "binary_tree.svg")
    void visualize(Node* root, const char* output_file_format = "svg", const char* output_filename = "binary_tree.svg") const {
        Agraph_t* graph = agopen(const_cast<char*>("G"), Agdirected, nullptr);  // Create a directed graph for the binary tree
        _visualize(graph, root); // Recursive call to visualize the tree structure

        // Layout and render the graph
        gvLayout(gvc, graph, "dot"); // Use the "dot" layout engine for layout
        gvRenderFilename(gvc, graph, output_file_format, output_filename); // Render the graph to a file
        gvFreeLayout(gvc, graph); // Free the layout resources
        agclose(graph); // Close the graph to free resources
    }

    // Destructor to free the Graphviz context
    ~BinaryTreeVisualizer() {
        gvFreeContext(gvc); // Free the Graphviz context when the visualizer is destroyed
    }
private:
    // Recursive helper function to visualize the binary tree
    // Parameters:
    // - g: Pointer to the graph to which nodes and edges will be added
    // - node: Pointer to the current node in the binary tree
    void _visualize(Agraph_t* graph, Node* node) const {
        if (node == nullptr) {
            return;
        }

        // Generate a unique ID for each node (can be memory address or any other unique value)
        std::string node_id = std::to_string(reinterpret_cast<uintptr_t>(node));

        // Create the current node in the graph with a unique ID and a label
        Agnode_t* graph_node = agnode(graph, const_cast<char*>(node_id.c_str()), 1);
        agset(graph_node, const_cast<char*>("label"), const_cast<char*>(node->repr().c_str()));

        // If the left child exists, create the left edge and recursively visualize the left subtree
        if (node->left) {
            std::string left_node_id = std::to_string(reinterpret_cast<uintptr_t>(node->left));
            Agnode_t* left_child_node = agnode(graph, const_cast<char*>(left_node_id.c_str()), 1);
            agedge(graph, graph_node, left_child_node, nullptr, 1);
            _visualize(graph, node->left);  // Recursively add the left subtree
        }

        // If the right child exists, create the right edge and recursively visualize the right subtree
        if (node->right) {
            std::string right_node_id = std::to_string(reinterpret_cast<uintptr_t>(node->right));
            Agnode_t* right_child_node = agnode(graph, const_cast<char*>(right_node_id.c_str()), 1);
            agedge(graph, graph_node, right_child_node, nullptr, 1);
            _visualize(graph, node->right);  // Recursively add the right subtree
        }
    }
private:
    GVC_t* gvc;
};
} // namespace TreeVisualizer

#endif  // BINARY_TREE_VISUALIZER_H_
