#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Hocam  printf("Enter D(Delete), I(Insert), F(Find) or Q(Quit)> ") bu kod sürekli iki defa çalýþýyor nasýl düzeltebilirim acaba? Neyden kaynaklandýðýný anlayamadým.


int find(char *str, char *find_);
char* deleted(char *str,char *del);
char* insertion(char *str,char *insert,int index);


int main()
{   char find_[40];
    char del[40];
    char insert[40];
    int insert_index;
    char command=' ';
    char source[80];
    printf("Enter the source string:\n>");
    gets(source);
    int source_len = strlen(source);
    while(command!='Q'){
        printf("Enter D(Delete), I(Insert), F(Find) or Q(Quit)> ");
        scanf("%c",&command);
        switch (command){
            case 'F':
                printf("String to find> ");
                scanf("%s",find_);
                printf("'%s' found at position %d\n\n",find_,find(source,find_));
                break;

            case 'D':
                printf("String to delete> ");
                scanf("%s",del);
                printf("New source is: %s\n\n",deleted(source,del));
                break;

            case 'I':
                printf("String to insert> ");
                scanf("%s",insert);
                printf("Position of insertion> ");
                scanf("%d",&insert_index);
                printf("New source: %s\n\n",insertion(source,insert,insert_index));
                break;

            case 'Q':
                break;
        }
    }

    return 0;
}

int find(char *str, char *find_){
    int comp;
    int len_str = strlen(str);
    int len_find = strlen(find_);
    char copy1[len_find];
    int i;
    for(i=0;i<len_str;i++){
        if(str[i] == find_[0]){
            strncpy(copy1,&str[i],len_find);
            copy1[len_find]='\0';
            comp = strcmp(copy1,find_);
            if(comp==0) return i;
        }
    }
    return -1;

}

char* deleted(char *str,char *del){
    int length_str = strlen(str);
    int length_del = strlen(del);
    int index_del = find(str,del);
    char copy1[80];
    strncpy(copy1,str,index_del);
    copy1[index_del]='\0';
    strcat(copy1,&str[index_del+length_del]);
    strcpy(str,copy1);
    return str;
}
char* insertion(char *str,char *insert,int index){
    char copy1[80];
    strncpy(copy1,str,index+1);
    copy1[index+1]='\0';
    strcat(copy1,insert);
    strcat(copy1,&str[index]);
    strcpy(str,copy1);
    return str;

}





