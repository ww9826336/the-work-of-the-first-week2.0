
#include"linklist.h"
Status creat_node(LinkedList* L)
{
    *L = (LinkedList)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        printf("����ʧ��");
        return error;

    }
    else return success;


}
Status InitList(LinkedList *L) {//����������ͷ��㲻������Ч����,����ѭ��
    creat_node( L);
    (*L)->next = *L;

    return success;
}

Status DestroyList(LinkedList L) {//��������
    LinkedList temp=NULL;
    LinkedList head = L;
    if (L == NULL)
    {
        printf("δ����������������");
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
    printf("����������");
    return success;
}

Status InsertList(LNode* p, ElemType data) {//�����㣬�������
    LinkedList cur = p;
    LinkedList newp = (LinkedList)malloc(sizeof(LNode));

    if (newp== NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    newp->data = data;
    newp->next = p;//���µ�β�����ͷ������
    while ((cur->next != NULL)&&(cur->next!=p))
    {
        cur= cur->next;
    }
    cur->next = newp;//�����ݴ��ڽ�β������һ���ʹ֮��Ϊ�µ�β���
    return success;
}

Status DeleteList(LNode* p, ElemType e) {
    LinkedList posNode=NULL;
    LinkedList leftposNode=NULL;
    if (p!=NULL)
    {
        posNode = p->next;//��ָ�붨λ�ڵ�һ����Ч�ڵ���
        leftposNode = p;//�������ҵ�ָ��
    }
    else 
    {
        printf("����δ�������������ݿ�ɾ��");
        return error;
    }
    if (posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else
    {
        while (posNode->data != e)
        {
            leftposNode = posNode;
            posNode = posNode->next;
            if (posNode == p)//���������ڵ�ص�ͷ����ʱ��˵��������û�и�����
            {
                printf("û�и�����\n");
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
    while ((temp != NULL)&&(temp!=L))//������ѭ����ʱ���ٴ�ӡ����
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
    LNode* newHead;  //����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode* p1;   //ÿ�ζ�ָ��ǰһ���ڵ� 
    LNode* p2;   // ����δ��תǰ����һ���ڵ� 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = *L;
    newHead = p1;//��newHead��־p1
    while (p2 != * L) {
        p1 = p2;//��p1�ƶ���p1����һ�����
        p2 = p1->next;//��p2�ƶ���p2����һ�����
        p1->next = newHead;//���Ѿ��ƶ�����һ������p1��ָ����ָ�����ȱ��p1��newHead
        newHead = p1;//��newHead �ƶ����µ�p1,���±��p1
    }
    (*L)->next = newHead;
    return success;
}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while ((fast->next != NULL && slow->next != NULL) && (fast->next != L))//��ָ��ָ�����һ���ڵ㲻Ϊ�ջ��߲���ͷ���
    {
        fast = fast->next;//������һ��˼�룬������ߵ���ͷ�����ľ��ߵ����м�
        slow = slow->next;
        if ((fast->next!= NULL)&&(fast->next!=L))fast = fast->next;
    }
    return slow;
}
Status xchangelist(LinkedList L,int x) {
    LNode* p = L;//��־Ҫ��������ż���ǰһ�����
    LNode* p1;
    LNode* p2;
  for(int i=0;i<=(x/2)-1;i++)//xΪ����Ľ�����
    {
        p1 = p->next;//��־��������������
        p2 = p1->next;//��־����������ż���
        //���濪ʼ����
        p->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        p = p1;//��p������һ��Ҫ��������ż���ǰһλ
    }//ѭ����������Ȼ����ѭ������
    return success;
}
Status ringlist(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next->next)
    {
        slow = slow->next;//�ܵ�����ָ��
        fast = fast->next->next;  //�ܵÿ��ָ��
        if (fast == NULL)return error;
        if (fast == slow)//���׷�������ɹ����ǳɻ�
            return success;
    }
    return error;
}

void show(void)//�˵�����
{
    printf("\n\n\n\n������ADT\n\n");
    printf("1.��������\n");
    printf("2.�������\n");
    printf("3.������\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��ż������\n");
    printf("10.�����м���\n");
    printf("11.�˳�\n");
    printf("\n�������Ӧ������(1-11)��");
}

int judge_int(void)  //��ֹ�û��������������ַ�
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
            if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else//����Ǵ�������ѭ����ֹ
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;//�������������
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
        case 1://����������
        {
            if (InitList(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://�������
        {
            DestroyList(head);
            head = NULL;
            size = 0;
            break;
        }
        case 3://��������
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
                printf("���������ݣ�");
                scanf_s("%d", &num);
                if (InsertList(head, num))
                {
                    printf("���ݲ���ɹ�\n");
                    size++;
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://ɾ������
        {
            printf("����ɾ���ĸ����ݣ�");
            scanf_s("%d", &num);
            if (DeleteList(head, num))
            {
                printf("����ɾ���ɹ�\n");
                size--;
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        }
        case 5://��������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        }
        case 6://��������
        {
            printf("��������Ҫ���ҵ����ݣ�");
            scanf_s("%d", &num);
            if (SearchList(head, num))
            {
                printf("��������\n");
            }
            else
            {
                printf("����������\n");
            }
            break;
        }
        case 7://��ת����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("����ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }

            }
            break;
        }
        case 8://�ж������Ƿ�ɻ�
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (ringlist(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("����û�гɻ�\n");
                }
            }
            break;
        }
        case 9://�������ż������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("������ż����ʧ��\n");
            }
            else
            {
                if (xchangelist(head,size))
                {
                    printf("������ż�����ɹ�\n");
                }
                else
                {
                    printf("������ż����ʧ��\n");
                }

            }
            break;
        }
        case 10://�����м���
        {
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {
                printf("�����м䴢���ֵΪ%d\n", (FindMidNode(head))->data);
            }
            break;
        }
        case 11://��������
        {
            DestroyList(head);
            break;
        }
        default:
        {
            printf("�������������֣�(1-11)\n");
            break;
        }
        }
    } while (choice != 11);//������11ʱ�˳��˵�

    return 0;
}