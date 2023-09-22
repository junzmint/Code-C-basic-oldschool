#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"

int main(){
    treeType root;
    treeType n1 = makeNewNode(1);
    treeType n2 = makeNewNode(2);
    treeType n3 = makeNewNode(3);
    treeType n4 = makeNewNode(4);
    treeType n5 = makeNewNode(5);
    treeType n6 = makeNewNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    root = n1;
    //drawTree(root);
    //bfs(root);
    root = reverseTree(root);
    drawTree(root);
    bfs(root);
    return 0;
}