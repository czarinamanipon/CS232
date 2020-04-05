char password[8] = "secret";
int main() {
    char input[8];
    int length;
    printf("please enter your password\n");
    scanf("%s", input);

   for(length = 0; length <= 7; length++) {
        if((input[length] >= 65) && (input[length] <= 90)){
            input[length] = input[length] + 32;
        }
        
    }
    if(strcmp(input, password) == 0){
        return 0;
    }else{
        return -1;
    }
    
}