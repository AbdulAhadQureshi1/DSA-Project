#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dos.h>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

template <typename T>
T ConvertToType(const string& s) {
  // Use a stringstream to convert the string to the desired data type
  stringstream ss(s);
  T t;
  ss >> t;
  return t;
}

template <typename T>
AVLTree<T> parse(const string& filename, map<string, vector<string>> &map) {

  int index = 0;
  
  // Create an instance of the AVLTree class
  AVLTree<T> tree;

  // Open the .csv file
  ifstream file(filename);

  // Check if the file was successfully opened
  if (!file.is_open()) {
    cerr << "Error: Could not open file" << endl;
    return tree;
  }

  bool first_line = true; //first line flag
  // Read the file line by line
  string line = "";
  while (getline(file, line)) {

    // Skip the processing of the first line
    if (first_line) {
      first_line = false;
      continue;
    }

    // Split the line into fields using a string stream
    stringstream ss(line);
    string field="";
    vector<string> fields;

    while (getline(ss, field, ',')) {
      if(field == "NaN") field = "0";
      transform(field.begin(), field.end(), field.begin(), ::tolower); // convert to lowercase.
      fields.push_back(field);
    }

    // if string already, skip conversion
    if(typeid(fields[0]).name() == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") {
      T data = fields[0];
    }
    else {
    // Convert the fields from strings to the appropriate data type
      T data = ConvertToType<T>(fields[0]);
    }
    // Insert the data into the AVL tree
    tree.insert(fields[0]);

    // Insert App info in the map
    map[fields[0]] = fields;
    index++;
  }
  return tree;
}
