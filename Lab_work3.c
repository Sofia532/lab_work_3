#include <stdio.h>
#include <stdlib.h>

int is_natural_string(const char *str) {
    if (str[0] == '\0' || str[0] == '0' || str[0] == '-') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}
int is_float_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') start += 1;
    if (str[start] == '\0') return 0;
    int dot_count = 0;
    int digit_count = 0;
for (int i = start; str[i] != '\0'; i++) {
    if (str[i] == '.') {
        dot_count++;
        if (dot_count > 1) return 0;
    }
    else if (str[i] >= '0' && str[i] <= '9') {
        digit_count++;
}
else {
    return 0;
}
}
if (digit_count == 0) return 0;
return 1;
}
int main() {
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;
    while (1) {
         printf("N: ");
         if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения\n");
            free(N_str);
            continue;
        }
        if (is_natural_string(N_str)) {
            N = atoi(N_str);
            free(N_str);
            break;
        } 
        else {
            free(N_str);
            printf("Чичло должно быть натуральным\n");
        }
    }
    while (1) {
        printf("M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения\n");
            free(M_str);
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
            free(M_str);
            break;
        }
        else {
            printf("Чичло должно быть натуральным\n");
            free(M_str);
}
}
if (N < 2){
    printf("Нужно ввести минимум 2 строки\n");
    return 1;
}
float *Matrix = malloc(M * N * sizeof(*Matrix));
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        char *element = NULL;
        float value;
        while (1) {
            printf("Введите элемент [%i][%i]: ", i, j);
            if (scanf("%ms", &element) != 1) {
                printf("Ошибка чтения\n");
                free(element);
                continue;
            }
            if (is_float_string(element)) {
                value = atof(element);
                free(element);
                break;
            } else {
                free(element);
                printf("некорректный ввод\n");
            }
        }
        Matrix[i*M + j] = value;
    }
}

printf("Матрица:\n");
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        printf("| %f |", Matrix[i*M + j]);
    }
    printf("\n");
}
// Начало
 float min_val = 0.0;
 int min_i = -1, min_j = -1;
int found = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        float current = Matrix[i*M + j];
        if (current > 0) {
            if (found  == 0 || current < min_val) {
                min_val = current;
                min_i = i;
                min_j = j;
                found = 1;
            }
        }
    }
}
if (found == 0) {
    printf("нет положительных элементов\n");
    free(Matrix);
    return 1;
}
printf("Mинимaльный положительный элемент: %f\n", min_val);
printf("координаты: строка %d, столбец %d\n", min_i, min_j);



double P = 1.0;
int index = 1;
for (int j = 0; j < M; j++) {
    float a = Matrix[index * M + j];
    if (a == 0.0) {
        printf("элемент равен 0, делить нельзя\n");
        free(Matrix);
        return 1;
    }
    double x = (1.0 / a) + 4.2;
    P = P * x;
}
printf("P = %lf\n", P);



Matrix[min_i * M + min_j] = (float)P;
printf("после изменений:\n");
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        printf("| %.4f |", Matrix[i*M + j]);
    }
    printf("\n");
}
free(Matrix);


return 0;
}