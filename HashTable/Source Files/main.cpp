#include "../Header Files/menu.h"
#include "../Header Files/Dictionary.h"
#include <iostream>
#include <limits>

void InvalidInput();

int main()
{
    Dictionary dict;
    bool exit = false;

    while (!exit) 
    {
        ShowMenu();
        int choice;
        std::cin >> choice;

        std::string key, value;
        bool rehashed = false;

        if (std::cin.fail()) 
        {
            InvalidInput(); 
            continue;       
        }

        switch (choice) 
        {
        case 1: 
            key = GetKey();
            std::cout << "Enter value: ";
            std::cin >> value;
            rehashed = dict.Add(key, value);

            if (rehashed) 
            {
                std::cout << "Rehashing occurred. Table size increased.\n";
            }
            else 
            {
                std::cout << "Added successfully!\n";
            }
   
            break;

        case 2: 
            key = GetKey();
            if (dict.Delete(key, value))
            {
                std::cout << "Removed value: " << value << "\n";
            }
            else {
                std::cout << "Key not found!\n";
            }
            break;

        case 3: 
            key = GetKey();
            if (dict.Search(key, value)) 
            {
                std::cout << "Value: " << value << "\n";
            }
            else {
                std::cout << "Key not found!\n";
            }
            break;


        case 4: 
            ShowHashTable(dict.GetHashTable());
            break;

        case 5: 
            exit = true;
            break;

        default: 
            InvalidInput();
        }
    }

    return 0;
}


void InvalidInput()
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Unknown command. Please enter a valid choice.\n";
}
