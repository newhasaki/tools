//
//  scanning.h
//  tools
//
//  Created by mac on 2019/10/29.
//  Copyright © 2019 mac. All rights reserved.
//

#ifndef scanning_h
#define scanning_h
#include<iostream>
#include <vector>

struct token{
    std::string value;
    int type;
};


struct parse_node{
    token tk;
    parse_node* left;
    parse_node* right;
};

typedef enum{
    VARIABLE,MUL,PLUS,
    SUB,DIV,LP,RP,SEM
    ,ERROR
}TokenType;


std::vector<token> scanning(std::string str);

#endif /* scanning_h */
