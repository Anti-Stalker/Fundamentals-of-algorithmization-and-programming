#include "orders.h"
#include <fstream>
#include <xor_crypt.h>
#include <sstream>

Orders::Orders() {}

Order Orders::parse_order(std::string str) {
    std::vector<std::string> vect;
    std::string delimiter = ";";

    std::stringstream ss(str);
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        vect.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    Order o;
    o.id = vect[0];
    o.customerName = vect[1];
    o.modelPath  = vect[2];
    o.material = vect[3];
    o.price = std::stof(vect[4]);
    o.volume = std::stof(vect[5]);
    o.date = QDate::fromString(QString::fromStdString(vect[6]),"dd-MM-yyyy");

    return o;
}

std::string Orders::order_to_str(Order o) {
    std::string delimiter = ";";

    std::stringstream ss;

    ss << o.id << delimiter;
    ss << o.customerName << delimiter;
    ss << o.modelPath << delimiter;
    ss << o.material << delimiter;
    ss << o.price << delimiter;
    ss << o.volume << delimiter;
    ss << o.date.toString("dd-MM-yyyy").toStdString() << delimiter;

    return ss.str();
}

void Orders::load_from_file(QString file_path) {
    d.clear();
    std::ifstream infile(file_path.toStdString());
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::stringstream decrypted_buffer;
    decrypted_buffer << xor_crypt("DASHA", buffer.str());
    std::string line;
    while (std::getline(decrypted_buffer, line))
    {
        d.push_back(parse_order(line));
    }
}

void Orders::save_to_file(QString file_path) {
    std::stringstream ss;
    foreach(Order o, d) {
        ss << this->order_to_str(o) << std::endl;
    }
    std::ofstream outfile(file_path.toStdString());
    outfile << xor_crypt("DASHA", ss.str());

    outfile.close();
}
