#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
class Breadthfs
{
public:
    Node* insert(Node *,int);
    void bfs(Node *);
};
Node *insert(Node *root,int data)
{
    if(!root)
    {
        return new Node(data);
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=new Node(data);
            return root;

        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right==NULL)
        {
            temp->right=new Node(data);
            return root;

        }
        else
        {
            q.push(temp->right);
        }
    }
}
void bfs(Node *head)
{
    queue<Node *>q;
    q.push(head);
    int qSize;
    while(!q.empty())
    {
        qSize=q.size();
        #pragma omp parallel for
        for(int i=0;i<qSize;i++)
        {

            Node *currNode;
            #pragma omp critical
            {
                currNode=q.front();
                q.pop();
                cout<<"\t"<<currNode->data;
            }
            #pragma omp critical
            {
                if(currNode->left)
                {
                    q.push(currNode->left);
                }
                if(currNode->right)
                {
                    q.push(currNode->right);
                }
            }
        }
    }
}

int main()
{
    Node *root=NULL;
    int data;
    char ans;

    do
    {
        cout<<"\n enter data :";
        cin>>data;
        root=insert(root,data);
        cout<<"do you want to insert more node ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    bfs(root);

    return 0;

}
