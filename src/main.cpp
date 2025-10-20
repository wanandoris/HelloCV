#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <limits>// 清除输入缓冲区
#include "head.hpp"
using namespace std;
int main(){
    string incode,inputFile;
    int secretKey;
    int length;
    int option1,option2;
    string outputfilename = "encrypted.txt";
    vector<char> outcode;
    vector<char> outputfile;
    cout <<"欢迎使用"<< endl;
    cout <<"请选择输入类型："<< endl;
    cout <<"输入文本请按1,输入文件请按2"<< endl;
    start1:cin >>option1;
    if(option1<1||option1>2){
        cout <<"请按指示输入"<< endl;
        goto start1;
    }
    cout <<"请选择你要进行的操作："<< endl;
    cout <<"Caesar加密请按1,Caeser解密请按2,XOR加密请按3,XOR解密请按4,回退到上一页面请按5"<< endl;
    start2:cin >>option2;
    if(option2<=0||option2>=6){
        cout <<"请按指示输入"<< endl;
        goto start2;
    }
    else if(option2==5){
         cout <<"输入文本请按1,输入文件请按2"<< endl;
        goto start1;
    }
    switch(option1){
        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
            cout <<"请输入文本：";
            getline(cin,incode);
            cout <<"请输入密钥：";
            cin >>secretKey;
            outcode=storeTheCode(incode);
            length=incode.length();
            switch(option2){
            case 1:
                cout <<"加密结果：";
                for(int i=0;i<length;i++){
                    outcode[i]=CaeserenCipher(outcode[i],secretKey);
                    cout <<outcode[i];
                }
                break;
            case 2:
                cout <<"解密结果：";
                for(int i=0;i<length;i++){
                    outcode[i]=CaeserenCipher(outcode[i],secretKey);
                    cout <<outcode[i];
                }
                break;
            case 3:
                cout <<"加密结果：";
                for(int i=0;i<length;i++){
                    outcode[i]=XORCipher(outcode[i],secretKey);
                    cout <<outcode[i];
                }
                break;
            case 4:
                cout <<"解密结果：";
                for(int i=0;i<length;i++){
                    outcode[i]=XORCipher(outcode[i],secretKey);
                    cout <<outcode[i];
                }
                break;
            case 5:
                cout <<"输入文本请按1,输入文件请按2"<< endl;
                goto start1;
            }
        break;
        case 2:
            cout <<"请输入文件路径：";
            cin >>inputFile;
            cout <<"请输入密钥：";
            cin >>secretKey;
            string content=readFile(inputFile);
            length=content.length();
            outputfile=storeTheCode(content);
            switch(option2){
            case 1:
                for(int i=0;i<length;i++){
                    outputfile[i]=CaeserenCipher(outputfile[i],secretKey);
                }
                saveFile(outputfile, outputfilename);
                cout <<"加密结果已保存到:encrypted.txt";
                break;
            case 2:
                for(int i=0;i<length;i++){
                    outputfile[i]=CaeserdeCipher(outputfile[i],secretKey);
                }
                saveFile(outputfile, outputfilename);
                cout <<"解密结果已保存到:encrypted.txt";
                break;
            case 3:
                for(int i=0;i<length;i++){
                    outputfile[i]=XORCipher(outputfile[i],secretKey);
                }
                saveFile(outputfile, outputfilename);
                cout <<"加密结果已保存到:encrypted.txt";
                break;
            case 4:
                for(int i=0;i<length;i++){
                    outputfile[i]=XORCipher(outputfile[i],secretKey);
                }
                saveFile(outputfile, outputfilename);
                cout <<"解密结果已保存到:encrypted.txt";
                break;
            }
        break;
    }
    return 0;
}
