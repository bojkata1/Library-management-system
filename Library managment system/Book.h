#pragma once
#include <iostream>
#include <string>

class Book {
private:
	std::string title;
	std::string author;
	int publication_year;
	std::string isbn;
public:
	Book(std::string title, std::string author, int publication_year, std::string isbn);
	~Book();
};