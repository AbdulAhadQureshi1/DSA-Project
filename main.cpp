#include<iostream>
#include <typeinfo>
#include "AVLTree.h"
#include "parser.h"
#include "auth.h"
using namespace std;

int main()
{
    AVLTree<string> tree = parse<string>("googleplaystore.csv");

    cout << "Welcome to PlayStore My G" << endl;
    while(!authMain()) {
        cout << "Authenticate yourself please:" << endl;
    }

    cout << "What do you wanna do: \n1.Search" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        string search;
        cout << "What would you like to search?  ";
        cin >> search;
        transform(search.begin(), search.end(), search.begin(), ::tolower);
        vector<string> results = tree.search(search);
        for(int i=0; i<results.size(); i++) {
            cout << results[i] << endl;
        }
        break;
    }


    return 0;
}