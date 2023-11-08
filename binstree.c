#include <stdio.h>
#include <stdlib.h>

struct key{
    int data;
    struct key* left;
    struct key* right;
};

struct key* create_key(int data){
    struct key* n = (struct key*)malloc(sizeof(struct key));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct key* insert(struct key* root, int data){
    if (root == NULL){
        return create_key (data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

struct key* search(struct key* root, int d){
    if(root == NULL || root->data == d){
        return root;
    }
    if(d < root->data){
        return search(root->left, d);
    }
    return search(root->right, d);
}


struct key* delete_key(struct key* root, int k){
    if(root == NULL){
        printf("No such key exists in the BST!!\n");
        return root;
    }
    
    if(root->data > k){
        root->left = delete_key(root->left, k);
        return root;
    }else if(root->data < k){
        root->right = delete_key(root->right, k);
        return root;
    }
    
    if(root->left == NULL){
        struct key* temp = root->right;
        root = NULL;
        return temp;
    }else if(root->right == NULL){
        struct key* temp = root->left;
        root = NULL;
        return temp;
    }else{
        struct key* root_ = root;
        struct key* succ = root->right;
        while (succ->left != NULL) {
            root_ = succ;
            succ = succ->left;
        }
        if(root_ != root){
            root_->left = succ->right;
        }else
            root_->right = succ->right;
            root->data = succ->data;
        succ = NULL;
        return root;
    }
}

void inOrder(struct key* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct key* inordersucc(struct key* root, int d){
    struct key* succ = NULL;

    while(root != NULL){
        if(d >= root->data){
            root = root->right;
        }else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

struct key* inorderpred(struct key* root, int d){
    struct key* pred = NULL;

    while(root != NULL){
        if(d <= root->data){
            root = root->left;
        }else{
            pred = root;
            root = root->right;
        }
    }
    return pred;
}

int main(){
    struct key* root = NULL;
    int i, choice, data, size;
    
    printf("Enter the number of keys : ");
    scanf("%d", &size);
    
    int* m = (int*) malloc (sizeof(int)* size);
    
    printf("\nEnter the Input array to construct a BST...\n --> ");
    for(i=0; i<size; i++){
        scanf("%d", (m+i));
    }
    for(i=0; i<size; i++){
        root = insert(root, *(m+i));
    }

    while (1){
        printf("\n\nWhat you wanna perform? \n\n");
        printf("1. Insert a node\n");
        printf("2. Display In-Order\n");
        printf("3. Find a key\n");
        printf("4. Find predecessor and succesor\n");
        printf("5. Delete a key\n");
        printf("6. Exit\n --> ");

        scanf("%d", &choice);



        switch (choice){
            case 1:
                printf("Enter data to insert : ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("BST (In-order traversal) : ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter key data : ");
                scanf("%d", &data);
                if (search(root, data) != NULL){
                    printf("key found!\n");
                } else{
                    printf("key not found.\n");
                }
                break;
            case 4:
                printf("Enter the key data : ");
                scanf("%d", &data);

                struct key* root_ = inorderpred(root, data);
                            root = inordersucc(root, data);


                
                if (search(root, data) != NULL){
                    printf("\nOutput...................\n");
                    if(root_ != NULL){
                        printf("predecessor = %d\n", root_->data);
                    }else{
                        printf("no predecessor found!\n");
                    }
                    if(root != NULL){
                        printf("   successor = %d\n", root->data);
                    }else{
                        printf("no successor found!\n");
                    }
                }else{
                    printf("\nNo valid data entered!(press 4 to enter again)");
                }
                break;
            case 5:
                printf("\nEnter data : ");
                    scanf("%d", &data);
                    root = delete_key(root, data);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
