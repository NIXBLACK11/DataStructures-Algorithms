#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int info;
    struct tree* left;
    struct tree* right;
}tree_type;

tree_type* create(int n)
{
    tree_type *p;
    p = (tree_type*)malloc(sizeof(tree_type));
    p->info = n;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(tree_type **rt,tree_type *temp)
{
    if(*rt==NULL)
    {
        *rt = temp;
    }
    else
    {
        if((temp->info)<((*rt)->info))
        {
            insert(&((*rt)->left),temp);
        }
        else if((temp->info)>((*rt)->info))
        {
            insert(&((*rt)->right),temp);
        }
    }
}

void insertG(tree_type **rt, int num)
{
    if(*rt == NULL)
    {
        *rt = (tree_type*)malloc(sizeof(tree_type));
        if(*rt != NULL)
        {
            (*rt)->info = num;
            (*rt)->left = NULL;
            (*rt)->right = NULL;
        }
    }
    else if(num<(*rt)->info)
    {
        insertG(&(*rt)->left,num);
    }
    else
    {
        insertG(&(*rt)->right,num);
    }
}

void preorder(tree_type *root)
{
    if(root!=NULL)
    {
        printf("%d,",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

if(*rt == NULL)
    {
        *rt = (tree_type*)malloc(sizeof(tree_type));
        if(*rt != NULL)
        {
            (*rt)->info = num;
            (*rt)->left = NULL;
            (*rt)->right = NULL;
        }
    }if(*rt == NULL)
    {
        *rt = (tree_type*)malloc(sizeof(tree_type));
        if(*rt != NULL)
        {
            (*rt)->info = num;
            (*rt)->left = NULL;
            (*rt)->right = NULL;
        }
    }

void postorder(tree_type *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->info);
    }
}

void printEven(tree_type *root)
{
    if(root!=NULL)
    {
        printEven(root->left);
        if(root->info % 2 == 0)
        {
            printf("%d,",(root->info));
        }
        printEven(root->right);
    }
}

int countNodes(tree_type *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void countNodesR(tree_type *root,int c)
{
    if(root != NULL)
    {
        countNodesR(root->left,++c);
        printf("%d, ",++c);
        countNodesR(root->right,++c);
    }
}

int countLeafNodes(tree_type *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int countOneChild(tree_type *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        return 1;
    }
    else
    {
        return countOneChild(root->left) + countOneChild(root->right);
    }
}

tree_type* minValueNode(tree_type* node)
{
    tree_type *current = node;
    while(current && current->left)
        current = current->left;
    return current;
}

tree_type* deleteNode(tree_type *root, int key)
{
    if(root==NULL)
        return root;

    if(key > root->info)
        root->right = deleteNode(root->right, key);
    
    else if(key < root->info)
        root->left = deleteNode(root->left, key);

    else
    {
        if(root->right==NULL)
        {
            tree_type *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            tree_type *temp = root->right;
            free(root);
            return temp;
        }

        tree_type *temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

void findNode(tree_type *root, int value)
{
    if(root!=NULL)
    {
        findNode(root->left, value);
        if(root->info == value)
        {
            printf("%d found", value);
            return;
        }
        findNode(root->right, value);
    }
}

int Height(tree_type* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else 
    {
        int lDepth = Height(head->left);
        int rDepth = Height(head->right);
        if (lDepth > rDepth)
        {
            return (lDepth + 1);
        }
        else
        {
            return (rDepth + 1);
        }
    }
}

int countRight(tree_type *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + countRight(root->left) + countRight(root->right);
}

void printlevel(tree_type *root, int l)
{
    if(root == NULL)
    {
        return;
    }
    if(l==1)
    {
        printf("%d ,",root->info);
    }
    else if(l>1)
    {
        printlevel(root->left, l-1);
        printlevel(root->right, l-1);
    }
}

void printlevelorder(tree_type *root)
{
    int h = Height(root);
    for(int i=1;i<=h;i++)
    {
        printlevel(root, i);
    }
}

tree_type *greaterThanK(tree_type *root, int k)
{
    if(root!=NULL)
    {
        greaterThanK(root->left, k);
        if(root->info == k)
        {
            if(root->right != NULL)
            {
                return root->right;
            }
            else
            {
                return NULL;
            }        
        }
        greaterThanK(root->right, k);
    }
}

void printSmallest(tree_type *root)
{
    tree_type *current = root;
    while(current != NULL && current->left != NULL)
    {
        current  = current->left;
    }
    printf("\nThe answer is:%d", current->info);
}

int minValue(tree_type *root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    int leftMax = minValue(root->left);
    int rightMax = minValue(root->right);
    int value = 0;
    if(leftMax>rightMax)
    {
        value = leftMax;
    }
    else
    {
        value = rightMax;
    }
    if(value > root->info)
    {
        value = root->info;
    }
    return value;
}

int maxValue(tree_type *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);
    int value = 0;
    if(leftMin<rightMin)
    {
        value = leftMin;
    }
    else
    {
        value = rightMin;
    }
    if(value < root->info)
    {
        value = root->info;
    }
    return value;
}

int isBST(tree_type *root)
{
    if(root == NULL)
    {
        return 1;
    }
    else if((root->left != NULL) && (maxValue(root->left) > root->info))
    {
        return 0;
    }
    else if((root->right != NULL) && (minValue(root->right) < root->info))
    {
        return 0;
    }
    else if(!isBST(root->left) || !isBST(root->right))
    {
        return 0;
    }
    return 1;
}

void printLeftView(tree_type *root, int level, int *maxLevel)
{
    if(root == NULL)
    {
        return;
    }
    if(*maxLevel<level)
    {
        printf("\n%d",root->info);
        *maxLevel = level;
    }
    printLeftView(root->left, level+1, maxLevel);
    printLeftView(root->right, level+1, maxLevel);
}

void leftView(tree_type *root)
{
    int maxLevel = 0;
    printLeftView(root, 1, &maxLevel);
}

int main()
{
    int num;
    tree_type*root = NULL, *temp;
    int opt = 0;
    int count = 0;
    do{
        printf("\n1 for insert\n2 for preorder\n3 for inorder\n4 for postorder\n5 for number of nodes\n6 for number of leaf nodes\n7 for number of nodes with one child\n8 for count nodes without return\n9 for delete element\n10 for even\n11 for find node\n12 for exit.");
        printf("\nEnter the option : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 0:
                printf("\nEnter the element:");
                scanf("%d",&num);
                insertG(&root,num);
                break;
            case 1:
                printf("\nEnter the element:");
                scanf("%d",&num);
                temp = create(num);
                insert(&root,temp);
                break;
            case 2:
                printf("preorder:");
                preorder(root);
                break;
            case 3:
                printf("inorder:");
                inorder(root);
                break;
            case 4:
                printf("postorder:");
                postorder(root);
                break;
            case 5:
                count = countNodes(root);
                printf("\nNumber of nodes:%d",count);
                break;
            case 6:
                count = countLeafNodes(root);
                printf("\nNumber of leaf nodes:%d",count);
                break;
            case 7:
                count = countOneChild(root);
                printf("\nNumber of nodes with one child:%d",count);
                break;
            case 8:
                countNodesR(root,0);
                break;
            case 9:
                printf("\nEnter the value to be deleted:");
                scanf("%d",&count);
                root = deleteNode(root, count);
                break;
            case 10:
                printEven(root);
                break;
            case 11:
                printf("\nInput number to find:");
                scanf("%d",&count);
                findNode(root, count);
                break;
            case 12:
                count = Height(root);
                printf("\nHeight is:%d", count);
                break;
            case 13:
                count = countRight(root->right);
                if(root->right == NULL)
                {
                    printf("sdsd");
                }
                printf("Number of nodes to right:", count);
                break;
            case 14:
                printlevelorder(root);
                break;
            case 15:
                printf("\nEnter the element k:");
                scanf("%d",&count);
                temp = greaterThanK(root, count);
                if(temp == NULL)
                {
                    printf("No such element!");
                }
                else
                {
                    printf("%d",temp->info);
                    printSmallest(temp);
                }
                break;
            case 16:
                if(isBST(root))
                {
                    printf("Valid BST");
                }
                else
                {
                    printf("Invalid BST");
                }
                break;
            case 17:
                leftView(root);
                break;
            case 18:
                printf("\nexit!");
                exit(0);
                break;
            default:
                printf("\nwrong input!");
                break;
        }   
    }while(1);
}