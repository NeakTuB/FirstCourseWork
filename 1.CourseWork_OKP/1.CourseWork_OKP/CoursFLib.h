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
typedef struct Accounts {
    char* login;
    char* password;
    int IDdoc;
    int mode;
    struct Accounts* prev;
}Accounts;
Accounts* headAcc = NULL;
char* encryption(char*);
//Считывание строки с клавиатуы со всеми проверками на ввод чисел и букв
    //1 - только цифры 
    //2 - только русские буквы и чёрточка
    //3 - англ и русские буквы, - _ / . ,  и цифры
    //4 - англ буквы и цифры, - , _. 
bool checkStr(char**, int);
char* writeStr(int);
char* readFromFile(FILE);
//приводит строку в нужную форму (первая букву в верхнем регистре, а остальные в нижнем)
char* strconv(char*);
//считывание информации в структуры с файла
void readingDataDoc(Doctors**, FILE*);
void readingDataCust(Customers**, FILE*);
void readingDataApp(Appeals**, FILE*);
void readingDataAccount(Accounts**, FILE*);
//перезапись структуры в файл:
    //вывод в файл одного врача (повторение)
void fprintfDoc(Doctors**, FILE*);
void rewriteDoc(Doctors**, FILE*);
//вывод в файл данных одного врача (повторение)
void fprintfAccount(Accounts**, FILE*);
void rewriteAccount(Accounts**, FILE*);
//вывод в файл одного клиента (повторение)
void fprintfCust(Customers**, FILE*);
void rewriteCust(Customers**, FILE*);
//вывод в файл одно обращение (повторение)
void fprintfApp(Appeals**, FILE*);
void rewriteApp(Appeals**, FILE*);
//сравнение введённых данных с файло для проверки наличия пользователя
bool compare(char**, FILE*, int);



//Функции для авторизации

//проверка логина и пароля
bool ReadAuthCheck(FILE*, char*, char*, int);
//вызов проверки и ввод логина и пароля
int AuthFunction(int);
//регистрация нового пользователя, если главврач его добавил 
void registration();
//изменение пароля
void EditPass(Accounts**, int);



//Функции для работы со структурами


//Просмотр всех значений в табличной форме
void dataTableDoc(Doctors**);
void dataTableCust(Customers**);
void dataTableApp(Appeals**);
//Добавление элемента в стек
    //изменение на первую букву в верхнем регистре, а остальные в нижнем
void pushDoc(Doctors**, FILE*);
void pushCust(Customers**, FILE*);
void PushAppealCust(Appeals**, Customers**, FILE*, FILE*, int);
//Удаление элемента из стека
void popDoc(Doctors**, Accounts**);
void popCust(Customers**);
//Редактирование данных в стеке
    //исправить менюшку
void editDataDoc(Doctors**);
void editDataCust(Customers**);
void editDataApp(Appeals** head);
//шапка для вывода данных врача
void DoctorsHat();
//шапка для вывода данных пациента
void CustomersHat();
//шапка для вывода данных приёма
void AppealsHat();
//поиск врача по ID
void SearchIDDoc(Doctors* head);
//поиск врача по фамилии
void SearchSurnameDoc(Doctors* head);
//поиск врача по имени
void SearchNameDoc(Doctors* head);
//поиск врача по отчеству
void SearchMiddleNameDoc(Doctors* head);
//поиск врача по специальности
void SearchSpecialtyDoc(Doctors* head);
//поиск врача по категории
void SearchCategoryDoc(Doctors* head);
//меню поиска врачей
void SearchMenuDoc(Doctors* head);
//сорттировка врачей по ID по возрастанию
void SortIDUpDoc(Doctors** head);
//сортировка врачей по ID по убыванию
void SortIDDownDoc(Doctors** head);
//сортировка врачей по фамилии по алфавиту
void SortSurnameDoc(Doctors** head);
//сортировка врачей по имени по алфавиту
void SortNameDoc(Doctors** head);
//сортировка врачей по отчеству по алфавиту
void SortMiddleNameDoc(Doctors** head);
//сортировка врачей по специальности по алфавиту
void SortSpecialtyDoc(Doctors** head);
//сортировка врачей по категории
void SortCategoryDoc(Doctors** head);
//меню сортировки врачей
void SortMenuDoc(Doctors* head);
//выполнение задачи
void Task(Appeals** head);
//поиск пациента по ID
void SearchIDCust(Customers* head);
//поиск пациента по фамилии 
void SearchSurnameCust(Customers* head);
//поиск пациента по имени
void SearchNameCust(Customers* head);
//поиск пациента по отчесту
void SearchMiddleNameCust(Customers* head);
//поиск пациента по дате рождения
void SearchDateCust(Customers* head);
//меню поиска пациентов
void SearchMenuCust(Customers* head);
//сортировка ID пациентов по возрастанию
void SortIDUpCust(Customers** head);
//сортировка ID пациентов по убыванию
void SortIDDownCust(Customers** head);
//сортировка фамилий пациентов по алфавиту
void SortSurnameCust(Customers** head);
//сортировка имён пациентов по алфавиту
void SortNameCust(Customers** head);
//сортировка отчеств пациентов по алфавиту
void SortMiddleNameCust(Customers** head);
///////////////////////////
//сортировка даты по убыванию
void SortDateDownCust(Customers**);
//сортировка даты по возрастанию
void SortDateUpCust(Customers**);
//меню сортировки пациентов
void SortMenuCust(Customers*);
//поиск по ID доктора
void SearchIDAppDoc(Appeals*);
//поиск по ID пациента
void SearchIDAppCust(Appeals*);
//поиск дигноза
void SearchDiagnosisApp(Appeals*);
//меню поиска приёмов
void SearchMenuApp(Appeals*);
//сортировка ID приёма по возрастанию
void SortIDUpApp(Appeals**);
//сортировка ID приёма по убыванию
void SortIDDownApp(Appeals**);
//сортировка даты приёма от новой к старой
void SortDateDownApp(Appeals**);
//сортировка даты приёма от старой к новой
void SortDateUpApp(Appeals**);
//сортировка стоимости по возрастанию
void SortCoastUpApp(Appeals** head);
//сортировка стоимости по убыванию
void SortCoastDownApp(Appeals**);
//меню сортировки приёмов
void SortMenuApp(Appeals**);
//меню для выбора поиск\сортировка
char manage_menu();
//выбор действий с данными врачей
void ManageDataDoc(Doctors*);
//выбор действий с данными пациентов
void ManageDataCust(Customers*);
//выбор действий с данными приёмов
void ManageDataApp(Appeals*);
//меню выбора данных для работы
void UserSwitchDataMenu(Customers* , Appeals*);
//меню для выбора просматриваемых данных
char data_menu();
//Меню 1-го уровня
char main_menu();
//Меню 2-го уровня для врача
void user_menu(int);
//Меню 2-го уровня для главврача
void admin_menu(int);
//Меню 2-го уровня для медрегистатора
void regist_menu(int);



















            //Общие функции
//шифрование
char* encryption(char* str)
{
    if (atoi(str) != 0) _itoa((atoi(str) ^ 225), str, 10);
    else for (int i = 0; i < (int)strlen(str); i++) str[i] = *(str + i) ^ 225;
    return str;
}
//Считывание строки с клавиатуы со всеми проверками на ввод чисел и букв
    //1 - только цифры 
    //2 - только русские буквы и чёрточка
    //3 - англ и русские буквы, - _ / . ,  и цифры
    //4 - англ буквы и цифры, - , _. 
bool checkStr(char** str,int mode) {
    bool check = false;
    char s;
    for (int i = 0; i < (int)strlen(*str); i++) {
        check = true;
        s = *(*str + i);
        if (mode == 1) {
            if ((int)s < 48 && (int)s > 57) {
                check = false;
                i = strlen(*str);
                printf("\n\tНеккоректный ввод! Возможно ввести только цифры.\n\n");
            }
        }
        else if (mode == 2) {
            if ((int)s < -88 || (int)s > -88 && (int)s < -72 || (int)s > -72 && (int)s < -64 || (int)s > -1 && (int)s < 45 || (int)s > 45) {
                check = false;
                i = strlen(*str);
                printf("\n\tНеккоректный ввод! Возможные символы: А-я, '-'. \n\n");
            }
        }
        else if (mode == 3) {
            if ((int)s < -88 || (int)s > -88 && (int)s < -72 || (int)s > - 72 && (int)s < -64 || (int)s > -1 && (int)s < 32 || (int)s > 32 && (int)s < 44 || (int)s > 47 && (int)s < 48 || (int)s > 57 && (int)s < 65 || (int)s > 90 && (int)s < 95 || (int)s > 95 && (int)s < 97 || (int)s > 122){
                check = false;
                i = strlen(*str);
                printf("\n\tНеккоректный ввод! Возможные символы: А-я, A-z и спецсимволы.\n\n");
            }
        }
        else if (mode == 4) {
            if ((int)s < 45 || (int)s > 46 && (int)s < 48 || (int)s > 57 && (int)s < 65 || (int)s > 90 && (int)s < 95 || (int)s > 95 && (int)s < 97 || (int)s > 122) {
                check = false;
                i = strlen(*str);
                printf("\n\tНеккоректный ввод! Возможные символы: A-z, 0-9, '-' , '_'.\n\n");
            }
        }
    }
    if (check == true) return true;
    else {
        system("pause");
        system("cls");
        return false;
    }
}
char* writeStr(int modeAuth) { ////Исправить эту функцию по количеству символов и подставить в код
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
            n--;
        }
        else if ((int)s != 8 && (int)s != 13) {
            if (modeAuth == 1) {
                printf("*");                
            }
            else {
                printf("%c", s);
            }
            *(str + n) = s;
            n++;
        }
    } while ((int)s != 13 && Esc == 0);
    *(str + n) = '\0';
    printf("\n");
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
//приводит строку в нужную форму (первая букву в верхнем регистре, а остальные в нижнем)
char* strconv(char* str) {
    int count, string = (int)*str;
    count = strlen(str);
    if (strcmp(str, "EscMode") == 0) return "EscMode";
    else if (string >= -32 && string <= -1) {
        string -= 32;
        *str = (char)string;
    }
    else if (string == -72) {
        string = -88;
        *str = (char)string;
    }
    for (int i = 1; i < count; i++) {
        string = (int)*(str + i);
        if (string >= -64 && string <= -33) string += 32;
        else if (string == -88) string = -72;
        *(str + i) = (char)string;
    }
    return str;
}
//считывание информации в структуры с файла
void readingDataDoc(Doctors** head, FILE* Doc) {
    Doctors* p = NULL;
    int count = 0, tmp = 0;
    fseek(Doc, 0, SEEK_END);
    if (ftell(Doc) == 0);
    else {
        p = malloc(sizeof(Doctors));
        if ((p = malloc(sizeof(Doctors))) == NULL) {
            printf("\tОшибка выделения памяти для стека!\n");
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
            printf("\tОшибка выделения памяти для стека!\n");
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
            printf("\tОшибка выделения памяти для стека!\n");
        }
        tmp = ftell(Doc);
        fseek(Doc, 0, SEEK_SET);
        do {
            if (count == 0) {
                p->prev = NULL;
                p->NumApp = atoi(readFromFile(Doc));
                p->IDdoc = atoi(readFromFile(Doc));
                p->IDcust = atoi(readFromFile(Doc));
                p->dateAppeal.day = atoi(readFromFile(Doc));
                p->dateAppeal.month = atoi(readFromFile(Doc));
                p->dateAppeal.year = atoi(readFromFile(Doc));
                p->diagnosis = readFromFile(Doc);
                p->costOfTreatment = atoi(readFromFile(Doc));
                count++;
            }
            else {
                p = malloc(sizeof(Appeals));
                p->prev = *head;
                p->NumApp = atoi(readFromFile(Doc));
                p->IDdoc = atoi(readFromFile(Doc));
                p->IDcust = atoi(readFromFile(Doc));
                p->dateAppeal.day = atoi(readFromFile(Doc));
                p->dateAppeal.month = atoi(readFromFile(Doc));
                p->dateAppeal.year = atoi(readFromFile(Doc));
                p->diagnosis = readFromFile(Doc);
                p->costOfTreatment = atoi(readFromFile(Doc));
                count++;
            }
            *head = p;
        } while (ftell(Doc) < tmp);
    }
}
void readingDataAccount(Accounts** head, FILE* Doc) {
    Accounts* p = NULL;
    int count = 0, tmp = 0, countN = 0;
    fseek(Doc, 0, SEEK_END);
    if (ftell(Doc) == 0) {
        printf("\tФайл пуст!\n");
        system("pause");
        system("cls");
    }
    else {
        p = malloc(sizeof(Accounts));
        if ((p = malloc(sizeof(Accounts))) == NULL) {
            printf("\tОшибка выделения памяти для стека!\n");
        }
        tmp = ftell(Doc);
        fseek(Doc, 0, SEEK_SET);
        do {
            if (count == 0) {
                p->login = encryption(readFromFile(Doc));
                p->password = encryption(readFromFile(Doc));
                p->mode = atoi(encryption(readFromFile(Doc)));
                p->IDdoc = atoi(encryption(readFromFile(Doc)));
                p->prev = NULL;
                count++;
            }
            else {
                p = malloc(sizeof(Doctors));
                p->prev = *head;
                p->login = encryption(readFromFile(Doc));
                p->password = encryption(readFromFile(Doc));
                p->mode = atoi(encryption(readFromFile(Doc)));
                p->IDdoc = atoi(encryption(readFromFile(Doc)));
                count++;
            }
            *head = p;
        } while (ftell(Doc) < tmp);
    }
}
//перезапись структуры в файл:
    //вывод в файл одного врача (повторение)
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
        printf("\tОшибка создания / открытия файла!\n");
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
//вывод в файл данных одного врача (повторение)
void fprintfAccount(Accounts** p, FILE* File) {;
    fprintf(File, "%s ", encryption((*p)->login));
    fprintf(File, "%s ", encryption((*p)->password));
    fprintf(File, "%d ", (*p)->mode ^ 225);
    fprintf(File, "%d\n", (*p)->IDdoc ^ 225);
}
void rewriteAccount(Accounts** head, FILE* File) {
    Accounts* p = *head;
    if (File != NULL) {
        fclose(File);
        File = fopen("Authentification.txt", "w+");
    }
    if (File == NULL) {
        printf("\tОшибка создания / открытия файла!\n");
    }
    else {
        if (*head == NULL);
        else {
            p = *head;
            do {
                fprintfAccount(&p, File);
                p = p->prev;
            } while (p != NULL);
        }
    }
}
    //вывод в файл одного клиента (повторение)
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
        printf("\tОшибка создания / открытия файла!\n");
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
//вывод в файл одно обращение (повторение)
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
        printf("\tОшибка создания / открытия файла!\n");
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
    //сравнение введённых данных с файло для проверки наличия пользователя
bool compare(char** str, FILE* File, int mode) {
    fseek(File, 0, SEEK_END);
    int tmp = ftell(File);
    if (tmp != 0) {
        fseek(File, 0, SEEK_SET);
        do {
            if (mode == 2) readFromFile(File);
            if ((strcmp(*str, readFromFile(File))) == 0) return true;
        } while (ftell(File) < tmp);
        return false;
    }
    else return false;
}



        //Функции для авторизации

//проверка логина и пароля
bool ReadAuthCheck(FILE* File, char* login, char* pass, int mode) {
    fseek(File, 0, SEEK_END);
    int tmp = ftell(File);
    bool checkLogin = false, checkPassword = false, checkMode = false;
    if (tmp == 0) return false;
    else {
        fseek(File, 0, SEEK_SET);
        do {
            if (strcmp(readFromFile(File), login) == 0) checkLogin = true;
        } while (ftell(File) < tmp && checkLogin == false);
        if (checkLogin == true) {
            if (strcmp(readFromFile(File), pass) == 0) checkPassword = true;
            if (atoi(encryption(readFromFile(File))) == mode) checkMode = true;
            readFromFile(File);
        }
        if (checkLogin == true && checkPassword == true && checkMode == true) return true;
        else return false;
    }

}
//вызов проверки и ввод логина и пароля
int AuthFunction(int mode) {
    FILE* authFile,* DoctorsFile = NULL;
    bool Auth = false, EscCheck = false, check;
    char* inputLogin = NULL, * inputPassword = NULL;
    int ID = 0;
    authFile = fopen("Authentification.txt", "a+");
    if (authFile == NULL) {
        printf("\tОшибка открытия файла!\n");
    }
    else {
        fseek(authFile, 0, SEEK_END);
        if (ftell(authFile) == 0 && mode == 1) {
            DoctorsFile = fopen("ListOfDoctors.txt", "a+");
            if (DoctorsFile == NULL) {
                printf("\tОшибка открытия файла!\n");
            }
            else {
                printf("\n\t\tРегистрация главврача\n\t* * * * * * * * * * * * * * *\n\n");
                pushDoc(&headDoc, DoctorsFile);
                if (DoctorsFile != NULL) {
                    rewriteDoc(&headDoc, DoctorsFile);
                    fclose(DoctorsFile);
                    memset(headDoc, 0, sizeof(Doctors));
                    free(headDoc);
                }
            }
        }
        do {
            check = true;
            EscCheck = false;
            do {
                printf("\n\t\tАвторизация\n\t* * * * * * * * * * * * * * *\n\n");
                printf("  Введите логин: ");
                inputLogin = writeStr(0);
                if (strcmp(inputLogin, "") == 0) {
                    EscCheck = true;
                    check = true;
                    Auth = true;
                }
                else {
                    if (strcmp(inputLogin, "EscMode") == 0) EscCheck = true;
                    else {
                        if (strlen(inputLogin) < MinLogSymbol || strlen(inputLogin) > MaxLogSymbol) {
                            printf("\n\tВозможный размер логина от %d до %d символов!\n\n", MinLogSymbol, MaxLogSymbol);
                            system("pause");
                            system("cls");
                            check = false;
                        }
                        if(check == true) check = checkStr(&inputLogin, 4);
                    }
                }
            } while (EscCheck == false && check == false);
            check = true;
            if (EscCheck == false) {
                do {
                    system("cls");
                    printf("\n\t\tАвторизация\n\t* * * * * * * * * * * * * * *\n\n");
                    printf("  Введите логин: ");
                    printf("%s\n", inputLogin);
                    printf("  Введите пароль: ");
                    inputPassword = writeStr(1);
                    if (strcmp(inputPassword, "") == 0) {
                        EscCheck = true;
                        check = true;
                        Auth = true;
                    }
                    else {
                        if (strcmp(inputPassword, "EscMode") == 0) EscCheck = true;
                        else {
                            if (strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol) {
                                printf("\n\tВозможный размер пароля от %d до %d символов!\n\n", MinPassSymbol, MaxPassSymbol);
                                system("pause");
                                check = false;
                            }
                            if (check == true) check = checkStr(&inputPassword, 4);
                        }
                    }
                } while (EscCheck == false && check == false);
            }
            if (EscCheck == false) {
                inputLogin = encryption(inputLogin);
                inputPassword = encryption(inputPassword);
                Auth = ReadAuthCheck(authFile, inputLogin, inputPassword, mode);
                if (Auth == true) {
                    fseek(authFile, -5, SEEK_CUR);
                    ID = atoi(encryption(readFromFile(authFile)));;
                    printf("\n\tВы успешно вошли в систему\n\n");
                }
                else {
                    printf("\n\tНеверный логин или пароль\n\n");
                }
                system("pause");
                system("cls");
            }
        } while (Auth == false && EscCheck == false);
        if (EscCheck == false) {
            free(inputLogin);
            free(inputPassword);
        }
        if (authFile != NULL) fclose(authFile);
        else printf("\n\tОшибка закрытия файла!\n\n");        
    }
    if (EscCheck == true) system("cls");
    return ID;
}
//регистрация нового пользователя, если главврач его добавил 
void registration() {
    FILE* authFile,* regFile;
    bool EscCheck = false, check = true;
    char* inputLogin = NULL, * inputPassword = NULL;
    EscCheck = false;
    authFile = fopen("Authentification.txt", "a+");
    if (authFile == NULL) {
        printf("\n\tОшибка открытия файла!\n");
    }
    else {
        check = true;
        do {
            printf("\n\t\tРегистрация\n\t* * * * * * * * * * * * * * *\n\n");
            printf("  Введите логин: ");
            inputLogin = writeStr(0);
            if (strcmp(inputLogin, "") == 0) {
                EscCheck = true;
                check = true;
            }
            else {
                if (strcmp(inputLogin, "EscMode") == 0) EscCheck = true;
                else {
                    check = checkStr(&inputLogin, 4);
                    inputLogin = encryption(inputLogin);
                    if (check == true) {
                        if (strlen(inputLogin) < MinLogSymbol || strlen(inputLogin) > MaxLogSymbol) {
                            printf("\n\tВозможный размер логина от %d до %d символов!\n", MinLogSymbol, MaxLogSymbol);
                            system("pause");
                            system("cls");
                            check = false;
                        }
                        else if (compare(&inputLogin, authFile, 1) == true) {
                            printf("\n\tДанный логин недоступен!\n");
                            system("pause");
                            system("cls");
                            check = false;
                        }
                    }
                }
            }
        } while (EscCheck == false && check == false);
        if (EscCheck == false) {
            regFile = fopen("RegFile.txt", "a+");
            if (regFile == NULL) {
                printf("\n\tОшибка создания / открытия файла!\n");
                system("pause");
                system("cls");
            }
            else {
                if (EscCheck == false) {
                    fseek(authFile, 0, SEEK_END);
                    if (ftell(authFile) == 0) {
                        fprintf(regFile, "%s %d %d\n", inputLogin, 1 ^ 225, 1 ^ 225);
                        fclose(regFile);
                        regFile = fopen("RegFile.txt", "r+");
                    }
                    if (regFile == NULL) {
                        printf("\n\tОшибка создания / открытия файла!\n");
                        system("pause");
                        system("cls");
                    }
                    else {
                        if (compare(&inputLogin, regFile, 1) == true) {
                            int poz = ftell(regFile);
                            if (EscCheck == false) {
                                check = true;
                                do {
                                    system("cls");
                                    printf("\n\t\tРегистрация\n\t* * * * * * * * * * * * * * *\n\n");
                                    printf("  Введите логин: ");
                                    printf("%s\n", inputLogin);
                                    printf("  Введите пароль: ");
                                    inputPassword = writeStr(0);
                                    if (strcmp(inputPassword, "") == 0) {
                                        EscCheck = true;
                                        check = true;
                                    }
                                    else {                                        
                                        if (strcmp(inputPassword, "EscMode") == 0) EscCheck = true;
                                        else {
                                            check = checkStr(&inputPassword, 4);
                                            if (check == true) {
                                                if (strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol) {
                                                    printf("\n\tВозможный размер пароля от %d до %d символов!\n", MinPassSymbol, MaxPassSymbol);
                                                    system("pause");
                                                    check = false;
                                                }
                                                else if (compare(&inputPassword, authFile, 1) == true) {
                                                    printf("\n\tДанный пароль недоступен!\n");
                                                    system("pause");
                                                    check = false;
                                                }
                                            }
                                        }
                                    }
                                } while (EscCheck != true && check == false);
                                printf("\n\tРегистрация выполнена!\n");
                                system("pause");
                                system("cls");
                            }
                            fseek(regFile, poz, SEEK_SET);
                            inputPassword = encryption(inputPassword);
                            fprintf(authFile, "%s %s %s ", inputLogin, inputPassword, readFromFile(regFile));
                            fprintf(authFile, "%s\n", readFromFile(regFile));

                        }
                        else {
                            printf("\n\tВы не можете зарегестрироваться! Обратитесь к главврачу.\n\n");
                            system("pause");
                            system("cls");
                        }
                    }
                }
                if (EscCheck == false || strcmp(inputLogin, "adm") != 0) {
                    free(inputLogin);
                    free(inputPassword);
                }
                if (authFile != NULL) fclose(authFile);
                else printf("\n\tОшибка закрытия файла!\n");
            }
        }
    }
    if (EscCheck == true) system("cls");
}
//изменение пароля
void EditPass(Accounts** headAc, int ID) {
    Accounts* pAc;
    pAc = *headAc;
    int n = 0;
    char* inputPassword,* newPassword = NULL,* secondPassword;
    bool EscCheck = false,  CheckPass = false;
    FILE* authFile = fopen("Authentification.txt", "a+");
    if (authFile == NULL) {
        printf("\n\tОшибка создания / открытия файла!\n");
        system("pause");
        system("cls");
    }
    else {
        do {
            system("cls");
            printf("\n\t\tИзменение пароля\n\t* * * * * * * * * * * * * * *\n\n");
            printf("  Введите старый пароль: ");
            inputPassword = writeStr(0);
            if (strcmp(inputPassword, "EscMode") == 0) EscCheck = true;
            else {
                if (strlen(inputPassword) < MinPassSymbol || strlen(inputPassword) > MaxPassSymbol) {
                    printf("\n\tВозможный размер пароля от %d до %d символов!\n", MinPassSymbol, MaxPassSymbol);
                    system("pause");
                }
                else {
                    encryption(inputPassword);
                    if (compare(&inputPassword, authFile, 2) == true) {
                        readFromFile(authFile);
                        if (atoi(readFromFile(authFile)) == (ID ^ 225)) CheckPass = true;
                    }
                    else {
                        CheckPass = false;
                        printf("\n\tНеверный пароль!\n");
                        system("pause");
                    }
                    encryption(inputPassword);
                    if (CheckPass == true) CheckPass = checkStr(&inputPassword, 4);
                }
            }
        } while (CheckPass == false && EscCheck == false);
        if (EscCheck == false) {
            do {
                CheckPass = false;
                printf("\n  Введите новый пароль: ");
                newPassword = writeStr(0);
                if (strcmp(newPassword, "EscMode") == 0) EscCheck = true;
                else {
                    if (strlen(newPassword) < MinPassSymbol || strlen(newPassword) > MaxPassSymbol) {
                        printf("\n\tВозможный размер пароля от %d до %d символов!\n", MinPassSymbol, MaxPassSymbol);
                        system("pause");
                    }                    
                    else {
                        encryption(newPassword);
                        if (compare(&newPassword, authFile, 2) == true) {
                            printf("\n\tДанный пароль недоступен!\n");
                            system("pause");
                        }
                        else CheckPass = true;

                        encryption(newPassword);
                        if (CheckPass == true) CheckPass = checkStr(&newPassword, 4);
                    }
                }
            } while (CheckPass == false && EscCheck == false);
            if (EscCheck == false) {
                do {
                    printf("  Подтвердите пароль: ");
                    secondPassword = writeStr(0);
                    if (strcmp(secondPassword, "EscMode") == 0) EscCheck = true;
                    else {
                        if (strcmp(secondPassword, newPassword) == 0) {
                            printf("\n\tПароль успешно изменён!\n");
                            system("pause");
                            system("cls");
                            while (pAc != NULL) {
                                if (strcmp(inputPassword, pAc->password) == 0) {
                                    pAc->password = newPassword;
                                }
                                pAc = pAc->prev;
                            }
                            
                        }
                    }
                } while (CheckPass == false && EscCheck == false);
            }
        }
    }
}



            //Функции для работы со структурами


//Просмотр всех значений в табличной форме
void dataTableDoc(Doctors** head) {
    Doctors* p = NULL;
    p = *head;
    system("cls");
    puts("    ******************************************************************************************************************");
    puts("    |        |                  |             |                  |                                     |             |");
    puts("    |   ID   |      Фамилия     |     Имя     |     Отчество     |            Специальность            |  Категория  |");
    puts("    |        |                  |             |                  |                                     |             |");
    puts("    ******************************************************************************************************************");
    while (p != NULL) {
        printf("    | %-6d | %-16s | %-11s | %-16s | %-35s | %-11s |\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
        puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        p = p->prev;
    }
    printf("\n");
}
void dataTableCust(Customers** head) {
    Customers* p = NULL;
    p = *head;
    char tmpDay[3], tmpMouth[3], tmp[3];
    system("cls");
    puts("    **********************************************************************");
    puts("    |      |                |           |                |               |");
    puts("    |  ID  |     Фамилия    |    Имя    |    Отчество    | Дата рождения |");
    puts("    |      |                |           |                |               |");
    puts("    **********************************************************************");
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
        printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
        puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        p = p->prev;
    }
    printf("\n");
} 
void dataTableApp(Appeals** head) {
    system("cls");
    Appeals* p = NULL;
    p = *head;
    char tmpDay[3], tmpMonth[3], tmp[3];
    puts("    ***********************************************************************************************************************");
    puts("    |           |         |          |             |                                                  |                   |");
    puts("    |   Номер   |    ID   |    ID    | Дата приёма |                     Диагноз                      | Стоимость лечения |");
    puts("    | обращения | Доктора | Пациента |             |                                                  |                   |");
    puts("    |           |         |          |             |                                                  |                   |");
    puts("    ***********************************************************************************************************************");
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
        printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
        puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        p = p->prev;
    }
    printf("\n");
}
//Добавление элемента в стек
    //изменение на первую букву в верхнем регистре, а остальные в нижнем
void pushDoc(Doctors** head, FILE* File) {
    Doctors* p;
    FILE* tmpLogin;
    bool check, checkString, checkEsc = false;
    int mode;
    if (*head == NULL) {
        p = malloc(sizeof(Doctors));
        if ((p = malloc(sizeof(Doctors))) == NULL) {
            printf("\tОшибка выделения памяти для стека!\n");
        }
        p->prev = NULL;
        p->ID = 1;
    }
    else {
        int count = (*head)->ID;
        p = (*head)->prev;
        while (p != NULL) {
            if (p->ID > count) {
                count = p->ID;
            }
            p = p->prev;
        }
        p = *head;
        p = malloc(sizeof(Doctors));
        p->prev = *head;
        p->ID = count + 1;
    }
    do {
        check = false;       
        checkString = false;
        do {
            system("cls");
            printf("  Введите фамилию: ");
            p->surname = strconv(writeStr(0));
            if (strcmp(p->surname, "EscMode") == 0) checkEsc = true;
            else {
                if (strlen(p->surname) > MaxSecondNameSymbol) {
                    printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSecondNameSymbol);
                    system("pause");
                    system("cls");
                }
                checkString = checkStr(&p->surname, 2);
            }            
        } while (strlen(p->surname) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
        if (strlen(p->surname) == 0) p->surname = "-";
        checkString = false;
        if (checkEsc == false) {
            do {
                system("cls");
                printf("  Введите фамилию: %s\n", p->surname);
                printf("  Введите имя: ");
                p->name = strconv(writeStr(0));
                if (strcmp(p->surname, "EscMode") == 0) checkEsc = true;
                else {
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\n\tМаксимальный размер строки %d символов\n\n", MaxNameSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->name, 2);
                }
            } while (strlen(p->name) > MaxNameSymbol || checkString == false && checkEsc == false);
            if (strlen(p->name) == 0) p->name = "-";
        }        
        checkString = false;
        if (checkEsc == false) {
            do {
                system("cls");
                printf("  Введите фамилию: %s\n", p->surname);
                printf("  Введите имя: %s\n", p->name);
                printf("  Введите отчество: ");
                p->middleName = strconv(writeStr(0));
                if (strcmp(p->middleName, "EscMode") == 0) checkEsc = true;
                else {
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->middleName, 2);
                }
            } while (strlen(p->middleName) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
            if (strlen(p->middleName) == 0) p->middleName = "-";
        }
        checkString = false;
        if (checkEsc == false) {
            do {
                system("cls");
                printf("  Введите фамилию: %s\n", p->surname);
                printf("  Введите имя: %s\n", p->name);
                printf("  Введите отчество: %s\n", p->middleName);
                printf("  Введите специальность: ");
                p->specialty = strconv(writeStr(0));
                if (strcmp(p->specialty, "EscMode") == 0) checkEsc = true;
                else {
                    if (strlen(p->specialty) > MaxSpecialSymbol) {
                        printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSpecialSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->specialty, 2);
                }
            } while (strlen(p->specialty) > MaxSpecialSymbol || checkString == false);
            if (strlen(p->specialty) == 0) p->specialty = "-";
        }
        if (checkEsc == false) {
            if (ftell(File) != 0) {
                if (strcmp(p->specialty, "Медрегистратор") == 0) p->category = "-";
                else {
                    checkString = false;
                    do {
                        system("cls");
                        printf("  Введите фамилию: %s\n", p->surname);
                        printf("  Введите имя: %s\n", p->name);
                        printf("  Введите отчество: %s\n", p->middleName);
                        printf("  Введите специальность: %s\n", p->specialty);
                        printf("  Введите категорию: ");
                        p->category = strconv(writeStr(0));
                        if (strlen(p->category) > MaxCategorSymbol) {
                            printf("\n\tМаксимальный размер строки %d символов\n\n", MaxCategorSymbol);
                            system("pause");
                            system("cls");
                        }
                        checkString = checkStr(&p->category, 2);
                    } while (strlen(p->category) > MaxCategorSymbol || checkString == false);
                    if (strlen(p->category) == 0) p->category = "-";
                }
                if (compare(&p->surname, File, 1) == true && compare(&p->name, File, 1) == true && compare(&p->middleName, File, 1) == true) {
                    check = true;
                    memset(p, 0, sizeof(Doctors));
                    printf("\n\tДанный пользователь уже существует в системе!\n\n");
                    system("pause");
                    system("cls");
                }
                checkString = false;
                do {
                    system("cls");
                    printf("  Введите фамилию: %s\n", p->surname);
                    printf("  Введите имя: %s\n", p->name);
                    printf("  Введите отчество: %s\n", p->middleName);
                    printf("  Введите специальность: %s\n", p->specialty);
                    printf("  Введите категорию: %s\n\n", p->category);
                    printf("  Введите логин медработника: ");
                    char* tmp = writeStr(0);
                    checkString = checkStr(&tmp, 4);
                    if (strlen(tmp) > MaxLogSymbol || strlen(tmp) < MinLogSymbol) {
                        printf("\n\tВозможный размер логина от %d до %d символов!\n\n", MinLogSymbol, MaxLogSymbol);
                        system("pause");
                        system("cls");
                    }
                    else if (checkString == false);
                    else {
                        tmpLogin = fopen("RegFile.txt", "a+");
                        if (tmpLogin == NULL) {
                            printf("\n\tОшибка создания / открытия файла!\n\n");
                            system("pause");
                            system("cls");
                        }
                        else {
                            if (strcmp(p->specialty, "Медрегистратор") == 0) {
                                mode = 3;
                            }
                            else if (strcmp(p->category, "Высшая") == 0) mode = 1;
                            else mode = 2;
                            fprintf(tmpLogin, "%s %d %d\n", encryption(tmp), mode ^ 225, p->ID ^ 225);
                            fclose(tmpLogin);
                        }
                    }
                } while (strlen(p->category) > MaxCategorSymbol || checkString == false);
            }
            else {
                p->category = "Высшая";
                registration();
            }            
            if (checkEsc == false && p->ID != 1) {
                printf("\n\tВыполнено!\n\n");
                system("pause");
                system("cls");
            }
            *head = p;
        }     
        else memset(p, 0, sizeof(Doctors));
    } while (check == true);
}
void pushCust(Customers** head, FILE* File) {
    Customers* p = NULL;
    char* tmp = NULL;
    bool check = false, checkCompare, checkString;
    do {
        checkCompare = false;
        if (*head == NULL) {
            p = malloc(sizeof(Customers));
            if ((p = malloc(sizeof(Customers))) == NULL) {
                printf("\tОшибка выделения памяти для стека!\n");
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
        checkString = false;
        do {
            printf("Введите фамилию: ");
            p->surname = strconv(writeStr(0));
            if (strlen(p->surname) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&p->surname, 2);
        } while (strlen(p->surname) > MaxSecondNameSymbol || checkString == false);
        if (strlen(p->surname) == 0) p->surname = "-";
        checkString = false;
        do {
            printf("Введите имя: ");
            p->name = strconv(writeStr(0));
            if (strlen(p->name) > MaxNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&p->name, 2);
        } while (strlen(p->name) > MaxNameSymbol || checkString == false);
        if (strlen(p->name) == 0) p->name = "-";
        checkString = false;
        do {
            printf("Введите отчество: ");
            p->middleName = strconv(writeStr(0));
            if (strlen(p->middleName) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&p->middleName, 2);
        } while (strlen(p->middleName) > MaxSecondNameSymbol || checkString == false);
        if (strlen(p->middleName) == 0) p->middleName = "-";
        const time_t timer = time(NULL);
        struct tm* u = localtime(&timer);
        checkString = false;
        do {
            do {
                printf("Введите год: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
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
            checkString = false;
            do {
                printf("Введите месяц: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
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
            checkString = false;
            do {
                printf("Введите день: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
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
            else if (p->dateBirthday.month == 4 || p->dateBirthday.month == 6 || p->dateBirthday.month == 9 || p->dateBirthday.month == 11) {
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
        char* str1,* str2,* str3;
        str1 = (char*)malloc(sizeof(char) * 3);
        str2 = (char*)malloc(sizeof(char) * 3);
        str3 = (char*)malloc(sizeof(char) * 5);
        _itoa(p->dateBirthday.day, str1, 10);
        _itoa(p->dateBirthday.month, str2, 10);
        _itoa(p->dateBirthday.year, str3, 10);
        check = false;
        if (compare(&p->surname, File, 1) == true && compare(&p->name, File, 1) == true && compare(&p->middleName, File, 1) == true && compare(&str1, File, 1) == true && compare(&str2, File, 1) == true && compare(&str3, File, 1) == true) {
            check = true;
            memset(p, 0, sizeof(Customers));
            printf("\tДанный пользователь уже существует в системе!\n");
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
    bool check = false, checkCompare, checkString;
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    pApp = NULL;
    if (*headApp == NULL) {
        pApp = malloc(sizeof(Appeals));
        if ((pApp = malloc(sizeof(Appeals))) == NULL) {
            printf("\tОшибка выделения памяти для стека!\n");
        }
        pApp->prev = NULL;
        pApp->NumApp = 1;
    }
    else {
        int count = (*headApp)->NumApp;
        pApp = (*headApp)->prev;
        while (pApp != NULL) {
            if (pApp->NumApp > count) {
                count = pApp->NumApp;
            }
            pApp = pApp->prev;
        }
        pApp = *headApp;
        pApp = malloc(sizeof(Appeals));
        pApp->prev = *headApp;
        pApp->NumApp = count + 1;
    }
    do {
        checkCompare = false;
        system("cls");
        printf("\tВвод данных пациента:\n");        
        checkString = false;
        do {
            printf("Введите фамилию: ");
            surname = strconv(writeStr(0));
            if (strlen(surname) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&surname, 2);
        } while (strlen(surname) > MaxSecondNameSymbol || checkString == false);
        checkString = false;
        do {
            system("cls");
            printf("\tВвод данных пациента:\n");
            printf("Введите фамилию: %s\n", surname);
            printf("Введите имя: ");
            name = strconv(writeStr(0));
            if (strlen(name) > MaxNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&name, 2);
        } while (strlen(name) > MaxNameSymbol || checkString == false);
        checkString = false;
        do {
            system("cls");
            printf("\tВвод данных пациента:\n");
            printf("Введите фамилию: %s\n", surname);
            printf("Введите имя: %s\n", name);
            printf("Введите отчество: ");
            middleName = strconv(writeStr(0));
            if (strlen(middleName) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&middleName, 2);
        } while (strlen(middleName) > MaxSecondNameSymbol || checkString == false);
        checkString = false;
        do {
            do {
                system("cls");
                printf("\tВвод данных пациента:\n");
                printf("Введите фамилию: %s\n", surname);
                printf("Введите имя: %s\n", name);
                printf("Введите отчество: %s\n", middleName);
                printf("Введите год: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
            year = atoi(tmp);
            if (year <= 0 || year > u->tm_year + 1900 || year < 1900) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        checkString = false;
        do {
            do {
                system("cls");
                printf("\tВвод данных пациента:\n");
                printf("Введите фамилию: %s\n", surname);
                printf("Введите имя: %s\n", name);
                printf("Введите отчество: %s\n", middleName);
                printf("Введите год: %d\n", year);
                printf("Введите месяц: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
            month = atoi(tmp);
            u->tm_mon = u->tm_mon + 1;
            if (month <= 0 || month > 12 || (month > u->tm_mon && year == 2020)) {
                printf("\tНекорректное значение\n");
                system("pause");
                system("cls");
            }
            else check = true;
        } while (check == false);
        check = false;
        bool checkDay = false;
        checkString = false;
        do {
            do {
                system("cls");
                printf("\tВвод данных пациента:\n");
                printf("Введите фамилию: %s\n", surname);
                printf("Введите имя: %s\n", name);
                printf("Введите отчество: %s\n", middleName);
                printf("Введите год: %d\n", year);
                printf("Введите месяц: %d\n", month);
                printf("Введите день: ");
                tmp = writeStr(0);
                checkString = checkStr(&tmp, 1);
            } while (checkString == false);
            day = atoi(tmp);
            if (u->tm_mon == month && year == 2020 && day > u->tm_mday) { //прверка на ошибку завтрашнего дня
                checkDay = true;
            }
            else checkDay = false;
            check = false;
            if (month == 2 && year % 4 == 0 || checkDay == true) {
                if (day <= 0 || day > 29 || checkDay == true) {
                    printf("\tНекорректное значение\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (month == 2 && year % 4 != 0) {
                if (day <= 0 || day > 28) {
                    printf("\tНекорректное значение\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day <= 0 || day > 30) {
                    printf("\tНекорректное значение\n");
                    system("pause");
                    system("cls");
                }
                else check = true;
            }
            else {
                if (day <= 0 || day > 31) {
                    printf("\tНекорректное значение\n");
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
            printf("\tДанные приняты\n");
            system("pause");
            system("cls");
            if (*headApp == NULL) {
                pApp = malloc(sizeof(Appeals));
                if ((pApp = malloc(sizeof(Appeals))) == NULL) {
                    printf("\tОшибка выделения памяти для стека!\n");
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
            checkString = false;
            do {
                printf("Введите диагноз пациента: ");
                pApp->diagnosis = writeStr(0);
                checkString = checkStr(&pApp->diagnosis, 3);
            } while (strlen(pApp->diagnosis) > 50 || checkString == false);
            checkString = false;
            do {
                do {
                    system("cls");
                    printf("Введите диагноз пациента: %s\n", pApp->diagnosis);
                    printf("Введите стоимость лечения: ");
                    tmp = writeStr(0);
                    checkString = checkStr(&tmp, 1);
                } while (checkString == false);
                pApp->costOfTreatment = atoi(tmp);
                system("pause");
                system("cls");
            } while (pApp->costOfTreatment > 100000 || pApp->costOfTreatment < 0);
            check = true;
        }
        pCust = pCust->prev;
    } while (pCust != NULL);
    *headApp = pApp;
    if (check == false) printf("\tДанного пациента нет в базе данных! Обратитесь в регистратуру.\n");
    else printf("\tВыполнено!\n");
}
//Удаление элемента из стека
void popDoc(Doctors** head, Accounts** headAc) {    
    bool checkTruth = false, check;
    Doctors* p = NULL, * tmpD;
    Accounts* pAc = NULL,* tmpA;
    pAc = *headAc;
    p = *head;
    char* IDpop;
    int n = 0, count = 0;
    do {
        check = false;
        checkTruth = false;
        do {
            system("cls");
            dataTableDoc(&headDoc);
            printf("\n");
            printf("  Введите ID врача для удаления: ");
            IDpop = writeStr(0);
        } while (checkStr == false);
        while (p != NULL && strcmp(IDpop, "EscMode") != 0) {
            if (p->ID == atoi(IDpop)) {
                checkTruth = true;
                while (pAc != NULL && check == false) {
                    if (atoi(IDpop) == pAc->IDdoc) {
                        if (pAc->mode == 1) {
                            pAc = *headAc;
                            while (pAc != NULL) {
                                if (pAc->mode == 1) count++;
                                pAc = pAc->prev;
                            }
                            if (count < 2) {
                                printf("\n\tНевозможно удалить единственного администратора!\n\n");
                                system("pause");
                                system("cls");
                                check = true;
                            }
                        }
                    }
                    if (check == false) pAc = pAc->prev;
                }
            }
            p = p->prev;
        }
        if (checkTruth == false && strcmp(IDpop, "EscMode") != 0 && check == false) {
            printf("\n\tВрача с таким ID не существует\n\n");
            system("pause");
        }
    } while (check == true || strcmp(IDpop, "EscMode") != 0 && checkTruth == false);
    p = *head;
    while (p != NULL && checkTruth == true && check == false && strcmp(IDpop, "EscMode") != 0) {
        if (p->ID == atoi(IDpop)) {
            if (p->ID == (*head)->ID) {
                tmpD = (*head)->prev;
                (*head) = NULL;
                p = tmpD;
                *head = p;
            }
            else {
                tmpD = p->prev;
                p->prev = NULL;
                p = *head;
                for (int i = 0; i < n - 1; i++) {
                    p = p->prev;
                }
                p->prev = tmpD;
            }
            printf("\n\tДанные врача с ID %d удалены\n\n", atoi(IDpop));
            system("pause");            
        }
        else {
            p = p->prev;
            n++;
        }
    }
    pAc = *headAc;
    n = 0;
    while (pAc != NULL && checkTruth == true && strcmp(IDpop, "EscMode") != 0) {
        if (pAc->IDdoc == atoi(IDpop)) {
            if (pAc->IDdoc == (*headAc)->IDdoc) {
                tmpA = (*headAc)->prev;
                (*headAc) = NULL;
                pAc = tmpA;
                *headAc = pAc;
            }
            else {
                tmpA = pAc->prev;
                pAc->prev = NULL;
                pAc = *headAc;
                for (int i = 0; i < n - 1; i++) {
                    pAc = pAc->prev;
                }
                pAc->prev = tmpA;
            }
        }
        else {
            pAc = pAc->prev;
            n++;
        }
    }    
    system("cls");
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
    system("cls");
}
//Редактирование данных в стеке
    //исправить менюшку
void editDataDoc(Doctors** head) {    
    int a = 0;
    char* IDedit, editChoice;
    bool checkTruth = false, checkString, checkEsc = false, check = false;
    Doctors* p = NULL;
    do {
        do {
            system("cls");
            dataTableDoc(&headDoc);
            printf("\n");
            printf("  Введите ID врача для редактирования: ");
            IDedit = writeStr(0);
            if (strcmp(IDedit, "EscMode") == 0) checkEsc = true;
        } while (checkStr(&IDedit, 1) == false && checkEsc == false);
        if (checkEsc == false) {
            p = *head;
            while (p != NULL && checkTruth == false) {
                if (p->ID == atoi(IDedit)) {
                    checkTruth = true;
                }
                else {
                    p = p->prev;
                }
            }
            if (checkTruth == false) {
                printf("\n\tВрача с таким ID не существует\n\n");
                system("pause");
            }
            else {
                system("cls");
                while (a == 0) {
                    system("cls");
                    printf("\n\t  Меню редактирования данных\n\t* * * * * * * * * * * * * * * * * *\n\n");
                    printf("  1) Редактировать фамилию\n");
                    printf("  2) Редактировать имя\n");
                    printf("  3) Редактировать отчество\n");
                    printf("  4) Редактировать специальность\n");
                    printf("  5) Редактировать категорию\n");
                    printf("  6) Сохранение изменений\n\n");
                    editChoice = _getch();
                    switch (editChoice) {
                    case '1':
                        checkString = false;
                        do {
                            printf("Введите фамилию: ");
                            p->surname = writeStr(0);
                            if (strlen(p->surname) > MaxSecondNameSymbol) {
                                printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSecondNameSymbol);
                                system("pause");
                            }
                            checkString = checkStr(&p->surname, 2);
                        } while (strlen(p->surname) > MaxSecondNameSymbol || checkString == false);
                        break;
                    case '2':
                        checkString = false;
                        do {
                            printf("Введите имя: ");
                            p->name = writeStr(0);
                            if (strlen(p->name) > MaxNameSymbol) {
                                printf("\n\tМаксимальный размер строки %d символов\n\n", MaxNameSymbol);
                                system("pause");
                            }
                            checkString = checkStr(&p->name, 2);
                        } while (strlen(p->surname) > MaxNameSymbol || checkString == false);
                        break;
                    case '3':
                        checkString = false;
                        do {
                            printf("Введите отчество: ");
                            p->middleName = writeStr(0);
                            if (strlen(p->middleName) > MaxSecondNameSymbol) {
                                printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSecondNameSymbol);
                                system("pause");
                            }
                            checkString = checkStr(&p->middleName, 2);
                        } while (strlen(p->middleName) > MaxSecondNameSymbol || checkString == false);
                        break;
                    case '4':
                        checkString = false;
                        do {
                            printf("Введите специальность: ");
                            p->specialty = writeStr(0);
                            if (strlen(p->specialty) > MaxSpecialSymbol) {
                                printf("\n\tМаксимальный размер строки %d символов\n\n", MaxSpecialSymbol);
                                system("pause");
                            }
                            checkString = checkStr(&p->specialty, 2);
                        } while (strlen(p->specialty) > MaxSpecialSymbol || checkString == false);
                        break;
                    case '5':
                        checkString = false;
                        do {
                            printf("Введите категорию: ");
                            p->category = writeStr(0);
                            if (strlen(p->category) > MaxCategorSymbol) {
                                printf("\n\tМаксимальный размер строки %d символов\n\n", MaxCategorSymbol);
                                system("pause");
                            }
                            checkString = checkStr(&p->category, 2);
                        } while (strlen(p->category) > MaxCategorSymbol || checkString == false);
                        break;
                    case '6':
                        check = true;
                        printf("\n\tВыполенено!\n\n");
                        system("pause");
                        a = 1;
                        break;
                    }
                }
            }
        }
    }while (checkEsc == false && check == false);
    system("cls");
}
void editDataCust(Customers** head) {
    dataTableCust(&headCust);
    printf("\n");
    int IDedit, editChoice, a = 0;
    bool checkTruth = false, check = false, checkString;
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
            printf("\t5) Сохранение изменений\n\n");
            editChoice = getc(stdin);
            system("cls");
            switch (editChoice) {
            case '1':
                checkString = false;
                do {
                    printf("Введите фамилию: ");
                    p->surname = writeStr(0);
                    if (strlen(p->surname) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->surname, 2);
                } while (strlen(p->surname) > MaxSecondNameSymbol || checkString == false);
                printf("\tВыполнено\n");
                system("pause");
                break;
            case '2':
                checkString = false;
                do {
                    printf("Введите имя: ");
                    p->name = writeStr(0);
                    if (strlen(p->name) > MaxNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->name, 2);
                } while (strlen(p->name) > MaxNameSymbol || checkString == false);
                printf("\tВыполнено\n");
                system("pause");
                break;
            case '3':
                checkString = false;
                do {
                    printf("Введите отчество: ");
                    p->middleName = writeStr(0);
                    if (strlen(p->middleName) > MaxSecondNameSymbol) {
                        printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                        system("pause");
                        system("cls");
                    }
                    checkString = checkStr(&p->middleName, 2);
                } while (strlen(p->middleName) > MaxSecondNameSymbol || checkString == false);
                printf("\tВыполнено\n");
                system("pause");
                break;
            case '4':
                do {
                    checkString = false;
                    do {
                        printf("Введите год: ");
                        tmp = writeStr(0);
                        checkString = checkStr(&tmp, 1);
                    } while (checkString == false);
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
                    checkString = false;
                    do {
                        printf("Введите месяц: ");
                        tmp = writeStr(0);
                        checkString = checkStr(&tmp, 1);
                    } while (checkString == false);
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
                    checkString = false;
                    do {
                        printf("Введите день: ");
                        tmp = writeStr(0);
                        checkString = checkStr(&tmp, 1);
                    } while (checkString == false);
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
                    else if (p->dateBirthday.month == 4 || p->dateBirthday.month == 6 || p->dateBirthday.month == 9 || p->dateBirthday.month == 11) {
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
                printf("\tВыполнено\n");
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
    dataTableApp(&headApp);
    printf("\n");
    int IDedit, editChoice, a = 0;
    bool checkTruth = false, check = false, checkString;
    Appeals* p = NULL;
    char* tmp = NULL;
    const time_t timer = time(NULL);
    struct tm* u = localtime(&timer);
    printf("Введите номер обращения для редактирования: ");
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
        printf("\tОбращения с таким номером не существует\n");
        system("pause");
    }
    else {
        system("cls");
        while (a == 0) {
            printf("\t1) Редактировать диагноз\n");
            printf("\t2) Редактировать стоимость лечения\n");
            printf("\t3) Сохранение изменений\n\n");
            editChoice = getc(stdin);
            system("cls");
            switch (editChoice) {
            case '1':
                checkString = false;
                do {
                    printf("Введите диагноз пациента: ");
                    p->diagnosis = writeStr(0);
                    checkString = checkStr(&p->diagnosis, 3);
                } while (strlen(p->diagnosis) > 50 || checkString == false);
                printf("\tВыполнено\n");
                system("pause");
                break;
            case '2':
                checkString = false;
                do {
                    do {
                        printf("Введите стоимость лечения: ");
                        tmp = writeStr(0);
                        checkString = checkStr(&tmp, 1);
                    } while (checkString == false);
                    p->costOfTreatment = atoi(tmp);
                    system("pause");
                    system("cls");
                } while (p->costOfTreatment > 100000 || p->costOfTreatment < 0);
                printf("\tВыполнено\n");
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

            //функции поиска, сортировки и фильтрации
//шапки для вывода данных 
void DoctorsHat() {
    puts("    ******************************************************************************************************");
    puts("    |      |                |           |                |                                   |           |");
    puts("    |  ID  |     Фамилия    |    Имя    |    Отчество    |           Специальность           | Категория |");
    puts("    |      |                |           |                |                                   |           |");
    puts("    ******************************************************************************************************");
}
void CustomersHat() {
    puts("    *****************************************************************************");
    puts("    |        |                  |             |                  |               |");
    puts("    |   ID   |      Фамилия     |     Имя     |     Отчество     | Дата рождения |");
    puts("    |        |                  |             |                  |               |");
    puts("    *****************************************************************************");
}
void AppealsHat() {
    puts("    ***********************************************************************************************************************");
    puts("    |           |         |          |             |                                                  |                   |");
    puts("    |   Номер   |    ID   |    ID    | Дата приёма |                     Диагноз                      | Стоимость лечения |");
    puts("    | обращения | Доктора | Пациента |             |                                                  |                   |");
    puts("    |           |         |          |             |                                                  |                   |");
    puts("    ***********************************************************************************************************************");
}


        //исправить Esc
//поиск данных врача
void SearchIDDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    do {
        dataTableDoc(&head);
        printf("Введите ID врача: ");
        str = writeStr(0);
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > 4) {
                printf("\tМаксимальный размер строки 4 символа\n");
                system("pause");
                system("cls");
                checkString = false;
            }
            else checkString = checkStr(&str, 1);
        }
    } while (checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;        
        check = false;
        do {
            if (atoi(str) == p->ID) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchSurnameDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    checkString = false;
    do {
        dataTableDoc(&head);
        printf("Введите фамилию врача: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (strcmp(str, p->surname) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d|%-16s|%-11s|%-16s|%-35s|%-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchNameDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    do {
        dataTableDoc(&head);
        printf("Введите имя врача: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        check = false;
        p = head;
        do {
            if (strcmp(str, p->name) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d|%-16s|%-11s|%-16s|%-35s|%-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchMiddleNameDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    do {
        dataTableDoc(&head);
        printf("Введите отчество врача: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        check = false;
        p = head;
        do {
            if (strcmp(str, p->middleName) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d|%-16s|%-11s|%-16s|%-35s|%-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchSpecialtyDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    i = 0;
    do {
        dataTableDoc(&head);
        printf("Введите специальность врача: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSpecialSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSpecialSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSpecialSymbol || checkString == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (strcmp(str, p->specialty) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d|%-16s|%-11s|%-16s|%-35s|%-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchCategoryDoc(Doctors* head) {
    bool checkString = false, checkEsc = false, check;
    Doctors* p;
    int i = 0;
    char* str;
    i = 0;
    do {
        dataTableDoc(&head);
        printf("Введите категорию врача: ");
        str = strconv(writeStr(0));
        if (strlen(str) > MaxCategorSymbol) {
            printf("\tМаксимальный размер строки %d символов\n", MaxCategorSymbol);
            system("pause");
            system("cls");
        }
        checkString = checkStr(&str, 2);
    } while (strlen(str) > MaxCategorSymbol || checkString == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (strcmp(str, p->category) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    DoctorsHat();
                }
                printf("    |%-6d|%-16s|%-11s|%-16s|%-35s|%-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchMenuDoc(Doctors* head) {
    char choice;
    while (1) {
        dataTableDoc(&head);
        printf("\n\t1) Поиск по ID врача \n");
        printf("\t2) Поиск по фамилии \n");
        printf("\t3) Поиск по имени \n");
        printf("\t4) Поиск по отчеству \n");
        printf("\t5) Поиск по специальности \n");
        printf("\t6) Поиск по категории \n");
        printf("\t7) Выход\n\n");        
        choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
            SearchIDDoc(head);
            system("pause");
            system("cls");
            break;
        case '2':
            SearchSurnameDoc(head);
            system("pause");
            system("cls");
            break;
        case '3':
            SearchNameDoc(head);
            system("pause");
            system("cls");
            break;
        case '4':
            SearchMiddleNameDoc(head);
            system("pause");
            system("cls");
            break;
        case '5':
            SearchSpecialtyDoc(head);
            system("pause");
            system("cls");
            break;
        case '6':
            SearchCategoryDoc(head);
            system("pause");
            system("cls");
            break;
        case '7':
            return;
        }

    }
}

//сортировка данных врача
void SortIDUpDoc(Doctors** head) {
    int count = 0, tmp, Max = 0, min, f = 0;
    Doctors* p = *head;
    tmp = p->ID;
    while (p != NULL) {
        if (p->ID < tmp) tmp = p->ID;
        if (p->ID > Max) Max = p->ID;
        p = p->prev;
        count++;
    }    
    tmp--;
    DoctorsHat();
    min = Max;
    for (int i = 0; i < count - 1; i++) {
        p = *head;       
        f = 0;
        while (p != NULL) {
            if (p->ID < Max - f + 1 && p->ID > tmp && p->ID < min) min = p->ID;
            p = p->prev;
            f++;
        }
        tmp = min;
        p = *head;
        while (p != NULL) {
            if (p->ID == min) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
        min = Max;
    }
}
void SortIDDownDoc(Doctors** head) {
    int count = 0, tmp = 0, Max = 0;
    Doctors* p;
    p = *head;
    while (p != NULL) {
        if (p->ID > tmp) tmp = p->ID;
        p = p->prev;
        count++;
    }
    tmp++;
    DoctorsHat();
    for (int i = 0; i < count; i++) {
        p = *head;
        Max = 0;
        while (p != NULL) {
            if (p->ID > Max && p->ID < tmp) Max = p->ID;
            p = p->prev;
        }
        tmp = Max;
        p = *head;
        while (p != NULL) {
            if (p->ID == Max) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortSurnameDoc(Doctors** head) {
    int count = 0;
    char s;
    Doctors* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    DoctorsHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->surname[0] == s) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortNameDoc(Doctors** head) {
    int count = 0;
    char s;
    Doctors* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    DoctorsHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->name[0] == s) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortMiddleNameDoc(Doctors** head) {
    int count = 0;
    char s;
    Doctors* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    DoctorsHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->middleName[0] == s) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortSpecialtyDoc(Doctors** head) {
    int count = 0;
    char s;
    Doctors* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    DoctorsHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->specialty[0] == s) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortCategoryDoc(Doctors** head) {
    int count = 0;
    char str[7];
    Doctors* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    DoctorsHat();
    p = *head;
    for (int i = 0; i < 3; i++) {
        if (i == 0) strcpy(str, "Высшая");
        else if (i == 1) strcpy(str, "Первая");
        else strcpy(str, "Вторая");
        p = *head;
        while (p != NULL) {
            if (strcmp(p->category, str) == 0) {
                printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
    p = *head;
    while (p != NULL) {
        if (strcmp(p->category, "-") == 0) {
            printf("    |%-6d %-16s %-11s %-16s %-35s %-11s|\n", p->ID, p->surname, p->name, p->middleName, p->specialty, p->category);
            puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        }
        p = p->prev;
    }
}
void SortMenuDoc(Doctors* head) {
    char choice;
    Doctors* p;
    while (1) {
        p = head;
        system("cls");
        dataTableDoc(&head);
        printf("\n\t1) Сортировка ID по убыванию\n");
        printf("\t2) Сортировка ID по возрастанию\n");
        printf("\t3) Сортировка фамилий по алфавиту\n");
        printf("\t4) Сортировка имён по алфавиту\n");
        printf("\t5) Сортировка отчеств по алфавиту\n");
        printf("\t6) Сортировка специальностей по алфавиту\n");
        printf("\t7) Сортировка категорий\n");
        printf("\t8) Выход\n\n");
        choice = _getch();
        switch (choice) {
        case '1':
            system("cls");
            SortIDDownDoc(&head);
            system("pause");
            break;
        case '2':
            system("cls");
            SortIDUpDoc(&head);  
            system("pause");
            break;
        case '3':
            system("cls");
            SortSurnameDoc(&head);
            system("pause");
            break;
        case '4':
            system("cls");
            SortNameDoc(&head);
            system("pause");
            break;
        case '5':
            system("cls");
            SortMiddleNameDoc(&head);
            system("pause");
            break;
        case '6':
            system("cls");
            SortSpecialtyDoc(&head);
            system("pause");
            break;
        case '7':
            system("cls");
            SortCategoryDoc(&head);
            system("pause");
            break;
        case '8':
            return;
        }

    }
}
void Task(Appeals** head) {
    system("cls");
    Appeals* p = *head;
    char str[50], str1[50], str2[50], str3[50], str4[50], str5[50];
    int count = 0, countD = 0, CountTop1 = 0, CountTop2 = 0, CountTop3 = 0, CountTop4 = 0, CountTop5 = 0, CountTop;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    p = *head;
    for (int i = 0; i < count; i++) {
        CountTop = 0;
        p = *head;
        for (int f = 0; f < countD; f++) p = p->prev;
        strcpy(str, p->diagnosis);
        p = *head;
        while (p != NULL) {
            if (strcmp(str, strconv(p->diagnosis)) == 0) CountTop++;
            p = p->prev;
        }
        if (strcmp(str1, str) != 0 && strcmp(str2, str) != 0 && strcmp(str3, str) != 0 && strcmp(str4, str) != 0 && strcmp(str5, str) != 0) {
            if (CountTop > CountTop1) {
                CountTop1 = CountTop;
                strcpy(str1, str);
            }
            else if (CountTop > CountTop2) {
                CountTop2 = CountTop;
                strcpy(str2, str);
            }
            else if (CountTop > CountTop3) {
                CountTop3 = CountTop;
                strcpy(str3, str);
            }
            else if (CountTop > CountTop4) {
                CountTop4 = CountTop;
                strcpy(str4, str);
            }
            else if (CountTop > CountTop5) {
                CountTop5 = CountTop;
                strcpy(str5, str);
            }
        }
        countD++;
    }
    printf("Топ 5 самых частых дигнозов: \n\t1) %s\n\t2) %s\n\t3) %s\n\t4) %s\n\t5) %s\n", str1, str2, str3, str4, str5);
    system("pause");
    system("cls");
}


//РАБОТАЕТ


//поиск для побращений
void SearchIDCust(Customers* head) {
    bool checkString = false, checkEsc = false, check;
    Customers* p;
    int i = 0;
    char tmpDay[3], tmpMouth[3], tmp[3],* str;
    i = 0;
    do {
        dataTableCust(&head);
        printf("Введите ID пациента: ");
        str = writeStr(0);
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > 4) {
                printf("\tМаксимальный размер строки 4 символа\n");
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 1);
        }
    } while (strlen(str) > 4 || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (atoi(str) == p->ID) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    CustomersHat();
                }
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchSurnameCust(Customers* head) {
    bool checkString = false, checkEsc = false, check;
    Customers* p;
    int i = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], * str;
    i = 0;
    checkString = false;
    do {
        dataTableCust(&head);
        printf("Введите фамилию пациента: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (strcmp(str, p->surname) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    CustomersHat();
                }
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchNameCust(Customers* head) {
    bool checkString = false, checkEsc = false, check;
    Customers* p;
    int i = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], * str;
    i = 0;
    do {
        dataTableCust(&head);
        printf("Введите имя пациента: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        check = false;
        p = head;
        do {
            if (strcmp(str, p->name) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    CustomersHat();
                }
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchMiddleNameCust(Customers* head) {
    bool checkString = false, checkEsc = false, check;
    Customers* p;
    int i = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], * str;
    i = 0;
    do {
        dataTableCust(&head);
        printf("Введите отчество пациента: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        system("cls");
        check = false;
        p = head;
        do {
            if (strcmp(str, p->middleName) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    CustomersHat();
                }
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
//////////////////////
//сортировка по дате
void SearchDateCust(Customers* head) {

}
//////////////////////
void SearchMenuCust(Customers* head) {
    char choice;
    while (1) {
        dataTableCust(&head);
        printf("\n\t1) Поиск по ID пациента \n");
        printf("\t2) Поиск по фамилии \n");
        printf("\t3) Поиск по имени \n");
        printf("\t4) Поиск по отчеству \n");
        printf("\t5) Поиск дате рождения \n");
        printf("\t6) Выход\n\n");
        choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
            SearchIDCust(head);
            system("pause");
            system("cls");
            break;
        case '2':
            SearchSurnameCust(head);
            system("pause");
            system("cls");
            break;
        case '3':
            SearchNameCust(head);
            system("pause");
            system("cls");
            break;
        case '4':
            SearchMiddleNameCust(head);
            system("pause");
            system("cls");
            break;
        case '5':      
            SearchDateCust(head);
            system("pause");
            system("cls");
            break;
        case '6':
            return;
        }

    }
}



void SortIDUpCust(Customers** head) {
    int count = 0, tmp, Max = 0, min, f = 0;
    char tmpDay[3], tmpMouth[3], tmp3[3];
    Customers* p = *head;
    tmp = p->ID;
    while (p != NULL) {
        if (p->ID < tmp) tmp = p->ID;
        if (p->ID > Max) Max = p->ID;
        p = p->prev;
        count++;
    }
    tmp--;
    CustomersHat();
    min = Max;
    for (int i = 0; i < count - 1; i++) {
        p = *head;
        f = 0;
        while (p != NULL) {
            if (p->ID < Max - f + 1 && p->ID > tmp && p->ID < min) min = p->ID;
            p = p->prev;
            f++;
        }
        tmp = min;
        p = *head;
        while (p != NULL) {
            if (p->ID == min) {
                if (p->dateBirthday.day < 10) {
                    memset(tmpDay, 0, sizeof(tmpDay));
                    tmpDay[0] = '0';
                    strcat(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                }
                else strcpy(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                if (p->dateBirthday.month < 10) {
                    memset(tmpMouth, 0, sizeof(tmpMouth));
                    tmpMouth[0] = '0';
                    strcat(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                }
                else strcpy(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
        min = Max;
    }
}
void SortIDDownCust(Customers** head) {
    int count = 0, tmp = 0, Max = 0;
    char tmpDay[3], tmpMouth[3], tmp3[3];
    Customers* p;
    p = *head;
    while (p != NULL) {
        if (p->ID > tmp) tmp = p->ID;
        p = p->prev;
        count++;
    }
    tmp++;
    CustomersHat();
    for (int i = 0; i < count; i++) {
        p = *head;
        Max = 0;
        while (p != NULL) {
            if (p->ID > Max && p->ID < tmp) Max = p->ID;
            p = p->prev;
        }
        tmp = Max;
        p = *head;
        while (p != NULL) {
            if (p->ID == Max) {
                if (p->dateBirthday.day < 10) {
                    memset(tmpDay, 0, sizeof(tmpDay));
                    tmpDay[0] = '0';
                    strcat(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                }
                else strcpy(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                if (p->dateBirthday.month < 10) {
                    memset(tmpMouth, 0, sizeof(tmpMouth));
                    tmpMouth[0] = '0';
                    strcat(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                }
                else strcpy(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortSurnameCust(Customers** head) {
    int count = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], s;
    Customers* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    CustomersHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->surname[0] == s) {
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortNameCust(Customers** head) {
    int count = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], s;
    Customers* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    CustomersHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->name[0] == s) {
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
void SortMiddleNameCust(Customers** head) {
    int count = 0;
    char tmpDay[3], tmpMouth[3], tmp[3], s;
    Customers* p = *head;
    while (p != NULL) {
        p = p->prev;
        count++;
    }
    CustomersHat();
    p = *head;
    for (int i = -64; i < -32; i++) {
        s = i;
        p = *head;
        while (p != NULL) {
            if (p->middleName[0] == s) {
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
                printf("    |%-6d|%-16s|%-11s|%-16s|  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
///////////////////////////

void SortDateDownCust(Customers** head) {
    int count = 0, tmp = 0, tmpM = 0, tmpD = 0, Max = 0, MaxM = 0, MaxD = 0, M = 0, D = 0;
    char tmpDay[3], tmpMouth[3], tmp3[3];
    Customers* p = *head;
    while (p != NULL) {
        if (p->dateBirthday.year > tmp) tmp = p->dateBirthday.year;
        if (p->dateBirthday.month > tmpM) tmpM = p->dateBirthday.month;
        if (p->dateBirthday.day > tmpD) tmpD = p->dateBirthday.day;
        p = p->prev;
        count++;
    }
    tmp++;
    M = tmpM++;//!!!!!
    D = tmpD++;
    CustomersHat();
    for (int i = 0; i < count; i++) {
        p = *head;
        Max = 0;        
        while (p != NULL) {
            if (p->dateBirthday.year > Max && p->dateBirthday.year < tmp) Max = p->dateBirthday.year;
            p = p->prev;
        }
        tmp = Max;
        p = *head;
        tmpM = M;
        while (p != NULL) {
            MaxM = 0;            
            while (p != NULL) {
                if (p->dateBirthday.year == Max) if (p->dateBirthday.month > MaxM && p->dateBirthday.month < tmpM) MaxM = p->dateBirthday.month;
                p = p->prev;
            }
            tmpM = MaxM;
            p = *head;
            tmpD = D;
            while (p != NULL) {
                MaxD = 0;
                while (p != NULL) {
                    if (p->dateBirthday.year == Max && p->dateBirthday.month == MaxM) {
                        if (p->dateBirthday.day > MaxD && p->dateBirthday.day < tmpD) MaxD = p->dateBirthday.day;
                    }
                    p = p->prev;
                }
                tmpD = MaxD;
                p = *head;
                while (p != NULL) {
                    if (p->dateBirthday.year == Max && p->dateBirthday.month == MaxM && p->dateBirthday.day == MaxD) {
                        if (p->dateBirthday.day < 10) {
                            memset(tmpDay, 0, sizeof(tmpDay));
                            tmpDay[0] = '0';
                            strcat(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                        }
                        else strcpy(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                        if (p->dateBirthday.month < 10) {
                            memset(tmpMouth, 0, sizeof(tmpMouth));
                            tmpMouth[0] = '0';
                            strcat(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                        }
                        else strcpy(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                        printf("    | %-6d | %-16s | %-11s | %-16s |  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                        puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
                    }
                    p = p->prev;
                }
            }
        }
    }

}
void SortDateUpCust(Customers** head) {
    /*int count = 0, tmp, tmpM = 0, tmpD = 0, Max = 0, MaxM = 0, MaxD = 0, M = 0, D = 0, min, minM, minD, f = 0;
    char tmpDay[3], tmpMouth[3], tmp3[3];
    Customers* p = *head;
    tmp = p->dateBirthday.year;
    tmpM = p->dateBirthday.month;
    tmpD = p->dateBirthday.day;
    while (p != NULL) {
        if (p->dateBirthday.year < tmp) tmp = p->dateBirthday.year;        
        if (p->dateBirthday.year > Max) Max = p->dateBirthday.year;
        if (p->dateBirthday.month < tmpM) tmpM = p->dateBirthday.month;        
        if (p->dateBirthday.month > MaxM) MaxM = p->dateBirthday.month;        
        if (p->dateBirthday.day < tmpD) tmpD = p->dateBirthday.day;        
        if (p->dateBirthday.day > MaxD) MaxD = p->dateBirthday.day;
        p = p->prev;
        count++;
    }
    tmp--;
    M = tmpM++;
    D = tmpD++;
    CustomersHat();
    min = Max;
    minM = MaxM;
    minD = MaxD;
    for (int i = 0; i < count - 1; i++) {
        p = *head;
        f = 0;
        while (p != NULL) {
            if (p->dateBirthday.year < Max - f + 1 && p->dateBirthday.year > tmp && p->dateBirthday.year < min) min = p->dateBirthday.year;
            p = p->prev;
            f++;
        }
        tmp = min;
        p = *head;        
        tmpM = M;
        while (p != NULL) {
            f = 0;
            while (p != NULL) {
                if(p->dateBirthday.year == min) if(p->dateBirthday.month < MaxM - f + 1 && p->dateBirthday.month > tmpM && p->dateBirthday.month < minM) minM = p->dateBirthday.month;
                p = p->prev;
                f++;
            }
            tmpM = minM;
            p = *head;
            tmpD = D;
            while (p != NULL) {
                f = 0;
                while (p != NULL) {
                    if(p->dateBirthday.year == min && p->dateBirthday.month == minM) if(p->dateBirthday.day < MaxD - f + 1 && p->dateBirthday.day > tmpD && p->dateBirthday.day < minD) minD = p->dateBirthday.day;
                    p = p->prev;
                    f++;
                }
                tmpD = minD;
                p = *head;
                while (p != NULL) {
                    if (p->dateBirthday.year == min && p->dateBirthday.month == minM && p->dateBirthday.day == minD) {
                        if (p->dateBirthday.day < 10) {
                            memset(tmpDay, 0, sizeof(tmpDay));
                            tmpDay[0] = '0';
                            strcat(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                        }
                        else strcpy(tmpDay, _itoa(p->dateBirthday.day, tmp3, 10));
                        if (p->dateBirthday.month < 10) {
                            memset(tmpMouth, 0, sizeof(tmpMouth));
                            tmpMouth[0] = '0';
                            strcat(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                        }
                        else strcpy(tmpMouth, _itoa(p->dateBirthday.month, tmp3, 10));
                        printf("    | %-6d | %-16s | %-11s | %-16s |  %-2s.%-2s.%-d   |\n", p->ID, p->surname, p->name, p->middleName, tmpDay, tmpMouth, p->dateBirthday.year);
                        puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
                    }
                    p = p->prev;
                }
                minD = MaxD;                
            }
            minM = MaxM;
        }
        min = Max;
    }*/
    ///*int count = 0, tmp;
    //Customers* p = *head;
    //while (p != NULL) {
    //    p = p->prev;
    //    count++;
    //}
    //p = *head;
    //for (int f = 0; f < count; f++) {
    //    for(int i = 0; i < count - 1; i++) {
    //        if (p[i].dateBirthday.year > p[i + 1].dateBirthday.year) {
    //            tmp = p[i].dateBirthday.year;
    //            p[i].dateBirthday.year = p[i + 1].dateBirthday.year;
    //            p[i + 1].dateBirthday.year = tmp;
    //        }
    //        else if (p[i].dateBirthday.year == p[i + 1].dateBirthday.year && p[i].dateBirthday.month > p[i + 1].dateBirthday.month) {
    //            tmp = p[i].dateBirthday.year;
    //            p[i].dateBirthday.year = p[i + 1].dateBirthday.year;
    //            p[i + 1].dateBirthday.year = tmp;
    //        }
    //        else if 
    //    }
    //}*/
}

////////////////////////////
void SortMenuCust(Customers* head) {
    Customers* p;
    char choice;
    while (1) {
        p = head;
        system("cls");
        dataTableCust(&head);
        printf("\n\t1) Сортировка ID по убыванию\n");
        printf("\t2) Сортировка ID по возрастанию\n");
        printf("\t3) Сортировка фамилий по алфавиту\n");
        printf("\t4) Сортировка имён по алфавиту\n");
        printf("\t5) Сортировка отчеств по алфавиту\n");
        printf("\t6) Сортировка даты рождения по убыванию\n");
        printf("\t7) Сортировка даты рождения по возрастанию\n");
        printf("\t8) Выход\n\n");
        choice = _getch();
        switch (choice) {
        case '1':
            system("cls");
            SortIDDownCust(&head);
            system("pause");
            break;
        case '2':
            system("cls");
            SortIDUpCust(&head);
            system("pause");
            break;
        case '3':
            system("cls");
            SortSurnameCust(&head);
            system("pause");
            break;
        case '4':
            system("cls");
            SortNameCust(&head);
            system("pause");
            break;
        case '5':
            system("cls");
            SortMiddleNameCust(&head);
            system("pause");
            break;
        case '6':
            system("cls");
            SortDateDownCust(&head);
            system("pause");
            break;
        case '7':
            system("cls");
            SortDateUpCust(&head);
            system("pause");
            break;
        case '8':
            return;
        }

    }
}


void SearchIDAppDoc(Appeals* head) {
    bool checkString = false, checkEsc = false, check;
    Appeals* p;
    int i;
    char tmpDay[3], tmpMonth[3], tmp[3], * str;
    i = 0;
    do {
        dataTableApp(&head);
        printf("Введите ID доктора: ");
        str = writeStr(0);
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > 4) {
                printf("\tМаксимальный размер строки 4 символа\n");
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 1);
        }
    } while (strlen(str) > 4 || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (atoi(str) == p->IDdoc) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    AppealsHat();
                }
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
                printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchIDAppCust(Appeals* head) {
    bool checkString = false, checkEsc = false, check;
    Appeals* p;
    int i = 0;
    char tmpDay[3], tmpMonth[3], tmp[3], * str;
    i = 0;
    do {
        dataTableApp(&head);
        printf("Введите ID пациента: ");
        str = writeStr(0);
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > 4) {
                printf("\tМаксимальный размер строки 4 символа\n");
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 1);
        }
    } while (strlen(str) > 4 || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (atoi(str) == p->IDcust) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    AppealsHat();
                }
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
                printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchDiagnosisApp(Appeals* head) {
    bool checkString = false, checkEsc = false, check;
    Appeals* p;
    int i = 0;
    char tmpDay[3], tmpMonth[3], tmp[3], * str;
    i = 0;
    checkString = false;
    do {
        dataTableApp(&head);
        printf("Введите диагноз пациента: ");
        str = strconv(writeStr(0));
        if (strcmp(str, "EscMode") == 0) checkEsc = true;
        else {
            if (strlen(str) > MaxSecondNameSymbol) {
                printf("\tМаксимальный размер строки %d символов\n", MaxSecondNameSymbol);
                system("pause");
                system("cls");
            }
            checkString = checkStr(&str, 2);
        }
    } while (strlen(str) > MaxSecondNameSymbol || checkString == false && checkEsc == false);
    if (checkEsc == false) {
        p = head;
        check = false;
        do {
            if (strcmp(str, p->diagnosis) == 0) {
                check = true;
                i++;
                if (i == 1) {
                    system("cls");
                    AppealsHat();
                }
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
                printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        } while (p != NULL);
        if (check == false) printf("\tПользователь не найден!\n");
    }
}
void SearchMenuApp(Appeals* head) {
    char choice;
    while (1) {
        dataTableApp(&head);
        printf("\n\t1) Поиск по ID врача \n");
        printf("\t2) Поиск по ID пациента \n");
        printf("\t3) Поиск по диагнозу \n");
        printf("\t4) Выход\n\n");
        choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
            SearchIDAppDoc(head);
            system("pause");
            system("cls");
            break;
        case '2':
            SearchIDAppCust(head);
            system("pause");
            system("cls");
            break;
        case '3':
            SearchDiagnosisApp(head);
            system("pause");
            system("cls");
            break;        
        case '4':
            return;
        }

    }
}


void SortIDUpApp(Appeals** head) {
    int count = 0, tmp, Max = 0, min, f = 0;
    char tmpDay[3], tmpMonth[3], tmp3[3];
    Appeals* p = *head;
    tmp = p->NumApp;
    while (p != NULL) {
        if (p->NumApp < tmp) tmp = p->NumApp;
        if (p->NumApp > Max) Max = p->NumApp;
        p = p->prev;
        count++;
    }
    tmp--;
    AppealsHat();
    min = Max;
    for (int i = 0; i < count - 1; i++) {
        p = *head;
        f = 0;
        while (p != NULL) {
            if (p->NumApp < Max - f + 1 && p->NumApp > tmp && p->NumApp < min) min = p->NumApp;
            p = p->prev;
            f++;
        }
        tmp = min;
        p = *head;
        while (p != NULL) {
            if (p->NumApp == min) {
                if (p->dateAppeal.day < 10) {
                    memset(tmpDay, 0, sizeof(tmpDay));
                    tmpDay[0] = '0';
                    strcat(tmpDay, _itoa(p->dateAppeal.day, tmp3, 10));
                }
                else strcpy(tmpDay, _itoa(p->dateAppeal.day, tmp3, 10));
                if (p->dateAppeal.month < 10) {
                    memset(tmpMonth, 0, sizeof(tmpMonth));
                    tmpMonth[0] = '0';
                    strcat(tmpMonth, _itoa(p->dateAppeal.month, tmp3, 10));
                }
                else strcpy(tmpMonth, _itoa(p->dateAppeal.month, tmp3, 10));
                printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
        min = Max;
    }
}
void SortIDDownApp(Appeals** head) {
    int count = 0, tmp = 0, Max = 0;
    char tmpDay[3], tmpMonth[3], tmp3[3];
    Appeals* p;
    p = *head;
    while (p != NULL) {
        if (p->NumApp > tmp) tmp = p->NumApp;
        p = p->prev;
        count++;
    }
    tmp++;
    AppealsHat();
    for (int i = 0; i < count; i++) {
        p = *head;
        Max = 0;
        while (p != NULL) {
            if (p->NumApp > Max && p->NumApp < tmp) Max = p->NumApp;
            p = p->prev;
        }
        tmp = Max;
        p = *head;
        while (p != NULL) {
            if (p->NumApp == Max) {
                if (p->dateAppeal.day < 10) {
                    memset(tmpDay, 0, sizeof(tmpDay));
                    tmpDay[0] = '0';
                    strcat(tmpDay, _itoa(p->dateAppeal.day, tmp3, 10));
                }
                else strcpy(tmpDay, _itoa(p->dateAppeal.day, tmp3, 10));
                if (p->dateAppeal.month < 10) {
                    memset(tmpMonth, 0, sizeof(tmpMonth));
                    tmpMonth[0] = '0';
                    strcat(tmpMonth, _itoa(p->dateAppeal.month, tmp3, 10));
                }
                else strcpy(tmpMonth, _itoa(p->dateAppeal.month, tmp3, 10));
                printf("    |%-11d|%-9d|%-10d|  %-2s.%-2s.%-d |%-50s|%13d руб. |\n", p->NumApp, p->IDdoc, p->IDcust, tmpDay, tmpMonth, p->dateAppeal.year, p->diagnosis, p->costOfTreatment);
                puts("    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            }
            p = p->prev;
        }
    }
}
///////////////////////////
void SortDateDownApp(Appeals** head) {

}
void SortDateUpApp(Appeals** head) {

}
void SortCoastUpApp(Appeals** head) {
    
}
void SortCoastDownApp(Appeals** head) {
    
}
////////////////////////////
void SortMenuApp(Appeals** head) {
    Appeals* p;
    char choice;
    while (1) {
        p = *head;
        system("cls");
        dataTableApp(head);
        printf("\n\t1) Сортировка ID приёмов по убыванию\n");
        printf("\t2) Сортировка ID приёмов  по возрастанию\n");
        printf("\t3) Сортировка по стоимости лечения\n");
        printf("\t4) Выход\n\n");
        choice = _getch();
        switch (choice) {
        case '1':
            system("cls");
            SortIDDownApp(head);
            system("pause");
            break;
        case '2':
            system("cls");
            SortIDUpApp(head);
            system("pause");
            break;
        case '3':
            system("cls");
            SortCoastUpApp(head);
            system("pause");
            break;
        case '4':
            return;
        }

    }
}



//меню для выбора поиск\сортировка\ фильтрация
char manage_menu() {
    int first_choice;
    do {
        system("cls");
        printf("\n\t\tУправление данными\n\t* * * * * * * * * * * * * * *\n\n");
        printf("\t1) Поиск данных\n\t2) Сортировка данных\n\t3) Выход\n");
        first_choice = _getch();
        system("cls");
    } while ((int)first_choice < 48 || (int)first_choice > 51);
    return first_choice;
}
//работа с данными доктора
void ManageDataDoc(Doctors* head) {
    while (1) {
        switch (manage_menu()) {
        case '1':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SearchMenuDoc(head);
            system("cls");
            break;
        case '2':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SortMenuDoc(head);
            system("cls");
            break;
        case '3':
            return;
        }
    }
}
void ManageDataCust(Customers* head) {
    while (1) {
        switch (manage_menu()) {
        case '1':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SearchMenuCust(head);

            break;
        case '2':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SortMenuCust(head);
            system("pause");
            system("cls");
            break;
        case '3':
            return;
        }
    }
}
void ManageDataApp(Appeals* head) {
    while (1) {
        switch (manage_menu()) {
        case '1':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SearchMenuApp(head);

            break;
        case '2':
            if (headDoc == NULL) printf("\tДанные отсутствуют!\n");
            else SortMenuApp(&head);
            system("pause");
            system("cls");
            break;
        case '3':
            return;
        }
    }
}
//менб для просмотра данных
void UserSwitchDataMenu(Customers* headCust, Appeals* headApp) {
    int first_choice;
    while (1) {
        printf("\t1) Поиск и сортировка данных пациентов\n\t2) Поиск и сортировка данных приёмов\n\t3) Выход\n");
        first_choice = _getch();
        system("cls");
        switch (first_choice) {
        case '1':
            ManageDataCust(headCust);
            break;
        case '2':
            ManageDataApp(headApp);
            break;        
        case '3':
            return;
        }
    }
}
char data_menu() {
    int first_choice;
    system("cls");
    do {
        printf("\n\t\tГлавное меню\n\t* * * * * * * * * * * * * * *\n\n\t1) Просмотр всех данных пациентов\n\t2) Просмотр всех данных врачей\n\t3) Выход\n");
        first_choice = _getch();
        system("cls");
    } while ((int)first_choice < 48 || (int)first_choice > 50);
    return first_choice;
}










//Меню 1-го уровня
char main_menu() {
    int first_choice;
    system("cls");
    do {
        printf("\n\t\tГлавное меню\n\t* * * * * * * * * * * * * * *\n\n\t1) Главврач\n\t2) Врач\n\t3) Медрегистратор\n\t4) Регистрация\n\t5) Выход\n");
        first_choice = _getch();
        system("cls");
    } while ((int)first_choice < 48 || (int)first_choice > 53);
    return first_choice;
}
//Меню 2-го уровня для врача
void user_menu(int ID)
{
    int a = 1;
    FILE* CustomersFile = NULL,* AppealsFile = NULL,* DoctorsFile = NULL,* authFile = NULL;
    char user_choice;
    while (1) {
        system("cls");
        printf("\n\t\tМеню врача\n\t* * * * * * * * * * * * * * *\n\n");
        printf("  1) Открытие файла с данными\n");
        printf("  2) Приём пациената \n");
        printf("  3) Редактирование данных о приёме \n");
        printf("  4) Просмотр всех приёмов пациентов\n");
        printf("  5) Поиск и сортировка данных\n");
        printf("  6) Просмотр данных\n");       
        printf("  7) Выполнение задачи\n");       
        printf("  8) Изменение пароля\n");       
        printf("  9) Выход в меню\n");
        user_choice = _getch();
        switch (user_choice) {
        case '1':
            CustomersFile = fopen("ListOfCustomers.txt", "a+");
            AppealsFile = fopen("ListOfAppeals.txt", "a+");
            DoctorsFile = fopen("ListOfDoctors.txt", "a+");
            authFile = fopen("Authentification.txt", "a+");
            if (CustomersFile == NULL || AppealsFile == NULL || DoctorsFile == NULL || authFile == NULL) {
                printf("\n\tОшибка создания / открытия файла!\n");
                system("pause");
                system("cls");
            }
            else {
                readingDataCust(&headCust, CustomersFile);
                readingDataDoc(&headDoc, DoctorsFile);
                readingDataApp(&headApp, AppealsFile);
                readingDataAccount(&headAcc, authFile);
                printf("\n\tВыполнено!\n");
            }
            system("pause");
            system("cls");
            break;
        case '2':
            if (CustomersFile == NULL && AppealsFile == NULL && DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
            }
            else {
                PushAppealCust(&headApp, &headCust, AppealsFile, CustomersFile, ID);                
            }
            system("pause");
            system("cls");
            break;
        case '3':
            if (CustomersFile == NULL && AppealsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
                system("pause");
                system("cls");
            }
            else {
                editDataApp(&headApp);
            }
            break;
        case '4':
            if (AppealsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
                system("pause");
                system("cls");
            }
            else {
                if (headApp == NULL) printf("\n\tТаблица пуста!\n");
                else dataTableApp(&headApp);
                system("pause");
                system("cls");
            }
            break;
        case '5':
            if (CustomersFile == NULL && AppealsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
                system("pause");
                system("cls");
            }
            else UserSwitchDataMenu(headCust, headApp);
            break;
        case '6':
            a = 1;
            while (a == 1) {
                switch (data_menu()) {
                case '1':
                    if (CustomersFile == NULL) {
                        printf("\n\tФайл закрыт или не создан!\n");
                        system("pause");
                        system("cls");
                    }
                    else {
                        if (headCust == NULL) printf("\n\tТаблица пуста!\n");
                        else dataTableCust(&headCust);
                        system("pause");
                        system("cls");
                    }
                    break;
                case '2':
                    if (CustomersFile == NULL) {
                        printf("\n\tФайл закрыт или не создан!\n");
                        system("pause");
                        system("cls");
                    }
                    else {
                        if (headDoc == NULL) printf("\n\tТаблица пуста!\n");
                        else dataTableDoc(&headDoc);
                        system("pause");
                        system("cls");
                    }
                    break;
                case '3':
                    a = 0;
                }
            }
            break;
        case '7':
            if (authFile == NULL) printf("\n\tФайл закрыт или не создан!\n");
            else Task(&headApp);
            break;
        case '8':
            if (authFile == NULL) printf("\n\tФайл закрыт или не создан!\n");
            else EditPass(&headAcc, ID);
            break;
        case '9':
            if (CustomersFile != NULL && AppealsFile != NULL && DoctorsFile != NULL) {
                rewriteApp(&headApp, AppealsFile);
                fclose(CustomersFile);
                fclose(AppealsFile);
                fclose(DoctorsFile);
                if (headCust != NULL && headDoc != NULL && headApp != NULL) {
                    memset(headCust, 0, sizeof(Customers));
                    memset(headApp, 0, sizeof(Appeals));
                    memset(headDoc, 0, sizeof(Doctors));
                }
            }
            if (authFile != NULL) {
                rewriteAccount(&headAcc, authFile);
                fclose(authFile);
                authFile = NULL;
                memset(headAcc, 0, sizeof(Accounts));
            }
            return;
        }
    }
}
//Меню 2-го уровня для главврача
void admin_menu(int ID) {
    char admin_choice;
    FILE* DoctorsFile = NULL,* authFile = NULL;
    while (1) {        
        printf("\n\t\tМеню главврача\n\t* * * * * * * * * * * * * * *\n\n");
        printf("  1) Создание / открытие файла с данными\n");
        printf("  2) Добавление записи врача\n");
        printf("  3) Редактирование записи врача\n");
        printf("  4) Удаление записи врача\n");
        printf("  5) Просмотр всех данных врачей в табличной форме\n");
        printf("  6) Поиск и сортировка данных врачей\n");
        printf("  7) Управление клиентами\n");
        printf("  8) Изменение пароля\n");
        printf("  9) Выход в меню\n");
        admin_choice = _getch();
        switch (admin_choice) {
        case '1':
            if (DoctorsFile == NULL && authFile == NULL) {
                DoctorsFile = fopen("ListOfDoctors.txt", "a+");
                authFile = fopen("Authentification.txt", "a+");
                if (DoctorsFile == NULL || authFile == NULL) {
                    printf("\n\tОшибка создания / открытия файла!\n");
                    system("pause");
                    system("cls");
                }
                else {
                    readingDataAccount(&headAcc, authFile);
                    readingDataDoc(&headDoc, DoctorsFile);
                    printf("\n\tВыполнено!\n\n");
                }
            }
            else {
                printf("\n\tФайл создан / открыт ранее!\n\n");
                system("pause");
                system("cls");
            }
            system("pause");
            system("cls");
            break;
        case '2':
            if (DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n\n");
                system("pause");
                system("cls");
            }
            else {
                pushDoc(&headDoc, DoctorsFile);                
            }            
            break;
        case '3':
            if (DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n\n");
            }
            else {
                editDataDoc(&headDoc);
            }
            break;
        case '4':
            if (DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
            }
            else {
                popDoc(&headDoc, &headAcc);
            }            
            break;
        case '5':
            if (DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
            }
            else
            {
                if (headDoc == NULL) printf("\n\tТаблица пуста!\n");
                else dataTableDoc(&headDoc);
            }
            system("pause");
            system("cls");
            break;
        case '6':
            if (DoctorsFile == NULL) {
                printf("\n\tФайл закрыт или не создан!\n");
            }
            else ManageDataDoc(headDoc);
            break;
        case '7':
            if (DoctorsFile != NULL) {
                rewriteDoc(&headDoc, DoctorsFile);
                fclose(DoctorsFile);
                DoctorsFile = NULL;
                memset(headDoc, 0, sizeof(Doctors));
            }
            if (authFile != NULL) {
                rewriteAccount(&headAcc, authFile);
                fclose(authFile);
                authFile = NULL;
                memset(headAcc, 0, sizeof(Accounts));
            }
            user_menu(ID);
            break;
        case '8':
            if (authFile == NULL) printf("\n\tФайл закрыт или не создан!\n");
            else EditPass(&headAcc, ID);
            break;
        case '9':
            if (DoctorsFile != NULL) {
                rewriteDoc(&headDoc, DoctorsFile);
                fclose(DoctorsFile);
                DoctorsFile = NULL;
                memset(headDoc, 0, sizeof(Doctors));
            }
            if (authFile != NULL) {
                rewriteAccount(&headAcc, authFile);
                fclose(authFile);
                authFile = NULL;
                memset(headAcc, 0, sizeof(Accounts));
            }
            return;
        }
    }
}
//Меню 2-го уровня для медрегистатора
void regist_menu(int ID) {
    int a = 0;
    FILE* CustomersFile = NULL,* authFile = NULL;
    char user_choice;
    while (1) {
        system("cls");
        printf("\n\t\tАвторизация\n\t* * * * * * * * * * * * * * *\n\n");
        printf("  1) Открытие файла с данными данными\n");
        printf("  2) Добавление записи пациента\n");
        printf("  3) Удаление записи пациента\n");
        printf("  4) Редактирование записи пациента\n");
        printf("  5) Просмотр всех данных пациентов в табличной форме\n");
        printf("  6) Поиск и фильтрация данных\n");
        printf("  7) Изменение пароля\n");
        printf("  8) Выход в меню\n");
        user_choice = _getch();
        system("cls");
        switch (user_choice) {
        case '1':
            if (CustomersFile == NULL) {
                CustomersFile = fopen("ListOfCustomers.txt", "a+");
                authFile = fopen("Authentification.txt", "a+");
                if (CustomersFile == NULL || authFile == NULL) {
                    printf("\tОшибка создания / открытия файла!\n");
                }
                else {
                    readingDataCust(&headCust, CustomersFile);
                    readingDataAccount(&headAcc, authFile);
                    printf("\tВыполнено!\n");
                }
            }
            else printf("\tФайл создан / открыт ранее!\n");
            system("pause");
            system("cls");
            break;
        case '2':
            if (CustomersFile == NULL) {
                printf("\tФайл закрыт или не создан!\n");
            }
            else {
                pushCust(&headCust, CustomersFile);
                printf("\tВыполнено!\n");
            }
            system("pause");
            system("cls");
            break;
        case '3':
            if (CustomersFile == NULL) {
                printf("\tФайл закрыт или не создан!\n");
            }
            else {
                popCust(&headCust);
                printf("\tВыполнено!\n");
            }
            system("pause");
            system("cls");
            break;
        case '4':
            if (CustomersFile == NULL) {
                printf("\tФайл закрыт или не создан!\n");
            }
            else {
                editDataCust(&headCust);
                printf("\tВыполнено!\n");
            }
            system("pause");
            system("cls");
            break;
        case '5':
            if (CustomersFile == NULL) {
                printf("\tФайл закрыт или не создан!\n");
            }
            else {
                if (headCust == NULL) printf("\tТаблица пуста!\n");
                else dataTableCust(&headCust);                
            }    
            system("pause");
            system("cls");
            break;
        case '6':
            if (CustomersFile == NULL) {
                printf("\tФайл закрыт или не создан!\n");
            }
            else {
                
            }
            break;
        case '7':
            if (authFile == NULL) printf("\n\tФайл закрыт или не создан!\n");
            else EditPass(&headAcc, ID);
            break;
        case '8':
            if (CustomersFile != NULL) {
                rewriteCust(&headCust, CustomersFile);
                fclose(CustomersFile);
                memset(headCust, 0, sizeof(Customers));
                free(headCust);
                headCust = NULL;
            }
            if (authFile != NULL) {
                rewriteAccount(&headAcc, authFile);
                fclose(authFile);
                authFile = NULL;
                memset(headAcc, 0, sizeof(Accounts));
            }
            return;
        }
    }
}           