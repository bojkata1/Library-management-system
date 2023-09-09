#include "Library.h"

void Library::AddBook(std::string title, std::string author, int publication_year, std::string isbn) {
	Book NewBook(title, author, publication_year, isbn);
	books.push_back(NewBook);
}

void Library::RemoveBook() {
	std::cout << "Enter book title: ";
	
}