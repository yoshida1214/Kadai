#pragma once


template<typename T>
class Stack
{
private:
	struct InternalData
	{
		T data;
		InternalData* ptr;
	};

public:
	Stack():pPopData(nullptr), DataSize(0){};
	~Stack() {};
	inline void Push(T in) {
		InternalData *NewData = new InternalData();
		NewData->data = in;
		NewData->ptr = nullptr;

		if (pPopData == nullptr) {
			pPopData = NewData;
		}
		else {
			NewData->ptr = pPopData;
			pPopData = NewData;
		}
		DataSize++;
	}

	inline T Pop() {
		T out;
		if (pPopData != nullptr) {
			InternalData* pNewPopData = pPopData->ptr;
			out = pPopData->data;
			delete pPopData;
			pPopData = pNewPopData;
			DataSize--;
			return out;
		}
	}

	inline int GetSize() { return DataSize; }
private:
	InternalData* pPopData;
	int DataSize;
};
