#include "CGOManager.h"
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;
bool loadCGOManager(CGOManager& manager, const char* file_path);

int main(void) {
	CGOManager manager(200,200);

	bool active = true;
	while (active) {
		CGOManager manager(200,200);
		cout << "(1) Load an Example Quad Tree (25 Diff IDs)" << endl;
		cout << "(2) Load a Quad Tree using a Text File" << endl;
		cout << "Enter Choice: ";
		int in;
		cin >> in;
		string filePath;
		if (in == 1) {
			filePath = "example.txt";
		}
		else if (in == 2) {
			cout << "Enter FileName (Put the file in QuadTree folder): ";
			cin >> filePath;
			if (filePath.find(".txt", 0) == string::npos)
				filePath += ".txt";
		}
		else {
			cout << "Invalid Operation." << endl;
			continue;
		}
		if (loadCGOManager(manager, ("QuadTree//" + filePath).c_str()) == true) {
			cout << "Successfully loaded '" << filePath << "'. Found " << manager.getTotalSize() << " Game Objects." << endl;
			bool stop = false;
			while (stop != true) {
				cout << endl;
				cout << "(1) Print Tree" << endl;
				cout << "(2) Print surrounding GOs" << endl;
				cout << "(3) Exit to main interface" << endl;
				cout << "Enter Choice: ";
				int choice;
				cin >> choice;
				cout << endl;
				if (choice == 1) {
					manager.PrintTree();
				}
				else if (choice == 2) {
					cout << "Enter GO ID: ";
					int id;
					cin >> id;
					manager.PrintNearbyGO(id);
				}
				else {
					stop = true;
				}
			}
		}
		else {
			cout << "Error occured while loading file." << endl;
		}
		cout << endl;
	}
	return 0;
}

bool loadCGOManager(CGOManager& manager, const char* file_path) {
	std::ifstream fileStream(file_path, std::ios::binary);
	if (!fileStream.is_open())
	{
		std::cout << "Impossible to open " << file_path << ". Are you in the right directory ?\n";
		return false;
	}
	int line = 0;
	while (!fileStream.eof())
	{
		line++;
		char buf[256];
		fileStream.getline(buf, 256);
		int id, x, y;
		id = x = y = -1;
		sscanf_s((buf), "%d,%d,%d", &id,&x,&y);
		if (id == -1) {
			cout << "Line " << line << " couldn't be loaded" << endl;
		}
		CGO* cgo = new CGO(id,x,y);
		manager.addCGO(cgo);
	}
	return true;
}
