#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store user credentials
struct User {
  string name;
  string username;
  string password;
};

// Function to sign up a new user
void signUp(fstream& file) {
  User user;

  // Get user input for name, username, and password
  cout << "Enter name: ";
  cin >> user.name;
  cout << "Enter username: ";
  cin >> user.username;
  cout << "Enter password: ";
  cin >> user.password;

  // Write the user data to the file
  file << user.name << "," << user.username << "," << user.password << endl;
}

// Function to log in an existing user
bool logIn(fstream& file) {
  string username, password;

  // Get user input for username and password
  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  // Read the file line by line
  string line;
  while (getline(file, line)) {
  // Extract the name, username, and password from the line
    int i = line.find(',');
    string name = line.substr(0, i);
    int j = line.find(',', i + 1);
    string fileUsername = line.substr(i + 1, j - i - 1);
    string filePassword = line.substr(j + 1);

    // Check if the entered username and password match the ones in the file
    if (username == fileUsername && password == filePassword) {
      cout << "Logged in successfully as " << name << "." << endl;
      return true;
    }
  }

  // If we reach here, the username and password did not match any in the file
  cout << "Failed to log in. Invalid username or password." << endl;
  return false;
}

bool authMain() {
    // Open the file in append mode
  fstream file("credentials.txt", ios::app);

  // Sign up or log in
  cout << "1. Sign up" << endl;
  cout << "2. Log in" << endl;
  cout << "Enter your choice: ";
  int choice;
  cin >> choice;

  switch (choice) {
    case 1:
      signUp(file);
      cout << "Successfully Signed Up!" << endl;
      break;
    case 2:
      // Open the file in input mode
      file.close();
      file.open("credentials.txt", ios::in);
      return logIn(file);
      break;
  }

  // Close the file
  file.close();
  return false;
}
