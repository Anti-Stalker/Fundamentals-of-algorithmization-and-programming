#ifndef ORDERS_H
#define ORDERS_H
#include "QtCore"
#include <vector>

struct Order {
    std::string id;
    std::string customerName;
    std::string modelPath;
    std::string material;
    float price;
    float volume;
    QDate date;
};


class Orders
{
private:
    Order parse_order(std::string str);
    std::string order_to_str(Order);

public:
    Orders();
    std::vector<Order> d;
    void load_from_file(QString file_path);
    void save_to_file(QString file_path);
};

#endif // ORDERS_H
