#include "SocialNetwork.h"

int main() 
{
    User user1("u1", "str1", "ct1");
    User user2("u1", "str2", "ct2");
    User user3("u3", "str3", "ct3");

    UsersGroup group1("gr1");
    UsersGroup group2("gr2");

    group1.AddUser(&user1);
    group1.AddUser(&user2);
    group2.AddUser(&user2);
    group2.AddUser(&user3);

    group1.PrintUsers();
    std::cout << std::endl;
    group2.PrintUsers();
    std::cout << std::endl;

    user1.AddGroup(&group1);
    user2.AddGroup(&group1);
    user2.AddGroup(&group2);
    user3.AddGroup(&group2);

    std::cout << "Groups for user1:" << std::endl;
    for (auto group : user1.GetGroups()) 
        std::cout << group->GetName() << std::endl;
    
    std::cout << std::endl;

    std::cout << "Groups for user2:" << std::endl;
    for (auto group : user2.GetGroups()) 
        std::cout << group->GetName() << std::endl;
    
    std::cout << std::endl;

    std::cout << "Groups for user3:" << std::endl;
    for (auto group : user3.GetGroups()) 
        std::cout << group->GetName() << std::endl;
    
    std::cout << std::endl;

    //Address address1("str4", "ct4");
    //user1.SetAddress(address1);

    //std::cout << "Users from New York in group1:" << std::endl;
    //group1.PrintUsersFromCity("New York");

}
//----------------------------------------------------------------------


