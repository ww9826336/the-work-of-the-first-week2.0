
#include"linklist.h"
Status creat_node(LinkedList* L)
{
    *L = (LinkedList)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        printf("创建失败");
        return error;

    }
    else return success;


}
Status InitList(LinkedList *L) {//创建空链表，头结点不存有有效数据,构成循环
    creat_node( L);
    (*L)->next = *L;

    return success;
}

Status DestroyList(LinkedList L) {//销毁链表
    LinkedList temp=NULL;
    LinkedList head = L;
    if (L == NULL)
    {
        printf("未创建链表无需销毁");
        return error;
    }
    if (L->next == L)
        free(L);
    else
    {
        L = L->next;
        while (L!= head)
        {
            temp = L;
            L = temp->next;
            free(temp);
            
        }
        free(L);
    }
    printf("链表已销毁");
    return success;
}

Status InsertList(LNode* p, ElemType data) {//插入结点，添加数据
    LinkedList cur = p;
    LinkedList newp = (LinkedList)malloc(sizeof(LNode));

    if (newp== NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newp->data = data;
    newp->next = p;//让新的尾结点与头结点相接
    while ((cur->next != NULL)&&(cur->next!=p))
    {
        cur= cur->next;
    }
    cur->next = newp;//将数据存在结尾结点的下一结点使之成为新的尾结点
    return success;
}

Status DeleteList(LNode* p, ElemType e) {
    LinkedList posNode=NULL;
    LinkedList leftposNode=NULL;
    if (p!=NULL)
    {
        posNode = p->next;//将指针定位在第一个有效节点中
        leftposNode = p;//辅助查找的指针
    }
    else 
    {
        printf("链表未被创建，无数据可删除");
        return error;
    }
    if (posNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while (posNode->data != e)
        {
            leftposNode = posNode;
            posNode = posNode->next;
            if (posNode == p)//当遍历到节点回到头结点的时候，说明链表里没有该数据
            {
                printf("没有该数据\n");
                return error;
            }
        }
        leftposNode->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while ((temp != NULL)&&(temp!=L))//遍历到循环点时不再打印数据
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) {
    LinkedList p = L;
    while ((L != NULL)&&(L->next!=p))
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}

/*
void ReverseList(LinkedList L) {
    LinkedList current, next, pre;
    current = L->next;
    pre = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    L->next = pre;
}
*/

Status ReverseList(LinkedList* L) {
    LNode* newHead;  //储存每次反转后的第一个节点 
    LNode* p1;   //每次都指向前一个节点 
    LNode* p2;   // 储存未反转前的下一个节点 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = *L;
    newHead = p1;//用newHead标志p1
    while (p2 != * L) {
        p1 = p2;//将p1移动至p1的下一个结点
        p2 = p1->next;//将p2移动至p2的下一个结点
        p1->next = newHead;//将已经移动到下一个结点的p1的指针域指向事先标记p1的newHead
        newHead = p1;//让newHead 移动到新的p1,重新标记p1
    }
    (*L)->next = newHead;
    return success;
}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while ((fast->next != NULL && slow->next != NULL) && (fast->next != L))//快指针指向的下一个节点不为空或者不是头结点
    {
        fast = fast->next;//进二移一的思想，当快的走到尽头，慢的就走到了中间
        slow = slow->next;
        if ((fast->next!= NULL)&&(fast->next!=L))fast = fast->next;
    }
    return slow;
}
Status xchangelist(LinkedList L,int x) {
    LNode* p = L;//标志要交换的奇偶结点前一个结点
    LNode* p1;
    LNode* p2;
  for(int i=0;i<=(x/2)-1;i++)//x为链表的结点个数
    {
        p1 = p->next;//标志即将调换的奇结点
        p2 = p1->next;//标志即将调换的偶结点
        //下面开始调换
        p->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        p = p1;//将p置于下一个要交换的奇偶结点前一位
    }//循环结束后依然构成循环链表
    return success;
}
Status ringlist(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next->next)
    {
        slow = slow->next;//跑得慢的指针
        fast = fast->next->next;  //跑得快的指针
        if (fast == NULL)return error;
        if (fast == slow)//如果追及相遇成功就是成环
            return success;
    }
    return error;
}

void show(void)//菜单界面
{
    printf("\n\n\n\n单链表ADT\n\n");
    printf("1.创建链表\n");
    printf("2.清空链表\n");
    printf("3.插入结点\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.查找数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.奇偶结点调换\n");
    printf("10.查找中间结点\n");
    printf("11.退出\n");
    printf("\n请输入对应的数字(1-11)：");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf_s("%s", word,9);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else//如果是纯数字则循环终止
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // 将字符重新转换为数字
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;//返回输入的数字
}

int main(void)
{
    int choice, num = 0,size=0;
    LinkedList head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1://创建空链表
        {
            if (InitList(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://清空链表
        {
            DestroyList(head);
            head = NULL;
            size = 0;
            break;
        }
        case 3://插入数据
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
                printf("请输入数据：");
                scanf_s("%d", &num);
                if (InsertList(head, num))
                {
                    printf("数据插入成功\n");
                    size++;
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://删除数据
        {
            printf("你想删除哪个数据：");
            scanf_s("%d", &num);
            if (DeleteList(head, num))
            {
                printf("数据删除成功\n");
                size--;
            }
            else
            {
                printf("数据删除失败\n");
            }
            break;
        }
        case 5://遍历链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表不存在或者只存在一个空的头结点\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        }
        case 6://查找数据
        {
            printf("请输入你要查找的数据：");
            scanf_s("%d", &num);
            if (SearchList(head, num))
            {
                printf("该数存在\n");
            }
            else
            {
                printf("该数不存在\n");
            }
            break;
        }
        case 7://反转链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
            break;
        }
        case 8://判断链表是否成环
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if (ringlist(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        }
        case 9://链表的奇偶结点调换
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表奇偶调换失败\n");
            }
            else
            {
                if (xchangelist(head,size))
                {
                    printf("链表奇偶调换成功\n");
                }
                else
                {
                    printf("链表奇偶调换失败\n");
                }

            }
            break;
        }
        case 10://查找中间结点
        {
            if (head == NULL || head->next == NULL)
            {
                printf("这是空链表\n");
            }
            else
            {
                printf("链表中间储存的值为%d\n", (FindMidNode(head))->data);
            }
            break;
        }
        case 11://销毁链表
        {
            DestroyList(head);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-11)\n");
            break;
        }
        }
    } while (choice != 11);//当输入11时退出菜单

    return 0;
}