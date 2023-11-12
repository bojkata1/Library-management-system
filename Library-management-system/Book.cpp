#include "Book.h"
Book::Book(std::string title, std::string author, int publicationyear, std::string isbn) {
    this->title = title;
    this->author = author;
    this->publicationYear = publicationyear;
    this->isbn = isbn;
}
Book::Book() {
    title = "";
    author = "";
    publicationYear = 0;
    isbn = "";
}
std::string Book::GetTitle() const {
    return title;
}
std::string Book::GetAuthor() const {
    return author;
}
int Book::GetPublicationYear() const {
    return publicationYear;
}
std::string Book::GetIsbn() const {
    return isbn;
}

void Book::SetTitle() {
    std::string userInput;
    getline(std::cin, userInput);
    title = userInput;
}
void Book::SetTitle(std::string userInput) {
    title = userInput;
}
void Book::SetAuthor() {
    std::string userInput;
    getline(std::cin, userInput);
    author = userInput;
}
void Book::SetPublicationYear() {
    do {
        std::string userInput;
        bool isDigit = true;
        getline(std::cin, userInput);
        for (int i = 0; i < userInput.size(); i++) {
            if (isdigit(userInput[i]) == false) {
                isDigit = false;
                break;
            }
        }
        if (isDigit) {
            publicationYear = stoi(userInput);
            break;
        }
        else {
            std::cout << "Enter a valid year!: ";
        }
    } while (true);
}
void Book::SetIsbn() {
    std::string userInput;
    getline(std::cin, userInput);
    isbn = userInput;
}

void Book::ShowInfo() const {
    std::cout << "Title: " << title << ", Author: " << author
        << ", Publication year: " << publicationYear << ", ISBN: " << isbn << std::endl << std::endl;
}

Book::~Book(){}