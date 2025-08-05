#include <vector>
#include "BST.hpp"

int main() {
    std::vector<int> data = {10, 6, 3, 5, 9, 2, 13, 20, 15};

    BST bst = BST();

    for(int d : data) {
        bst.insert(d);
    }
    bst.printInorder();
    std::cout << "Removing 5, 9, and 2" << std::endl;
    bst.remove(5);
    bst.remove(9);
    bst.remove(2);
    bst.printInorder();

    std::cout << "Searching for 13...";
    if(bst.search(13)) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    std::cout << "Searching for 25...";
    if(bst.search(25)) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
