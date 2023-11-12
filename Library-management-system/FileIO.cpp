#include "FileIO.h"

Library readData() {
	std::string title, author, isbn, publication_year;
	Library Lib1;
	std::ifstream LibraryData("Library_data.csv");
	std::string rawData;
	while (getline(LibraryData, rawData)) {
		std::stringstream line(rawData);
		getline(line, title, ';');
		getline(line, author, ';');
		getline(line, publication_year, ';');
		getline(line, isbn, ';');
		Lib1.LoadBook(title, author, stoi(publication_year), isbn);
	}
	return Lib1;
}

void saveData(std::vector<Book> books){
	std::ofstream OutputFile("Library_data.csv");
	for (const Book book : books) {
		OutputFile << book.GetTitle() << ";";
		OutputFile << book.GetAuthor() << ";";
		OutputFile << book.GetPublicationYear() << ";";
		OutputFile << book.GetIsbn() << ";";
		OutputFile << std::endl;
	}
}