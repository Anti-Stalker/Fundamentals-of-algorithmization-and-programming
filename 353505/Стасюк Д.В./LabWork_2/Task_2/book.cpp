#include "book.h"

std::string Book::to_str() {
    return (author_surname) + ";" + (book_name) + ";" + (book_company) + ";" + std::to_string(book_year) + ";" + std::to_string(page_quantity) + ";";
}

std::string Book::GetAuthor() {
    return author_surname;
}
std::string Book::GetBookName() {
    return book_name;
}
std::string Book::GetBookCompany() {
    return book_company;
}
int Book::GetBookYear() {
    return book_year;
}
int Book::GetPageQuantity() {
    return page_quantity;
}
int Book::GetId() {
    return id;
}

void Book::SetId(int _id) {
    id = _id;
}
