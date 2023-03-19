#include"dulinklist.h"
Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));//ͷ��㲻������Ч����
    if (List == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    List->right = NULL;
    List->left = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->right;
        free(temp);
    }
}

Status InsertLeftList_DuL(DuLNode* p, DuLNode* q) {
    if (p->right == NULL)//������Ϊ��ʱ��ֱ������p��q��ʹ��q��Ϊ��һ���ڵ�
    {
        p->right = q;
        q->left = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->right;//temp���δ����ǰ�ĵ�һ���ڵ�
        p->right = q;//���½ڵ㸳����һ���ڵ��λ��
        q->right = temp;//���½ڵ���Ҷ���ԭ�ȵĵ�һ���ڵ�����
        temp->left = q;//�½ڵ����һ���ڵ���������
        q->left = p;
        return success;
    }
}

Status InsertRightList_DuL(DuLNode* p, DuLNode* q) {
    while (p->right != NULL)//ֱ�ӱ������������Ҷ�
    {
        p = p->right;
    }
    p->right = q;//���ڵ�������
    q->left = p;
    return success;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (p->right == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->right, posNodeFront = p;
        //�ҵ�ɾ������λ��
        while (posNode->data != *e)
        {
            posNodeFront = posNode;//˫ָ�뿪ʼ���ƣ�ֱ���ҵ�Ŀ�����ݻ��ߵ����һ���ڵ�
            posNode = posNode->right;
            if (posNode == NULL)//������ͷ
            {
                printf("�����ݲ�����\n");
                return error;
            }
        }
        if (posNode->right != NULL)//���Ŀ��ڵ㲻�����һ���ڵ㣬��Ŀ��ڵ����ڵ����ҽڵ�����
        {
            posNodeFront->right = posNode->right;
            posNode->right->left = posNodeFront;
        }
        else//���Ŀ��ڵ������һ���ڵ㣬ֱ�ӶϿ�����
        {
            posNodeFront-> right= NULL;
        }
        free(posNode);
        return success;
    }
}
Status Reverselist_DuL(DuLinkedList L) {
    DuLinkedList p1=L->right;
    DuLinkedList left = NULL;
    DuLinkedList right = NULL;
    while (p1 != NULL)//ÿ��ֻ�ı�һ���ڵ�����ָ���ָ��ѭ����󼴿��÷���ı�Ӷ���ת
    {
        right = p1->right;//�����һ���ڵ�
        p1->right = left;//�õ�ǰ���ڽڵ����ָ��ָ����ڵ�
        p1->left = right;//�õ�ǰ���ڽڵ����ָ��ָ���ҽڵ�
        left = p1;//ָ��ѭ�������ƶ�
        p1 = right;//�õ�ǰ�ڵ�λ�������ƶ��Ӷ�ʵ��ÿ���ڵ������ָ�����
    }
    L->right = left;//����ת��Ӧ����ͷ��㣨�����ڵ㣩���Ҷ�ָ�����һ���ڵ�
    return success;
}

void TraverseList_DuL(DuLinkedList L) {
    if (L == NULL)
    {
        printf("δ���������봴������\n");
    }
    else if (L->right == NULL)
    {
        printf("��ǰ����Ϊ��\n");
    }
    else
    {
        DuLinkedList temp = L->right;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
        }
        printf("\n");
    }
}

void show(void)
{
    printf("\n\n\n\n˫����ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.ͷ�巨��������\n");
    printf("4.β�巨��������\n");
    printf("5.ɾ������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�˳�\n");
    printf("\n�������Ӧ������(1-8)��");
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
        for (m = 0; m < len; m++)//���Ԫ�ؼ��
        {
            if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;//�������Ԫ�ض������֣�������һ���ж������Ƿ�Ϸ�
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
    return num;
}

int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1://����������
        {
            if (InitList_DuL(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://��������
        {
            DestroyList_DuL(&head);
            printf("�������ٳɹ�\n");
            break;
        }
        case 3://��巨��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;//�����½ڵ�
                if (InitList_DuL(&newNode))//�����½ڵ�����
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    if (InsertLeftList_DuL(head, newNode))//��ʼ��������
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://�Ҳ巨��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else//ͬ��
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    if (InsertRightList_DuL(head, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 5://ɾ������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                printf("��Ҫɾ��������Ϊ��");
                scanf_s("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("����ɾ���ɹ�\n");
                }
                else
                {
                    printf("����ɾ��ʧ��\n");
                }
            }
            break;
        }
        case 6://��������
        {
            TraverseList_DuL(head);
            break;
        }
        case 7://��ת����
        {
            if (head == NULL || head->right == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (Reverselist_DuL(head))
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
        case 8://�˳����� 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("��������������!(1-8)\n");
            break;
        }
        }
    } while (choice != 8);//������7��ʱ��ѭ���������˳�

    return 0;
}