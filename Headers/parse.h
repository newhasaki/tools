//
//  parse.h
//  tools
//
//  Created by mac on 2019/10/29.
//  Copyright © 2019 mac. All rights reserved.
//

#ifndef parse_h
#define parse_h


#include "scanning.h"

parse_node* parse(std::vector<token> tk);
void in_order_traversal(parse_node*);
void post_order_traversal_free(parse_node**);

#endif /* parse_h */
