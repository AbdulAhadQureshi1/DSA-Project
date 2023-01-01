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

    Queue *downloads = new Queue();
    LinkedList<string> *wishlist = new LinkedList<string>;

    cout << "Welcome to PlayStore My G" << endl;
    while(!authMain()) {
        cout << "Authenticate yourself please:" << endl;
    }

    int choice = 0;

    while(true) {
        cout << "What do you wanna do: \n1.Search\n2.Trending Apps\n3.Show Downloaded Apps\n4.Show Wishlist\n5.Quit\n>>> ";
        cin >> choice;
        if(choice == 5) break;

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
                int appNo;
                cout << "Enter index of desired app: ";
                cin >> appNo;
                int appInst = 0;

                while(appInst != 4){
                    cout << "Choose what to do with the app:\n1.Full Description\n2.Download\n3.Add to wishlist\n4.Go Back\n>>> ";
                    cin >> appInst;
                    switch (appInst){
                        case 1:
                            showAppDescription(result, appNo, appMap);
                            break;
                        case 2:
                            DownloadApp(result, appNo, downloads);
                            break;
                        case 3:
                            addToWishlist(result, appNo, wishlist);
                            break;
                        
                        default:
                            break;
                    }
                }
            }
        }
        else if(choice == 2) {
            map<int, vector<string>> appMap;
            AVLTree<int> tree_two = parse<int>("googleplaystore.csv", appMap, 3);
            const int POPULARITY_THRESHOLD = 1000000;
            vector<int> trendingApps = tree_two.TrendingApps(POPULARITY_THRESHOLD);
            vector<string> colNames = {"Name", "Category", "Rating", "Reviews", "Size", "Installs", "Type", "Price", "Content Rating", "Genres", "Last Updated", "Current Version", "Android Version"};
            for(int i=0; i<colNames.size(); i++) {
                cout << colNames[i] << " | ";
            }
            cout << endl;
            for(int i=0; i<trendingApps.size(); i++) {
                int app = trendingApps[i];
                if(appMap.find(app)!=appMap.end()){
                    for(int j=0; j<(appMap[app]).size(); j++) {
                        cout << appMap[app][j] << " | ";
                    }
                    cout << endl;
                }
            }
        }
        else if(choice == 3) {
            downloads->display();
        }
        else if(choice == 4) {
            wishlist->printList();
        }
    }
    return 0;
}