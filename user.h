#pragma once
#include<iostream>

struct User{
    std::string name;
    std::string surname;
    int age;
    int telephone_number;


    User(){
        name = "";
        surname= "";
        age = 0;
        telephone_number = 0; 
    }

    User(std::string name_user, std::string surname_user,int age_user, int telephone_number_user){
        name = name_user;
        surname= surname_user;
        age = age_user;
        telephone_number = telephone_number_user; 
    }
    bool operator==(const User& other){
    return name==other.name && surname==other.surname && age==other.age && telephone_number==other.telephone_number;
    }

    friend std::ostream& operator<<(std::ostream& o, const User& user) {
        return o <<"| "<<  user.name << "," << user.surname << "," << user.age << "," << user.telephone_number << " |";
    } 
    
    friend std::istream& operator>>(std::istream& i, User& user) {
        i >> user.name >> user.surname >> user.age >> user.telephone_number;
        return i;
    }
    
    
};

