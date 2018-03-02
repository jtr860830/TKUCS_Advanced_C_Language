#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define num2alpha(num) (num - 1 + 'a')

char strBuf[128];
char target[128];

typedef struct index_node
{
    int access_counter;
    int sum_for_table;
    struct index_node *next_index_table[27];
} iNode;

iNode *newNode(void)
{
    int i;
    iNode *temp = (iNode *)malloc(sizeof(iNode));
    temp->access_counter = 0;
    temp->sum_for_table = 0;
    for (i = 0; i < 27; i++)
    {
        temp->next_index_table[i] = NULL;
    }

    return temp;
}

int indexer(char c)
{
    int a = c;
    if (a < 97 || a > 122)
        return 0;
    else
        return a - 96;
}

iNode *seek_to(char *str, iNode *tree_root)
{
    int index;
    if (str[0] == '\0')
        return tree_root;

    index = indexer(tolower(str[0]));

    if (index && tree_root->next_index_table[index])
        return seek_to(str + 1, tree_root->next_index_table[index]);
    else
        return NULL;
}

void readInTree(FILE *pfile, iNode *main_root)
{
    /*read char and create tree*/
    char c;
    iNode *temp = main_root;

    do
    {
        c = fgetc(pfile);
        if(temp->next_index_table[indexer(tolower(c))] == NULL)
            temp->next_index_table[indexer(tolower(c))] = newNode();
        temp->next_index_table[indexer(tolower(c))]->sum_for_table += 1;
        temp = temp->next_index_table[indexer(tolower(c))];

        if(c == ' ') temp = main_root;

    } while (c != EOF);
}

void dfs_printAll(iNode *tree_root, int level)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        if (tree_root->next_index_table[i])
        {
            if (i)
            {
                strBuf[level] = num2alpha(i);
                dfs_printAll(tree_root->next_index_table[i], level + 1);
            }
            else
            {
                strBuf[level] = '\0';
                printf("            %s *%d\n", strBuf, tree_root->next_index_table[0]->access_counter);
            }
        }
    }
}

int printSubWord(char *str, iNode *tree_root)
{
    iNode *target = seek_to(str, tree_root);
    if (target)
    {
        strcpy(strBuf, str);
        dfs_printAll(target, strlen(str));
    }
    else
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./in.txt", "r");
    iNode *main_root = newNode();
    iNode *target_node = NULL;
    readInTree(fp, main_root);
    printf("Total Word : %d\n", main_root->sum_for_table);


    while (1)
    {
        printf("\n    Enter word or prefix to get more info :");
        scanf("%s", target);
        target_node = seek_to(target, main_root);
        if (target_node)
        {
            printf("        Has %d Word for prefix \"%s\"\n\n", target_node->sum_for_table, target);
            printSubWord(target, main_root);
        }
        else
            puts("        No word or prefix in that");
    }
    return 0;
}
