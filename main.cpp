#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
  string name;
  int age;

  Person() : name(""), age(0) {}

  Person(const string &name, int age) : name(name), age(age) {}

  // Function to save the object to a file
  void saveToFile(const string &filename) {
    ofstream ofs(filename);
    if (!ofs) {
      cerr << "Error opening file for writing." << endl;
      return;
    }
    ofs << name << endl;
    ofs << age << endl;
    ofs.close();
  }

  // Function to load the object from a file
  void loadFromFile(const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
      cerr << "Error opening file for reading." << endl;
      return;
    }
    getline(ifs, name);
    ifs >> age;
    ifs.close();
  }
};

int main() {
  string TypeName;
  int TypeAge;
  string Response;
  Person loadedPerson;

  cout << "What's your name?\n";
  cin >> TypeName;
  cout << "What's your age?\n";
  cin >> TypeAge;

  // Create a Person object
  Person person(TypeName, TypeAge);

  while (1) {
    cout << "Enter command (save/load/display): ";
    cin >> Response;

    if (Response == "save") {
      // Save to a file
      person.saveToFile("person.txt");
    } else if (Response == "load") {
      // Load data from file
      loadedPerson.loadFromFile("person.txt");
    } else if (Response == "display") {
      cout << "\nName: " << loadedPerson.name << ", Age: " << loadedPerson.age
           << endl;
    }
  }

  return 0;
}
