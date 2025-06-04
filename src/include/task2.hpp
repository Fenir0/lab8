/*
Вашей семиколенной сестре Прасковье нужно помочь с развитием магазина строитель-
ных материалов. Она хочет создать такой справочник с ценами, чтобы она не листала его,
а сразу находила цену на нужный товар. Реализуйте хэш-таблицу в виде класса HashTable,
в котором реализованы методы добавления, удаления, поиска значения (цены) ключа (то-
вара), проверки на пустую таблицу, получения размера таблицы. В конструкторе по умол-
чанию создаётся создаётся пустой объект на 10 позиций.
*/

#ifndef TASK2
#define TASK2
#include<vector>


template<typename T, typename P>
class HashTable{
    protected:
    std::vector<std::pair<T, P>> hs;

    public:
    HashTable();
    void add(T key, P value);
    void remove_key(T key);
    T search_key(P value);
    bool is_empty();
    int get_size();
    T& operator[](T key);
};

#endif