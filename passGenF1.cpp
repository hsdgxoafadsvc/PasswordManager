#include <iostream>

int main()
{
    unsigned short passLen = 0;
    std::cout << "Enter password legnt: ";
    std::cin >> passLen;
    srand(time(nullptr));
    std::string data = "0123456789";
    std::string _data = data;
    std::string password;
    std::string minus = "-";
    unsigned short id = rand() % data.size();
    
    std::cout << _data << std::endl;
    
    for (unsigned short i = 0; i < passLen; i++)
	{
		password += _data[id];
		_data.replace(id, 1, minus);
		
		do{
		    id = rand() % _data.size();
		}while(_data[id] == minus[0]);
	}
	
	std::cout << _data << std::endl;

	// длина пароля не может превышать количество симвлов

	std::cout << "Your password: " << password;  
    return 0;
}