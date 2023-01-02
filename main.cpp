#include<iostream>
#include <typeinfo>
#include <map>
#include <sstream>
#include <fstream>
#include "AVLTree.h"
#include "parser.h"
#include "auth.h"
#include "queue.h"
#include "funcs.h"
#include "pages.h"
using namespace std;



int main()
{

    Queue *downloads = new Queue();
    LinkedList<string> *wishlist = new LinkedList<string>;

    cout << "Welcome to PlayStore!" << endl;
    string logged_user = ""; // logged-in username will be stored here
    while(!authMain(logged_user)) {
        cout << "Authenticate yourself please:" << endl;
    }


    int choice = 0;

    while(true) {
        cout << "What do you wanna do: \n1.Search\n2.Trending Apps\n3.Education Apps\n4.Show Downloaded Apps\n5.Show Wishlist\n6.Quit\n>>> ";
        cin >> choice;
        if(choice == 6) break;

        string search = "";
        
        if(choice == 1){
            map<string, vector<string>> appMap;
            AVLTree<string> tree = parse<string>("googleplaystore.csv", appMap, 0);
            while(true){

                cout << "What would you like to search (g-Go back)?  ";
                cin >> search;
                if(search=="g") break;


                transform(search.begin(), search.end(), search.begin(), ::tolower);
                vector<string> result = SearchResults(tree, search);
                askAppInst(appMap, result, downloads, wishlist, logged_user);
            }
        }
        else if(choice == 2) {
            map<int, vector<string>> appMap;
            AVLTree<int> tree_two = parse<int>("googleplaystore.csv", appMap, 3);
            const int POPULARITY_THRESHOLD = 1000000;
            vector<int> trendingApps = tree_two.TrendingApps(POPULARITY_THRESHOLD);
            vector<string> trendingAppNames = showTrendingApps(trendingApps, appMap);
        }
        else if (choice == 3) {
            map<string, vector<string>> appMap;
            AVLTree<string> education_tree = parse<string>("googleplaystore.csv", appMap, 9);
            vector<string> apps = education_tree.search("education");
            apps = showEducationalApps(appMap, apps);
            askAppInst(appMap, apps, downloads, wishlist, logged_user);
        }
        else if(choice == 4) {
            downloads->display();
        }
        else if(choice == 5) {
            wishlist->printList();
        }
    }
    return 0;
}