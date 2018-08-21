#include <exception>
#include<iostream>
#pragma once
template <typename N>
struct Node
{
	Node(const N& idata)
	{
		data = idata;
		next = nullptr;
		prev = nullptr;
	}
	Node() {}
	Node<N>* next;
	Node<N>* prev;
	N data;
};

template <class T>
class Stack
{
public:
	Stack(){
		head = new Node<T>;
		head->next = nullptr;
		head->prev = nullptr;
		m_size = 0;
	}
	void push_back(const T& data) {
		Node<T>* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(data);
		tmp->next->prev = tmp;
		++m_size;
	}
	void pop_back() {
		Node<T>* tmp = head;
		if (head->next == nullptr)
		{
			throw std::runtime_error("The stack is already empty rotfl");
		}
		else {
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}

			tmp->prev->next = nullptr;
			delete(tmp);
		}
	}
	T at(const int& index) const {
		int count = 0;
		Node<T>* tmp = head->next;
		if (tmp == nullptr)
		{
			throw std::runtime_error("The stack is empty");
		}
		while (tmp->next != nullptr && count < index) {
			++count;
			tmp = tmp->next;
		}
		return tmp->data;
		
	}
	int size()
	{
		return m_size;
	}
	void printStack() const
	{
		Node<T>* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
			std::cout << tmp->data<<", ";
		}

	}
	void swap(const int& x, const int & y)
	{
		int count = 0;
		Node<T>* tmp1 = head->next;
		if (tmp1 == nullptr)
		{
			throw std::runtime_error("The stack is empty");
		}
		while (tmp1->next != nullptr && count < x)
		{
			++count;
			tmp1 = tmp1->next;
		}
		int count2 = 0;
		Node<T>* tmp2 = head->next;
		while (tmp2->next != nullptr && count2 < y)
		{
			++count2;
			tmp2 = tmp2->next;
		}
		T temp = tmp1->data;
		tmp1->data = tmp2->data;
		tmp2->data = temp;
		
	}
	void BubbleSortWeird(int numValues, bool isAscending = true)
	{
		int bubbleHere = 0;
		while (bubbleHere < numValues - 1)
		{
			if (!isAscending)
			{
				bubbleDownWeird(bubbleHere, numValues - 1);
			}
			else
			{
				bubbleUpWeird(bubbleHere, numValues - 1);
			}
			++bubbleHere;
		}

	}
	void bubbleDownWeird(int begin, int finish)
	{
		for (int i = finish; i > begin; --i)
			if (at(i - 1) * at(i))
				swap((i - 1), (i));
	}
	void bubbleUpWeird(int begin, int finish)
	{
		for (int i = finish; i> begin; --i)
			if (at(i - 1) * at(i))
				swap((i - 1), (i));
	}
	void BubbleSort( int numValues,bool isAscending=true)
	{
		int bubbleHere = 0;
		while (bubbleHere < numValues - 1)
		{
			if (!isAscending)
			{
				bubbleDown(bubbleHere, numValues - 1);
			}
			else
			{
				bubbleUp(bubbleHere, numValues - 1);
			}
			++bubbleHere;
		}


	}

	void bubbleDown( int begin, int finish)
	{
		for (int i = finish; i > begin; --i)
			if (at(i-1) < at(i))
				swap((i-1), (i));
	}
	void bubbleUp(int begin, int finish)
	{
		for (int i = finish; i> begin; --i)
			if (at(i - 1) > at(i))
				swap((i - 1), (i));
	}
private:
	Node<T>* head;
	Node<T>* tail;
	int m_size;
};