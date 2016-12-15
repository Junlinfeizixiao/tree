#include<iostream>
#include <cmath>
using namespace std;
typedef char Elemtype;
typedef struct _BTtree
{
	Elemtype data;
	struct _BTtree *lchild;
	struct _BTtree *rchild;
}BtNode,*BTtree;
BtNode* _BuyNODE()
{
	BtNode *s=(BtNode *)malloc(sizeof(BtNode));
	if (NULL==s)
	{
		exit(1);
	}
	memset(s,0,sizeof(BtNode));
	return s;
}
BtNode* CreateTree()
{
	Elemtype x;
	cin>>x;
	BtNode *s=NULL;
	if (x!='#')
	{	
		s=_BuyNODE();
		s->data = x;
		s->lchild = CreateTree();
		s->rchild = CreateTree();
	}
	return s;
}
void PreOrderTraverse(BTtree T)
{
	
	if (T!=NULL)
	{
		cout<<T->data<<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BTtree T)
{

	if (T!=NULL)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data<<" ";
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BTtree T)
{

	if (T!=NULL)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<" ";
	}
}
//int LSizeex(BtNode *ptr)
//{
//	int ltreesize=0;
//	if (ptr==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		ltreesize=LSizeex(ptr->lchild)+1;
//		return ltreesize;
//	}
//}
//int RSizeex(BtNode *ptr)
//{
//	int Rtreesize=0;
//	if (ptr==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		Rtreesize=RSizeex(ptr->lchild)+1;
//		return Rtreesize;
//	}
//}
//int Size(BtNode *ptr)
//{
//	if (ptr!=NULL)
//	{
//		return LSizeex(ptr)+RSizeex(ptr);	
//	}
//	else
//	{
//		return 0;
//	}
//}
int Sizeex(BtNode *ptr)
{
	int Ltreesize=0;
	int Rtreesize=0;
	if (ptr==NULL)
	{
		return 0;
	}
	else
	{
		Ltreesize=Sizeex(ptr->lchild)+1;
		Rtreesize=Sizeex(ptr->rchild)+1;
		return Rtreesize+Ltreesize;
	}
}
int Size(BtNode *ptr)
{
	if (ptr!=NULL)
	{
		return Sizeex(ptr)/2;	
	}
	else
	{
		return 0;
	}
}
int Depth(BtNode *ptr)
{
	int Ldepth=0;
	int Rdepth=0;
	if (ptr==NULL)
	{
		return 0;
	}
	else
	{
		Ldepth=Depth(ptr->lchild)+1;
		Rdepth=Depth(ptr->rchild)+1;
		return Rdepth>Ldepth?Rdepth:Ldepth;
	}
}
//bool FindValue(BtNode *ptr,Elemtype x)
//{
//
//	if (ptr!=NULL)
//	{	
//		if (ptr->data==x)
//		{
//			return true;
//		}
//		FindValue(ptr->lchild,x);
//		FindValue(ptr->rchild,x);	
//	}
//	return false;	
//}
bool Is_Full_BinarTree(BtNode *ptr)
{
	int len=Size(ptr);
	int dep=Depth(ptr);
	int num=pow((double)(2),dep)-1;
	if (len==num)
	{
		return true;
	}
	return false;
}
int main()
{
	BTtree root=NULL;
	root=	CreateTree();
	PreOrderTraverse(root);
	cout<<endl;
	InOrderTraverse(root);
	cout<<endl;
	PostOrderTraverse(root);
	cout<<endl;
	cout<<"Size:"<<Size(root)<<endl;
	cout<<endl;
	cout<<"DEpth:"<<Depth(root)<<endl;
	cout<<endl;
	//Elemtype e='A';
	//cout<<"Find "<<e<<"?"<<FindValue(root,e)<<endl;
	cout<<endl;
	cout<<"FullTree?:"<<Is_Full_BinarTree(root);
	return 0;
}