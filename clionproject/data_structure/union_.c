//
// Created by 曾立 on 2023/7/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 20

union PersonData
{
    char lesson[NAME_LEN];
    int score;
};

struct Person
{
    char name[NAME_LEN];
    int age;
    char sex;
    int flag;
    union PersonData person_data;
};

int GetName(char name[], int size);
int GetAge();
int GetSex();
int GetScore();
int GetLesson(char lesson[], int size);
int GetFlag();
int PrintArr(struct Person *p, int len);

int main(int argc, char *argv[])
{
    struct Person *plt = (struct Person*)malloc(sizeof(struct Person) * 3);
    for (int i = 0; i < 3; i++)
    {
        GetName(plt[i].name, NAME_LEN);
        plt[i].age = GetAge();
        plt[i].sex = GetSex();
        plt[i].flag = GetFlag();
        if (plt[i].flag == 0)
        {
            plt[i].person_data.score = GetScore();
        }
        else if (plt[i].flag == 1)
        {
            GetLesson(plt[i].person_data.lesson, NAME_LEN);
        }
    }
    PrintArr(plt, 3);

    free(plt);
    system("pause");
    return 0;
}

int GetName(char name[], int size)
{
    char ch = 0;
    int i = 0;
    if(size <= 0)
    {
        return -1;
    }
    printf("please input name: ");
    ch = getchar();
    while(ch != '\n')
    {
        name[i++] = ch;
        ch = getchar();
    }
    name[i] = '\0';

    return 0;
}

int GetAge()
{
    int age = -1;
    printf("please input age: ");
    scanf_s("%d", &age);
    while(getchar() != '\n'){}
    return age;

}

int GetSex()
{
    int sex = -1;
    printf("please input sex (0 - m, 1 - w): ");
    scanf_s("%d", &sex);
    while(getchar() != '\n'){}
    return sex;

}

int GetScore()
{
    printf("please input score: ");
    int score = -1;
    scanf_s("%d", &score);
    while(getchar() != '\n'){}
    return score;

}

int GetLesson(char lesson[], int size)
{
    char ch = 0;
    int i = 0;
    printf("please input lesson: ");
    if(size <= 0)
    {
        return -1;
    }
    ch = getchar();
    while(ch != '\n')
    {
        lesson[i++] = ch;
        ch = getchar();
    }
    lesson[i] = '\0';
    return 0;
}

int GetFlag()
{
    printf("please input person type (0-student 1- teacher): ");
    int score = -1;
    scanf_s("%d", &score);
    while(getchar() != '\n'){}

    return score;
}

int PrintArr(struct Person *p, int len)
{
    if (NULL == p || len <= 0)
    {
        return -1;
    }
    for (int i = 0; i < len; i++)
    {
        printf("name: %s ", p[i].name);
        printf("age: %d ", p[i].age);
        printf("sex: %d ", p[i].sex);
        if(p[i].flag == 0)
        {
            printf("score: %d\n", p[i].person_data.score);
        }
        else if(p[i].flag == 1)
        {
            printf("lesson: %s\n", p[i].person_data.lesson);
        }
    }
    return 0;
}