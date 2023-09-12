#include <iostream>
#include <string>
#include "FileIO.h"
#include "Library.h"
int main() {
	do {
		std::string command;
		Library MyLib = readData();
		MyLib.ShowBooks();
		std::cout << std::endl;
		std::cout << "Command list: AddBooks, RemoveBooks, UpdateBooks" << std::endl;
		std::cout << "Command line: "; std::getline(std::cin, command);
		system("cls");
		if (command == "AddBooks") {
			std::string title, author, year, isbn;
		}
		else if (command == "RemoveBooks") {
			MyLib.RemoveBook();
		}
		else if (command == "UpdateBooks") {
			MyLib.UpdateBook();
		}
		system("cls");
	} while (true);
	return 0;
}