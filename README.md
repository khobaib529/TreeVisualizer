# TreeVisualizer Utility

TreeVisualizer is a C++ utility for visualizing binary tree structures using the Graphviz library. It generates graphical representations of binary trees and outputs the result in various formats such as SVG.

**Note:** This program has been tested on an Ubuntu system.

## Features
- **Visualize Trees**: Easily create visual representations of trees.
- **Output Formats**: Supports generating SVG output for clear visualization.
- **Template Class**: Generic design allows for visualization of any tree structure.

## Installation
To use TreeVisualizer, you need to have the Graphviz library installed on your system. You can install it using your package manager.

### For Ubuntu/Debian:
```bash
sudo apt-get install graphviz libgraphviz-dev
```

## Testing
To test the TreeVisualizer utility, use the provided test programs. It verifies the correctness of the binary tree visualizations using predefined test cases.

**1. Build the Test Executable:**
Before building the test executable, you need to create the necessary directory structure. Run the following commands:

```bash
mkdir build && cd build && mkdir tests
```
```shell
g++ -o build/tests/test_binary_tree_visualizer tests/test_binary_tree_visualizer.cpp -lgvc -lcgraph -I./include
```

**2. Run the Tests**
```shell
build/tests/test_binary_tree_visualizer
```

## Dependencies
- **C++ Compiler**: A C++ compiler (e.g., g++, clang++).
- **Graphviz**: The Graphviz library for visualizing graphs. Ensure you have the development package installed.
