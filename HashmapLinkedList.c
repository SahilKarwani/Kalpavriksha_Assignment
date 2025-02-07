#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
 
typedef struct Node{
    int key;
    int val;
    struct Node* next;
}Node;
 
void insertion(Node* hashMap[]){
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    int val;
    printf("Enter val:");
    scanf("%d", &val);
    int index=key%(MAX_SIZE);
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->key=key;
    newNode->val=val;
    if(hashMap[index]==NULL){
        hashMap[index]=newNode;
        return;
    }else{
        Node* temp=hashMap[index];
        hashMap[index]=newNode;
        newNode->next=temp;
    }
}
 
void searchValue(Node* hashMap[]){
    int key;
    printf("Enter key: ");
    scanf("%d",&key);
    int index=key%MAX_SIZE;
    Node* temp=hashMap[index];
    if(temp==NULL){
        printf("Invalid Key\n");
    }else{
        int flag=1;
        while(temp!=NULL){
            if(temp->key==key){
                flag=0;
                printf("Value: %d\n",temp->val);
                break;
            }
            temp=temp->next;
        }
        if(flag){
           printf("Invalid Key\n"); 
        }
    }
    return;
}
 
void deleteValue(Node* hashMap[]){
    int key;
    printf("Enter key:");
    scanf("%d",&key);
    int index=key%MAX_SIZE;
    Node* temp=hashMap[index];
    if(temp==NULL){
       printf("Can't delete, Invalid Key\n");
       return;
    }
    if(temp->next==NULL){ // single node for this index
        if(temp->key==key){
        free(temp);
        printf("Key %d deleted\n",key);
        hashMap[index]=NULL;
        return;
        }else {
            printf("Can't delete, Invalid Key\n");
            return;
        }
    }
    Node* prev=temp;
    temp=temp->next;
    while(temp!=NULL){
        if(temp->key==key){ // delete this key
            prev->next=temp->next;
            printf("Key %d deleted\n",key);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Can't delete, Invalid Key\n");
}
 
void displayValue(Node* hashMap[]){
    int flag=1;
    for(int i=0; i<MAX_SIZE; i++){
        if(hashMap[i]!=NULL){
            flag=0;
            Node* temp=hashMap[i];
            int flag=1;
            printf("Index %d:",i);
            while(temp!=NULL){
                if(flag){
                    flag=0;
                    printf("(%d,%d)", temp->key, temp->val);
                }else{
                     printf("->(%d,%d)", temp->key, temp->val);
                }
                temp=temp->next;
            }
            printf("\n");
        }
    }
    if(flag){
        printf("Empty Hashmap\n");
    }
}
 
void intialize(Node* hashMap[]){
    for(int i=0; i<MAX_SIZE; i++){
        hashMap[i]=0;
    }
}
 
int main() {
    Node* hashMap[MAX_SIZE];
    intialize(hashMap);
    int n;
    printf("Enter number of operations:");
    scanf("%d", &n);
    while(n--){
       int choice;
       printf("Enter the choice of operation you want to perform");
       printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            insertValue(hashMap);
            break;
            case 2:
            searchValue(hashMap);
            break;
            case 3:
            deleteValue(hashMap);
            break;
            case 4:
            displayValue(hashMap);
            break;
            case 5:
            printf("Exit\n");
            return 0;
            default:
            printf("Invalid.\n");
        }
    }
 
    return 0;
}
