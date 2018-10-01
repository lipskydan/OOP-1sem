//
//  main.cpp
//  task34
//
//  Created by Danial on 26.09.2018.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>

#include "BTree.hpp"
//#include "BTree.hpp"

using namespace std;



int main() {
    BTree root(10);
    root.add_to_tree(15);
    root.add_to_tree(11);
    root.add_to_tree(5);
    root.add_to_tree(22);
    root.add_to_tree(105);
    root.add_to_tree(50);
    root.add_to_tree(17);
    root.add_to_tree(25);
    root.add_to_tree(7);
    
    root.show_tree();
    
    return 0;
}
