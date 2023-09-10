#include "Library.h"

Library::Library() {
	std::cout << "Library loaded!" << std::endl;
}

void Library::AddBook(std::string title, std::string author, int publication_year, std::string isbn) {
	Book NewBook(title, author, publication_year, isbn);
	books.push_back(NewBook);
}

void Library::RemoveBook() {
	std::cout << "Enter book title: ";
	
}
void Library::UpdateBook() {
	std::cout << "Enter book title: ";
}
void Library::ShowBooks() {
	for (const Book book : books) {
		std::cout << "Title: " << book.GetTitle() << ", Author: " << book.GetAuthor()
		<< ", Publication year: " << book.GetPublicationYear() << ", Isbn: " << book.GetIsbn() << std::endl;
	}
}

Library::~Library(){}