#pragma once
#include <iostream>
#include <string>
#include <iostream>

class Book {
private:
	std::string title;
	std::string author;
	int publicationYear;
	std::string isbn;
public:
	Book();
	Book(std::string title, std::string author, int publication_year, std::string isbn);
	std::string GetTitle() const;
	std::string GetAuthor() const;
	int GetPublicationYear() const;
	std::string GetIsbn() const;
	void SetTitle();
	void SetTitle(std::string userInput);
	void SetAuthor();
	void SetPublicationYear();
	void SetIsbn();
	~Book();
};