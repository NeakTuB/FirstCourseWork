#pragma once

typedef struct Doctors{
    int ID;
    char* surname;
    char* name;
    char* middleName;
    char* specialty;
    char* category;
    struct Doctors* prev;
}Doctors;
Doctors* headDoc = NULL;

typedef struct Date{
    int day;
    int month;
    int year;
}Date;
Date* headDate = NULL;

typedef struct Customers{
    int ID;
    char* surname;
    char* name;
    char* middleName;
    struct Date dateBirthday;
    struct Customers* prev;
}Customers;
Customers* headCust = NULL;

typedef struct Appeals{
    int NumApp;
    int IDdoc;
    int IDcust;
    Date dateAppeal;
    char* diagnosis;
    int costOfTreatment;
    struct Appeals* prev;
}Appeals;
Appeals* headApp = NULL;

//typedef struct {
//    int IDindicators;
//    int IDcompanies;
//    Date dateDynamics;
//}Dynamics;

//����� ������� �������� ��� pushDoc(), pushCust() �� ������� �������� � ����
//���������� �������������� �� ����������� ������ ��� ������������� �������  (������ � ���� ����������� ��� ������ �������)
//� ����� ���������� ���� �� ������,����� ����� ������� ����

//������� � ������ ��� ���������� ������ ������������ ���� ������ ������ ������������,����� ������� ����������� ������ ������������ (�����. �������� ��������� ID ��� authFun...)
//������������ ����� ID �� ��������� ����������� ���-�� �������� � ������\������
//������� �������� �� ��,����� ����� �� ��� ����� �� ������ 
//�������� ���� ������ ������������ ��� ���������� ��� � ������
//������� ������� ����� � ������������ ���� � ����� ��������,����� �� ������ ��������
//������� �������� � ��������,����� ������ ���� ������� ������� �����
//��� ���������� ������ ������������ ������� �������� �� ������ ����
//������� ��������� ������� float
//�������,�����, ���� �� ������� ������ � ���������, ������ ������� (����� ������� �����)


void pushDoc(Doctors** head, FILE* File);

            //����� �������


//���������� ������ � ��������� �� ����� ���������� �� ���� ����� � ����
    //1 - ������ ����� 
    //2 - ������ ������� ����� � ��������
    //3 - ���� � ������� �����, - / . ,  � �����
    //4 - ���� ����� � �����, - . 
char* writeStr(int mode) { ////��������� ��� ������� �� ���������� �������� � ���������� � ���
    char* str = NULL, s;
    bool check;
    int Esc = 0, n = 0;
    do {
        check = false;
        str = realloc(str, (n + 1) * sizeof(char));
        s = _getch();
        if ((int)s == 27) {
            Esc++;
        }
        else if ((int)s == 8 && n > 0) {
            printf("\b \b");
            *(str + n) = NULL;
            n--;
        }
        else if ((int)s != 8 && (int)s != 13) {
            if (mode == 1) {
                if ((int)s >= 48 && (int)s <= 57) check = true;
            }
            else if (mode == 2) {
                if (((int)s >= -64 && (int)s <= -1) || (int)s == 45 || (int)s == -72 || (int)s == -88) check = true;
            }
            else if (mode == 3){
                if (((int)s >= -64 && (int)s <= -1) || ((int)s >= 65 && (int)s <= 90) || ((int)s >= 97 && (int)s <= 122) || ((int)s >= 44 && (int)s <= 47) || (int)s >= 49 && (int)s <= 57 || (int)s == -72 || (int)s == -88 || (int)s == 32) check = true;
            }
            else if(mode == 4){
                if (((int)s >= 65 && (int)s <= 90) || ((int)s >= 97 && (int)s <= 122) || ((int)s >= 45 && (int)s <= 46) || (int)s >= 49 && (int)s <= 57) check = true;
            }
            if (check == true) {
                printf("%c", s);
                *(str + n) = s;
                n++;
            }
        }
    } while ((int)s != 13 && Esc == 0);
    *(str + n) = '\0';
    system("cls");
    if (Esc != 0) return "EscMode";
    else return str;
}
char* readFromFile(FILE* File) {
    int n = 0;
    char* str = NULL, s;
    do {        
        str = realloc(str, (n + 1) * sizeof(char));        
        s = fgetc(File);
        *(str + n) = s;
        n++;
    } while (s != ' ' && s != '\n');
    *(str + n - 1) = '\0';
    return str;
}
//�������� ������ � ������ ����� (������ ����� � ������� ��������, � ��������� � ������)
char* strconv(char* str) {
    int count, string = (int)*str;
    count = strlen(str);
    if (string >= -32 && string <= -1) {
        string -= 32;
        *str = (char)string;
    }
    else if (string == -72) {
        string = -88;
        *str = (char)string;
    }
    for (int i = 1; i < count; i++) {
        string = (int)*(str+i);
        if (string >= -64 && string <= -33) string += 32;
        else if (string == -88) string == -72;
        *(str + i) = (char)string;
    }
    return str;
}
//���������� ���������� � ��������� � �����
void readingDataDoc(Doctors** head, FILE* Doc) {
    Doctors* p = NULL;
    int count = 0, tmp = 0, countN = 0;
    fseek(Doc, 0, SEEK_END);
    if (ftell(Doc) == 0);
    else {
        p = malloc(sizeof(Doctors));
        if ((p = malloc(sizeof(Doctors))) == NULL) {
            printf("\t������ ��������� ������ ��� �����!\n");
        }
        tmp = ftell(Doc);
        fseek(Doc, 0, SEEK_SET);
        do {            
            if (count == 0) {
                p->prev = NULL;
                p->ID = atoi(readFromFile(Doc));
                p->surname = readFromFile(Doc);
                p->name = readFromFile(Doc);
                p->middleName = readFromFile(Doc);
                p->specialty = readFromFile(Doc);
                p->category = readFromFile(Doc);
                count++;
            }
            else {                
                p = malloc(sizeof(Doctors));
                p->prev = *head;                
                p->ID = atoi(readFromFile(Doc));
                p->surname = readFromFile(Doc);
                p->name = readFromFile(Doc);
                p->middleName = readFromFile(Doc);
                p->specialty = readFromFile(Doc);
                p->category = readFromFile(Doc);
                count++;
            }
            *head = p;
        } while (ftell(Doc) < tmp);
    }
}
void readingDataCust(Customers** head, FILE* Doc) {
    Customers* p = NULL;
    int count = 0, tmp = 0;
    fseek(Doc, 0, SEEK_END);
    if (ftell(Doc) == 0);
    else {
        p = malloc(sizeof(Customers));
        if ((p = malloc(sizeof(Customers))) == NULL) {
            printf("\t������ ��������� ������ ��� �����!\n");
        }
        tmp = ftell(Doc);
        fseek(Doc, 0, SEEK_SET);
        do {
            if (count == 0) {
                p->prev = NULL;
                p->ID = atoi(readFromFile(Doc));
                p->surname = readFromFile(Doc);
                p->name = readFromFile(Doc);
                p->middleName = readFromFile(Doc);
                p->dateBirthday.day = atoi(readFromFile(Doc));
                p->dateBirthday.month = atoi(readFromFile(Doc));
                p->dateBirthday.year = atoi(readFromFile(Doc));
                count++;
            }
            else {
                p = malloc(sizeof(Customers));
                p->prev = *head;
                p->ID = atoi(readFromFile(Doc));
                p->surname = readFromFile(Doc);
                p->name = readFromFile(Doc);
                p->middleName = readFromFile(Doc);
                p->dateBirthday.day = atoi(readFromFile(Doc));
                p->dateBirthday.month = atoi(readFromFile(Doc));
                p->dateBirthday.year = atoi(readFromFile(Doc));
                count++;
            }
            *head = p;
        } while (ftell(Doc) < tmp);
    }
}
void readingDataApp(Appeals** head, FILE* Doc) {
    Appeals* p = NULL;
    int count = 0, tmp = 0;
    fseek(Doc, 0, SEEK_END);
    if (ftell(Doc) == 0);
    else {
        p = malloc(sizeof(Appeals));
        if ((p = malloc(sizeof(Appeals))) == NULL) {
            printf("\t������ ��������� ������ ��� �����!\n");
        }
        tmp = ftell(Doc);
        fseek(Doc, 0, SEEK_SET);
        do {
            if (count == 0) {
                p->prev = NULL;
                printf("%d ", p->IDdoc);
                printf("%d ", p->IDcust);
                printf("%d ", p->dateAppeal.day);
                printf("%d ", p->dateAppeal.month);
                printf("%d ", p->dateAppeal.year);
                printf("%s ", p->diagnosis);
                printf("%d\n", p->costOfTreatment);
                count++;
            }
            else {
                p = malloc(sizeof(Appeals));
                p->prev = *head;
                printf("%d ", p->IDdoc);
                printf("%d ", p->IDcust);
                printf("%d ", p->dateAppeal.day);
                printf("%d ", p->dateAppeal.month);
                printf("%d ", p->dateAppeal.year);
                printf("%s ", p->diagnosis);
                printf("%d\n", p->costOfTreatment);
                count++;
            }
            *head = p;
        } while (ftell(Doc) < tmp);
    }
}
//���������� ��������� � ����:
    //����� � ���� ������ ����� (����������)
void fprintfDoc(Doctors** p,  FILE* File) {
    fprintf(File, "%d ", (*p)->ID);
    fprintf(File, "%s ", (*p)->surname);
    fprintf(File, "%s ", (*p)->name);
    fprintf(File, "%s ", (*p)->middleName);
    fprintf(File, "%s ", (*p)->specialty);
    fprintf(File, "%s\n", (*p)->category);
}
void rewriteDoc(Doctors** head, FILE* File) {
    Doctors* p = NULL;
    if (File != NULL) {
        fclose(File);
        File = fopen("ListOfDoctors.txt", "w+");
    }
    if (File == NULL) {
        printf("\t������ �������� / �������� �����!\n");
    }
    else {
        if (*head == NULL);
        else {
            p = *head;
            do {
                fprintfDoc(&p, File);
                p = p->prev;
            } while (p != NULL);
        }
    }
}
    //����� � ���� ������ ������� (����������)
void fprintfCust(Customers** p, FILE* File) {
    fprintf(File, "%d ", (*p)->ID);
    fprintf(File, "%s ", (*p)->surname);
    fprintf(File, "%s ", (*p)->name);
    fprintf(File, "%s ", (*p)->middleName);
    fprintf(File, "%d ", (*p)->dateBirthday.day);
    fprintf(File, "%d ", (*p)->dateBirthday.month);
    fprintf(File, "%d\n", (*p)->dateBirthday.year);
}
void rewriteCust(Customers** head, FILE* File) {
    Customers* p = NULL;
    if (File != NULL) {
        fclose(File);
        File = fopen("ListOfCustomers.txt", "w+");
    }
    if (File == NULL) {
        printf("\t������ �������� / �������� �����!\n");
    }
    else {
        if (*head == NULL);
        else {
            p = *head;
            do {
                fprintfCust(&p, File);
                p = p->prev;
            } while (p != NULL);
        }
    }
}
//����� � ���� ���� ��������� (����������)
void fprintfApp(Appeals** p, FILE* File) {
    fprintf(File, "%d ", (*p)->NumApp);
    fprintf(File, "%d ", (*p)->IDdoc);
    fprintf(File, "%d ", (*p)->IDcust);
    fprintf(File, "%d ", (*p)->dateAppeal.day);
    fprintf(File, "%d ", (*p)->dateAppeal.month);
    fprintf(File, "%d ", (*p)->dateAppeal.year);
    fprintf(File, "%s ", (*p)->diagnosis);
    fprintf(File, "%d\n", (*p)->costOfTreatment);
}
void rewriteApp(Appeals** head, FILE* File) {
    Appeals* p = NULL;
    if (File != NULL) {
        fclose(File);
        File = fopen("ListOfAppeals.txt", "w+");
    }
    if (File == NULL) {
        printf("\t������ �������� / �������� �����!\n");
    }
    else {
        if (*head == NULL);
        else {
            p = *head;
            do {
                fprintfApp(&p, File);
                p = p->prev;
            } while (p != NULL);
        }
    }
}
    //��������� �������� ������ � ����� ��� �������� ������� ������������
bool compare(char** str, FILE* File) {
    fseek(File, 0, SEEK_END);
    int tmp = ftell(File);
    if (tmp != 0) {
        fseek(File, 0, SEEK_SET);
        do {
            if ((strcmp(*str, readFromFile(File))) == 0) return true;
        } while (ftell(File) < tmp);
        return false;
    }
    else return false;
}


        //������� ��� �����������

//�������� ������ � ������
bool ReadAuthCheck(FILE* File, char* login, char* pass, int mode) {
    fseek(File, 0, SEEK_END);
    int tmp = ftell(File);
    char s;
    bool checkLogin = false, checkPassword = false, checkMode = false;
    if (tmp == 0) return false;
    else {
        fseek(File, 0, SEEK_SET);
        do {
            if (strcmp(readFromFile(File), login) == 0) checkLogin = true;
        } while (ftell(File) < tmp && checkLogin == false);
        if (checkLogin == true) {
            if (strcmp(readFromFile(File), pass) == 0) checkPassword = true;
            if (atoi(readFromFile(File)) == mode) checkMode = true;
            readFromFile(File);
        }
        if (checkLogin == true && checkPassword == true && checkMode == true) return true;
        else return false;
    }

}
//����� �������� � ���� ������ � ������
int AuthFunction(int mode) {
    FILE* authFile,* DoctorsFile;
    bool Auth = false, EscCheck = false;
    char* inputLogin = NULL, * inputPassword = NULL;
    int ID = 0;
    authFile = fopen("Authentification.txt", "a+");
    if (authFile == NULL) {
        printf("\t������ �������� �����!\n");
    }
    else {
        fseek(authFile, 0, SEEK_END);
        if (ftell(authFile) == 0 && mode == 1) {
            DoctorsFile = fopen("ListOfDoctors.txt", "a+");
            if (DoctorsFile == NULL) {
                printf("\t������ �������� �����!\n");
            }
            else pushDoc(&headDoc, DoctorsFile);
        }
        do {
            EscCheck = false;
            do {
                printf("������� �����: ");
                inputLogin = writeStr(4);
                if (strcmp(inputLogin, "EscMode") == 0) EscCheck = true;
                else {
                    if (strlen(inputLogin) < MinLogSymbol || strlen(inputLogin) > MaxLogSymbol) {
                        printf("��������� ������ ������ �� %d �� %d ��������!\n", MinLogSymbol, MaxLogSymbol);
                        system("pause");
                        system("cls");
                    }
                }
            } while (strlen(inputLogin) < MinLogSymbol || strlen(inputLogin) > MaxLogSymbol && EscCheck == false);
            if (EscCheck == false) {
                do {
                    printf("������� ������: ");
                    inputPassword = writeStr(4);
                    if (strcmp(inputPassword, "EscMode") == 0) EscCheck = true;
                    else {
                        if (strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol) {
                            printf("��������� ������ ������ �� %d �� %d ��������!\n", MinPassSymbol, MaxPassSymbol);
                            system("pause");
                            system("cls");
                        }
                    }
                } while (EscCheck != true && strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol);
            }
            if (EscCheck != true) {
                Auth = ReadAuthCheck(authFile, inputLogin, inputPassword, mode);
                if (Auth == true) {
                    fseek(authFile, -3, SEEK_CUR);
                    ID = atoi(readFromFile(authFile));;
                    printf("\t�� ������� ����� � �������\n\n");
                }
                else {
                    printf("\t�������� ����� ��� ������\n\n");
                }
                system("pause");
                system("cls");
            }
        } while (Auth == false && EscCheck == false);
        if (EscCheck == false) {
            free(inputLogin);
            free(inputPassword);
        }
        if (authFile != NULL) {
            fclose(authFile);
        }
        else {
            printf("\t������ �������� �����!\n");
        }
        return ID;
        /*if (Auth == true && EscCheck == false) {
            return ID;
        }
        else return 0;*/
    }
}
//����������� ������ ������������, ���� �������� ��� ������� 
void registration() {
    FILE* authFile, * regFile;
    bool EscCheck = false, CheckLog = false, CheckPass = false;
    char* inputLogin = NULL, * inputPassword = NULL, s;
    EscCheck = false;
    authFile = fopen("Authentification.txt", "a+");
    if (authFile == NULL) {
        printf("\t������ �������� �����!\n");
    }
    else {
        do {
            printf("������� �����: ");
            inputLogin = writeStr(4);
            if (strcmp(inputLogin, "EscMode") == 0) EscCheck = true;
            else {
                if (strlen(inputLogin) < MinLogSymbol || strlen(inputLogin) > MaxLogSymbol) {
                    printf("��������� ������ ������ �� %d �� %d ��������!\n", MinLogSymbol, MaxLogSymbol);
                    system("pause");
                    system("cls");
                }
                else if (compare(&inputLogin, authFile) == true) {
                    printf("������ ����� ����������!\n");
                    system("pause");
                    system("cls");
                }
                else CheckLog = true;
            }
        } while (CheckLog == false && EscCheck == false);
        regFile = fopen("RegFile.txt", "a+");
        if (regFile == NULL) {
            printf("\t������ �������� / �������� �����!\n");
            system("pause");
            system("cls");
        }
        else {
            if (EscCheck == false) {
                fseek(authFile, 0, SEEK_END);
                if (ftell(authFile) == 0) {
                    fprintf(regFile, "%s 1 1\n", inputLogin);
                    fclose(regFile);
                    regFile = fopen("RegFile.txt", "r+");
                }
                if (regFile == NULL) {
                    printf("\t������ �������� / �������� �����!\n");
                    system("pause");
                    system("cls");
                }
                else {
                    if (compare(&inputLogin, regFile) == true) {
                        int poz = ftell(regFile);
                        if (EscCheck == false) {
                            do {
                                printf("������� ������: ");
                                inputPassword = writeStr(4);
                                if (strcmp(inputPassword, "EscMode") == 0) EscCheck = true;
                                else {
                                    if (strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol) {
                                        printf("��������� ������ ������ �� %d �� %d ��������!\n", MinPassSymbol, MaxPassSymbol);
                                        system("pause");
                                        system("cls");
                                    }
                                    else if (compare(&inputPassword, authFile) == true) {
                                        printf("������ ������ ����������!\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else CheckPass = true;
                                }
                            } while (EscCheck != true && CheckPass != true);
                        }
                        printf("\t����������� ���������!\n");
                        system("pause");
                        system("cls");
                        fseek(regFile, poz, SEEK_SET);
                        fprintf(authFile, "%s %s %d ", inputLogin, inputPassword, atoi(readFromFile(regFile)));
                        fprintf(authFile, "%d\n", atoi(readFromFile(regFile)));
                    }
                    else {
                        printf("\t�� �� ������ ������������������! ���������� � ���������.\n");
                        system("pause");
                        system("cls");
                    }
                }
            }
            if (EscCheck == false || strcmp(inputLogin, "adm") != 0) {
                free(inputLogin);
                free(inputPassword);
            }
            if (authFile != NULL) {
                fclose(authFile);
            }
            else {
                printf("\t������ �������� �����!\n");
            }
        }
    }
}



            //������� ��� ������ �� �����������


//�������� ���� �������� � ��������� �����
void dataTableDoc(Doctors** head) {
    Doctors* p = NULL;
    p = *head;
    puts("*****************************************************************************************************");
    puts("  ID  |     �������    |    ���    |    ��������    |           �������������           | ��������� |");
    puts("*****************************************************************************************************");
    while (p != NULL) {
        printf("%6d|%16s|%11s|%16s|%35s|%11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
        puts("-----------------------------------------------------------------------------------------------------");
        p = p->prev;
    }
}
void dataTableCust(Customers** head) {
    Customers* p = NULL;
    p = *head;
    char tmpDay[3], tmpMouth[3], tmp[3];
    puts("**********************************************************************");
    puts("|  ID  |     �������    |    ���    |    ��������    | ���� �������� |");
    puts("**********************************************************************");
    while (p != NULL) {
        if (p->dateBirthday.day < 10) {
            memset(tmpDay, 0, sizeof(tmpDay));
            tmpDay[0] = '0';
            strcat(tmpDay, _itoa(p->dateBirthday.day, tmp, 10));
        }
        else strcpy(tmpDay, _itoa(p->dateBirthday.day, tmp, 10));
        if (p->dateBirthday.month < 10) {
            memset(tmpMouth, 0, sizeof(tmpMouth));
            tmpMouth[0] = '0';
            strcat(tmpMouth, _itoa(p->dateBirthday.month, tmp, 10));
        }
        else strcpy(tmpMouth, _itoa(p->dateBirthday.month, tmp, 10));
        printf("|%6d|%16s|%11s|%16s|  %2s.%2s.%d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
        puts("----------------------------------------------------------------------");
        p = p->prev;
    }
} 
void dataTableApp(Appeals** head) {
    Appeals* p = NULL;
    p = *head;
    char tmpDay[3], tmpMonth[3], tmp[3];
    puts("***********************************************************************************************************************");
    puts("|   �����   |    ID   |    ID    | ���� ����� |                     �������                      | ��������� ������� |");
    puts("| ��������� | ������� | �������� |             |                                                  |                   |");
    puts("***********************************************************************************************************************");
    while (p != NULL) {
        if (p->dateAppeal.day < 10) {
            memset(tmpDay, 0, sizeof(tmpDay));
            tmpDay[0] = '0';
            strcat(tmpDay, _itoa(p->dateAppeal.day, tmp, 10));
        }
        else strcpy(tmpDay, _itoa(p->dateAppeal.day, tmp, 10));
        if (p->dateAppeal.month < 10) {
            memset(tmpMonth, 0, sizeof(tmpMonth));
            tmpMonth[0] = '0';
            strcat(tmpMonth, _itoa(p->dateAppeal.month, tmp, 10));
        }
        else strcpy(tmpMonth, _itoa(p->dateAppeal.month, tmp, 10));
        printf("|%11d|%9d|%10d|  %2s.%2s.%d |%50s|%13d ���. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
        puts("-----------------------------------------------------------------------------------------------------------------------");
        p = p->prev;
    }
}
//���������� �������� � ����
    //��������� �� ������ ����� � ������� ��������, � ��������� � ������
void pushDoc(Doctors** head, FILE* File) {
    Doctors* p;
    FILE* tmpLogin;
    bool check;
    int mode;
    do {
        check = false;
        p = NULL;
        if (*head == NULL) {
            p = malloc(sizeof(Doctors));
            if ((p = malloc(sizeof(Doctors))) == NULL) {
                printf("\t������ ��������� ������ ��� �����!\n");
            }
            p->prev = NULL;
            p->ID = 1;
        }
        else {
            int count = (*head)->ID;
            p = *head;
            do {
                if (p->ID > count) {
                    count = p->ID;
                }
                p = p->prev;
            } while (p != NULL);
            p = *head;
            p = malloc(sizeof(Doctors));
            p->prev = *head;
            p->ID = count + 1;
        }
        do {
            printf("������� �������: ");
            p->surname = strconv(writeStr(2));

            if (strlen(p->surname) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->surname) > MaxSecondNameSymbol);
        do {
            printf("������� ���: ");
            p->name = strconv(writeStr(2));
            if (strlen(p->name) > MaxNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->name) > MaxNameSymbol);
        do {
            printf("������� ��������: ");
            p->middleName = strconv(writeStr(2));
            if (strlen(p->middleName) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->middleName) > MaxSecondNameSymbol);
        do {
            printf("������� �������������: ");
            p->specialty = strconv(writeStr(2));
            if (strlen(p->specialty) > MaxSpecialSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSpecialSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->specialty) > MaxSpecialSymbol);
        if (ftell(File) != 0) {
            if(strcmp(p->specialty, "��������������") == 0) p->category = "-";
            else {
                do {
                    printf("������� ���������: ");
                    p->category = strconv(writeStr(2));
                    if (strlen(p->category) > MaxCategorSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxCategorSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->category) > MaxCategorSymbol);
            }
            if (compare(&p->surname, File) == true && compare(&p->name, File) == true && compare(&p->middleName, File) == true) {
                check = true;
                memset(p, 0, sizeof(Doctors));
                printf("\t������ ������������ ��� ���������� � �������!\n");
                system("pause");
                system("cls");
            }
            do {
                printf("������� ����� ������������: ");
                char* tmp = writeStr(4);
                if (strlen(tmp) > MaxLogSymbol || strlen(tmp) < MinLogSymbol) {
                    printf("��������� ������ ������ �� %d �� %d ��������!\n", MinLogSymbol, MaxLogSymbol);
                    system("pause");
                    system("cls");
                }
                else {
                    tmpLogin = fopen("RegFile.txt", "a+");
                    if (tmpLogin == NULL) {
                        printf("\t������ �������� / �������� �����!\n");
                        system("pause");
                        system("cls");
                    }
                    else {
                        if (strcmp(p->specialty, "��������������") == 0) {                            
                            mode = 3;
                        }
                        else if (strcmp(p->category, "������") == 0) mode = 1;
                        else mode = 2;
                        fprintf(tmpLogin, "%s %d %d\n", tmp, mode, p->ID);
                        fclose(tmpLogin);
                    }
                }
            } while (strlen(p->category) > MaxCategorSymbol);
        }
        else {
            p->category = "������";
            registration();
        }
        *head = p;        
    } while (check == true);
}
void pushCust(Customers** head, FILE* File) {
    Customers* p = NULL;
    char* tmp = NULL;
    bool check = false, checkCompare;
    do {
        checkCompare = false;
        if (*head == NULL) {
            p = malloc(sizeof(Customers));
            if ((p = malloc(sizeof(Customers))) == NULL) {
                printf("\t������ ��������� ������ ��� �����!\n");
            }
            p->prev = NULL;
            p->ID = 1;
        }
        else {
            int countID = (*head)->ID;
            p = *head;
            do {
                if (p->ID > countID) {
                    countID = p->ID;
                }
                p = p->prev;
            } while (p != NULL);
            p = *head;
            p = malloc(sizeof(Customers));
            p->prev = *head;
            p->ID = countID + 1;
        }
        do {
            printf("������� �������: ");
            p->surname = strconv(writeStr(2));
            if (strlen(p->surname) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->surname) > MaxSecondNameSymbol);
        do {
            printf("������� ���: ");
            p->name = strconv(writeStr(2));
            if (strlen(p->name) > MaxNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->name) > MaxNameSymbol);
        do {
            printf("������� ��������: ");
            p->middleName = strconv(writeStr(2));
            if (strlen(p->middleName) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(p->middleName) > MaxSecondNameSymbol);
        const time_t timer = time(NULL);
        struct tm* u = localtime(&timer);
        do {
            printf("������� ���: ");
            tmp = writeStr(1);
            p->dateBirthday.year = atoi(tmp);
            if (p->dateBirthday.year <= 0 || p->dateBirthday.year > u->tm_year + 1900 || p->dateBirthday.year < 1900) {
                printf("\t������������ ��������\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        do {
            printf("������� �����: ");
            tmp = writeStr(1);
            p->dateBirthday.month = atoi(tmp);
            u->tm_mon = u->tm_mon + 1;
            if (p->dateBirthday.month <= 0 || p->dateBirthday.month > 12 || (p->dateBirthday.month > u->tm_mon && p->dateBirthday.year == 2020)) {
                printf("\t������������ ��������\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        bool checkDay = false;
        do {
            printf("������� ����: ");
            tmp = writeStr(1);
            p->dateBirthday.day = atoi(tmp);
            if (u->tm_mon == p->dateBirthday.month && p->dateBirthday.year == 2020 && p->dateBirthday.day > u->tm_mday) { //������� �� ������ ����������� ���
                checkDay = true;
            }
            else checkDay = false;
            check = false;
            if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 == 0 || checkDay == true) {
                if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 29 || checkDay == true) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 != 0) {
                if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 28) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (p->dateBirthday.month == 4 && p->dateBirthday.month == 6 && p->dateBirthday.month == 9 && p->dateBirthday.month == 11) {
                if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 30) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else {
                if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 31) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
        } while (check == false);
        char* str1,* str2,* str3;
        str1 = (char*)malloc(sizeof(char) * 3);
        str2 = (char*)malloc(sizeof(char) * 3);
        str3 = (char*)malloc(sizeof(char) * 5);
        _itoa(p->dateBirthday.day, str1, 10);
        _itoa(p->dateBirthday.month, str2, 10);
        _itoa(p->dateBirthday.year, str3, 10);
        check = false;
        if (compare(&p->surname, File) == true && compare(&p->name, File) == true && compare(&p->middleName, File) == true && compare(&str1, File) == true && compare(&str2, File) == true && compare(&str3, File) == true) {
            check = true;
            memset(p, 0, sizeof(Customers));
            printf("\t������ ������������ ��� ���������� � �������!\n");
            system("pause");
            system("cls");
        }
        *head = p;
    }while (check == true);
} 
void PushAppealCust(Appeals** headApp, Customers** headCust, FILE* FileApp, FILE* FileCust, int ID) {
    char* surname, * name, * middleName,* tmp = NULL;
    int day, month, year;
    Appeals* pApp = NULL;
    Customers* pCust = NULL;
    bool check = false, checkCompare;
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    do {
        checkCompare = false;
        printf("\t���� ������ ��������\n");
        system("pause");
        system("cls");
        do {
            printf("������� �������: ");
            surname = strconv(writeStr(2));
            if (strlen(surname) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(surname) > MaxSecondNameSymbol);
        do {
            printf("������� ���: ");
            name = strconv(writeStr(2));
            if (strlen(name) > MaxNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(name) > MaxNameSymbol);
        do {
            printf("������� ��������: ");
            middleName = strconv(writeStr(2));
            if (strlen(middleName) > MaxSecondNameSymbol) {
                printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
        } while (strlen(middleName) > MaxSecondNameSymbol);
        do {
            printf("������� ���: ");
            tmp = writeStr(1);
            year = atoi(tmp);
            if (year <= 0 || year > u->tm_year + 1900 || year < 1900) {
                printf("\t������������ ��������\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        do {
            printf("������� �����: ");
            tmp = writeStr(1);
            month = atoi(tmp);
            u->tm_mon = u->tm_mon + 1;
            if (month <= 0 || month > 12 || (month > u->tm_mon && year == 2020)) {
                printf("\t������������ ��������\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        bool checkDay = false;
        do {
            printf("������� ����: ");
            tmp = writeStr(1);
            day = atoi(tmp);
            if (u->tm_mon == month && year == 2020 && day > u->tm_mday) { //������� �� ������ ����������� ���
                checkDay = true;
            }
            else checkDay = false;
            check = false;
            if (month == 2 && year % 4 == 0 || checkDay == true) {
                if (day <= 0 || day > 29 || checkDay == true) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (month == 2 && year % 4 != 0) {
                if (day <= 0 || day > 28) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (month == 4 && month == 6 && month == 9 && month == 11) {
                if (day <= 0 || day > 30) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else {
                if (day <= 0 || day > 31) {
                    printf("\t������������ ��������\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
        } while (check == false);
    } while (check == false);
    check = false;
    pCust = *headCust;
    do {
        if (strcmp(pCust->name, name) == 0 && strcmp(pCust->surname, surname) == 0 && strcmp(pCust->middleName, middleName) == 0 && pCust->dateBirthday.day == day && pCust->dateBirthday.month == month && pCust->dateBirthday.year == year) {
            printf("\t������ �������\n");
            system("pause");
            system("cls");
            if (*headApp == NULL) {
                pApp = malloc(sizeof(Appeals));
                if ((pApp = malloc(sizeof(Appeals))) == NULL) {
                    printf("\t������ ��������� ������ ��� �����!\n");
                }
                pApp->NumApp = 1;
                pApp->prev = NULL;
            }
            else {
                int count = (*headApp)->NumApp;
                pApp = *headApp;
                do {
                    if (pApp->NumApp > count) {
                        count = pApp->NumApp;
                    }
                    pApp = pApp->prev;
                } while (pApp != NULL);
                pApp = *headApp;
                pApp = malloc(sizeof(Appeals));
                pApp->prev = *headApp;
                pApp->NumApp = count + 1;
            }
            pApp->IDdoc = ID;
            pApp->IDcust = pCust->ID;
            pApp->dateAppeal.year = u->tm_year + 1900;
            pApp->dateAppeal.month = u->tm_mon;
            pApp->dateAppeal.day = u->tm_mday;
            do {
                printf("������� ������� ��������: ");
                pApp->diagnosis = writeStr(3);
            } while (strlen(pApp->diagnosis) > 50);
            do {
                printf("������� ��������� �������: ");
                pApp->costOfTreatment = atoi(writeStr(1));
                system("pause");
                system("cls");
            } while (pApp->costOfTreatment > 100000 || pApp->costOfTreatment < 0);
            check = true;
        }
        pCust = pCust->prev;
    } while (pCust != NULL);
    *headApp = pApp;
    if (check == false) printf("\t������� �������� ��� � ���� ������! ���������� � ������������.\n");
    else printf("\t���������!\n");
}
//�������� �������� �� �����
void popDoc(Doctors** head) {
    bool checkTruth = false;
    Doctors* p = NULL, * tmp;
    p = *head;
    int IDpop, n = 0;
    printf("������� ID ����� ��� ��������: ");
    scanf_s("%d", &IDpop);
    while (p != NULL && checkTruth == false) {
        if (p->ID == IDpop) {
            if (p->ID == (*head)->ID) {
                tmp = (*head)->prev;
                (*head) = NULL;
                p = tmp;
                *head = p;
            }
            else {
                tmp = p->prev;
                p->prev = NULL;
                p = *head;
                for (int i = 0; i < n - 1; i++) {
                    p = p->prev;
                }
                p->prev = tmp;                
            }
            checkTruth = true;
            system("cls");
            printf("\t������ ����� � ID %d �������\n", IDpop);
        }
        else {
            p = p->prev;
            n++;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\t����� � ����� ID �� ����������\n");
    }
    
}
void popCust(Customers** head) {
    bool checkTruth = false;
    Customers* p = NULL, * tmp;
    p = *head;
    int IDpop, n = 0;
    printf("������� ID ������� ��� ��������: ");
    scanf_s("%d", &IDpop);
    while (p != NULL && checkTruth == false) {
        if (p->ID == IDpop) {
            if (p->ID == (*head)->ID) {
                tmp = (*head)->prev;
                (*head) = NULL;
                p = tmp;
                *head = p;
                checkTruth = true;
            }
            else {
                tmp = p->prev;
                p->prev = NULL;
                p = *head;
                for (int i = 0; i < n - 1; i++) {
                    p = p->prev;
                }
                p->prev = tmp;
                checkTruth = true;
            }
            system("cls");
            printf("\t������ ������� � ID %d �������\n", IDpop);
            system("pause");
        }
        else {
            p = p->prev;
            n++;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\t������� � ����� ID �� ����������\n");
        system("pause");
    }
    system("cls");
}
//�������������� ������ � �����
    //��������� �������
void editDataDoc(Doctors** head) {
    int IDedit, editChoice, a = 0;
    bool checkTruth = false;
    Doctors* p = NULL;
    printf("������� ID ����� ��� ��������������: ");
    scanf_s("%d", &IDedit);
    p = *head;
    while (p != NULL && checkTruth == false) {
        if (p->ID == IDedit) {
            checkTruth = true;
        }
        else {
            p = p->prev;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\t����� � ����� ID �� ����������\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {            
            printf("\t1) ������������� �������\n");
            printf("\t2) ������������� ���\n");
            printf("\t3) ������������� ��������\n");
            printf("\t4) ������������� �������������\n");
            printf("\t5) ������������� ���������\n");
            printf("\t6) ���������� ���������\n\n");
            scanf_s("%d", &editChoice);
            system("cls");
            switch (editChoice) {
            case 1:
                do {
                    printf("������� �������: ");
                    p->surname = writeStr(2);
                    if (strlen(p->surname) > MaxSecondNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->surname) > MaxSecondNameSymbol);
                break;
            case 2:                
                do {
                    printf("������� ���: ");
                    p->name = writeStr(2);
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->surname) > MaxNameSymbol);
                break;
            case 3:
                do {
                    printf("������� ��������: ");
                    p->middleName = writeStr(2);
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->middleName) > MaxSecondNameSymbol);
                break;
            case 4:
                do {
                    printf("������� �������������: ");
                    p->specialty = writeStr(2);
                    if (strlen(p->specialty) > MaxSpecialSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxSpecialSymbol);
                        system("pause");
                    }
                } while (strlen(p->specialty) > MaxSpecialSymbol);
                break;
            case 5:
                do {
                    printf("������� ���������: ");
                    p->category = writeStr(2);
                    if (strlen(p->category) > MaxCategorSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxCategorSymbol);
                        system("pause");
                    }
                } while (strlen(p->category) > MaxCategorSymbol);
                break;
            case 6:
                a = 1;
                break;
            }
        }
    }    
}
void editDataCust(Customers** head) {
    int IDedit, editChoice, a = 0;
    bool checkTruth = false, check = false;
    Customers* p = NULL;
    char* tmp = NULL;
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    printf("������� ID ������� ��� ��������������: ");
    scanf_s("%d", &IDedit);
    p = *head;
    while (p != NULL && checkTruth == false) {
        if (p->ID == IDedit) {
            checkTruth = true;
        }
        else {
            p = p->prev;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\t������� � ����� ID �� ����������\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {
            printf("\t1) ������������� �������\n");
            printf("\t2) ������������� ���\n");
            printf("\t3) ������������� ��������\n");
            printf("\t4) ������������� ���� ��������\n");
            printf("\t5) ���������� ���������\n\n");
            editChoice = getc(stdin);
            system("cls");
            switch (editChoice) {
            case '1':
                do {
                    printf("������� �������: ");
                    p->surname = writeStr(2);
                    if (strlen(p->surname) > MaxSecondNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->surname) > MaxSecondNameSymbol);
                printf("\t���������\n");
                system("pause");
                break;
            case '2':
                do {
                    printf("������� ���: ");
                    p->name = writeStr(2);
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->name) > MaxNameSymbol);
                printf("\t���������\n");
                system("pause");
                break;
            case '3':
                do {
                    printf("������� ��������: ");
                    p->middleName = writeStr(2);
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\t������������ ������ ������ %d ��������\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->middleName) > MaxSecondNameSymbol);
                printf("\t���������\n");
                system("pause");
                break;
            case '4':
                do {
                    printf("������� ���: ");
                    tmp = writeStr(1);
                    p->dateBirthday.year = atoi(tmp);
                    if (p->dateBirthday.year <= 0 || p->dateBirthday.year > u->tm_year + 1900 || p->dateBirthday.year < 1900) {
                        printf("\t������������ ��������\n");
                        system("pause");
                        system("cls");
                    }
                    else check = true;
                } while (check == false);
                check = false;
                do {
                    printf("������� �����: ");
                    tmp = writeStr(1);
                    p->dateBirthday.month = atoi(tmp);
                    u->tm_mon = u->tm_mon + 1;
                    if (p->dateBirthday.month <= 0 || p->dateBirthday.month > 12 || (p->dateBirthday.month > u->tm_mon&& p->dateBirthday.year == 2020)) {
                        printf("\t������������ ��������\n");
                        system("pause");
                        system("cls");
                    }
                    else check = true;
                } while (check == false);
                check = false;
                bool checkDay = false;
                do {
                    printf("������� ����: ");
                    tmp = writeStr(1);
                    p->dateBirthday.day = atoi(tmp);
                    if (u->tm_mon == p->dateBirthday.month && p->dateBirthday.year == 2020 && p->dateBirthday.day > u->tm_mday) { //������� �� ������ ����������� ���
                        checkDay = true;
                    }
                    else checkDay = false;
                    check = false;
                    if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 == 0 || checkDay == true) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 29 || checkDay == true) {
                            printf("\t������������ ��������\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 != 0) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 28) {
                            printf("\t������������ ��������\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else if (p->dateBirthday.month == 4 && p->dateBirthday.month == 6 && p->dateBirthday.month == 9 && p->dateBirthday.month == 11) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 30) {
                            printf("\t������������ ��������\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 31) {
                            printf("\t������������ ��������\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                } while (check == false);
                printf("\t���������\n");
                system("pause");
            case '5':
                a = 1;
                break;
            }
        }
    }
    system("cls");
}
void editDataApp(Appeals** head) {
    int IDedit, editChoice, a = 0;
    bool checkTruth = false, check = false;
    Appeals* p = NULL;
    char* tmp = NULL;
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    printf("������� ����� ��������� ��� ��������������: ");
    scanf_s("%d", &IDedit);
    p = *head;
    while (p != NULL && checkTruth == false) {
        if (p->NumApp == IDedit) {
            checkTruth = true;
        }
        else {
            p = p->prev;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\t��������� � ����� ������� �� ����������\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {
            printf("\t1) ������������� �������\n");
            printf("\t2) ������������� ��������� �������\n");
            printf("\t3) ���������� ���������\n\n");
            editChoice = getc(stdin);
            system("cls");
            switch (editChoice) {
            case '1':
                do {
                    printf("������� ������� ��������: ");
                    p->diagnosis = writeStr(3);
                } while (strlen(p->diagnosis) > 50);
                printf("\t���������\n");
                system("pause");
                break;
            case '2':
                do {
                    printf("������� ��������� �������: ");
                    p->costOfTreatment = atoi(writeStr(1));
                    system("pause");
                    system("cls");
                } while (p->costOfTreatment > 100000 || p->costOfTreatment < 0);
                printf("\t���������\n");
                system("pause");
                break;
            case '3':
                a = 1;
                break;
            }
        }
    }
    system("cls");
}




            //�������
//��������� ��,��� ������� ��� ����� � �������� �� �������


//���� 1-�� ������
char main_menu() {
    int first_choice;
    do {
        printf("\t1) ��������\n\t2) ����\n\t3) ��������������\n\t4) �����������\n\t5) �����\n");
        first_choice = getc(stdin);
        system("cls");
    } while ((int)first_choice < 48 || (int)first_choice > 53);
    return first_choice;
}
//���� 2-�� ������ ��� �����
void user_menu(int ID)
{
    int user_choice, a = 0;
    FILE* CustomersFile = NULL,* AppealsFile = NULL,* DoctorsFile = NULL;
    while (1) {
        printf("\t1) �������� ����� � ������� ���������\n");
        printf("\t2) ���� ��������� \n");
        printf("\t3) �������������� ������ � ����� \n");
        printf("\t4) �������� ���� ������ ���������\n");
        printf("\t5) ����� � ���������� ������\n");
        printf("\t6) �������� ���� ������ ���������\n");
        printf("\t7) �������� ���� ������ ������\n");        
        printf("\t8) ����� � ����\n");
        user_choice = getc(stdin);
        system("cls");
        switch (user_choice) {
        case '1':
            CustomersFile = fopen("ListOfCustomers.txt", "a+");
            AppealsFile = fopen("ListOfAppeals.txt", "a+");
            DoctorsFile = fopen("ListOfDoctors.txt", "a+");
            if (CustomersFile == NULL && AppealsFile == NULL && DoctorsFile == NULL) {
                printf("\t������ �������� / �������� �����!\n");
                system("pause");
                system("cls");
            }
            else {
                readingDataCust(&headCust, CustomersFile);
                readingDataDoc(&headDoc, DoctorsFile);
                readingDataApp(&headApp, AppealsFile);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '2':
            if (CustomersFile == NULL && AppealsFile == NULL && DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                PushAppealCust(&headApp, &headCust, AppealsFile, CustomersFile, ID);                
            }
            system("pause");
            system("cls");
            break;
        case '3':
            if (CustomersFile == NULL && AppealsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
                system("pause");
                system("cls");
            }
            else {
                editDataApp(&headApp);
            }
            break;
        case '4':
            if (AppealsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
                system("pause");
                system("cls");
            }
            else {
                if (headApp == NULL) printf("\t������� �����!\n");
                else dataTableApp(&headApp);
                system("pause");
                system("cls");
            }
            break;
        case '5':
            if (CustomersFile == NULL && AppealsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
                system("pause");
                system("cls");
            }
            else {

            }
            break;
        case '6':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
                system("pause");
                system("cls");
            }
            else {
                if (headCust == NULL) printf("\t������� �����!\n");
                else dataTableCust(&headCust);  
                system("pause");
                system("cls");
            }
            break;
        case '7':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
                system("pause");
                system("cls");
            }
            else {
                if (headDoc == NULL) printf("\t������� �����!\n");
                else dataTableDoc(&headDoc);
                system("pause");
                system("cls");
            }
            break;  
        case '8':
            if (CustomersFile != NULL && AppealsFile != NULL && DoctorsFile != NULL) {
                rewriteApp(&headApp, AppealsFile);
                fclose(CustomersFile);
                fclose(AppealsFile);
                fclose(DoctorsFile);
                memset(headCust, 0, sizeof(Customers));
                memset(headApp, 0, sizeof(Appeals));
                memset(headDoc, 0, sizeof(Doctors));
                free(headCust);
                free(headApp);
                free(headDoc);
            }
            return;
        }
    }
}
//���� 2-�� ������ ��� ���������
void admin_menu(int ID) {
    int admin_choice;
    FILE* DoctorsFile = NULL;
    while (1) {
        printf("\t1) �������� / �������� ����� � ������� ������\n");
        printf("\t2) ���������� ������ �����\n");
        printf("\t3) �������������� ������ �����\n");
        printf("\t4) �������� ������ �����\n");
        printf("\t5) �������� ���� ������ ������ � ��������� �����\n");
        printf("\t6) ����� � ���������� ������ ������\n"); //---------------------------------
        printf("\t7) ���������� ���������\n"); //-----------------------------------
        printf("\t8) ����� � ����\n");
        fflush(stdin);
        admin_choice = getc(stdin);
        system("cls");
        switch (admin_choice) {
        case '1':
            if (DoctorsFile == NULL) {
                DoctorsFile = fopen("ListOfDoctors.txt", "a+");
                if (DoctorsFile == NULL) {
                    printf("\t������ �������� / �������� �����!\n");
                    system("pause");
                    system("cls");
                }
                else {
                    readingDataDoc(&headDoc, DoctorsFile);
                    printf("\t���������!\n");
                }
            }
            else printf("\t���� ������ / ������ �����!\n");
            system("pause");
            system("cls");
            break;
        case '2':
            if (DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                pushDoc(&headDoc, DoctorsFile);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '3':
            if (DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                editDataDoc(&headDoc);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '4':
            if (DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                popDoc(&headDoc);
            }
            system("pause");
            system("cls");
            break;
        case '5':
            if (DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else
            {
                if (headDoc == NULL) printf("\t������� �����!\n");
                else dataTableDoc(&headDoc);
            }
            system("pause");
            system("cls");
            break;
        case '6':
            if (DoctorsFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {

            }
            system("pause");
            system("cls");
            break;
        case '7':
            user_menu(ID);
            break;
        case '8':
            if (DoctorsFile == NULL) {
                DoctorsFile = fopen("ListOfDoctors.txt", "a+");
                if (DoctorsFile == NULL) {
                    printf("\t������ �������� / �������� �����!\n");
                    system("pause");
                    system("cls");
                }
            }
            rewriteDoc(&headDoc, DoctorsFile);
            fclose(DoctorsFile);
            memset(headDoc, 0, sizeof(Doctors));
            free(headDoc);
            headDoc = NULL;
            return;
        }
    }
}
//���� 2-�� ������ ��� ��������������
void regist_menu() {
    int user_choice = 0L, a = 0;
    FILE* CustomersFile = NULL;
    while (1) {
        printf("\t1) �������� ����� � ������� ���������\n");
        printf("\t2) ���������� ������ ��������\n");
        printf("\t3) �������� ������ ��������\n");
        printf("\t4) �������������� ������ ��������\n");
        printf("\t5) �������� ���� ������ ��������� � ��������� �����\n");
        printf("\t6) ����� � ���������� ������\n");
        printf("\t7) ����� � ����\n");
        user_choice = getc(stdin);
        system("cls");
        switch (user_choice) {
        case '1':
            if (CustomersFile == NULL) {
                CustomersFile = fopen("ListOfCustomers.txt", "a+");
                if (CustomersFile == NULL) {
                    printf("\t������ �������� / �������� �����!\n");
                }
                else {
                    readingDataCust(&headCust, CustomersFile);
                    printf("\t���������!\n");
                }
            }
            else printf("\t���� ������ / ������ �����!\n");
            system("pause");
            system("cls");
            break;
        case '2':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                pushCust(&headCust, CustomersFile);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '3':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                popCust(&headCust);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '4':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                editDataCust(&headCust);
                printf("\t���������!\n");
            }
            system("pause");
            system("cls");
            break;
        case '5':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                if (headCust == NULL) printf("\t������� �����!\n");
                else dataTableCust(&headCust);                
            }    
            system("pause");
            system("cls");
            break;
        case '6':
            if (CustomersFile == NULL) {
                printf("\t���� ������ ��� �� ������!\n");
            }
            else {
                
            }
            break;
        case '7':
            if (CustomersFile != NULL) {
                rewriteCust(&headCust, CustomersFile);
                fclose(CustomersFile);
                memset(headCust, 0, sizeof(Customers));
                free(headCust);
                headCust = NULL;
            }
            return;
        }
    }
}           