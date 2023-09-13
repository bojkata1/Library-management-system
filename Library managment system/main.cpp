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
		std::cout << "Command list: AddBooks, RemoveBooks, UpdateBooks, exit" << std::endl;
		std::cout << "Command line: "; std::getline(std::cin, command);
		system("cls");
		if (command == "exit") {
			break;
		}
		else if (command == "AddBooks") {
			MyLib.AddBook();
			saveData(MyLib.GetBooks());
		}
		else if (command == "RemoveBooks") {
			MyLib.RemoveBook();
			saveData(MyLib.GetBooks());
		}
		else if (command == "UpdateBooks") {
			MyLib.UpdateBook();
			saveData(MyLib.GetBooks());
		}
		system("cls");
	} while (true);
	return 0;
}