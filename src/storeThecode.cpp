#include<iostream>
#include<string>
#include<vector>
#include "head.hpp"

using namespace std;
vector<char> storeTheCode(string incode){
    vector<char> outcode;
   for (char c:incode){
       outcode.push_back(c);
  }
    return outcode;
}