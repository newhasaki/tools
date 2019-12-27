//
//  main.cpp
//  tools
//
//  Created by mac on 2019/10/29.
//  Copyright © 2019 mac. All rights reserved.
//

#include "scanning.h"
#include "parse.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::string str("((((v9 * v50) - (v9 * (v6 * v5))) + ((v5 * v7) * v10)) - (v10 * v62)) - ((v14 * v7) * v34);");   //测试表达式
    
    std::vector<token> tokens = scanning(str); //词法分析生成token流
    
    parse_node* node = parse(tokens);   //语法分析，生成抽象语法树，语法树中已处理完优先级
    
    in_order_traversal(node);           //中序遍历语法树
    std::cout<<std::endl;
    post_order_traversal_free(&node);    //后序遍历释放树节点内存
    
    return 0;
}
