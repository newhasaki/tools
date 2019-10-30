//
//  scanning.cpp
//  tools
//
//  Created by mac on 2019/10/29.
//  Copyright © 2019 mac. All rights reserved.
//
#include "scanning.h"


std::vector<token> scanning(std::string str){
    std::vector<token> tokens;
    for(size_t i = 0;i<str.length();++i){
        token tk;
        tk.type = ERROR;
        
        switch (str.at(i)) {
            case '*':
                tk.type = MUL;
                tk.value = '*';
                break;
            case '/':
                tk.type  = DIV;
                tk.value = '/';
                break;
            case '+':
                tk.type = PLUS;
                tk.value = '+';
                break;
            case '-':
                tk.type = SUB;
                tk.value = '-';
                break;
            case ')':
                tk.type = RP;
                tk.value = ')';
                break;
            case '(':
                tk.type = LP;
                tk.value = '(';
                break;
            case ';':
                tk.type = SEM;
                tk.value = ';';
                break;
            default:
                break;
        }
        
        if(tk.type!=ERROR){
            //std::cout<<tk.value<<std::endl;
            tokens.push_back(tk);
        }
        
        if(isalpha(str.at(i))){
           
            do{
                tk.value.push_back(str.at(i));
                i++;
            }while (isalnum(str.at(i)));
           
            i--; //for 循环中会加一
            tk.type = VARIABLE;
            
            //std::cout<<tk.value<<std::endl;
            tokens.push_back(tk);
        }
        
    }
    return tokens;
}
