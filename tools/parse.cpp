//
//  parse.cpp
//  tools
//
//  Created by mac on 2019/10/29.
//  Copyright © 2019 mac. All rights reserved.
//

#include "parse.h"

static int token_index = -1;


parse_node* exp(std::vector<token>&);


void post_order_traversal_free(parse_node* node){
    if(nullptr == node->left&&nullptr == node->right){
        free(node);
        node = nullptr;
        return;
    }
    
    post_order_traversal_free(node->left);
    post_order_traversal_free(node->right);
    free(node);
    node = nullptr;
}

void in_order_traversal(parse_node* node){
    if(node->tk.type == VARIABLE){
        std::cout<<node->tk.value;
        return;
    }
    
    in_order_traversal(node->left);
    std::cout<<node->tk.value;
    in_order_traversal(node->right);
    
    
}

parse_node* factor(std::vector<token>& tk){
    
    token_index++;
    
    if(tk.at(token_index).type == VARIABLE){
        parse_node* node = (parse_node*)malloc(sizeof(parse_node));
        node->tk = tk.at(token_index);
        node->left = nullptr;
        node->right = nullptr;
        token_index++;
        return node;
        
    }else if(tk.at(token_index).type == LP){
        parse_node* node = exp(tk);
        token_index++;
        return node;
    }
    return nullptr;
}

parse_node* term(std::vector<token>& tk){
    parse_node* left_node = factor(tk);
    if(tk.at(token_index).type == SEM
       ||tk.at(token_index).type == RP){
        return left_node;
    }
   
    while(tk.at(token_index).type == MUL
          ||tk.at(token_index).type == DIV){
        parse_node* root = (parse_node*)malloc(sizeof(parse_node));
        switch (tk.at(token_index).type) {
            case MUL:
                root->tk = tk.at(token_index);
                root->left = left_node;
                root->right = factor(tk);
                left_node = root;
                break;
            case DIV:
                root->tk = tk.at(token_index);
                root->tk.type = DIV;
                root->left = left_node;
                root->right = factor(tk);
                left_node = root;
                break;
            default:
                break;
        }
    }
    return left_node;
}

parse_node* exp(std::vector<token>& tk){
    parse_node* left_node = term(tk);
    
    if(tk.at(token_index).type == RP
       ||tk.at(token_index).type == SEM){
        return left_node;
    }
    
    while(tk.at(token_index).type == PLUS
             ||tk.at(token_index).type == SUB){
           parse_node* root = (parse_node*)malloc(sizeof(parse_node));
           switch (tk.at(token_index).type) {
               case PLUS:
                   root->tk = tk.at(token_index);
                   root->left = left_node;
                   root->right = term(tk);
                   left_node = root;
                   break;
               case SUB:
                   root->tk = tk.at(token_index);
                   root->left = left_node;
                   root->right = term(tk);
                   left_node = root;
               default:
                   break;
           }
       }
       return left_node;
}

parse_node* parse(std::vector<token> tk){
    parse_node* node = nullptr;
    node = exp(tk);
    return node;
}
