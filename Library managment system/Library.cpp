#include "Library.h"

Library::Library() {
	std::cout << "";
}

std::vector<Book> Library::GetBooks() {
	return books;
}

void Library::LoadBook(std::string title, std::string author, int publication_year, std::string isbn) {
	Book NewBook(title, author, publication_year, isbn);
	books.push_back(NewBook);
}

void Library::AddBook() {
	do {
		ShowBooks();
		Book NewBook;		
		std::string command;
		std::cout << "Enter \"stop\" to exit the command" << std::endl;
		std::cout << "Enter the book's title: ";
		getline(std::cin, command);
		if (command == "stop") {
			break;
		}
		NewBook.SetTitle(command);
		std::cout << "Enter the name of the book's author: ";
		NewBook.SetAuthor();
		std::cout << "Enter the book's publication year: ";
		NewBook.SetPublicationYear();
		std::cout << "Enter the book's ISBN: ";
		NewBook.SetIsbn();
		books.push_back(NewBook);
		system("cls");
	} while (true);
}

void Library::RemoveBook() {
	do {
		ShowBooks();
		std::string command; int i = 0;
		std::cout << "Enter \"stop\" to exit the command" << std::endl;
		std::cout << "Enter \"isbn\" to search by ISBN" << std::endl;
		std::cout << "Enter the title of the book You want to remove: ";
		getline(std::cin, command);
		if (command == "stop") {
			break;
		}
		else if (command == "isbn") {
			std::cout << "Enter the ISBN of the book You want to remove: ";
			getline(std::cin, command);
		}
		for (const Book book : books) {
			if (book.GetIsbn() == command || book.GetTitle() == command) {
				books.erase(books.begin() + i);
				std::cout << "The book was deleted successfully!" << std::endl;
				break;
			}
			else {
				i++;
			}
		}
		system("cls");
	} while (true);
}
void Library::UpdateBook() {
	do {
		ShowBooks();
		std::string command;
		std::cout << "Enter \"stop\" to exit the command";
		std::cout << "Enter \"isbn\" to search by ISBN" << std::endl;
		std::cout << "Enter the title of the book You want to update: ";
		getline(std::cin, command);
		if (command == "stop") {
			break;
		}
		else if (command == "isbn") {
			std::cout << "Enter the ISBN of the book You want to remove: ";
			getline(std::cin, command);
		}
		for (Book& book : books) {
			system("cls");
			if (book.GetIsbn() == command || book.GetTitle() == command) {
				std::cout << "Title: " << book.GetTitle() << ", Author: " << book.GetAuthor()
					<< ", Publication year: " << book.GetPublicationYear() << ", ISBN: " << book.GetIsbn() << std::endl;
				std::cout << "What do you want to update (\"title\", \"author\", \"publication year\" or \"isbn\": ";
				getline(std::cin, command);
				if (command == "title") {
					std::cout << "Enter the book's new title: ";
					book.SetTitle();
				}
				else if (command == "author") {
					std::cout << "Enter the book's new author: ";
					book.SetAuthor();
				}
				else if (command == "publication year") {
					std::cout << "Enter the book's new publication year: ";
					book.SetPublicationYear();
				}
				else if (command == "isbn") {
					std::cout << "Enter the book's new ISBN: ";
					book.SetIsbn();
				}
				std::cout << "The book was updated successfully!" << std::endl;
				break;
			}
		
		}
		system("cls");
	} while (true);
}
void Library::ShowBooks() {
	std::cout << "Books:" << std::endl;
	for (Book& book : books) {
		book.ShowInfo();
	}
}

void Library::SortBooks() {
	std::string command;
	std::cout << "Sort by (title, author, year): ";
	getline(std::cin, command);
	if (command == "title") {
		std::sort(books.begin(), books.end(), [](Book book1, Book book2){
			return book1.GetTitle() < book2.GetTitle();
		});	
		ShowBooks();
		std::cout << "Enter \"reverse\" to reverse the sorting order or press \"Enter\" to continue to the main menu: ";
		getline(std::cin, command);
		if (command == "reverse") {
			std::sort(books.begin(), books.end(), [](Book book1, Book book2) {
				return book1.GetTitle() > book2.GetTitle();
			});
		}
	}
	else if (command == "author") {
		std::sort(books.begin(), books.end(), [](Book book1, Book book2) {
			return book1.GetAuthor() < book2.GetAuthor();
		});
		ShowBooks();
		std::cout << "Enter \"reverse\" to reverse the sorting order or press \"Enter\" to continue to the main menu: ";
		getline(std::cin, command);
		if (command == "reverse") {
			std::sort(books.begin(), books.end(), [](Book book1, Book book2) {
				return book1.GetAuthor() > book2.GetAuthor();
			});
		}
	}
	else if (command == "year") {
		std::sort(books.begin(), books.end(), [](Book book1, Book book2) {
			return book1.GetPublicationYear() < book2.GetPublicationYear();
		});
		ShowBooks();
		std::cout << "Enter \"reverse\" to reverse the sorting order or press \"Enter\" to continue to the main menu: ";
		getline(std::cin, command);
		if (command == "reverse") {
			std::sort(books.begin(), books.end(), [](Book book1, Book book2) {
				return book1.GetPublicationYear() > book2.GetPublicationYear();
			});
		}
	}
}

void Library::SearchBook() {
	std::string command;
	std::vector<Book> results;
	std::cout << "Search by (title, author, year): ";
	getline(std::cin, command);
	if (command == "title") {
		std::cout << "Enter the book's title: ";
		getline(std::cin, command);
		for (const Book book : books) {
			if (book.GetTitle().find(command) < book.GetTitle().size()) {
				results.push_back(book);
			}
		}
	}
	else if (command == "author") {
		std::cout << "Enter the author's name: ";
		getline(std::cin, command);
		for (const Book book : books) {
			if (book.GetAuthor().find(command) < book.GetTitle().size()) {
				results.push_back(book);
			}
		}
	}
	else if (command == "year") {
		std::cout << "Enter the book's publication year: ";
		getline(std::cin, command);
		for (const Book book : books) {
			try {
				if (book.GetPublicationYear() == stoi(command)) {
					results.push_back(book);
				}
			} catch(...) {
				std::cout << "Invalid number!!!" << std::endl;
				break;
			}
		}
	}
	int size = results.size();
	if (size != 0) {
		std::cout << "There are " << size << " matches!" << std::endl << std::endl;
		for (const Book book : results) {
			book.ShowInfo();
		}
	}
	else {
		std::cout << "No results found!" << std::endl;
	}
	system("pause");
}

Library::~Library(){}