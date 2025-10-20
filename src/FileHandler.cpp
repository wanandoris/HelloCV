#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "head.hpp"
using namespace std;
string readFile(string filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("无法打开文件: " + filename);
    }
    string content;
    file.seekg(0, ios::end);
    content.resize(file.tellg());
    file.seekg(0, ios::beg);
    file.read(&content[0], content.size());
    file.close();
    
    return content;
}

void saveFile(vector<char> content,string filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("无法创建文件: " + filename);
    }
    
    file.write(content.data(), content.size());
    file.close();
}