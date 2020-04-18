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
Date* headDate = 0;

typedef struct Customers{
    int ID;
    char* surname;
    char* name;
    char* middleName;
    struct Date dateBirthday;
    struct Customers* prev;
}Customers;
Customers* headCust = 0;

typedef struct {
    Doctors ID;
    Customers ID;
    Date DateAppeals;
    char diagnosis[100];
    int costOfTreatment;
}Appeals;
typedef struct {
    int IDindicators;
    int IDcompanies;
    Date dateDynamics;
}Dynamics;




            //Общие функции


//Считывание строки
char* writeString() { ////Исправить эту функцию по количеству символов и подставить в код
    char* str = NULL, s;
    int Esc = 0, n = 0;
    do {
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
            if (((int)s >= 65 && (int)s <= 90) || ((int)s>=97 && (int)s<=122) || ((int)s >= -64 && (int)s <= -1) || (int)s == -88 || (int)s == -72) {
                printf("%c", s);
                *(str + n) = s;
                n++;
            }
        }
    } while ((int)s != 13 && Esc == 0);
    *(str + n) = '\0';
    system("cls");
    return str;
}
char* writeStringInt() { ////Исправить эту функцию по количеству символов и подставить в код
    char* str = NULL, s;
    int Esc = 0, n = 0;
    do {
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
            if ((int)s>=49 || (int)s<=57) {
                printf("%c", s);
                *(str + n) = s;
                n++;
            }
        }
    } while ((int)s != 13 && Esc == 0);
    *(str + n) = '\0';
    system("cls");
    return str;
}





            //Функции для работы со структурами


//Просмотр всех значений в табличной форме
void dataTableDoc(Doctors** head) {
    Doctors* p = NULL;
    p = *head;
    puts("*****************************************************************************************************");
    puts("  ID  |     Фамилия    |    Имя    |    Отчество    |           Специальность           | Категория |");
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
    puts("|  ID  |     Фамилия    |    Имя    |    Отчество    | Дата рождения |");
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
        printf("|%6d|%16s|%11s|%16s|  %2s.%2s.%4d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
        puts("----------------------------------------------------------------------");
        p = p->prev;
    }
} 
//Добавление элемента в стек
void pushDoc(Doctors** head) {
    Doctors* p = NULL;
    if (*head == NULL) {
        p = malloc(sizeof(Doctors));
        if ((p = malloc(sizeof(Doctors))) == NULL) {
            exit(0);        //изменить сообщение
        }
        p->prev = NULL;
        p->ID = 1;
    }
    else {
        p = malloc(sizeof(Doctors));
        p->prev = *head;
        p->ID = (*head)->ID + 1;
    }     
    do {
        printf("Введите фамилию: ");
        p->surname = writeString();
        if (strlen(p->surname) > MaxSecondNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->surname) > MaxSecondNameSymbol);
    do {
        printf("Введите имя: ");
        p->name = writeString();
        if (strlen(p->name) > MaxNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->name) > MaxNameSymbol);    
    do {
        printf("Введите отчество: ");
        p->middleName = writeString();
        if (strlen(p->middleName) > MaxSecondNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->middleName) > MaxSecondNameSymbol);
    do {
        printf("Введите специальность: ");
        p->specialty = writeString();
        if (strlen(p->specialty) > MaxSpecialSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxSpecialSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->specialty) > MaxSpecialSymbol);    
    do {
        printf("Введите категорию: ");
        p->category = writeString();
        if (strlen(p->category) > MaxCategorSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxCategorSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->category) > MaxCategorSymbol);
    *head = p;
}
void pushCust(Customers** head) {
    Customers* p = NULL;
    char* tmp = NULL;
    bool check = false;
    if (*head == NULL) {
        p = malloc(sizeof(Doctors));
        if ((p = malloc(sizeof(Doctors))) == NULL) {
            exit(0);        //изменить сообщение
        }
        p->prev = NULL;
        p->ID = 1;
    }
    else {
        p = malloc(sizeof(Doctors));
        p->prev = *head;
        p->ID = (*head)->ID + 1;
    }   
    do {
        printf("Введите фамилию: ");
        p->surname = writeString();
        if (strlen(p->surname) > MaxSecondNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->surname) > MaxSecondNameSymbol);
    do {
        printf("Введите имя: ");
        p->name = writeString();
        if (strlen(p->name) > MaxNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->name) > MaxNameSymbol);
    do {
        printf("Введите отчество: ");
        p->middleName = writeString();
        if (strlen(p->middleName) > MaxSecondNameSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
            system("pause");
            system("cls");
        }
    } while (strlen(p->middleName) > MaxSecondNameSymbol);
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    do {  
        printf("Введите год: "); 
        tmp = writeStringInt();
        p->dateBirthday.year = atoi(tmp);
        if (p->dateBirthday.year <= 0 || p->dateBirthday.year > u->tm_year+1900 || p->dateBirthday.year < 1900) {
            printf("\tНекорректное значение\n");
            system("pause");
            system("cls");
        }
        else check = true;
    } while (check == false);    
    check = false;
    do {      
        printf("Введите месяц: "); 
        tmp = writeStringInt();
        p->dateBirthday.month = atoi(tmp);
        u->tm_mon = u->tm_mon + 1;
        if (p->dateBirthday.month <= 0 || p->dateBirthday.month > 12 || (p->dateBirthday.month > u->tm_mon && p->dateBirthday.year == 2020)) {
            printf("\tНекорректное значение\n");
            system("pause");
            system("cls");
        }
        else check = true;
    } while (check == false);
    check = false;
    bool checkDay = false;
    do {   
        printf("Введите день: ");
        tmp = writeStringInt();
        p->dateBirthday.day = atoi(tmp);
        if (u->tm_mon == p->dateBirthday.month && p->dateBirthday.year == 2020 && p->dateBirthday.day > u->tm_mday) { //прверка на ошибку завтрашнего дня
            checkDay = true;
        }
        else checkDay = false;
        check = false;
        if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 == 0 || checkDay == true) {
            if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 29 || checkDay == true) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        }
        else if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 != 0){
            if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 28) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        }
        else if (p->dateBirthday.month == 4 && p->dateBirthday.month == 6 && p->dateBirthday.month == 9 && p->dateBirthday.month == 11) {
            if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 30) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        }
        else {
            if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 31) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        }        
    } while (check == false);    
    *head = p;
} 
//Удаление элемента из стека
void popDoc(Doctors** head) {
    bool checkTruth = false;
    Doctors* p = NULL, * tmp;
    p = *head;
    int IDpop, n = 0;
    printf("Введите ID врача для удаления: ");
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
            printf("\tДанные врача с ID %d удалены\n", IDpop);
            system("pause");
        }
        else {
            p = p->prev;
            n++;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\tВрача с таким ID не существует\n");
        system("pause");
    }
}
void popCust(Customers** head) {
    bool checkTruth = false;
    Customers* p = NULL, * tmp;
    p = *head;
    int IDpop, n = 0;
    printf("Введите ID клиента для удаления: ");
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
            printf("\tДанные клиента с ID %d удалены\n", IDpop);
            system("pause");
        }
        else {
            p = p->prev;
            n++;
        }
    }
    if (checkTruth == false) {
        system("cls");
        printf("\tКлиента с таким ID не существует\n");
        system("pause");
    }
}
//Редактирование данных в стеке
void editDataDoc(Doctors** head) {
    int IDedit, editChoice, a = 0;
    bool checkTruth = false;
    Doctors* p = NULL;
    printf("Введите ID врача для редактирования: ");
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
        printf("\tВрача с таким ID не существует\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {            
            printf("\t1) Редактировать фамилию\n");
            printf("\t2) Редактировать имя\n");
            printf("\t3) Редактировать отчество\n");
            printf("\t4) Редактировать специальность\n");
            printf("\t5) Редактировать категорию\n");
            printf("\t6) Выход\n\n");
            scanf_s("%d", &editChoice);
            system("cls");
            switch (editChoice) {
            case 1:
                do {
                    printf("Введите фамилию: ");
                    p->surname = writeString(MaxSecondNameSymbol);
                    if (strlen(p->surname) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->surname) > MaxSecondNameSymbol);
                break;
            case 2:                
                do {
                    printf("Введите имя: ");
                    p->name = writeString(MaxNameSymbol);
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->surname) > MaxNameSymbol);
                break;
            case 3:
                do {
                    printf("Введите отчество: ");
                    p->middleName = writeString(MaxSecondNameSymbol);
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                    }
                } while (strlen(p->middleName) > MaxSecondNameSymbol);
                break;
            case 4:
                do {
                    printf("Введите специальность: ");
                    p->specialty = writeString(MaxSpecialSymbol);
                    if (strlen(p->specialty) > MaxSpecialSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSpecialSymbol);
                        system("pause");
                    }
                } while (strlen(p->specialty) > MaxSpecialSymbol);
                break;
            case 5:
                do {
                    printf("Введите категорию: ");
                    p->category = writeString(MaxCategorSymbol);
                    if (strlen(p->category) > MaxCategorSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxCategorSymbol);
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
    printf("Введите ID клиента для редактирования: ");
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
        printf("\tКлиента с таким ID не существует\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {
            printf("\t1) Редактировать фамилию\n");
            printf("\t2) Редактировать имя\n");
            printf("\t3) Редактировать отчество\n");
            printf("\t4) Редактировать дату рождения\n");
            printf("\t5) Выход\n\n");
            editChoice = getc(stdin);
            system("cls");
            switch (editChoice) {
            case '1':
                do {
                    printf("Введите фамилию: ");
                    p->surname = writeString();
                    if (strlen(p->surname) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->surname) > MaxSecondNameSymbol);
                break;
            case '2':
                do {
                    printf("Введите имя: ");
                    p->name = writeString();
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->name) > MaxNameSymbol);
                break;
            case '3':
                do {
                    printf("Введите отчество: ");
                    p->middleName = writeString();
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                } while (strlen(p->middleName) > MaxSecondNameSymbol);
                break;
            case '4':
                do {
                    printf("Введите год: ");
                    tmp = writeStringInt();
                    p->dateBirthday.year = atoi(tmp);
                    if (p->dateBirthday.year <= 0 || p->dateBirthday.year > u->tm_year + 1900 || p->dateBirthday.year < 1900) {
                        printf("\tНекорректное значение\n");
                        system("pause");
                        system("cls");
                    }
                    else check = true;
                } while (check == false);
                check = false;
                do {
                    printf("Введите месяц: ");
                    tmp = writeStringInt();
                    p->dateBirthday.month = atoi(tmp);
                    u->tm_mon = u->tm_mon + 1;
                    if (p->dateBirthday.month <= 0 || p->dateBirthday.month > 12 || (p->dateBirthday.month > u->tm_mon&& p->dateBirthday.year == 2020)) {
                        printf("\tНекорректное значение\n");
                        system("pause");
                        system("cls");
                    }
                    else check = true;
                } while (check == false);
                check = false;
                bool checkDay = false;
                do {
                    printf("Введите день: ");
                    tmp = writeStringInt();
                    p->dateBirthday.day = atoi(tmp);
                    if (u->tm_mon == p->dateBirthday.month && p->dateBirthday.year == 2020 && p->dateBirthday.day > u->tm_mday) { //прверка на ошибку завтрашнего дня
                        checkDay = true;
                    }
                    else checkDay = false;
                    check = false;
                    if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 == 0 || checkDay == true) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 29 || checkDay == true) {
                            printf("\tНекорректное значение\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else if (p->dateBirthday.month == 2 && p->dateBirthday.year % 4 != 0) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 28) {
                            printf("\tНекорректное значение\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else if (p->dateBirthday.month == 4 && p->dateBirthday.month == 6 && p->dateBirthday.month == 9 && p->dateBirthday.month == 11) {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 30) {
                            printf("\tНекорректное значение\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                    else {
                        if (p->dateBirthday.day <= 0 || p->dateBirthday.day > 31) {
                            printf("\tНекорректное значение\n");
                            system("pause");
                            system("cls");
                        }
                        else check = true;
                    }
                } while (check == false);
            case '5':
                a = 1;
                break;
            }
        }
    }
}
                            //сделать редактирование (не исправлено по пунктам)


            //Менюшки


//Меню 1-го уровня
char main_menu() {
    int first_choice;
    do {
        printf("\t1) Администратор\n\t2) Пользователь\n\t3) Выход\n");
        /*scanf_s("%d", &first_choice);
        system("cls");
        return first_choice;*/
        first_choice = getc(stdin);
        system("cls");
    } while ((int)first_choice < 48 || (int)first_choice > 57);
    return first_choice;
}
//Меню 2-го уровня для администратора
void admin_menu() {
    int admin_choice;
    FILE* patients;
    while (1) {
        printf("\t1) Создание / открытие файла с данными врачей\n");
        printf("\t2) Добавление записи врача\n");
        printf("\t3) Редактирование записи врача\n");
        printf("\t4) Удаление записи врача\n");
        printf("\t5) Просмотр всех данных врачей в табличной форме\n");
        printf("\t6) Поиск и фильтрация данных врачей\n"); //---------------------------------
        printf("\t7) Управление клиентами\n"); //-----------------------------------
        printf("\t8) Выход в меню\n");
        admin_choice = getc(stdin);
        system("cls");
        switch (admin_choice) {
        case '1':
            patients = fopen("ListOfPatients.txt", "a");
            if ((patients = fopen("ListOfPatients.txt", "a")) == NULL) {
                printf("\tОшибка создания файла!\n");
            }
            else printf("\tВыполнено\n");
            system("pause");
            system("cls");
            break;
        case '2':
            /* freopen("ListOfPatients.txt", "a", stdout);*/
            pushDoc(&headDoc);
            system("pause");
            system("cls");
            break;
        case '3':
            editDataDoc(&headDoc);
            system("cls");
            break;
        case '4':
            popDoc(&headDoc);
            system("cls");
            break;
        case '5':
            dataTableDoc(&headDoc);
            system("pause");
            system("cls");
            break;
        case '6':
            system("cls");
            break;
        case '7':
            break;
        case '8':
            if (patients = fopen("ListOfPatients.txt", "a")) {
                fclose(patients);
            }
            return;
        }

    }
}
//Меню 2-го уровня для пользователя
void user_menu()
{
    int user_choice, a = 0;
    FILE* Customers;
    while (1) {
        printf("\t1) Открытие файла с данными клиентов\n");
        printf("\t2) Добавление записи клиента\n");
        printf("\t3) Удаление записи клиента\n");
        printf("\t4) Редактирование записи клиента\n");
        printf("\t5) Просмотр всех данных клиентов в табличной форме\n");
        printf("\t6) ???????????????????Выполнение задачи???????????????\n");
        printf("\t7) Поиск и фильтрация данных\n");
        printf("\t8) Выход в меню\n");
        user_choice = getc(stdin);
        system("cls");
        switch (user_choice) {
        case '1':
            Customers = fopen("ListOfPatients.txt", "a");
            if ((Customers = fopen("ListOfPatients.txt", "a")) == NULL) {
                printf("\tОшибка создания файла!\n");
            }
            break;
        case '2':
            pushCust(&headCust);
            system("pause");
            system("cls");
            break;
        case '3':
            popCust(&headCust);
            system("cls");
            break;
        case '4':
            editDataCust(&headCust);
            system("cls");
            break;
        case '5':
            dataTableCust(&headCust);
            system("pause");
            system("cls");
            break;
        case '6':
            system("cls");
            break;
        case '7':
            break;
        case '8':
            if (Customers = fopen("ListOfPatients.txt", "a")) {
                fclose(Customers);
            }
            return;
        }
    }
}


            //Функции для авторизации


//Определение режима проверки auth
void DeterminePoz(FILE* File, const char* InputMode) {
    int n = 0/*, CheckTruthFind = 0*/;
    bool CheckTruthFind = false;
    char* str, s;
    fseek(File, 0, SEEK_SET);
    do {
        do {
            s = fgetc(File);
        } while ((int)s != -103 && s != EOF);
        if (s == EOF) {
            printf("Ошибка доступа!\n");
        }
        else {
            str = (char*)malloc(sizeof(char) * 7);
            n = 0;
            do {
                s = fgetc(File);
                *(str + n) = s;
                n++;
            } while (n != 6);
            if (strcmp(InputMode, "ADMIN") == 0) {
                *(str + n) = '\0';
            }
            else {
                *(str + n - 1) = '\0';
            }
            if (strcmp(InputMode, "ADMIN") == 0) {
                if (strcmp(str, "ADMIN™") == 0) {
                    CheckTruthFind = true;
                }
            }
            else {
                if (strcmp(str, "USER™") == 0) {
                    CheckTruthFind = true;
                    fseek(File, -1, SEEK_CUR);
                }
            }
        }
    } while (CheckTruthFind != true && s != EOF);
}
//Поиск и сравнение логина/пароля
bool SearchCompare(FILE* File, char* EnteredData, const char* InputMode, const char* CheckMode) {
    int n = 0, CheckTruthFind = 0, CountUsers = 0;
    char* str, s;
    bool CheckTruth = false;
    s = fgetc(File);
    do {
        n = 0;
        s = fgetc(File);
        if ((int)s == -103) {
            s = EOF;
        }
        else {
            if (strcmp(CheckMode, "PASS") == 0) {
                s = fgetc(File);
                while (s != '\n' && s != EOF) {
                    s = fgetc(File);
                }
                if (CountUsers < 9) { fseek(File, 1, SEEK_CUR); }
                else{ fseek(File, 0, SEEK_CUR); }
            }
            if (CountUsers >= 9) {
                fseek(File, 9, SEEK_CUR);
            }
            else {
                fseek(File, 8, SEEK_CUR);
            }            
            str = (char*)malloc(sizeof(char) * MaxLogSymbol + 1);
            s = fgetc(File);
            while (s != '\n' && s != EOF) {
                *(str + n) = s;
                n++;
                s = fgetc(File);
            }
            *(str + n) = '\0';
            CountUsers++;
            if (!strcmp(EnteredData, str)) { // strcmp(EnteredData, str) == 0        =    !strcmp(EnteredData, str
                CheckTruth = true;
            }
            else if (strcmp(CheckMode, "LOGIN") == 0) {
                do {
                    s = fgetc(File);
                } while (s != '\n' && s != EOF);
            }
            free(str);
        }
    } while (CheckTruth != true && s != EOF && CountUsers < 99);
    if (CountUsers == 99) {
        printf("Достигнуто максимальное количество пользователей\n");
    }
    return CheckTruth;
}
//Ввод логина/пароля
char* auth(char* str, const char* CheckMode) {
    char s;
    int n = 0, valid_input = 0, Esc = 0;
    if ((strcmp(CheckMode, "LOGIN")) == 0) {
        printf("Введите логин: ");
        str = (char*)malloc(sizeof(char) * MaxLogSymbol + 1);
    }
    else {
        printf("Введите пароль: ");
        str = (char*)malloc(sizeof(char) * MaxPassSymbol + 1);
    }
    do {            ///Добавить функцию под ввод символов
        do {
            s = _getch();
            if ((int)s == 27) {
                Esc++;
            }
            else if ((int)s == 8 && n > 0) { //!!!!!!!!!!!!!!!!!исправить ошибку удаления лишних символов
                printf("\b ");
                printf("\b");
                *(str + n) = NULL;
                n--;
            }
            else if ((int)s != 8) {  // (if ((int)s != 8) ) - исправление backspace
                if ((strcmp(CheckMode, "PASS")) == 0) {
                    printf("*");
                }
                else {
                    printf("%c", s);
                }
                *(str + n) = s;
                n++;
            }
        } while ((int)s != 13 && valid_input == 0 && Esc == 0);
        if (Esc == 0) {
            if ((strcmp(CheckMode, "LOGIN")) == 0) {
                if (n < MinLogSymbol + 1 || n > MaxLogSymbol + 1) {
                    system("cls");
                    printf("Допустимая длина логина - от 4-х до 20-ти знаков\n");
                    n = 0;
                    valid_input = 0;
                    printf("Введите логин: ");
                }
                else {
                    valid_input = 1;
                }
            }
            else {
                if (n < MinPassSymbol + 1 || n > MaxPassSymbol + 1) {
                    system("cls");
                    printf("Допустимая длина пароля - от 8-и до 20-ти знаков\n");
                    n = 0;
                    valid_input = 0;
                    printf("Введите пароль: ");
                }
                else {
                    valid_input = 1;
                }
            }
        }
    } while (n < MinLogSymbol + 1 && n > MaxLogSymbol + 1 && Esc == 0);
    if (Esc == 0) {
        *(str + n - 1) = '\0';
        system("cls");
        return str;
    }
    else {
        return NULL;
    }
}
//Проверка логина/пароля
bool ReadAuthCheck(FILE* File, char* EnteredData, const char* CheckMode, const char* InputMode) {
    int n = 0;
    const char* login = "LOGIN", * pass = "PASS";
    bool CheckTruth;
    if ((strcmp(CheckMode, "LOGIN")) == 0) { //проверка логина
        if (strcmp(InputMode, "ADMIN") == 0) { //проверка у админа
            DeterminePoz(File, InputMode);
            CheckTruth = SearchCompare(File, EnteredData, InputMode, login);
        }
        else {                              //проверка у пользователя  
            DeterminePoz(File, InputMode);
            CheckTruth = SearchCompare(File, EnteredData, InputMode, login);
        }
    }
    else { //проверка пароля
        if (strcmp(InputMode, "ADMIN") == 0) {
            DeterminePoz(File, InputMode);
            CheckTruth = SearchCompare(File, EnteredData, InputMode, pass);
        }
        else {
            DeterminePoz(File, InputMode);
            CheckTruth = SearchCompare(File, EnteredData, InputMode, pass);
        }
    }
    return CheckTruth;
}
//Добавление нового пользователя (+вывод сообщения)
bool addUser(FILE* File, char* Login, char* Password) {
    const char* user = "USER";
    char s = NULL;
    int n = 0, choice;
    printf("\tХотите зарегестрировать нового пользователя?\n\n");
    printf("\t1) Да\t\t\t2)Нет\n");
    scanf_s("%d", &choice);
    system("cls");
    do {
        switch (choice) {
        case 1:
            DeterminePoz(File, user);
            do {
                do {
                    s = fgetc(File);
                } while (s != '\n' && s != EOF);
                n++;
            } while (s != EOF);
            n /= 2;
            fclose(File);
            File = fopen("Authentification.txt", "a+");
            if ((File = fopen("Authentification.txt", "a+")) == NULL) {
                printf("\tОшибка открытия файла!\n");
            }
            else {
                fprintf(File, "\n%d)Login: %s\n  Passw: %s", n + 1, Login, Password);
                fclose(File);
                File = fopen("Authentification.txt", "r");
                if ((File = fopen("Authentification.txt", "r")) == NULL) {
                    printf("\tОшибка открытия файла!\n");
                }
                printf("\tПользователь успешно добавлен\n");
                system("pause");
                system("cls");
                return true;
                break;
            }
        case 2:
            return false;
            break;
        }
    } while (choice != 1 && choice != 2);
}