#include<stdio.h>
#include<stdlib.h>
struct node{
    char name[20];
    int count;
    struct node *child[10];
};
struct node* root=NULL;

void create();
void display();

int main()
{
    int choice;
    while(1)
    {
        printf("1. Create \n2. Display \n3. Quit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
            default: printf("Enter a valid choice\n");
                    break;
        }
    }
}

void create()
{
    int i,j,k,chp_count,sec_count,sub_count;
    root=(struct node*)malloc(sizeof(struct node));
    printf("Enter name of the Book: ");
    scanf("%s",root->name);
    printf("Enter the no. of chapter (max 10): ");
    scanf("%d",&chp_count);
    root->count=chp_count;
    for(i=0;i<chp_count;i++)
    {
        root->child[i]=(struct node*)malloc(sizeof(struct node));
        printf("Enter the name of the chapter %d: ",i+1);
        scanf("%s",root->child[i]->name);
        printf("Enter the no. of sections in the chapter %d: ",i+1);
        scanf("%d",&sec_count);
        root->child[i]->count=sec_count;

        for(j=0;j<sec_count;j++)
        {
            root->child[i]->child[j]=(struct node*)malloc(sizeof(struct node));
            printf("Enter the name of Section %d: ",j+1);
            scanf("%s",root->child[i]->child[j]->name);

            printf("Enter the no. of subsection in Section %d: ",j+1);
            scanf("%d",&sub_count);
            root->child[i]->child[j]->count=sub_count;
            for(k=0;k<sub_count;k++)
            {
                root->child[i]->child[j]->child[k]=(struct node*)malloc(sizeof(struct node));
                printf("Enter the name of the subsection %d: ",k+1);
                scanf("%s",root->child[i]->child[j]->child[k]->name);
            }

        }

    }

}

void display()
{
    printf("\n------------------Heirarchy----------------\n\n ");
    int i,j,k;
    printf("Book Name: %s\n",root->name);
    for(i=0;i<root->count;i++)
    {
        printf("Chapter %d: %s \n",i+1,root->child[i]->name );
        for(j=0;j<root->child[i]->count;j++)
        {
            printf("Section %d: %s \n",j+1,root->child[i]->child[j]->name);
            for(k=0;k<root->child[i]->child[j]->count;k++)
            {
                printf("Subsection %d: %s \n",k+1,root->child[i]->child[j]->child[k]->name);

            }
        }

    }
}