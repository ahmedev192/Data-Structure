#include <iostream>
#include "BinaryTree.cpp"
#include <vector> // Include the vector header

using namespace std;
int main()
{
    // Create a binary tree with root value 1
    BinaryTree<int> tree(1);

    // Add nodes to the tree
    std::vector<int> values = { 2, 3, 4, 5, 6 };
    std::vector<char> directions = { 'L', 'R', 'L', 'R', 'L' };
    tree.add(values, directions);

    // Test printInOrder
    std::cout << "InOrder Traversal: ";
    tree.printInOrder(tree.root);
    std::cout << std::endl;

    // Test printPreOrder
    std::cout << "PreOrder Traversal: ";
    tree.printPreOrder(tree.root);
    std::cout << std::endl;

    // Test printPostOrder
    std::cout << "PostOrder Traversal: ";
    tree.printPostOrder(tree.root);
    std::cout << std::endl;

    // Test MaxValue
    std::cout << "Max Value in the tree: " << tree.MaxValue() << std::endl;

    // Test maxHeight
    std::cout << "Max Height of the tree: " << tree.maxHeight() << std::endl;

    // Test countNodes
    std::cout << "Number of nodes in the tree: " << tree.countNodes() << std::endl;

    // Test search
    int valueToSearch = 4;
    std::cout << "Is value " << valueToSearch << " present in the tree? " << (tree.search(valueToSearch) ? "Yes" : "No") << std::endl;

    // Test isPerfectFomula
    std::cout << "Is the tree perfect? " << (tree.isPerfectFomula() ? "Yes" : "No") << std::endl;

    // Test printLevelOrder
    std::cout << "Level Order Traversal: ";
    tree.printLevelOrder();
    std::cout << std::endl;

    // Test print_nodes_level
    int levelToPrint = 2;
    std::cout << "Nodes at level " << levelToPrint << ": ";
    tree.print_nodes_level(levelToPrint);
    std::cout << std::endl;

    // Test level_order_traversal_spiral
    std::cout << "Spiral Level Order Traversal: ";
    tree.level_order_traversal_spiral();
    std::cout << std::endl;


}

