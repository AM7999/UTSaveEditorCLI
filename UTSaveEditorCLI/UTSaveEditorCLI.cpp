#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

string utIniPath;
string file0Path;
string saveDirPath;

// slowprint
void sprint(const string& message, int milliseconds) {
    for(char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }
}

string oldFun() {

  ifstream utini;
  ifstream file0;

  string newFile0Name = saveDirPath + "file0";
  string newUtiniName = saveDirPath + "undertale.ini";

  utini.open(utIniPath);
  file0.open(file0Path);

  if(!file0.is_open() || !utini.is_open()) {
    cout << "Could not open your saves! Will now exit.." << endl;
  }

  string line;
  int lineNumber = 36;
  for(int i = 1; i <= lineNumber; ++i) {
    getline(file0, line);
  }

  return line;
  
}

void changeFunValue() {
  string oldFunValue = oldFun();
  string newFun;

  ifstream utini;
  ifstream file0;

  utini.open(utIniPath);
  file0.open(file0Path);

  string newFile0Name = saveDirPath + "file0";
  string newUtiniName = saveDirPath + "undertale.ini";
  
  cout << "Your current fun value is: " << oldFunValue << " What would you like to change it to?" << endl;
  cin >> newFun;

  string line;
  // int lineNumber = 36;
  while(getline(file0, line)) {
	  size_t pos = line.find(newFun);


  }
}

#define clear() printf("\033[H\033[J")

void changeHumanName() {
	string oldHumanName;
	string newHumanName;
	ifstream utini;
	ofstream tempUtini;
	ifstream file0;
	ofstream tempFile0;
	//probably the worst use of memory but oh well
	 string oldUtiniName = saveDirPath + "temp_utini.txt";
	 string oldFile0Name = saveDirPath + "temp_file0.txt";
	 string newFile0Name = saveDirPath + "file0";
	 string newUtiniName = saveDirPath + "undertale.ini";

	 // string saveDirPath is declared globally
	utini.open(utIniPath);
	tempUtini.open(saveDirPath + "temp_utini.txt");
	file0.open(file0Path);
	tempFile0.open(saveDirPath + "temp_file0.txt");

	clear();

	if (!utini.is_open() || !file0.is_open()) {
		cout << "Could not open UNDERTALE.ini and file0!" << endl;
		return;
	}

	cout << "Please enter your current humans name: "; cin >> oldHumanName;
	cout << "Please choose a new human name: "; cin >> newHumanName;

	string line;
	while (getline(file0, line)) {
		size_t pos = line.find(oldHumanName);
		if (pos != string::npos) {
			line.replace(pos, oldHumanName.length(), newHumanName);
		}
		tempFile0 << line << endl;  // Write to the temporary file
	}

	while (getline(utini, line)) {
		size_t pos = line.find(oldHumanName);
		if (pos != string::npos) {
			line.replace(pos, oldHumanName.length(), newHumanName);
		}
		tempUtini << line << endl;  // Write to the temporary file
	}

	utini.close();
	tempUtini.close();
	file0.close();
	tempFile0.close();

	if (rename(oldUtiniName.c_str(), newUtiniName.c_str()) != 0) {
		cout << "Error renaming UNDERTALE.ini. Changes might not be applied." << endl;
		cout << errno << endl;
	}
	else {
		cout << "UNDERTALE.ini renamed successfully." << endl;
	}

	if (rename(oldFile0Name.c_str(), newFile0Name.c_str()) != 0) {
		cout << "Error renaming file0. Changes might not be applied." << endl;
		cout << errno << endl;
	}
	else {
		cout << "file0 renamed successfully." << endl;
	}

	// i love messy code
}

void writeSystemInfoFile() {
	int sysInfoMen;

	// My mid clear macro defined at the begining of the file
	clear();

	cout << "Please enter the path to your undertale save directory NOT an individual file: "; cin >> saveDirPath;

	cout << "What system info file do you want to write?" << endl;
	cout << "1. 962\n2. 963\n" << endl;
	cin >> sysInfoMen;

	string sysInfoFileName;
	char sysInfoChar;

	// Good Practice???
	if (sysInfoMen == 1) {
		sysInfoFileName = "system_information_962";
		sysInfoChar = 'a';
	}
	else if (sysInfoMen == 2) {
		sysInfoFileName = "system_information_963";
		sysInfoChar = 'b';
	}
	else {
		cout << "Invalid option." << endl;
		return;
	}

	ofstream sysInfoFile;
	sysInfoFile.open(saveDirPath + sysInfoFileName);
	sysInfoFile << sysInfoChar;
	sysInfoFile.close();
}

int main() {
	int menu;

	cout << "please enter the path to your undertale.ini: "; cin >> utIniPath;
	cout << "Please enter the path to your file0: "; cin >> file0Path;
	cout << "Please enter the path to where your UNDERTALE saves are locted (ex. %localappdata%\\UNDERTALE)"; cin >> saveDirPath;
	clear();

  sprint("Welcome to the Undertale SAVE Editor, Where YOU are the ruler of this world\n", 10);

	//cout << "Welcome to the Undertale SAVE Editor, Where YOU are the ruler of this world" << endl;
	cout << "1. Change your Humans name\n2. Write a system_info file\n";

	cout << "Please choose a menu option: "; cin >> menu;
	// still working on other functions
	// should i just turn the whole thing into one big ol'e array since its just a string of letters and numbers?
	// nah

	if (menu == 1) {
		changeHumanName();
	} else if (menu == 2) {
		writeSystemInfoFile();
	} else {
		changeFunValue();
	}
	return 0;
}
