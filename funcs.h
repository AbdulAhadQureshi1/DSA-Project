#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dos.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "linkedList.h"
using namespace std;

void DownloadApp(vector<string> result, int appIndex, Queue *downloads, string active_user) {
    downloads->enqueue(result[appIndex-1]); // user entered will be based on natural numbers(from 1)
    fstream file("UserDownloads.txt", ios::app);
    file << active_user <<":"<<result[appIndex-1]<< endl;
    file.close();
}

void showAppDescription(vector<string> result, int appIndex, map<string, vector<string>> &map) {
    string appName = result[appIndex-1];
    vector<string> colNames = {"Name", "Category", "Rating", "Reviews", "Size", "Installs", "Type", "Price", "Content Rating", "Genres", "Last Updated", "Current Version", "Android Version"};
    if(map.find(appName)!=map.end()) {
        for(int i=0; i<(map[appName]).size(); i++) {
            cout << colNames[i] << ": " << map[appName][i] << endl;
        }
    }
}

void addToWishlist(vector<string> result, int appIndex, LinkedList<string> *list, string active_user) {
    list->insertNode(result[appIndex-1]);
    fstream file("UserWishList.txt", ios::app);
    file << active_user <<":"<<result[appIndex-1]<< endl;
    file.close();
}

void askAppInst(map<string, vector<string>> &appMap, vector<string> &result, Queue *downloads, LinkedList<string> *wishlist, string user) {

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
                DownloadApp(result, appNo, downloads, user);
                break;
            case 3:
                addToWishlist(result, appNo, wishlist, user);
                break;
            
            default:
                break;
        }
    }

}

vector<string> SearchResults(AVLTree<string> tree, string search) {
    transform(search.begin(), search.end(), search.begin(), ::tolower);
    vector<string> results = tree.search(search);
    for(int i=0; i<results.size(); i++) {
        cout << i+1 << ": " << results[i] << endl;
    }
    return results;
}
