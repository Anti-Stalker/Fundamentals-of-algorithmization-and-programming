#include <iostream>
#include "Map.h"
#include "Set.h"
#include "unordered_map.h"

int main() {

    unord_map<int, std::string, h<int>> table;
    std::pair<int, std::string> my_pair(11, "bebra in honor of Maxim");
    table.insert(my_pair);
    std::cout << table.contain(11);
    table[12] = "meow";
    std::cout << table[12] << table.contain(12) << table[11] << "\nsize - " << table.size() << '\n';
    table.clear();

    Set<std::string> s;
    s.insert("meow");
    s.insert("UwU");
    s.insert("OwO");
    Set<std::string>::Iterator it = s.begin();
    for(it; it != s.end(); ++it ){
        std::cout << *it << "\n";
    }

    Map<std::string , int> m;
    m["osu"] = 5;
    m["e"] = 7;
    m["asd"] = 9;
    m.clear();
    m["osu"] = 228;
    Map<std::string, int>::Iterator iter = m.begin();


    for(iter; iter != m.end(); ++iter){
        std::cout << *iter << " ";
    }


    std::cout << "\n sz - "<< m.size() << '\n';
    //std::cout << m[0] << " " << m[13] <<" " << m.empty() << " "<< m.size() << std::endl;
    return 0;
}
