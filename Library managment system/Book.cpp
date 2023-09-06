#include "Book.h"
#include <iostream>
#include <string>
Book::Book(std::string title, std::string author, int publication_year, std::string isbn) {
    this->title = title;
    this->author = author;
    this->publication_year = publication_year;
    this->isbn = isbn;
    std::cout << "Hi" << std::endl;
}