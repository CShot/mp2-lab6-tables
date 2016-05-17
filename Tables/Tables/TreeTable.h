#pragma once

#include "Table.h"
#include "Stack.h"

class Node{
public:
	Node *pLeft, *pRight; 
	TRecord rec; 
	int balanse; 

	Node(TRecord _rec){
		pLeft = NULL;
		pRight = NULL;
		rec = _rec;
		balanse = 0;
	}
};



class TTreeTable :public TTable{
protected:
	Node* pRoot; // указатель на корень
	Node* pCurr; // указатель на текущее звено
	Node **pRes; // адрес указателя для вставки и удаления
	Stack <Node*> st; // стэк указателей на звенья
	int CurrPos; // позиция для итератора 
public:
	
	TTreeTable()
	{
		pRoot = NULL;
		pCurr = NULL;
		st.clear();
	}
	
	~TTreeTable(){
		DelSTree(pRoot);
	}
	
	void DelSTree(Node *p)
	{
		if (p != NULL)
		{
			DelSTree(p->pLeft);
			DelSTree(p->pRight);
			delete p;
		}
		return;
	}
	
	virtual TRecord GetCurr() const
	{
		return (pCurr->rec);
	}

	virtual bool IsFull() const
	{
		return false;
	}

	
	virtual bool  Find(TKey _key)
	{
		Node *tmp = pRoot;
		pRes = &pRoot;
		while (tmp != NULL)
		{
			if ((tmp->rec.key) == _key)
				return true;
			else{
				if ((tmp->rec.key) < _key){
					pRes = &(tmp->pLeft);
					tmp = (tmp->pLeft);
				}
				else{
					pRes = &(tmp->pRight);
					tmp = (tmp->pRight);
				}
			}
		}
		return false;
	}

	virtual void Insert(TRecord rec)
	{
		if (!Find(rec.key)){
			DataCount++;
			Node *tmp = new Node(rec);
			*pRes = tmp;
		}
		else{
			(*pRes)->rec.val++;
		}
	}
	
	virtual void Delete(TKey Key)
	{
		if (!Find(Key))
			return;
		else
		{
			Node* pNode = *pRes;
			Node* tmp = *pRes;
			Node* pMax = *pRes;
			if (tmp->pLeft == NULL)
			{
				*pRes = tmp->pRight;
				delete tmp;
				return;
			}
			else
				if (tmp->pRight == NULL)
				{
					*pRes = tmp->pLeft;
					delete tmp;
					return;
				}
				else
				{
					pMax = pMax->pLeft;
					if (pMax->pRight == NULL)
						pNode = pMax->pLeft;
					else
					{
						while (pMax->pRight != NULL)
						{
							tmp = pMax;
							pMax = pMax->pRight;
						}
						pNode->rec = pMax->rec;
						tmp->pRight = pMax->pLeft;
					}
				}
			delete pMax;
			DataCount--;
		}
	}

	
	virtual void Reset(){
		pCurr = pRoot;
		st.clear();
		CurrPos = 0;
		do{
			st.push(pCurr);
			pCurr = (pCurr->pLeft);
		} while (pCurr != NULL);
		pCurr = st.top();
	}
	
	virtual bool IsEnd(){
		return (CurrPos == DataCount);
	}
	
	virtual void GoNext(){
		st.pop();
		pCurr = (pCurr->pRight);
		while (pCurr != NULL){
			st.push(pCurr);
			pCurr = (pCurr->pLeft);
		}
		if (!st.empty()){
			pCurr = st.top();
		}
		CurrPos++;
	}

	void PrintTreeTable(Node *p, int lvl){
		if (p != NULL){
			PrintTreeTable((p->pRight), (lvl + 1));
			for (int i = 0; i < (2 * lvl); i++){
				cout << "";
			}
			cout << p->rec.key << " - " << p->rec.val << endl;
			PrintTreeTable((p->pLeft), (lvl + 1));
		}
	}

	void PrintTree(){
		PrintTreeTable(this->pRoot, 0);
	}
};