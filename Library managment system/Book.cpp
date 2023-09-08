#include "Book.h"

Book::Book(std::string title, std::string author, int publication_year, std::string isbn) {
    this->title = title;
    this->author = author;
    this->publication_year = publication_year;
    this->isbn = isbn;
}
Book::~Book(){}