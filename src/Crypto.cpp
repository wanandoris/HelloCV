#include<iostream>
#include<string>
#include<vector>
#include "head.hpp"
using namespace std;

char CaeserdeCipher(char letter,int key1){
    int key2=key1%26;
    if((int(letter)>=97&&int(letter)<=97+key2)||(int(letter)>=65&&int(letter)<=65+key2)){
        letter+=(26-key2);
    }
    else if((int(letter)>=98+key2&&int(letter)<=122)||(int(letter)>=66+key2&&int(letter)<=90)){
        letter-=key2;
    }
    return letter;
} 
char CaeserenCipher(char letter,int key1){
    int key2=key1%26;
    if((int(letter)>=97&&int(letter)<=122-key2)||(int(letter)>=65&&int(letter)<=90-key2)){
        letter+=key2;
    }
    else if((int(letter)>=123-key2&&int(letter)<=122)||(int(letter)>=91-key2&&int(letter)<=90)){
        letter-=(26-key2);
    }
    return letter;
} 
char XORCipher(char letter,char key){
    letter=letter^key;
    return letter;
}
