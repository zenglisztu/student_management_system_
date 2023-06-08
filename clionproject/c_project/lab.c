#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct PersonNode
{
    char first_name[N];
    char last_name[N];
    char id[N];
    int score;
    int retake;
    char GPA[N];
    struct PersonNode *pst_next;
};
struct HeadNode
{
    int len;
    struct PersonNode *pst_first;
};

int init(struct HeadNode *pst_head);
struct HeadNode* create_head_node();
int delete_head_node(struct HeadNode *pst_head);
struct PersonNode * create_node(struct PersonNode *pst_data);
int delete_node(struct PersonNode *pst_node);
int append_person(struct HeadNode *pst_head, struct PersonNode *new_pst);
int remove_person(struct HeadNode *pst_head, struct PersonNode *pst);
struct PersonNode* search_by_id(struct  HeadNode *pst_head, char *id);
int print_all_node(struct HeadNode *pst_head);
void print_option();
int add_person(struct HeadNode * pst_head, char first_name[], char last_name[], char id[], int score);
int is_retake(struct PersonNode *pst);
int calc_gpa(struct PersonNode *pst);
int interactive_window(struct HeadNode *pst_head);
int print_person(struct PersonNode *pst);
int change_node(struct HeadNode *pst_head, struct PersonNode *pst1, struct PersonNode *pst2);
int sort_by_score(struct HeadNode *pst_head);
int print_rank(struct HeadNode *pst_head);
int encode(struct HeadNode *pst_head, int key, char *code);
char int_to_char(int num,int key);
int encode_score(int score, int key);
int analysis(struct HeadNode *pst_head);
int decode(struct HeadNode *pst_head, int key);
int decode_score(int score, int key);
int decode_num(int num, int key);
int main(int argc, char *argv[])
{
    struct HeadNode* head = create_head_node();
    struct PersonNode *pst_s = NULL;
    char id[N] = "";
    init(head);
    scanf("%s", id);
    while(strcmp(id, "0"))
    {
        pst_s = search_by_id(head, id);
        if(pst_s != NULL)
        {
            print_person(pst_s);
        }
        else
        {
            printf("Not Found.\n");
        }

        scanf("%s", id);
    }

    delete_head_node(head);

    return 0;
}
/// 数据初始化
/// \param pst_head 头结点地址
/// \return 初始化成功返回 0 失败返回 1
int init(struct HeadNode *pst_head)
{/*
 * Name_f Name_l stu_id score retake GPA

Jingyu LI 202200000000 85 0 A

Jy LEE 202200100000 89 0 A

Jxxxyx Leeeee 202100100000 100 1 A+

Jingyu11 LI 202200000001 85 0 A

Jingyuuuu LI 202200000900 59 0 F

Jingyuuuu Lous 202100000900 60 1 D

Asss Dccc 202212344321 84 0 B+

Asssd Dccec 202122244321 83 0 B+*/
    char f_name[N] = {0};
    char l_name[N] = {0};
    char id[N] = {0};
    int score = 0;

    add_person(pst_head,"Jingyu", "LI", "202200000000", 85);
    add_person(pst_head,"Jy", "LEE", "202200100000", 89);
    add_person(pst_head,"Jxxxyx", "Leeeee", "202100100000", 100);
    add_person(pst_head,"Jingyu11", "LI", "202200000001", 85);
    add_person(pst_head,"Jingyuuuu", "LI", "202200000900", 59);
    add_person(pst_head,"Jingyuuuu", "Lous", "202100000900", 60);
    add_person(pst_head,"Asss", "Dccc", "202212344321", 84);
    add_person(pst_head,"Asssd", "Dccec", "202122244321", 83);

    return 0;
}
/// 创建头节点
/// \return 成功返回头结点地址 失败返回 NULL
struct HeadNode* create_head_node()
{
    struct HeadNode * pst_new = NULL;
    pst_new = (struct HeadNode*)malloc(sizeof(struct HeadNode));
    if(NULL == pst_new)
    {
        return NULL;
    }
    memset(pst_new, 0, sizeof(struct HeadNode));

    return pst_new;
}
/// 删除头结点
/// \param pst_head 头结点地址
/// \return 成功返回 0 失败返回 -1
int delete_head_node(struct HeadNode *pst_head)
{
    struct PersonNode *pst_node = NULL;
    struct PersonNode *pst_next = NULL;
    if(pst_node == NULL)
    {
        return -1;
    }

    pst_node = pst_head->pst_first;
    while(pst_node != NULL)
    {
        pst_next = pst_node->pst_next;
        delete_node(pst_node);
        pst_node = pst_next;
    }
    free(pst_head);
    pst_head = NULL;
    return 0;
}

/// 创建节点
/// \param pst_data 节点模板地址
/// \return 成功返回节点首地址 失败返回 NULL
struct PersonNode * create_node(struct PersonNode *pst_data)
{
    struct PersonNode *pst_new = NULL;
    pst_new = (struct PersonNode*)malloc(sizeof(struct PersonNode));
    if(NULL == pst_new)
    {
        return NULL;
    }
    if(pst_data == NULL)
    {
        memset(pst_new, 0, sizeof(struct PersonNode));
    }
    else
    {
        memcpy(pst_new, pst_data, sizeof(struct PersonNode));
        pst_new->pst_next = NULL;
    }
    return pst_new;
}

/// free节点
/// \param pst_node 节点地址
/// \return 成功返回 0
int delete_node(struct PersonNode *pst_node)
{
    if(pst_node != NULL)
    {
        free(pst_node);
        pst_node = NULL;
    }
    return 0;
}
/// 在链表末尾添加节点
/// \param pst_head 头节点地址
/// \param new_pst 要添加的节点地址
/// \return 成功 0 失败 -1
int append_person(struct HeadNode *pst_head, struct PersonNode *new_pst)
{
    struct PersonNode *pst_last = NULL;
    if(pst_head == NULL || new_pst == NULL)
    {
        return -1;
    }
    pst_last = pst_head->pst_first;
    while(pst_last != NULL)
    {
        if(pst_last->pst_next == NULL)
        {
            break;
        }
        pst_last = pst_last->pst_next;
    }
    if(pst_last == NULL)
    {
        pst_head->pst_first = new_pst;
    }
    else
    {
        pst_last->pst_next = new_pst;
    }
    new_pst->pst_next = NULL;
    pst_head->len++;
    return 0;
}

/// 从链表中移除节点
/// \param pst_head 头结点地址
/// \param pst 要移除的节点地址
/// \return 成功 0 失败 -1
int remove_person(struct HeadNode *pst_head, struct PersonNode *pst)
{
    struct PersonNode *pst_prev = NULL;
    struct PersonNode *temp = NULL;
    if(pst_head == NULL || pst == NULL)
    {
        return -1;
    }
    temp = pst_head->pst_first;
    if(NULL == temp)
    {
        return -1;
    }
    if(temp == pst)
    {
        pst_head->pst_first = pst->pst_next;
        pst->pst_next = NULL;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->pst_next == pst)
            {
                pst_prev = temp;
                break;
            }
            temp = temp->pst_next;
        }
        if(NULL == pst_prev)
        {
            return -1;
        }
        else
        {
            pst_prev->pst_next = pst->pst_next;
            pst->pst_next = NULL;
        }
    }
    pst_head->len--;
    return 0;
}

/// 通过 id 查询节点
/// \param pst_head 头结点地址
/// \param id 要查询的id
/// \return 成功 -id对应节点地址 失败 -NULL
struct PersonNode* search_by_id(struct  HeadNode *pst_head, char *id)
{
    struct PersonNode *pst_node = NULL;
    if(pst_head == NULL || id == NULL)
    {
        return NULL;
    }
    pst_node = pst_head->pst_first;
    while(pst_node != NULL)
    {
        if(!strcmp(id, pst_node->id))
        {
            break;
        }
        pst_node = pst_node->pst_next;
    }
    return pst_node;
}

/// 打印链表中所有节点的所有信息 调用print_person函数
/// \param pst_head 头结点地址
/// \return 成功 0 失败 -1
int print_all_node(struct HeadNode *pst_head)
{
    struct PersonNode *pst = NULL;
    if(pst_head == NULL)
    {
        return -1;
    }
    pst = pst_head->pst_first;
    while(pst != NULL)
    {
        print_person(pst);
        pst = pst->pst_next;
    }
    return 0;
}

///打印菜单栏
void print_option()
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

/// 在链表尾部添加节点 调用create_node、append_person函数
/// \param pst_head 头节点地址
/// \param first_name 名
/// \param last_name 姓
/// \param id 学号
/// \param score 成绩
/// \return 成功 0 失败 -1
int add_person(struct HeadNode * pst_head, char first_name[], char last_name[], char id[], int score)
{
    struct PersonNode *pst_nwe = NULL;
    struct PersonNode node_data = {{""}};
    if(score < 0 || score > 100 || strlen(id) != 12)
    {
        return -1;
    }
    strcpy(node_data.first_name, first_name);
    strcpy(node_data.last_name,last_name);
    strcpy(node_data.id, id);
    node_data.score = score;
    calc_gpa(&node_data);
    node_data.retake = is_retake(&node_data);
    pst_nwe = create_node(&node_data);
    append_person(pst_head, pst_nwe);
    return 0;
}

/// 计算GPA等级并赋值
/// \param pst 节点地址
/// \return 成功 0 失败 -1
int calc_gpa(struct PersonNode *pst)
{

    if (pst == NULL)
    {
        return -1;
    }
    if(pst->score >= 93)
    {
        strcpy(pst->GPA, "A+");
    }
    else if(pst->score >= 85)
    {
        strcpy(pst->GPA, "A");
    }
    else if(pst->score >= 80)
    {
        strcpy(pst->GPA, "B+");
    }
    else if(pst->score >= 75)
    {
        strcpy(pst->GPA, "B");
    }
    else if(pst->score >= 70)
    {
        strcpy(pst->GPA, "C+");
    }
    else if(pst->score >= 65)
    {
        strcpy(pst->GPA, "C");
    }
    else if(pst->score >= 60)
    {
        strcpy(pst->GPA, "D");
    }
    else
    {
        strcpy(pst->GPA, "F");
    }
    return 0;
}

/// 判断是否重修
/// \param pst 节点地址
/// \return 重修 返回 1 非重修返回 0
int is_retake(struct PersonNode *pst)
{
    char id[N] = {0};
    strcpy(id,pst->id);
    if(id[0] == '2' && id[1] == '0' && id[2] == '2'&& id[3] == '2')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/// 交互式窗口主程序
/// \param pst_head 头节点地址
/// \return 0
int interactive_window(struct HeadNode *pst_head)
{
    char res_encode_p[3*pst_head->len];
    memset(res_encode_p,0,3*pst_head->len);
    int option = 0;
    char f_name[N] = {0};
    char l_name[N] = {0};
    char id[N] = {0};
    int score = 0;
    int key = 0;
    printf("please select option:");
    scanf("%d",&option);
    while(option)
    {
        switch(option)
        {
            case 1 :
                printf("please input student info:\n");
                scanf("%s %s %s %d",f_name, l_name, id, &score);
                int res = add_person(pst_head,f_name, l_name, id, score);
                if(!res)
                {
                    printf("successfully added!\n");
                }
                else
                {
                    printf("fail to add, info invalid!\n");
                }
                break;
            case 2:
                printf("please input id:");
                scanf("%s", id);
                //判断id是否存在
                if(search_by_id(pst_head,id)== NULL)
                {
                    printf("fail to delete, id not exit\n");
                    break;
                }
                //使用remove_person函数移除节点
                remove_person(pst_head,search_by_id(pst_head,id));
                printf("successfully deleted!\n");
                break;
            case 3:
                printf("please input id:");
                scanf("%s", id);
                //判断id是否存在
                if(search_by_id(pst_head,id)== NULL)
                {
                    printf("fail to search, id not exit\n");
                    break;
                }
                print_person(search_by_id(pst_head,id));
                break;
            case 4:
                sort_by_score(pst_head);
                print_rank(pst_head);
                break;
            case 5:

                printf("please input key:");
                scanf("%d", &key);
                encode(pst_head, key, res_encode_p);
                printf("%s\n",res_encode_p);
                break;
            case 6:
                printf("please input key:");
                scanf("%d", &key);
                decode(pst_head,key);
            case 7:
                analysis(pst_head);
                break;
            case 8:
                print_all_node(pst_head);
            default:
                printf("option invalid!\n");
        }
        print_option();
        printf("please select option:");
        scanf("%d", &option);
    }
    return 0;
}
/// 打印节点信息
/// \param pst 节点地址
/// \return 成功 0 失败 -1
int print_person(struct PersonNode *pst)
{
    if(pst == NULL)
    {
        return -1;
    }
    printf("%s ",pst->first_name);
    printf("%s ", pst->last_name);
    printf("%s ", pst->id);
    printf("%d ", pst->score);
    printf("%d ", pst->retake);
    printf("%s\n", pst->GPA);
    return 0;
}
/// 交换两个节点
/// \param pst_head 头结点地址
/// \param pst1 节点1
/// \param pst2 节点2
/// \return 成功 0 失败 -1
int change_node(struct HeadNode *pst_head, struct PersonNode *pst1, struct PersonNode *pst2)
{
    struct PersonNode *pst_temp = NULL;
    struct PersonNode *prev1 = NULL;
    struct PersonNode *prev2 = NULL;
    if(NULL == pst_head || NULL == pst1 || NULL == pst2)
    {
        return -1;
    }

    if(pst_head->pst_first != pst1 && pst_head->pst_first != pst2)
    {
        prev1 = pst_head->pst_first;
        prev2 = pst_head->pst_first;
        while(prev1->pst_next != pst1)
        {
            prev1 = prev1->pst_next;
        }
        while(prev2->pst_next != pst2)
        {
            prev2 = prev2->pst_next;
        }
        prev1->pst_next = pst2;
        prev2->pst_next = pst1;
        pst_temp = pst1->pst_next;
        pst1->pst_next = pst2->pst_next;
        pst2->pst_next = pst_temp;
    }
    else if(pst_head->pst_first == pst1)
    {
        prev2 = pst_head->pst_first;
        while(prev2->pst_next != pst2)
        {
            prev2 = prev2->pst_next;
        }
        pst_head->pst_first = pst2;
        prev2->pst_next = pst1;
        pst_temp = pst1->pst_next;
        pst1->pst_next = pst2->pst_next;
        pst2->pst_next = pst_temp;
    }
    else
    {
        prev1 = pst_head->pst_first;
        while(prev1->pst_next != pst2)
        {
            prev1 = prev1->pst_next;
        }
        pst_head->pst_first = pst1;
        prev1->pst_next = pst2;
        pst_temp = pst1->pst_next;
        pst1->pst_next = pst2->pst_next;
        pst2->pst_next = pst_temp;
    }
    return 0;
}
/// 按score对链表降序排序
/// \param pst_head 头节点地址
/// \return 成功 0 失败 -1
int sort_by_score(struct HeadNode *pst_head)
{
    struct PersonNode *pst = NULL;
//    struct PersonNode *pst_temp = NULL;
    int i = 0;
    int j = 0;
    int n = 1;
    if(pst_head == NULL || pst_head->len < 2)
    {
        return -1;
    }

    for(i = 0; i < pst_head->len - 1; i++)
    {
        pst = pst_head->pst_first;
//        printf("-----------\n");
//        print_person(pst);
//        printf("-----------\n");
        for(j = 0; j < pst_head->len - i; j++)
        {
            if(pst->score < pst->pst_next->score)
            {
                change_node(pst_head, pst,pst->pst_next);
            }
//            print_all_node(pst_head);
//            printf("-----------\n");
//            print_person(pst);
//            printf("-----------\n");
            pst = pst_head->pst_first;
            n += j;
            while(n)
            {
                pst = pst->pst_next;
                n--;
            }

//            printf("-----------\n");
//            print_person(pst);
//            printf("-----------\n");
//            print_all_node(pst_head);
//            printf("-------------------\n\n");
        }
    }
    return 0;

}

/// 对列表顺序输出 节点->score相同则并列排名
/// \param pst_head 头节点地址
/// \return 成功 0 失败 -1
int print_rank(struct HeadNode *pst_head)
{
    struct PersonNode *pst = NULL;
    int rank = 1;
    if(pst_head == NULL || pst_head->len <= 0)
    {
        return -1;
    }
    printf("\n%-10s %-13s %-12s%-5s %-6s %-3s %-4s\n","Name_f", "Name_l", "stu_id", "score","retake", "GPA", "Rank");
    pst = pst_head->pst_first;
    while(pst != NULL)
    {
        printf("%-10s ",pst->first_name);
        printf("%-10s ", pst->last_name);
        printf("%-16s ", pst->id);
        printf("%-5d ", pst->score);
        printf("%-6d ", pst->retake);
        printf("%-3s ", pst->GPA);
        printf("%-4d\n", rank);
        if(pst->pst_next != NULL && pst->score == pst->pst_next->score)
        {
            rank--;
        }
        pst = pst->pst_next;
        rank++;
    }
    printf("total:%d\n\n",pst_head->len);
    return 0;

}
/// 对链表上所有的节点成绩加密
/// \param pst_head 头节点地址
/// \param key 密钥
/// \return 成功 0 失败 -1
int encode(struct HeadNode *pst_head, int key, char *code)
{

    struct PersonNode *pst = NULL;
    int score = 0;
    int i = 0;
    if(pst_head == NULL || pst_head->len == 0)
    {
        return -1;
    }
    pst = pst_head->pst_first;
    while(pst != NULL)
    {
        score = pst->score;
        if(score == 100)
        {
            code[i] = int_to_char(1, key);
            i++;
            code[i] = int_to_char(0, key);
            i++;
            code[i] = int_to_char(0, key);
            i++;
            code[i] = ' ';
            i++;
            pst->score = encode_score(score, key);
        }
        else
        {

            code[i] = int_to_char(score/10, key) ;
            i++;
            code[i] = int_to_char((int)(score%10), key);
            i++;
            code[i] = ' ';
            i++;
            pst->score = encode_score(score, key);
        }
        pst = pst->pst_next;
    }
    code[i] = '\0';

    return 0;
}

/// 对单个数字加密
/// \param num 需要加密的数字
/// \param key 密钥
/// \return 加密后的字符
char int_to_char(int num,int key)
{
    char ch = 0;

    ch = (char)((num + key)%10 + '0') ;

    return ch;
}
/// 对成绩按密钥加密
/// \param score 成绩
/// \param key 密钥
/// \return 加密后的程序
int encode_score(int score, int key)
{
    int res_score = 0;
    if(score == 100)
    {
        res_score = (1 + key)%10 * 100 + (0 + key)%10 * 10 + (0 + key)%10;
    }
    else
    {
        res_score += 10 * ((score / 10 + key) % 10);
        res_score += (score + key) % 10;
    }
    return res_score;
}

/// 对节点gap进行统计并输出
/// \param pst_head 头节点地址
/// \return 成功 0 失败 -1
int analysis(struct HeadNode *pst_head)
{
    struct PersonNode *pst = NULL;
    char gpa[8][3] = {"A+",
                      "A",
                      "B+",
                      "B",
                      "C+",
                      "C",
                      "D",
                      "F"};
    int i = 0;
    int count = 0;
    if(pst_head == NULL || pst_head->len <= 0)
    {
        return -1;
    }
    for(i = 0; i < 8; i++)
    {
        pst = pst_head->pst_first;
        count = 0;
        while(pst != NULL)
        {
            if(!strcmp(pst->GPA,gpa[i]))
            {
                count++;
            }
            pst = pst->pst_next;
        }
        if(count)
        {
            printf("%s: %d\n",gpa[i],count);
        }
    }
    return 0;
}

/// 对所有节点的score按密钥进行解码
/// \param pst_head 头节点地址
/// \param key 密钥
/// \return 成功 0 失败 -1
int decode(struct HeadNode *pst_head, int key)
{
    struct PersonNode *pst = NULL;
    if(pst_head == NULL || pst_head->len <= 0)
    {
        return -1;
    }
    pst = pst_head->pst_first;
    while(pst != NULL)
    {
        pst->score = decode_score(pst->score, key);
        pst = pst->pst_next;
    }
    return 0;
}

/// 对成绩进行解码
/// \param score 成绩
/// \param key 密钥
/// \return 解码后的成绩
int decode_score(int score, int key)
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
/// 对单个数字进行解码
/// \param num 需要解码的数字
/// \param key 密钥
/// \return 解码后的数字
int decode_num(int num, int key)
{
    if(num - key < 0)
    {
        return num - key + 10;
    }

    return num - key;
}