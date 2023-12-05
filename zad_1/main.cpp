#include <iostream>
#include <locale>
#include <cctype>
#include <codecvt>
#include <typeinfo>
#include "modAlphaCipher.cpp"
using namespace std;

void check(const wstring& Text, const wstring& key)
{ 
	 wstring cipherText;
     wstring decryptedText;
     modAlphaCipher cipher(key);
     cipherText = cipher.encrypt(Text);
     decryptedText = cipher.decrypt(cipherText);
     wcout<<L"key="<<key<<endl;
     wcout<<Text<<endl;
     wcout<<cipherText<<endl;
     wcout<<decryptedText<<endl;
}
	
int main(int argc, char **argv)
{ 	
try{
	locale loc("ru_RU.UTF-8");
    locale::global(loc);
	check(L"РОССИЯНЕ",L"НЕАМЕРИКАНЦЫ");
	check(L"АМЕРИКАНЦЫ",L"НЕРОССИЯНЕ");
	//check(L"АМЕРИКАНЦЫ",L"AMERICA");
	check(L"АМЕРИКАНЦЫ",L"A123");
}catch(std::invalid_argument& e){
       std::wcout <<"Error" << std::endl;
}
return 0;
}
