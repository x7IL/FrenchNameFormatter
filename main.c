#include <unistd.h>
#include <stdio.h>

//./a.out "JeAN-MICHEL don diEgo De la vega" | cat -e
//./a.out >/dev/null || echo "Exit status: $?"
void putcharr(char n){
    write(1,&n,1);
}

int spe(){
    write(1," ",1);
    return 1;
}

int main(int argc, char ** argv) {

    int a = 0;
    if(argv[1] == NULL){
        write(2,"Usage: frenchNameFormatter string\n",36);
        return 84;
    }
    for(int i = 0; argv[1][i]!='\0';i++){
        (a==0) ? (argv[1][i] == ' ') ? (a = spe()) : (i == 0 & argv[1][i] >= 65 & argv[1][i] < 97) ?
        putcharr(argv[1][i]) :
        ((argv[1][i - 1] <= 65 & argv[1][i - 1] >= 97) & (argv[1][i - 1] <= 97 & argv[1][i - 1] >= 122))?
        putcharr(argv[1][i]) :
        ((argv[1][i - 1] >= 65 & argv[1][i - 1] <= 97) & (argv[1][i] >= 65 & argv[1][i] <= 90))
        ? putcharr(argv[1][i] + 32) :
        ((argv[1][i - 1] >= 97 & argv[1][i - 1] <= 122) & (argv[1][i] >= 65 & argv[1][i] <= 90))
        ? putcharr(argv[1][i] + 32) :
        putcharr(argv[1][i])
        :(argv[1][i] >= 97 & argv[1][i] <=122) ? putcharr(argv[1][i] - 32)
        :putcharr(argv[1][i]);
    }
    return 0;
}
