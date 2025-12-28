#pragma once

struct Node {
    int val;
    Node *next;
};

using List =  Node*;

void add_node (List& m, List n);
void delete_node (List& m, List n);
void print_list (List m);
int find_value (List m, int val);

