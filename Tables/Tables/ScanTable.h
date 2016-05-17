#pragma once

#include "ArrayTable.h"

class TScanTable :public TArrayTable{
public:
	TScanTable(int _MaxSize = 1000) :TArrayTable(_MaxSize){}

	~TScanTable(){}

	int GetMaxSize()
	{
		return MaxSize;
	}
	
	TRecord GetMas(int i){
		if ((i >= 0) && (i < MaxSize)){
			return mas[i];
		}
	}

	virtual bool Find(TKey _key){
		for (int i = 0; i < DataCount; i++){
			if (mas[i].key == _key){
				Curr = i;
				return true;
			}
		}
		Curr = DataCount;
		return false;
	}
	
	virtual void Delete(TKey _key){
		if (Find(_key)){
			DataCount--;
			mas[Curr] = mas[DataCount];
		}
	}
	
	virtual void Findelem(TKey _key){
		for (int i = 0; i < DataCount; i++)
		{
			if (mas[i].key == _key)
			{
				Curr = i;
				break;
			}
		}
		cout << "Индекс слова " << _key << " = " << Curr + 1 << endl;
	}

	virtual void Insert(TRecord rec){
		if (IsFull()) return;
		if (!Find(rec.key))
		{
			mas[Curr] = rec;
			DataCount++;
		}
		else
		{
			mas[Curr].val++;
		}
	}
};