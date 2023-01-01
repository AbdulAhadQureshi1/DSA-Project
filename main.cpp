#include<iostream>
#include <typeinfo>
#include <map>
#include "AVLTree.h"
#include "parser.h"
#include "auth.h"
#include "queue.h"
#include "funcs.h"
using namespace std;



int main()
{

    map<string, vector<string>> appMap;
    AVLTree<string> tree = parse<string>("googleplaystore.csv", appMap);
    Queue *downloads = new Queue();

    cout << "Welcome to PlayStore My G" << endl;
    while(!authMain()) {
        cout << "Authenticate yourself please:" << endl;
    }

    cout << "What do you wanna do: \n1.Search\n>>> ";
    int choice;
    cin >> choice;

    string search;
    switch (choice)
    {
    case 1:
        cout << "What would you like to search?  ";
        cin >> search;
        vector<string> result = SearchResults(tree, search);
        int appNo;
        cout << "Enter index of desired app: ";
        cin >> appNo;
        int appInst;
        cout << "Choose what to do with the app:\n1.Full Description\n2.Download\n3.Add to wishlist\n4.Go Back\n>>> ";
        cin >> appInst;
        switch (appInst)
        {
        case 1:
            showAppDescription(result, appNo, appMap);
            break;
        case 2:
            DownloadApp(result, appNo, downloads);
            break;
        
        default:
            break;
        }
        break;
    }


    return 0;
}