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
    std::string str("((v48 * v34)+ (((((v19 * (v2 * v14)) * v34)+ ((v44 * v34)+ ((((v40 * v35)+ ((v35 * v39)+ ((((v32 * v35) + ((v10 * v28) + ((((v10 * v25) + ((v23 * v10) + ((((v9 * ((v2 * v14) * v11 )) + ((((v8 * v9) - (v9 * v12)) - (v9 * v17)) + (v9 * v19))) - (v9 * v20)) - (v22 * v10)))) - (v10 * v26)) - (v10 * v27))))- (v36 * v35))- (v38 * v35))))- (v35 * v41))- (v42 * v34))))- (v46 * v34))- (v47 * v34)));");   //测试表达式
    
    std::vector<token> tokens = scanning(str); //词法分析生成token流
    
    parse_node* node = parse(tokens);   //语法分析，生成抽象语法树，语法树中已处理完优先级
    
    in_order_traversal(node);           //中序遍历语法树
    post_order_traversal_free(&node);    //后序遍历释放树节点内存
    
    return 0;
}
