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
void show_person(const struct Student *stu);
void search_id(struct Student *s_arr[], int *n, char *id);
void sort(struct Student *s_arr[], int n);
void show_rank(struct Student *s_arr[], int n);
int encode(int score, int key);
int decode(int score, int key);
int decode_num(int num, int key);
void print_score(const int *arr, int size);

int main(int argc, char *argv[])
{
    int scores[N] = {0};
    char cmd = 0;
    int key = 0;
    int score = 0;
    int i = 0;
    scanf("%c", &cmd);
    scanf("%d", &key);
    //for(i = 0; ~scanf("%d", &score); i++)
    if(cmd == 'e')
    {
        for(i = 0; i < 12; i++)
        {
            scanf("%d", &score);
            scores[i] =encode(score, key);
        }
    }
    else if(cmd == 'd')
    {
        for(i = 0; i < 12; i++)
        {
            scanf("%d", &score);
            scores[i] =decode(score, key);
        }
    }

    print_score(scores, i);
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


void show_person(const struct Student *stu)
{
    printf("%s ", stu->f_name);
    printf("%s ", stu->l_name);
    printf("%s ", stu->id);
    printf("%d ", stu->score);
    printf("%d ", stu->retake);
    printf("%s\n", stu->gpa);
}

void search_id(struct Student *s_arr[], int *n, char *id)
{
    for (int i = 0; i < *n; ++i)
    {
        if (strcmp(s_arr[i]->id, id) == 0)
        {
            show_person(s_arr[i]);
            return;
        }
    }
    printf("Not Found.\n");
}

void sort(struct Student *s_arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (s_arr[j]->score < s_arr[j+1]->score)
            {
                struct Student *temp = s_arr[j];
                s_arr[j] = s_arr[j+1];
                s_arr[j+1] = temp;
            }
        }
    }
}

void show_rank(struct Student *s_arr[], int n)
{
    int rank = 1;

    for (int i = 0; i < n; ++i)
    {

        printf("%s ", s_arr[i]->f_name);
        printf("%s ", s_arr[i]->l_name);
        printf("%s ", s_arr[i]->id);
        printf("%d ", s_arr[i]->score);

        if (i == 0)
        {
            printf("%d\n", rank);
            rank++;
            continue;
        }
        if (i != 0 && s_arr[i]->score != s_arr[i - 1]->score)
        {
            printf("%d\n", rank);
        }
        else
            printf("%d\n", rank - 1);
        rank++;
    }
}


int encode(int score, int key)
{
    int res = 0;
    int i = 1;
    while(score)
    {
        res += ((score%10 + key)%10) * i;
        i *= 10;
        score /= 10;
    }
    return res;
}

int decode(int score, int key)
{
    int res_score = 0;
    if(score >= 100)
    {
        res_score = decode_num(score/100, key) * 100 + decode_num((score/10)%10, key) * 10 + decode_num(score%10,key);
    }
    else if(score < 10)
    {
        res_score += 10 * decode_num(0, key);
        res_score += decode_num(score%10, key);
    }
    else
    {
        res_score += 10 * decode_num(score/10, key);
        res_score += decode_num(score%10, key);
    }
    return res_score;

}


void print_score(const int *arr, int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(arr[i] >= 10)
        {
            printf("%d ", arr[i]);
        }
        else
        {
            printf("0%d ", arr[i]);
        }


    }
}

int decode_num(int num, int key)
{
    if(num - key < 0)
    {
        return num - key + 10;
    }

    return num - key;
}



char *calc_gpa(char *class, int score)
{

    if(score >= 93)
    {
        strcpy(class, "A+");
    }
    else if(score >= 85)
    {
        strcpy(class, "A");
    }
    else if(score >= 80)
    {
        strcpy(class, "B+");
    }
    else if(score >= 75)
    {
        strcpy(class, "B");
    }
    else if(score >= 70)
    {
        strcpy(class, "C+");
    }
    else if(score >= 65)
    {
        strcpy(class, "C");
    }
    else if(score >= 60)
    {
        strcpy(class, "D");
    }
    else
    {
        strcpy(class, "F");
    }

    return class;
}