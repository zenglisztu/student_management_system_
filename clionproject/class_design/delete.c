//
// Created by 曾立 on 2023/6/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
#define M 100

struct Student
{
    char f_name[N];
    char l_name[N];
    char id[N];
    int score;
    int retake;
    char gpa[N];
};

void sc_gpa(struct Student *student, int score);
int is_retake(char *id);
int add(struct Student *arr[], char *f_name, char *l_name, char *id, int score);
void show_info(struct Student *s_arr[], int n);
int checkId(char *id);
int checkScore(int score);
void delete(struct Student *s_arr[], int *n, char *id);

int main()
{
    struct Student *s_arr[M];
    char f_name[N] = "";
    char l_name[N] = "";
    char id[N] = "";
    int score = 0;
    int s_numbers = 0;

    s_numbers = add(s_arr, "Jingyu", "LI", "202200000000", 85);
    s_numbers = add(s_arr, "Jy", "LEE", "202200100000", 89);
    s_numbers = add(s_arr, "Jxxxyx", "Leeeee", "202100100000", 100);
    s_numbers = add(s_arr, "Jingyu11", "LI", "202200000001", 85);

    while(~scanf("%s", id))
    {
        int n = s_numbers;
        delete(s_arr,&s_numbers, id);
    }


    printf("Name_f Name_l stu_id score retake GPA\n");
    show_info(s_arr, s_numbers);
    printf("Total: %d", s_numbers);
    return 0;
}

int is_retake(char *id)
{
    if (id[0] == '2' && id[1] == '0' && id[2] == '2' && id[3] == '2')
        return 0;

    return 1;
}

void sc_gpa(struct Student *student, int score)
{
    if (score >= 93)
        strcpy(student->gpa, "A+");
    else if (score >= 85)
        strcpy(student->gpa, "A");
    else if (score >= 80)
        strcpy(student->gpa, "B+");
    else if (score >= 75)
        strcpy(student->gpa, "B");
    else if (score >= 70)
        strcpy(student->gpa, "C+");
    else if (score >= 65)
        strcpy(student->gpa, "C");
    else if (score >= 60)
        strcpy(student->gpa, "D");
    else
        strcpy(student->gpa, "F");
}

int add(struct Student *arr[], char *f_name, char *l_name, char *id, int score)
{
    static int stu_number = 0;
    struct Student *stu = (struct Student *)malloc(sizeof(struct Student));

    strcpy(stu->f_name, f_name);
    strcpy(stu->l_name, l_name);
    strcpy(stu->id, id);
    stu->score = score;
    stu->retake = is_retake(id);
    sc_gpa(stu, stu->score);

    arr[stu_number] = stu;
    stu_number++;

    return stu_number;
}

void show_info(struct Student *s_arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%s ", s_arr[i]->f_name);
        printf("%s ", s_arr[i]->l_name);
        printf("%s ", s_arr[i]->id);
        printf("%d ", s_arr[i]->score);
        printf("%d ", s_arr[i]->retake);
        printf("%s\n", s_arr[i]->gpa);
    }
}

int checkId(char *id)
{
    if (strlen(id) != 12)
        return 0;
    if (id[0] == '2' && id[1] == '0' && id[2] == '2' && id[3] == '2')
        return 1;
    if (id[0] == '2' && id[1] == '0' && id[2] == '2' && id[3] == '1')
        return 1;
    if (id[0] == '2' && id[1] == '0' && id[2] == '2' && id[3] == '0')
        return 1;
    return 0;
}

int checkScore(int score)
{
    if (score < 0 || score > 100)
        return 0;

    return 1;
}

void delete(struct Student *s_arr[], int *n, char *id)
{
    for (int i = 0; i < *n; ++i)
    {
        if (strcmp(s_arr[i]->id, id) == 0)
        {
            free(s_arr[i]);
            for (int j = i; j < *n - 1; ++j)
            {
                s_arr[j] = s_arr[j+1];
            }
            (*n)--;
            break;
        }
    }
}
