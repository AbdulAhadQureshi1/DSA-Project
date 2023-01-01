#include<iostream>
#include <typeinfo>
#include "AVLTree.h"
#include "parser.h"
using namespace std;

int main()
{

    AVLTree<string> tree = parse<string>("googleplaystore.csv");
    
    tree.inorder();
    if(tree.search("zowi app")) {
        cout << "Zowi app found" << endl;
    }
    else {
        cout << "Zowi app not found" << endl;
    }


    return 0;
}