#ifndef HEAD_HPP
#define HEAD_HPP
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <limits>
void saveFile(std::vector<char> content,std::string filename);
std::vector<char> storeTheCode(std::string incode);
char XORCipher(char letter,char key);
char CaeserdeCipher(char letter,int key1);
char CaeserenCipher(char letter,int key1);
std::string readFile(std::string filename);

#endif