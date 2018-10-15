#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Membuat tipe bentukan state yang merupakan array of char
typedef struct {
    char T[10];
} state;
//Deklarasi array untuk menampung state-state yang telah dilewati
state arrOfState[100];

void menuAwal();
bool isMenang(state q);
bool isSeri(state q);
void tulisState(state q);
void pindahState(state *q, int i);

int main(){
    int pilihan;
    int i,j;
    state qSekarang; //Menampung state yang sedang terjadi sekarang
    state q;

    menuAwal();
    printf("\n>> ");
    scanf("%d",&pilihan);

    //inisiasi start state
    qSekarang.T[0] = 'A';
    qSekarang.T[1] = 'A';
    qSekarang.T[2] = 'A';
    qSekarang.T[3] = 'A';
    qSekarang.T[4] = 'A';
    qSekarang.T[5] = 'A';
    qSekarang.T[6] = 'A';
    qSekarang.T[7] = 'A';
    qSekarang.T[8] = 'A';
    qSekarang.T[9] = '\0';

    //masukan pertama
    pindahState(&qSekarang,pilihan);

    tulisState(qSekarang);
    arrOfState[1] = qSekarang;
    j = 2;

    while (!isMenang(qSekarang) && !isSeri(qSekarang)){
        printf("\nMasukan nomor kotak yang ingin Anda beri tanda : ");
        scanf("%d",&i);

        pindahState(&qSekarang,i);
        tulisState(qSekarang);
        arrOfState[j] = qSekarang;
        j += 1;
    } //isMenang = true atau isSeri = true
    //Menampilkan status akhir permainan
    if (isMenang(qSekarang)){
        printf("\nPermainan telah selesai dan dimenangkan oleh komputer\n\n");
    } else if (isSeri(qSekarang)){
        printf("\nPermainan telah selesai dengan imbang\n\n");
    }
    //Menampilkan daftar state yang telah dilewati
    printf("Berikut ini ialah daftar state yang telah dilewati :\n");
    for (i = 1;i < j;i++){
        printf("%d. %s\n",i,arrOfState[i]);
    }

    printf("\nKetik sembarang angka untuk keluar : ");
    scanf("%d",&j);
    return 0;
}

void menuAwal(){
//Prosedur untuk menampilkan menu di awal permainan
    printf("---------------------------------\n");
    printf("---------- TIC TAC TOE ----------\n");
    printf("---------------------------------\n");
    printf("");
    printf("Siapa yang akan main pada giliran pertama?\n1. Komputer\n2. Anda\n");
}

bool isMenang(state q){
//Mengembalikan true bila state q merupakan final state dan dalam kondisi komputer menang
    FILE *pFile;
    char stateSebaris[110];
    char stateMenang[2] = "1";
    state qcek;
    state q1;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 111, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,q.T) == 0){
                memcpy(q1.T, &stateSebaris[9],1);
                q1.T[1] = '\0';
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
//Mengembalikan true apabila state q merupakan final state dan dalam kondisi permainan berakhir imbang.
    FILE *pFile;
    char stateSebaris[110];
    char stateSeri[2] = "2";
    state qcek;
    state q1;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 111, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,q.T) == 0){
                memcpy(q1.T, &stateSebaris[9],1);
                q1.T[1] = '\0';
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

    printf("\n%c | %c | %c\n",q.T[0],q.T[1],q.T[2]);
    printf("----------\n");
    printf("%c | %c | %c\n",q.T[3],q.T[4],q.T[5]);
    printf("----------\n");
    printf("%c | %c | %c\n",q.T[6],q.T[7],q.T[8]);
}

void pindahState(state *q, int i){
//Merubah state q ke state yang dituju jika diberi input i
    FILE *pFile;
    int j;
    char stateSebaris[110];
    state qcek;
    state qi;

    pFile = fopen ("state.txt", "r");
    while (!feof(pFile)){
        if (fgets(stateSebaris, 111, pFile) == NULL){
            break;
        } else {
            memcpy(qcek.T, &stateSebaris[0],9);
            qcek.T[9] = '\0';

            if (strcmp(qcek.T,(*q).T) == 0){
                memcpy(qi.T, &stateSebaris[11*i],9);
                qi.T[9] = '\0';

                *q = qi;
                break;
            }

        }
    }
    fclose(pFile);
}
