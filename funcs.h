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


vector<string> SearchResults(AVLTree<string> tree, string search) {
    transform(search.begin(), search.end(), search.begin(), ::tolower);
    vector<string> results = tree.search(search);
    for(int i=0; i<results.size(); i++) {
        cout << i+1 << ": " << results[i] << endl;
    }
    return results;
}

void DownloadApp(vector<string> result, int appIndex, Queue *downloads) {
    downloads->enqueue(result[appIndex-1]); // user entered will be based on natural numbers(from 1)
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

void addToWishlist(vector<string> result, int appIndex, LinkedList<string> *list) {
    list->insertNode(result[appIndex-1]);
}