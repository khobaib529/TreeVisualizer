/*
 * test_binary_tree_visualizer.cpp
 *
 * This file contains a test program for the BinaryTreeVisualizer class, which visualizes
 * binary tree structures using the Graphviz library.
 *
 * The program defines a simple binary tree node structure and constructs a sample binary tree.
 * It then creates an instance of the BinaryTreeVisualizer and generates a graphical representation
 * of the binary tree, outputting the result as an SVG file.
 *
 * Usage:
 * - Compile the program along with the BinaryTreeVisualizer class.
 * - Run the executable to generate a visual representation of the binary tree.
 * - The output will be saved as 'binary_tree_test.svg'.
 *
 * Dependencies:
 * - TreeVisualizer/BinaryTreeVisualizer.h (for the visualizer class)
 * - Graphviz (for layout and rendering)
 */

#include <TreeVisualizer/BinaryTreeVisualizer.h>
#include <string>
#include <iostream>

/* 
 * Define a simple binary tree node structure.
 *
 * This struct represents a single node in a binary tree, containing pointers 
 * to its left and right child nodes, as well as a value stored as a string.
 *
 * Members:
 * - Node* left: Pointer to the left child node.
 * - Node* right: Pointer to the right child node.
 * - std::string value: The value stored in the node, used for labeling 
 *   the node in visualizations.
 *
 * Constructor:
 * - Node(const std::string& val): Initializes a new node with the specified 
 *   value and sets both child pointers to nullptr.
 *
 * Method:
 * - std::string repr() const: Returns the string representation of the 
 *   node's value, used for labeling when visualizing the tree with Graphviz.
 */
struct Node {
    Node* left;
    Node* right;
    std::string value;

    // Constructor to initialize the node
    Node(const std::string& val) : left(nullptr), right(nullptr), value(val) {}

    // Method to return the string representation of the node (for labeling in Graphviz)
    std::string repr() const {
        return value;
    }
};

int main() {
    // Create a simple binary tree
    Node* root = new Node("root");
    root->left = new Node("left");
    root->right = new Node("right");
    root->left->left = new Node("left.left");
    root->left->right = new Node("left.right");
    root->right->left = new Node("right.left");
    root->right->right = new Node("right.right");

    // Create an instance of the BinaryTreeVisualizer
    TreeVisualizer::BinaryTreeVisualizer<Node> visualizer;

    // Visualize the binary tree and output it as an SVG file
    visualizer.visualize(root, "svg", "binary_tree_test.svg");

    std::cout << "Binary tree has been visualized to 'binary_tree_test.svg'" << std::endl;

    // Clean up the dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
