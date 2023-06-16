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
char *calc_gpa(char *class, int score);
void print_menu();
void student_system();

int main()
{
    // 启动学生管理系统
    student_system();

    return 0;
}


void student_system()
{
    struct Student *s_arr[M];
    char f_name[N] = "";
    char l_name[N] = "";
    char id[N] = "";
    int score = 0;
    int s_numbers = 0;
    int num = 0;
    int option;
    print_menu();
    while (1)
    {
        scanf("%d", &option);
        if(option == 1)
        {
            s_numbers = add(s_arr, "Jingyu", "LI", "202200000000", 85);
            s_numbers = add(s_arr, "Jy", "LEE", "202200100000", 89);
            s_numbers = add(s_arr, "Jxxxyx", "Leeeee", "202100100000", 100);
            s_numbers = add(s_arr, "Jingyu11", "LI", "202200000001", 85);

            while(~scanf("%s", f_name))
            {
                scanf("%s", l_name);
                scanf("%s", id);
                scanf("%d", &score);
                if (checkId(id) && checkScore(score))
                    s_numbers = add(s_arr, f_name, l_name, id, score);
            }


            printf("Name_f Name_l stu_id score retake GPA\n");
            show_info(s_arr, s_numbers);
            printf("Total: %d", s_numbers);
        }
        else if(option == 2)
        {
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
        }
        else if(option == 3)
        {
            s_numbers = add(s_arr, "Jingyu", "LI", "202200000000", 85);
            s_numbers = add(s_arr, "Jy", "LEE", "202200100000", 89);
            s_numbers = add(s_arr, "Jxxxyx", "Leeeee", "202100100000", 100);
            s_numbers = add(s_arr, "Jingyu11", "LI", "202200000001", 85);

            s_numbers = add(s_arr, "Jingyuuuu", "LI", "202200000900", 59);
            s_numbers = add(s_arr, "Jingyuuuu", "Lous", "202100000900", 60);
            s_numbers = add(s_arr, "Asss", "Dccc", "202212344321", 84);
            s_numbers = add(s_arr, "Asssd", "Dccec", "202122244321", 83);

            while(scanf("%s", id))
            {
                if (!strcmp(id, "0"))
                    break;
                search_id(s_arr,&s_numbers, id);
            }
        }
        else if(option == 4)
        {
            while(~scanf("%s", f_name))
            {
                scanf("%s", l_name);
                scanf("%s", id);
                scanf("%d", &score);
                if (checkId(id) && checkScore(score))
                    s_numbers = add(s_arr, f_name, l_name, id, score);
            }

            sort(s_arr, s_numbers);
            printf("Name_f Name_l stu_id score Rank\n");
            show_rank(s_arr, s_numbers);
        }
        else if(option == 5)
        {
            int scores[N] = {0};
            char cmd = 'e';
            int key = 0;
            int score = 0;
            int i = 0;
            //scanf("%c", &cmd);
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


            print_score(scores, i);
        }
        else if(option == 6)
        {
            int scores[N] = {0};
            char cmd = 'd';
            int key = 0;
            int score = 0;
            int i = 0;
            //scanf("%c", &cmd);
            scanf("%d", &key);
            //for(i = 0; ~scanf("%d", &score); i++)

            if(cmd == 'd')
            {
                for(i = 0; i < 12; i++)
                {
                    scanf("%d", &score);
                    scores[i] =decode(score, key);
                }
            }

            print_score(scores, i);
        }
        else if(option == 7)
        {
            char gpa[8][3] = {"A+",
                              "A",
                              "B+",
                              "B",
                              "C+",
                              "C",
                              "D",
                              "F"};
            int scores[N] = {0};
            char class[N] = {0};
            int score = 0;
            int i = 0;      //记录读入数组score的数量
            int j = 0;      //遍历score
            int n = 0;      //用于遍历gpa
            int count = 0;  //统计每个gpa级别数量
            for(i = 0; ~scanf("%d", &score); i++)
            {
                scores[i] = score;
            }
            for(n = 0; n < 8; n++)
            {
                count = 0;
                for(j = 0; j < i; j++)
                {
                    if(scores[j] >= 0 && scores[j] <= 100)
                    {
                        if(!strcmp(gpa[n], calc_gpa(class, scores[j])))
                        {
                            count++;
                        }
                    }

                }
                if(count)
                {
                    printf("%s: %d\n",gpa[n], count);
                }
            }
        }
        else if(option == 0)
        {
            num = 1;
            break;
        }
        else
        {
            printf("option err!\n");
        }
    }

    if (!num)
        print_menu();
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

void print_menu()
{
    printf("1 add\n"
           "2 delete\n"
           "3 search\n"
           "4 sort by score\n"
           "5 encrypt\n"
           "6 decrypt\n"
           "7 analysis\n"
           "0 exit\n");
}