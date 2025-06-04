#include "include/task1.hpp"

#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

std::map<long long, std::string> hs_voted;

int repeat;
const int p = 37;
const long long mod = 10e9+7;

void print_all(){
    std::cout << "Voters:  " << hs_voted.size() << '\n';
    std::cout << "Repeats: " << repeat          << '\n';
    std::cout << "Students: ";
    for(auto i: hs_voted){
        std::cout << i.second << '\n';
    }
}

long long hash(std::string& name){
    long long hash = 0, p_pow = 1;
    for(int i = 0; i < name.size(); i++){
        hash = (hash + (name[i]>'a'?name[i] - 'a' + 1:name[i]-'A'+1) * p_pow)%mod;
        p_pow = p_pow*p%mod;
    }
    return hash;
}

long long enrolled(std::string& path){
    repeat = 0;
    long long hs;
    bool found_repeat;

    try{
        std::ifstream in;
        in.clear();
        in.open(path);
        if(!in.is_open()) {
         
            std::cout << "file not found";
        }
        std::string s = "";
        while(std::getline(in, s)){
            // EOF
            if(s == "***") break;

            hs = hash(s);
            found_repeat = false;
            
            // If first surname to be read
            if(hs_voted.size() == 0){
                hs_voted[hs] = s;
                continue;
            }

            // Search for repetance
            for(auto i = hs_voted.begin(); i != hs_voted.end(); i++){
                if((*i).first == hs){
                    repeat++;
                    found_repeat = true;
                    break;
                }
            }

            // If not repeat
            if(!found_repeat){
                hs_voted[hs] = s;
            }
        }
        in.close();
    }
    catch(std::exception e){
        printf("Error while loading file\n");
        return -1;
    }
    return 0;
}

long long unenrolled(std::string& name){
    long long hs = hash(name);
    if(hs_voted.erase(hs))
        std::cout << "\nUnenrolling successful: " << name << " is no longer with us...\n";
    else
        std::cout << "Error: student not found\n";
    return 0;
}

