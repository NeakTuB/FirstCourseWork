//
//Обязательные требования :
//1. Предусмотреть создание меню 1 - го уровня со следующими пунктами :
//        a.Вход под администратором
//        b.Вход под пользователем
//        c.Выход
//2. Учетные записи администратора и обычного пользователя должна содержать логин и
//пароль.Сведения об учетных записях должны храниться в отдельном файле, желательно
//предусмотреть механизм шифрования / дешифрования логинов / паролей.
//3. Меню 2 - го уровня должно содержать :
//    -Для администратора :
//        a) Создание / открытие файла с данными
//        b) Добавление записи
//        c) Редактирование записи
//        d) Удаление записи
//        e) Просмотр всех данных в табличной форме
//        f) Различные процедуры поиска и фильтрации данных
//        g) Управление пользователями
//        h) Выход в меню 1 - го уровня
//    - Для обычного пользователя :
//        a) Открытие файла с данными
//        b) Просмотр всех данных в табличной форме
//        c) Выполнение задачи
//        d) Различные процедуры поиска и фильтрации данных
//        e) Выход в меню 1 - го уровня



//              Врачи  (КодВрача, Фамилия, Имя, Отчество, Специальность, Категория) 5
//              Больные  (КодБольного, Фамилия, Имя, Отчество, ГодРождения) 10
//              Обращения  (КодВрача, КодБольного, ДатаОбращения, Диагноз, СтоимостьЛечения) 15
//              ДинамикаПоказателей  (КодПоказателя, КодПредприятия, Дата, Значение) 15



//                                          Учет клиентов платной клиники

#define _CRT_SECURE_NO_WARNINGS   //функции, возвращающие указатель, считаются небезопасными (заменить старые названия функций на их безопасные версии)
#include <stdbool.h>            //использование переменных bool
#include <conio.h>              //консольный ввод/вывод (работа с текстом) getch,getche
#include <stdlib.h>             //выделение памяти, преобразование типов, atoi() - преобразование строки в число, itoa() - преобразование числа в строку
#include <stdio.h>              //обычный ввод/вывод + с файлами 
#include <string.h>             //работа со строками (strcmp)
#include <time.h>                //текущее системное время выводимое в секундах с 1 января 1970 года
#define MinLogSymbol 5          //Минималько количество символов для логина
#define MaxLogSymbol 24         //Максимальное количество символов для логина
#define MinPassSymbol 8         //Минимальное количество символов для пароля
#define MaxPassSymbol 24        //Максимальное количество символов для пароля
////////////////////////////////
#define MaxNameSymbol 11
#define MaxSecondNameSymbol 16    //не менять,т.к. съедет таблица
#define MaxSpecialSymbol 35
#define MaxCategorSymbol 6
#define MaxDateSymbol 2
///////////////////////////////
#include "CoursFlib.h"          //заголовочный файл с функциями
#include "HeaderTemp.h"
//typedef struct {
//    char login[MaxLogSymbol];
//    char password[MaxPassSymbol];
//}Account; //на случай переработки




int main() {
    system("chcp 1251>null");
    char* inputLogin = NULL, * inputPassword = NULL;
    const char* admin = "ADMIN", * user = "USER",* login = "LOGIN", * pass = "PASS";
    bool Login, Password, authCheck = false, EscCheck = false;
    FILE* authFile;
    authFile = fopen("Authentification.txt", "r");
    if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
        printf("\tОшибка открытия файла!\n");
    }
    while (1) {
        switch (main_menu()) {
        case '1':
            authFile = fopen("Authentification.txt", "r");
            if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
                printf("\tОшибка открытия файла!\n");
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
                            printf("\tВы успешно вошли в систему\n\n");
                            authCheck = true;
                        }
                        else {
                            printf("\tНеверный логин или пароль\n\n");                            
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
                    printf("\tОшибка закрытия файла!\n");
                }
                if (authCheck == true && EscCheck == false) {
                    admin_menu();
                }
            }
            break;
        case '2':
            authFile = fopen("Authentification.txt", "r");
            if ((authFile = fopen("Authentification.txt", "r")) == NULL) {
                printf("\tОшибка открытия файла!\n");
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
                            printf("\tВы успешно вошли в систему\n\n");
                            authCheck = true;
                        }
                        else {
                            printf("\tНеверный логин или пароль\n\n");  
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
                    printf("\tОшибка закрытия файла!\n");
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