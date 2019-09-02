#include"init.h"
#include"create_account.h"
#include"login.h"
#include<iostream>

using namespace Progrado;
using namespace Progrado::UI;


void init::execute()
{   
    int response = 0;
    int login_attempts = 3;
    std::cout << 
    "Type 1 to login\n"
    "New user? Type 2 to create an account\n"
    "Type 0 to exit\n";

    while(login_attempts > 0 && response != 0)
    {
        if(response == 1)
        {
            auto transfer_to_login = std::make_unique<login>();
            transfer_to_login->prompt_user();
            transfer_to_login->execute(); 
        }
        else if (response == 2)
        {
            auto transfer_to_create_acct = std::make_unique<create_account>();
            transfer_to_create_acct->execute(); 
        }
        else if(response == 0)
            return;
        else
        {
                std::cerr << "Invalid response: " << --login_attempts << " attempts left\n";
        }
            
    }

    
}