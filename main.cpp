#include "src/include/task1.hpp"
#include "src/include/task2.hpp"
#include "src/include/task3.hpp"

#include<iostream>
#include<string>
#include<map>
#include<filesystem>

using std::cin, std::cout;

int main(){
            /* - - task №1 - - */

    //*
    std::string path = "../src/res.txt";

    enrolled(path);
    std::string input;
    cin >> input;
    while(input != "end"){
        unenrolled(input);
        cin >> input;
    }
    
    print_all();
    //*/

            /* - - task 2 - - */

    //*
    HashTable<int, std::string> ht;

    ht.add(59, "Кирпич");
    ht.add(109, "Панель");
    ht.add(29, "Шифер");
    ht.add(85, "Доска");

    ht.remove_key(29);
    cout << "Текущий размер: "<< ht.get_size() << '\n';
    cout << "Поиск ключа (цены) по значению (\"Кирпич\"):" << ht.search_key("Кирпич") << '\n';
    cout << "Пустой? " << (ht.is_empty()?"YES":"NO") << '\n';
    //*/

            /* - - task №3 - - */
    std::string i_path = "../src/img.jpeg";
    load_and_compare(i_path);
}
