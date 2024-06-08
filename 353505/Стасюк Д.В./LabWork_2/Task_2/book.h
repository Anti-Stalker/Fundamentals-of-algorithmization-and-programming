#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
private:
    int id = 0;
    std::string author_surname;
    std::string book_name;
    std::string book_company;
    int book_year;
    int page_quantity;

public:
    Book (std::string autor_sname, std::string b_name, std::string b_company,int b_year, int p_quantity) {
        author_surname = autor_sname;
        book_name = b_name;
        book_company = b_company;
        book_year = b_year;
        page_quantity = p_quantity;
    }
    std::string to_str();

    std::string GetAuthor();

    std::string GetBookName();

    std::string GetBookCompany();

    int GetBookYear();

    int GetPageQuantity();

    int GetId();

    void SetId(int _id);

};


#endif // BOOK_H
