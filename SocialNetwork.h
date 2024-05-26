#pragma once

#include <iostream>
#include <vector>
#include <string>

class User;
class Address;
class UsersGroup;

class User 
{
    class Address
    {
    private:
        std::string street;
        std::string city;

    public:
        Address () {}
        Address(const std::string& street, const std::string& city) : street (street), city (city) {}

        const std::string& GetStreet() const
        {
            return street;
        }
        const std::string& GetCity() const
        {
            return city;
        }
    };

private:
    std::string name;
    std::vector<UsersGroup*> groups;
    Address address;

public:

    User(const std::string& name, const std::string& street, const std::string& city)
    {
        this->name = name;
        User::Address(street, city);
    }

    const std::string& GetName() const 
    {
        return name; 
    }
    void AddGroup(UsersGroup* group)
    {
        groups.push_back(group); 
    }

    std::vector<UsersGroup*> GetGroups() const 
    {
        return groups; 
    }

    void SetAddress(const Address& newAddress) 
    {
        address = newAddress; 
    }
    const Address& GetAddress() const 
    {
        return address; 
    }

    std::string GetCityName() const 
    {
        return address.GetCity(); 
    }
 
};

class UsersGroup 
{
private:
    std::string name;
    std::vector<User*> users;

public:
    UsersGroup(const std::string& name) : name(name) {}

    const std::string& GetName() const 
    {
        return name; 
    }
    void AddUser(User* user) 
    {
        users.push_back(user); 
        user->AddGroup(this);
    }

    std::vector<User*> GetUsers() const 
    { 
        return users; 
    }

    void PrintUsers() const 
    {
        for (auto user : users)         
            std::cout << user->GetName() << std::endl;
        
    }

    void PrintUsersFromCity(const std::string& cityName) const 
    {
        for (auto user : users) 
        {
            if (user->GetCityName() == cityName) 
                std::cout << user->GetName() << std::endl;
            
        }
    }


};



//class User;
//class Address;
//class UsersGroup;
//
//class User
//{
//private:
//    std::string name;
//    std::vector<UsersGroup*> groups;
//    Address address;
//
//public:
//    class Address
//    {
//    public:
//        Address(const std::string& street, const std::string& city) : street(street), city(city) {}
//
//        const std::string& GetStreet() const
//        {
//            return street;
//        }
//        const std::string& GetCity() const
//        {
//            return city;
//        }
//
//    private:
//        std::string street;
//        std::string city;
//    };
//
//
//    User(const std::string& name, const std::string& street, const std::string& city) : Address(street, city), name(name) {}
//
//    const std::string& GetName() const
//    {
//        return name;
//    }
//    void AddGroup(UsersGroup* group)
//    {
//        groups.push_back(group);
//    }
//
//    std::vector<UsersGroup*> GetGroups() const
//    {
//        return groups;
//    }
//
//    void SetAddress(const Address& newAddress)
//    {
//        address = newAddress;
//    }
//    const Address& GetAddress() const
//    {
//        return address;
//    }
//
//    std::string GetCityName() const
//    {
//        return address.city;
//    }
//};
//
//class UsersGroup
//{
//public:
//    UsersGroup(const std::string& name) : name(name) {}
//
//    const std::string& GetName() const { return name; }
//    void AddUser(User* user) { users.push_back(user); }
//
//    std::vector<User*> GetUsers() const { return users; }
//
//    void PrintUsers() const {
//        for (auto user : users)
//        {
//            std::cout << user->GetName() << std::endl;
//        }
//    }
//
//    void PrintUsersFromCity(const std::string& city_name) const {
//        for (auto user : users) {
//            if (user->GetCityName() == city_name) {
//                std::cout << user->GetName() << std::endl;
//            }
//        }
//    }
//
//private:
//    std::string name;
//    std::vector<User*> users;
//};