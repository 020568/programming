#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 必须包含，因为用到了 malloc 和 free

#define SLEN 81

// 定义结构体：注意 fname 和 lname 现在是指针，不占结构体内部空间
struct namect
{
    char *fname;   // 存储名字的地址
    char *lname;   // 存储姓氏的地址
    int letters;   // 名字字符总数
};

/* 函数原型声明 */
void getinfo(struct namect *);
void leninfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);
char * s_gets(char *st, int n);

int main()
{
    struct namect person; // 在栈(Stack)上开辟一个结构体变量
    
    getinfo(&person);     // 传入地址，在函数内部分配堆(Heap)内存
    leninfo(&person);     // 计算长度
    showinfo(&person);    // 输出结果
    cleanup(&person);     // 释放内存：这是动态分配的必经步骤，否则会内存泄漏
    
    return 0;
}

void getinfo(struct namect *pst)
{
    char temp[SLEN]; // 临时缓冲区，用来暂存用户输入的字符串
    
    printf("enter your firstname. \n");
    s_gets(temp, SLEN);
    
    // 【核心：动态分配】根据输入字符串的实际长度，去堆(Heap)里申请精准大小的空间
    // strlen(temp)+1 是为了给字符串结束符 '\0' 留个位置
    pst->fname = (char *) malloc(strlen(temp) + 1); 
    
    // 将暂存在 temp 里的内容拷贝到刚刚申请的永久地址里
    strcpy(pst->fname, temp);
    
    printf("enter your lastname. \n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void leninfo(struct namect * pst)
{
    // 利用 string.h 的库函数计算两个动态字符串的长度并累加
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    // const 修饰指针，表示在这个函数里，我们只读，不准修改 pst 指向的内容
    printf("%s %s, your name contains %d letters. \n", 
           pst->fname, pst->lname, pst->letters);	
}

void cleanup(struct namect * pst)
{
    // 【防内存泄漏】手动释放 malloc 申请的空间。
    // 在嵌入式系统里，如果不 free，运行久了内存就会耗尽（死机）
    free(pst->fname);
    free(pst->lname);
}

/* 这是一个比 scanf 和 gets 更安全的字符串输入函数 */
char* s_gets(char *pst, int n)//return a data which is a pointer 
{
    char * ret_val;
    char * find;
    
    // fgets 会读取换行符，且不会溢出
    ret_val = fgets(pst, n, stdin);
    if(ret_val)
    {
        find = strchr(pst, '\n'); // 查找换行符
        if (find)                 // 如果找到了
        {
            *find = '\0';         // 用空字符替换换行符，让字符串提前结束
        }
        else                      // 如果输入太长，清理输入流缓冲区
        {
            while(getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}