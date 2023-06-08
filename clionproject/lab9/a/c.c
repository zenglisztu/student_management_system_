//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 80
//
//int offset(char str_[], int ofs);
//char move_ch(char ch, int ofs);
//char change(char ch, int ofs);
//int is_letter(char ch);
//int is_out(char ch, int ofs);
//int main(int argc, char *argv[])
//{
//    char str[N] = {0};
//    int ofs = 0;
//    gets(str);
//    scanf("%d", &ofs);
//
//    offset(str,ofs);
//    printf(str);
//    system("pause");
//    return 0;
//}
//
//int offset(char str_[], int ofs)
//{
//    int i = 0;
//    if(str_ == NULL)
//    {
//        return -1;
//    }
//    if(ofs > 26)
//    {
//        ofs %= 26;
//    }
//    for(i = 0; i < strlen(str_); i++)
//    {
//        if(is_letter(str_[i]))
//        {
//            if(is_out(str_[i], ofs))
//            {
//                str_[i] = move_ch(str_[i], ofs);
//            }
//            else
//            {
//                str_[i] = change(str_[i], ofs);
//            }
//
//        }
//
//    }
//
//    return 1;
//}
//
//char move_ch(char ch, int ofs)
//{
//    return (char)(ch + ofs);
//}
//
//int is_letter(char ch)
//{
//    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
//        return 1;
//    }
//
//    return 0;
//}
//
//char change(char ch, int ofs)
//{
//    char res = 0;
//    if(ch >= 'a' && ch <= 'z' && ch + ofs > 'z')
//    {
//        res = (char)(ch + ofs - 'z' + ('a'-1));
//    }
//    else if(ch >= 'a' && ch <= 'z' && ch + ofs < 'a')
//    {
//        res = (char)(('z'+1) - ('a' - (ch + ofs)));
//    }
//    else if(ch >= 'A' && ch <= 'Z' && ch + ofs < 'A')
//    {
//        res = (char)(('Z'+1) - ('A' - (ch + ofs)));
//    }
//    else if(ch >= 'A' && ch <= 'Z' && ch + ofs > 'Z')
//    {
//        res = (char)(ch + ofs - 'Z' + ('A'-1));
//    }
//    return res;
//}
//
//int is_out(char ch, int ofs)
//{
//    int res = 1;
//    if(ch >= 'a' && ch <= 'z' && (ch + ofs > 'z' ||ch + ofs < 'a'))
//    {
//        res = 0;
//    }
//    else if(ch >= 'A' && ch <= 'Z' && (ch + ofs > 'Z' ||ch + ofs < 'A'))
//    {
//        res = 0;
//    }
//
//    return res;
//
//}