/*
Shai Dahan && Sarel Alush
209462712  &&   316373851
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


char word_tolower(char* str){
    while(*str)
    {
        if (*str >= 'A' && *str <= 'Z'){
            *str = *str+32;
        }
        str++;
    }    
}

long hash_arr(const char str[]){
    unsigned long h = 5381;
    int i;
    for(i=0;str[i];i++){
        h=h*33 +str[i];
    }
    return h;
}

long hash_ptr(const char* str){
    unsigned long h = 5381;
    for(;*str;str++){
        h=h*33 +(*str);
    }
    return h;
}

//check again!
bool is_legal_word(const char *str){

    while(*str){
        if(!((*str >= 'a' && *str <='z') || (*str >= 'A' && *str <= 'Z'))){
            return false;
        }
        str++;
    }
    return true;
}

int main() {
    char word_hash [500000] = {};
    char options [10] = {};
    char word [64] = {};
    int exit = 1;
    int opt = 0;


    while (exit == 1){ 

        printf("$ ");
        if (scanf("%s %s",options ,word ) == 2)
        {
            if(strcmp(options,"ADD") == 0)
                opt = 1;
            else if(strcmp(options,"CHECK") == 0)
                opt = 2;
            else if(strcmp(options,"EXIT") == 0){
                opt = 3;
            }
            else{
                opt =0;
            }
            
            switch (opt)
            {
            case 1:
                 if(is_legal_word(word))
                {
                    word_tolower(word);
                    long i = hash_ptr(word);
                    word_hash[i%500000] = 1;
                }
                else
                {
                    printf("illegal command\n");
                }
                break;
            case 2:
                if(is_legal_word(word))
                {
                    word_tolower(word);
                    long i = hash_ptr(word);
                    if(word_hash[i%500000] == 1){
                        printf("exists\n");
                    }
                    else{
                        printf("does not exist\n");
                    }
                }
                break;
            case 3:
                exit =0;
                break;

            default:
                printf("illegal command\n");
                break;
            }
        }
    }
    return 0;
}