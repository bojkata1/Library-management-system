#include <iostream>
#include <string>
#include "FileIO.h"
#include "Library.h"
int main() {
	do {
		std::string command;
		Library MyLib = readData();  // Loading data from Library_data.csv
		MyLib.ShowBooks();  // Display all books in the library
		std::cout << std::endl;
		std::cout << "Command list: AddBooks, RemoveBooks, UpdateBooks, SortBooks, SearchBook, exit" << std::endl;
		std::cout << "Command line: "; std::getline(std::cin, command);
		system("cls"); 
		// After each command the changes are saved in Library_data.csv
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
		else if (command == "SortBooks") {
			MyLib.SortBooks();
			saveData(MyLib.GetBooks());
		}
		else if (command == "SearchBook") {
			MyLib.SearchBook();
			saveData(MyLib.GetBooks());
		}
		system("cls");
	} while (true);
	return 0;
}