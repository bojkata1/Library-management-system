#pragma once
#include <iostream>
#include <string>

class Book {
private:
	std::string title;
	std::string author;
	int publicationYear;
	std::string isbn;
public:
	Book(std::string title, std::string author, int publication_year, std::string isbn);
	std::string GetTitle();
	std::string GetAuthor();
	int GetPublicationYear();
	std::string GetIsbn();
	void SetTitle();
	void SetAuthor();
	void SetPublicationYear();
	void SetIsbn();
	~Book();
};