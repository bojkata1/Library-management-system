#pragma once
#include "Book.h"
#include <vector>
#include <iostream>
#include <string>

class Library {
private:
	std::vector<Book> books;
public:
	Library();
	void AddBook(std::string title, std::string author, int publication_year, std::string isbn);
	void RemoveBook();
	void UpdateBook();
	void ShowBooks();
	~Library();
};