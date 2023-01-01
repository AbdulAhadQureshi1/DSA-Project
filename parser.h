#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
// #include <dos.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "AVLTree.h"


void parseFile() {
  // Create an instance of the AVLTree class
  AVLTree <string>tree;
  int count = 0;

  // Open the .csv file
  std::ifstream file("googleplaystore.csv");

  // Check if the file was successfully opened
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file" << std::endl;
    return ;
  }

  // Read the file line by line
    bool first_line = true;
    std::string line;
  while (std::getline(file, line)) {
    // Split the line into fields using a string stream
    // Skip the processing of the first line
    if (first_line) {
      first_line = false;
      continue;
    }

    stringstream ss(line);
    string field="";   // neccessary
    vector<string> fields;
    while (getline(ss, field, ',')) {
      // cout << " field: " << field << endl;
      
      if(field == "NaN") field = "0";
      transform(field.begin(), field.end(), field.begin(), ::tolower);
      fields.push_back(field);
    }

    // Convert the fields from strings to the appropriate data type
    // For example, if the fields contain integers:
    // for(int i=0; i<16; i++) cout << fields[i] << "---";
    // cout << fields[0]<<" ";
    // cout << fields[1]<<" ";
    // cout << fields[2]<<" ";
    // cout << fields[3]<<" ";
    // cout << fields[4]<<" ";
    // cout << fields[5]<<" ";
    // cout << fields[6]<<" ";
    // cout << endl;
    count++;
    // double data = std::stod(fields[2]);
    string data = fields[0];

    // Insert the data into the AVL tree
    tree.insert(data);
  }
  // tree.inorder();
  cout << count << endl;
  if(tree.search("zowi app")) {
    cout << "Zowi app found" << endl;
  }
  else {
    cout << "Zowi app not found" << endl;
  }
}
