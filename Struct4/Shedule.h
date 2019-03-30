#include<iostream>

using namespace std;
template<typename T>
class Shedule
{
public:
	Shedule();
	void push_back(T data);
	int GetLength() { return Length; }
	T& operator[](const int index);
	~Shedule();

private:
	template<typename T>
	class Node
	{
	public:
		Node *ptrNext;
		T data;
		Node(T data = T(), Node *ptrNext = nullptr)
		{
			this->data = data;
			this->ptrNext = ptrNext;
		}
	};

	int Length;
	Node<T> *head;
};

template<typename T>
Shedule<T>::Shedule()
{
	Length = 0;
	head = nullptr;
}
template<typename T>
T & Shedule<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->ptrNext;
		counter++;
	}
}

template<typename T>
Shedule<T>::~Shedule()
{

}

template<typename T>
void Shedule<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->ptrNext != nullptr)
		{
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}
	Length++;
}

