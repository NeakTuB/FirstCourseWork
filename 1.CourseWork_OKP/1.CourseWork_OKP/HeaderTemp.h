#pragma once
/*/Шифрование и дешифрование
/*void Encryption(FILE* File) {
	int key = 1, s;
	FILE* TempFile = NULL;
	File = fopen("Authentification.txt", "r+");
	if ((File = fopen("Authentification.txt", "r+")) == NULL) {
		printf("\tОшибка открытия файла!\n");
	}
	else {
		TempFile = fopen("Temp.txt", "w+");
		if ((TempFile = fopen("Temp.txt", "w+")) == NULL) {
			printf("\tОшибка открытия файла!\n");
		}
		else {
			fseek(File, 0, SEEK_SET);
			do {
				s = fgetc(File);
				fprintf(TempFile, "%c", s);
			} while (s != EOF);
		}		
	}	
	fclose(File);
	File = fopen("Authentification.txt", "w+");
	if ((File = fopen("Authentification.txt", "w+")) == NULL) {
		printf("\tОшибка открытия файла!\n");
	}
	fseek(TempFile, 0, SEEK_SET);
	do {
		s = fgetc(TempFile);
		s = (int)s;
		s = s + key;
		s = (char)s;
		fprintf(File, "%c", s);
		fprintf(File, " ");
	} while (s != EOF);
	fclose(TempFile);
	fclose(File);
	remove(TempFile);
}*/
//Ввод строки посимвольно 


//	Работа с массивами структур 

//Добавление нового элемента структуры
/*void push(Doctors** head,Doctors) {
	char s,* str;
	int Esc = 0, n = 0;
	Doctors* tmp = malloc(sizeof(Doctors));
	if (tmp == NULL) {
		exit(STACK_OVERFLOW);
	}	
	Doctors* head = malloc(sizeof(Doctors));
	tmp->next = *head;
	printf("Введите имя: ");
	do {
		str = (char*)malloc(sizeof(char));
		s = _getch();
		if ((int)s == 27) {
			Esc++;
		}
		else if ((int)s == 8 && n > 0) {
			printf("\b ");
			printf("\b");
			n--;
		}
		else {
			printf("%c", s);			
			*(str + n) = s;
			n++;
		}
	} while ((int)s != 13 && Esc == 0);
	*(str + n - 1) = '\0';
	tmp->next = str;
	printf("%s", tmp->name);
	*head = tmp;
}*/
/*typedef int T;
typedef struct Stack_tag {
    T* data;
    size_t size;
    size_t top;
} Stack_t;

Stack_t* createStack(int size) {    //Создание стака
    Stack_t* out = NULL;
    out = malloc(sizeof(Stack_t));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = size;
    out->data = malloc(out->size * sizeof(T));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}
void deleteStack(Stack_t** stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}
void push(Stack_t* stack, T value) {        //Вставка елемента в стак
    if (stack->top >= stack->size) {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
    stack->size++;
}
void resize(Stack_t* stack) {
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(T));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}
T pop(Stack_t* stack) {             //Удаление последнего елемента из стака
    if (stack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    stack->size--;
    return stack->data[stack->top];
}
T peek(const Stack_t* stack) {
    if (stack->top <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top - 1];
}
void printStackValue(const T value) {   //Печать значение стака
    printf("%d", value);
}
void printStack(const Stack_t* stack, void(*printStackValue)(const T)) {    //Печать стака
    int i;
    int len = stack->size - 1;
    printf("стек %d > ", stack->size - 1);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf("  ");
    }
    /*if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}
void printStack1(const Stack_t* stack, void(*printStackValue)(const T)) {   //Печать стака
    int i;
    int len = stack->size - 1;
    printf("stack %d > ", stack->size - 1);
    for (i = 0; i < len; i++) {
        if (i == 0) {
            printStackValue(stack->data[i]);
        }
    }
    /*if (stack->size != 0) {
    printStackValue(stack->data[i]);
    }
    printf("\n");
}
void clean_stdin() // Функция очистки буфера ввода с клавиатуры
{
    fflush(stdin);
    fseek(stdin, 0, SEEK_END);
}
int getInt() {
    int err, a;
    do
    {
        err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
        printf("\nВведите  єлемент ");
        clean_stdin(); // Очистить буфер ввода 
        if (scanf("%i[0-9]", &a) == 1) {} // Проверка ввел ли пользователь буквы или цифры
        else
        {
            printf("Вы ввели буквы, повторите ввод");
            err = 1; // Произошла ошибка.
        }
        if (a > 10000 || a < -10000) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
        {
            printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: -10000 - 10000");
            err = 1; // Произошла ошибка.
        }
    } while (err == 1); // Повторять пока есть ошибка

    return a;
}

int main() {
    int a, b, i, size = 1, error;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*printf("Введите размер стека");
    scanf("%i",&size);
    Stack_t* s = createStack(size);
    int f = s->size;

    do {
        printf("\nЄлементом сруктуры является точка в пространстве");
        printf("\n\n1) Добавление елемента в стек");
        printf("\n2) Удаление елемента из стека");
        printf("\n3) Чтение первого элемента стека");
        printf("\n4) Проверить на пустоту стек");
        printf("\n5) Получить размер стека");
        printf("\n0) Выйти");

        //printf("\nВведите число : ");
        //scanf("%i[0-9]", &b);
        b = getInt();

        switch (b)
        {
        case 1:
            if (s->size < 4) {
                printf("\nВведите новый єлемент:");
                a = getInt();
                push(s, a);
                printStack(s, printStackValue, f);
                //f--;
                getchar();
            }
            else printf("Стек полн");
            break;
        case 2:
            if (s->size - 1) {
                pop(s);
                f++;
                printStack(s, printStackValue);
            }
            printf("\nСтек пуст");
            break;
        case 3:
            printStack1(s, printStackValue);
            break;
        case 4:
            if (s->size == 1) {
                printf("\nСтек пуст");
            }
            else
                printf("\nСтек не пуст уго размер =%i", s->size - 1);
            break;
        case 5:
            printf("\nРазмер стека=%i", s->size - 1);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    } while (b);

    system("pause");

    return 0;
}*/

