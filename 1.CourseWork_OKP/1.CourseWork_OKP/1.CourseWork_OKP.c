//
//������������ ���������� :
//1. ������������� �������� ���� 1 - �� ������ �� ���������� �������� :
//        a.���� ��� ���������������
//        b.���� ��� �������������
//        c.�����
//2. ������� ������ �������������� � �������� ������������ ������ ��������� ����� �
//������.�������� �� ������� ������� ������ ��������� � ��������� �����, ����������
//������������� �������� ���������� / ������������ ������� / �������.
//3. ���� 2 - �� ������ ������ ��������� :
//    -��� �������������� :
//        a) �������� / �������� ����� � �������
//        b) ���������� ������
//        c) �������������� ������
//        d) �������� ������
//        e) �������� ���� ������ � ��������� �����
//        f) ��������� ��������� ������ � ���������� ������
//        g) ���������� ��������������
//        h) ����� � ���� 1 - �� ������
//    - ��� �������� ������������ :
//        a) �������� ����� � �������
//        b) �������� ���� ������ � ��������� �����
//        c) ���������� ������
//        d) ��������� ��������� ������ � ���������� ������
//        e) ����� � ���� 1 - �� ������



//              �����  (��������, �������, ���, ��������, �������������, ���������) 5
//              �������  (�����������, �������, ���, ��������, �����������) 10
//              ���������  (��������, �����������, �������������, �������, ����������������) 15
//              �������������������  (�������������, ��������������, ����, ��������) 15



//                                          ���� �������� ������� �������

#define _CRT_SECURE_NO_WARNINGS   //�������, ������������ ���������, ��������� ������������� (�������� ������ �������� ������� �� �� ���������� ������)
#include <stdbool.h>            //������������� ���������� bool
#include <conio.h>              //���������� ����/����� (������ � �������) getch,getche
#include <stdlib.h>             //��������� ������, �������������� �����, atoi() - �������������� ������ � �����, itoa() - �������������� ����� � ������
#include <stdio.h>              //������� ����/����� + � ������� 
#include <string.h>             //������ �� �������� (strcmp)
#include <time.h>                //������� ��������� ����� ��������� � �������� � 1 ������ 1970 ����
#define MinLogSymbol 5          //���������� ���������� �������� ��� ������
#define MaxLogSymbol 24         //������������ ���������� �������� ��� ������
#define MinPassSymbol 8         //����������� ���������� �������� ��� ������
#define MaxPassSymbol 24        //������������ ���������� �������� ��� ������
////////////////////////////////
#define MaxNameSymbol 11
#define MaxSecondNameSymbol 16    //�� ������,�.�. ������ �������
#define MaxSpecialSymbol 35
#define MaxCategorSymbol 6
#define MaxDateSymbol 2
///////////////////////////////
#include "CoursFlib.h"          //������������ ���� � ���������
#include "HeaderTemp.h"
//typedef struct {
//    char login[MaxLogSymbol];
//    char password[MaxPassSymbol];
//}Account; //�� ������ �����������




int main() {
    system("chcp 1251>null");
    char* inputLogin = NULL, * inputPassword = NULL;
    const char* admin = "ADMIN", * user = "USER",* login = "LOGIN", * pass = "PASS";
    bool Login, Password, authCheck = false, EscCheck = false;
    FILE* authFile;
    authFile = fopen("Authentification.txt", "r");
    if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
        printf("\t������ �������� �����!\n");
    }
    while (1) {
        switch (main_menu()) {
        case '1':
            authFile = fopen("Authentification.txt", "r");
            if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
                printf("\t������ �������� �����!\n");
            }
            else {
                do {
                    EscCheck = false;
                    inputLogin = auth(inputLogin, login);
                    if (inputLogin != NULL) {
                        inputPassword = auth(inputPassword, pass);
                    }
                    if (inputLogin == NULL || inputPassword == NULL) {
                        EscCheck = true;
                        system("cls");
                    }
                    else {
                        Login = ReadAuthCheck(authFile, inputLogin, login, admin);
                        Password = ReadAuthCheck(authFile, inputPassword, pass, admin);
                        if (Login == true && Password == true) {
                            printf("\t�� ������� ����� � �������\n\n");
                            authCheck = true;
                        }
                        else {
                            printf("\t�������� ����� ��� ������\n\n");                            
                            authCheck = false;
                        }
                        system("pause");
                        system("cls");          
                    }
                } while (authCheck == false && EscCheck == false);
                free(inputLogin);
                free(inputPassword);
                if ((authFile = fopen("Authentification.txt", "r")) != NULL) {
                    fclose(authFile);
                }
                else {
                    printf("\t������ �������� �����!\n");
                }
                if (authCheck == true && EscCheck == false) {
                    admin_menu();
                }
            }
            break;
        case '2':
            authFile = fopen("Authentification.txt", "r");
            if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
                printf("\t������ �������� �����!\n");
            }
            else {
                
                do {
                    EscCheck = false;
                    inputLogin = auth(inputLogin, login);
                    if (inputLogin != NULL) {
                        inputPassword = auth(inputPassword, pass);
                    }
                    if (inputLogin == NULL || inputPassword == NULL) {
                        EscCheck = true;
                        system("cls");
                    }
                    else {
                        Login = ReadAuthCheck(authFile, inputLogin, login, user);
                        Password = ReadAuthCheck(authFile, inputPassword, pass, user);
                        if (Login == true && Password == true) {
                            printf("\t�� ������� ����� � �������\n\n");
                            authCheck = true;
                        }
                        else {
                            printf("\t�������� ����� ��� ������\n\n");  
                            authCheck = addUser(authFile, inputLogin, inputPassword);
                        }
                        system("pause");
                        system("cls");
                    }
                } while (authCheck == false && EscCheck == false);
                free(inputLogin);
                free(inputPassword);
                if ((authFile = fopen("Authentification.txt", "r")) != NULL) {
                    fclose(authFile);
                }
                else {
                    printf("\t������ �������� �����!\n");
                }
                if (authCheck == true && EscCheck == false) {
                    user_menu();
                }
            }
            break;
        case '3':
            return 0;
            break;
        }
    }
}