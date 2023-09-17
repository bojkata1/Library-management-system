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
	std::vector<Book> GetBooks();
	void LoadBook(std::string title, std::string author, int publication_year, std::string isbn);
	void AddBook();
	void RemoveBook();
	void UpdateBook();
	void ShowBooks();
	void SortBooks();
	void SearchBook();
	~Library();
};