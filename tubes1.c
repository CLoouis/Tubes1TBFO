#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char T[10];
} state;

state arrOfState[100];

void menuAwal();
bool isMenang(state q);
bool isSeri(state q);
void tulisState(state q);
void pindahState(state *q, int i);


int main(){
    int pilihan;
    int i;
    int j;
    state qSekarang; //Menampung state yang sedang terjadi sekarang
    state q;


    menuAwal();
    printf("\n>>");
    scanf("%d",&pilihan);
    if (pilihan == 1){ //Komputer jalan duluan
        //Buat qSekarang
        qSekarang.T[0] = 'A';
        qSekarang.T[1] = 'A';
        qSekarang.T[2] = 'A';
        qSekarang.T[3] = 'A';
        qSekarang.T[4] = 'O';
        qSekarang.T[5] = 'A';
        qSekarang.T[6] = 'A';
        qSekarang.T[7] = 'A';
        qSekarang.T[8] = 'A';
        qSekarang.T[9]= '\0';
    } else {
        //Buat qSekarang
        qSekarang.T[0] = 'A';
        qSekarang.T[1] = 'A';
        qSekarang.T[2] = 'A';
        qSekarang.T[3] = 'A';
        qSekarang.T[4] = 'X';
        qSekarang.T[5] = 'A';
        qSekarang.T[6] = 'O';
        qSekarang.T[7] = 'A';
        qSekarang.T[8] = 'A';
        qSekarang.T[9]= '\0';
    }

    tulisState(qSekarang);
    arrOfState[1] = qSekarang;
    j = 2;

    while (!isMenang(qSekarang) && !isSeri(qSekarang)){
        printf("Giliran Anda : ");
        scanf("%d",&i);

        pindahState(&qSekarang,i);
        tulisState(qSekarang);
        arrOfState[j] = qSekarang;
        j += 1;
        printf("\n");
    }

    if (isMenang(qSekarang)){
        printf("Permainan selesai, Komputer menang, cupu lu\n");
    } else if (isSeri(qSekarang)){
        printf("Permainan selesai, imbang coy\n");
    }

    for (i = 1;i < j;i++){
        printf("%s\t",arrOfState[i]);
    }

    return 0;
}

void menuAwal(){
//Prosedur untuk menampilkan menu di awal permainan
    printf("---------------------------------\n");
    printf("---------- TIC TAC TOE ----------\n");
    printf("---------------------------------\n");
    printf("\n");
    printf("Siapa yang mau bermain duluan ?\n1.Komputer\n2.User\n");
}

bool isMenang(state q){
//Mengembalikan true bila state q merupakan final state dan dalam kondisi komputer
//menang
    FILE *pFile;
    char stateSebaris[100];
    char stateMenang[10] = "WWWWWWWWW";
    state qcek;
    state q1;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 101, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,q.T) == 0){
                memcpy(q1.T, &stateSebaris[10],9);
                q1.T[9] = '\0';
                if (strcmp(q1.T,stateMenang) == 0){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    fclose(pFile);
}

bool isSeri(state q){
//Mengembalikan true apabila state q merupakan final state dan dalam kondisi
//permainan berakhir imbang.
    FILE *pFile;
    char stateSebaris[100];
    char stateSeri[10] = "SSSSSSSSS";
    state qcek;
    state q1;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 101, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,q.T) == 0){
                memcpy(q1.T, &stateSebaris[10],9);
                q1.T[9] = '\0';
                if (strcmp(q1.T,stateSeri) == 0){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    fclose(pFile);
}

void tulisState(state q){
//Menampilkan state q ke layar berupa papan permainan tictactoe
    int i;
    for (i=0;i <= 8;i++){
        if (q.T[i] == 'A'){
            q.T[i] = ' ';
        }
    }

    printf("%c | %c | %c\n",q.T[0],q.T[1],q.T[2]);
    printf("----------\n");
    printf("%c | %c | %c\n",q.T[3],q.T[4],q.T[5]);
    printf("----------\n");
    printf("%c | %c | %c\n",q.T[6],q.T[7],q.T[8]);
}

void pindahState(state *q, int i){
//Merubah state q menuju state jika diinput i
    FILE *pFile;
    int j;
    char stateSebaris[100];
    state qcek;
    state qi;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 101, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,(*q).T) == 0){
                memcpy(qi.T, &stateSebaris[10*i],9);
                qi.T[9] = '\0';

                *q = qi;
                break;
            }

        }
    }
    fclose(pFile);
}
