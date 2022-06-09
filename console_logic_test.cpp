#include <iostream>
#include <string>
int main()
{
    srand(time(nullptr));
    std::string data = "0123456789";
    std::string mask = "1111523012345";
    std::string password;
    if (data.size() > mask.size()){
        while(data.size() != mask.size()){
            mask.push_back('0');
        }
    }
    if (data.size() < mask.size()){
        while(data.size() != mask.size()){
            mask.erase(data.size(), 1);
        }
    }
    std::string data_buff = data;
    std::string mask_buff = mask;
    unsigned short max_pas_len = 0;
    for (auto i: mask){
        max_pas_len += (unsigned (short(i)) - 48);
    }
    std::cout << "Use data: " << data << std::endl;
    std::cout << "Use mask: " << mask << std::endl;
    std::cout << "Max password legnt: " << max_pas_len << std::endl;
    unsigned short passLen = 0;
    std::cout << "Enter password legnt: ";
    std::cin >> passLen;
    if (passLen > max_pas_len) passLen = max_pas_len;
    std::cout << "Use password legnt: " << passLen << std::endl;
    
//  use rand
//    std::string minus = "-";
//  for (unsigned short i = 0, id = 0; i < passLen; i++){
// 	    do{
// 		    id = rand() % _data.size();
// 		}while(_data[id] == minus[0]);
// 		password += _data[id];
// 		_data.replace(id, 1, minus);
// 	}

//	use erase
// 	for (unsigned short i = 0, id = 0; i < passLen; i++){
// 		id = rand() % _data.size();
// 		password += _data[id];
// 		_data.erase(id, 1);
// 	}
	
// wich mask
	for (unsigned short i = 0, id = 0; i < passLen; i++){
	    new_id:
		id = rand() % data_buff.size();
		int mask_id_value = (int(mask[id]) - 48);
		if (mask_id_value == 0){
		   data_buff.erase(id, 1);
		   mask.erase(id, 1);
		   goto new_id;
		}
		password += data_buff[id];
		mask[id] -= 1;
	}
	
	std::cout << "Your password: " << password << std::endl;  
}