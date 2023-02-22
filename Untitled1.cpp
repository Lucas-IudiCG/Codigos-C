#include<stdio.h>
#include<conio.h>
#include<dirent.h>
#include <stdlib.h>
#include <string.h>

#define INDEX 100
#define IDNAME 31
#define PATH 100



struct bin_tree {
  char id[IDNAME + 1];
  char path[PATH + 1];
  char tipo;
  struct bin_tree *dir_ant;
  struct bin_tree *prox[INDEX];
};
typedef struct bin_tree node;

char* PathMaker(char* path,char*maker){
	char* caminho=strcat(path,maker);
	
	return caminho;
}

void insert(node **tree, char* val, char type,int indice,char *caminho) {
  node *temp = NULL;
  if (!(*tree)) {
    temp = (node *)malloc(sizeof(node));
    temp->dir_ant = temp->prox[0] = NULL;
    for (int i = 0; i < IDNAME; i++)
      temp->id[i] = val[i];
    temp->tipo = type;
     for (int i = 0; caminho[i] != '\0'; i++)
        {
    temp->path[i]=caminho[i];
}
    *tree = temp;
  }
  else {
    temp = (node *)malloc(sizeof(node));
    temp->dir_ant = (*tree);
    for (int i = 0; i < IDNAME; i++)
      temp->id[i] = val[i];
    temp->tipo = type;
    for (int i = 0; caminho[i] != '\0'; i++)
        {
    temp->path[i]=caminho[i];
}
    (*tree)->prox[indice] = temp;
  }
}

int ValidateString (char *B){
        int i;
        for (i = 0; B[i] != '\0'; i++)
        {
               if (B[i]=='.')
              {
                    return 1;
              }
       }
       return 0;
}

void Print(node *tree) {
  printf("\nPrintando\n");
  if (tree) {
    printf("%s\n", tree->id);
    for (int i = 0;i<INDEX; i++) {
    	if(tree->prox[i]->id!=NULL)
        printf("%s\n", tree->prox[i]->id);
  }
  }
}

node *Prox_Dir(node *tree, int indice) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp = tree->prox[indice];
  return temp;
}

node *Ant_Dir(node *tree) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp = tree->dir_ant;
  return temp;
}



void Read_Dir(node *tree,char *Path){

   DIR *dir;
   dir=opendir(Path);

  struct dirent *dent;

  if(dir!=NULL)
   {
    int i=0;
       while((dent=readdir(dir)))
         {
         	
            printf(dent->d_name);
            if(ValidateString(dent->d_name)){
            printf("\t Arquivo\n");
            insert(&tree,dent->d_name,'a',i,Path);

            }
            else{
            printf("\t Diretorio\n");
            insert(&tree,dent->d_name,'d',i,Path);

            }
            i++;
        }
    }
    else
            printf("ERROR OPENIN DIRECTORY");
}


void Dir(node *tree,char *Path){
    printf("\nF:");
    printf(tree->id);
}
int main(){
    node *root;
    root = NULL;
    char* DIR_PATH="D:";
    insert(&root, "/", 'd',0,DIR_PATH);
    Read_Dir(root,DIR_PATH);
    printf("\n");
    Print(root);
    root=Prox_Dir(root,2);
    Read_Dir(root,"D:\Ferramentas\ ");
    Print(root);
    root=Ant_Dir(root);
    printf("\n");
    root=Prox_Dir(root,3);
	Read_Dir(root,"D:\MACK\ ");
	Print(root);
	root=Ant_Dir(root);
	printf("\n");
    root=Prox_Dir(root,2);
	Print(root);
	root=Ant_Dir(root);
	printf("\n");
    Print(root);
    return 0;

}


