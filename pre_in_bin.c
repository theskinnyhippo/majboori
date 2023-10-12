#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int search(int* arr, int s, int e, int value){
    int i;
    for (i = s; i <= e; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}


struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


int validity_check(int a, int* b, int n){
    int i;
    for(i=0; i<n; i++){
        if(a==*(b+i)){
            return 1;
        }
    }
    return 0;
}


struct node* build_tree(int* in, int* pre, int first, int last){
    static int preIndex = 0;

    if (first > last)
        return NULL;

    struct node* n = newNode(pre[preIndex++]);

    if (first == last)
        return n;

    int inInd = search(in, first, last, n->data);

    n->left = build_tree(in, pre, first, inInd - 1);
    n->right = build_tree(in, pre, inInd + 1, last);

    return n;
}



void printInorder(struct node* node){
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int len, i, *in, *pre;
    printf("Enter the size of arrays : ");
        scanf("%d", &len);

    in = (int*)malloc(sizeof(int)*len);
    pre = (int*)malloc(sizeof(int)*len);

    printf("\nEnter Inorder array...\n");
    for(i=0; i<len; i++){
        scanf("%d", in+i);
    }

    printf("\nEnter Preorder array...\n");
    i = 0;
    while(i<len){
        scanf("%d", pre+i);
        while(validity_check(*(pre+i), in, len) != 1){
            printf("Invalid input\n try again : ");
            scanf("%d", pre+i);
        }
        i++;
    }
    
    struct node* root = build_tree(in, pre, 0, len - 1);

    printf("\nInorder traversal of the constructed tree is \n");
    printInorder(root);
}
