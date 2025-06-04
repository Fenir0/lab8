#include "include/task2.hpp"
#include<iostream>
// init
template <>
HashTable<int, std::string>::HashTable(){
    int init_size = 10;
    this->hs.resize(init_size);
}

// add a key->element
template <>
void HashTable<int, std::string>::add(int key, std::string value){
    std::pair<int, std::string> pair_to_add = std::make_pair(key, value);
    hs.push_back(pair_to_add);
}

// remove element by key
template <>
void HashTable<int, std::string>::remove_key(int key){
    try{
        for(auto i = hs.begin(); i != hs.end(); ++i){
            if(i->first == key){
                hs.erase(i);
                return;
            }
        }
        throw std::runtime_error("No such key found");
    }
    catch(std::exception err){
        printf("%s", err.what());
    }

}

// find a key by value (first match)
template <>
int HashTable<int, std::string>::search_key(std::string value){
    for(auto i = hs.begin(); i != hs.end(); ++i){
        if(i->second == value){
            return i->first;
        }
    }
    return -1;
}

template <>
bool HashTable<int, std::string>::is_empty(){
    return hs.empty();
}

// return size
template <>
int HashTable<int, std::string>::get_size(){
    return hs.size();
}



