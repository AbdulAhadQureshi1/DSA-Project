#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> showTrendingApps(vector<int> &trendingApps, map<int, vector<string>> &appMap){

    vector<string> appNames;
    for(int i=0; i<trendingApps.size(); i++) {
        int app = trendingApps[i];
        if(appMap.find(app)!=appMap.end()){
            cout << i+1 << ": " << appMap[app][0] << endl;
            appNames.push_back(appMap[app][0]);
        }
    }
    return appNames;
}

vector<string> showEducationalApps (map<string,vector<string>> &appMap, vector<string> &results) {
    vector<string> appNames;
    for(int i=0; i<results.size(); i++) {
        string appName = results[i];
        if(appMap.find(appName)!=appMap.end()) {
            cout << i+1 << ": " << appMap[appName][0] << endl;
            appNames.push_back(appMap[appName][0]);
        }
    }
    return appNames;
}
