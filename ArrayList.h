
// give credit to 
// ejfrancis on github
// for the dynamic arraylist

#ifndef ARRAYLIST
#define ARRAYLIST

#include <iostream>

//template to allow any numeric data type
template <class T>
class ArrayList
{
private:
	//current and maximum size of the array list
	int m_currentSize, m_maxSize;
	//pointer for array to hold data
	T* m_arrayList;

	//double the maximum size of the internal array
	void doubleMaxSize() {
		//create a temp array containing current m_arrayList
		T* tempOldList = m_arrayList;

		//store the current m_maxSize then double it
		int oldMaxSize = m_maxSize;
		m_maxSize = m_maxSize * 2;

		//create new larger m_arrayList
		m_arrayList = new T[m_maxSize];
		for (int i = 0; i < m_maxSize; i++) {
			//if we're still within the old array's data, copy it over
			if (i < oldMaxSize) {
				m_arrayList[i] = tempOldList[i];
			}
			//if we're past the end of the old array's data, add NULL
			else {
				m_arrayList[i] = NULL;
			}
		}
		delete[] tempOldList;
	}

	//cut the maximum size of the internal array in half
	void halfMaxSize() {
		//if the current data takes up more than half of the internal array, don't allow halving
		if (m_currentSize > (m_maxSize / 2)) {
			return;
		}
		//create a temp array containing current m_arrayList
		T* tempOldList = m_arrayList;

		//store the current m_maxSize then double it
		int oldMaxSize = m_maxSize;
		m_maxSize = m_maxSize / 2;

		//create new smaller m_arrayList
		m_arrayList = new T[m_maxSize];
		for (int i = 0; i < m_maxSize; i++) {
			//if we're still within the old array's data, copy it over
			if (i < oldMaxSize) {
				m_arrayList[i] = tempOldList[i];
			}
			//if we're past the end of the old array's data, add NULL
			else {
				m_arrayList[i] = NULL;
			}
		}
		delete[] tempOldList;
	}

public:
	//constructor
	ArrayList()
	{
		//allocate array of T type at m_maxSize(1)
		/*m_currentSize = 0;
		m_maxSize = 1;*/
		//populate the array with NULL values
		m_arrayList = new T[m_maxSize];
	/*	for (int i = 0; i < m_maxSize; i++)
		{
			m_arrayList[i] = NULL;
		}*/
		m_currentSize = 0;
		m_maxSize = 1;
		
	}
	//copy constructor
	//ArrayList(const ArrayList& p_other) :
	//	m_currentSize(p_other.m_currentSize), m_maxSize(p_other.m_maxSize)
	//{
	//	//create new m_arrayList
	//	m_arrayList = new T[p_other.m_maxSize];

	//	//iterate over other's items and copy
	//	for (int i = 0; i < p_other.m_maxSize; i++) {
	//		m_arrayList[i] = p_other.m_arrayList[i];
	//	}
	//}
	//copy assignment operator
	//ArrayList& ArrayList::operator=(const ArrayList& p_other)
	//{
	//	//create new m_arrayList
	//	m_arrayList = new T[p_other.m_maxSize];

	//	//iterate over other's items and copy
	//	for (int i = 0; i < p_other.m_maxSize; i++) {
	//		m_arrayList[i] = p_other.m_arrayList[i];
	//	}

	//	return *this;
	//}
	////bracket operator for get and set
	//T& operator [](int p_i) {
	//	return m_arrayList[p_i];
	//}

	//destructor
	~ArrayList() {
		delete[] m_arrayList;
	}
	//push a new item to the end of the array list
	//void push(T p_item) {

	//	//check if we've run out of room and we need to reallocate a larger m_arrayList
	//	if (m_currentSize == m_maxSize) 
	//	{
	//		doubleMaxSize();
	//	}
	//	//add item to m_arrayList
	//	m_arrayList[m_currentSize] = p_item;

	//	//increase current size
	//	m_currentSize++;

	//}
	//remove and return last item in array list
	T pop() {
		//get a copy of the last item in the list
		T lastItem = m_arrayList[m_currentSize - 1];

		//remove it from the list
		delete m_arrayList[m_currentSize - 1];

		//reduce m_currentSize by 1
		m_currentSize--;

		//if the data takes up less than half of the maximum size, cut the internal array's size in half
		if (m_currentSize < (m_maxSize / 2)) {
			halfMaxSize();
		}

		//return copied item
		return lastItem;
	}
	//print the contents to console
	void print() {
		if (m_currentSize == 0) {
			std::cout << "empty" << std::endl;
		}
		//iterate over each list item and log it
		for (int i = 0; i < m_currentSize; i++) {
			//print item
			std::cout << m_arrayList[i];
			//add comma after, except for last item
			if (i < m_currentSize - 1) {
				std::cout << ",";
			}
		}

		std::cout << std::endl;
	}
	//return the current size of the data in the array list
	int getSize() {
		return m_currentSize;
	}
	//return bool of whether or not the current data is empty
	bool isEmpty() {
		if (m_currentSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//print inspect data
	void inspect() {
		std::cout << "ArrayList inspect: currentSize=" << m_currentSize << ", maxSize=" << m_maxSize << std::endl;
	}
	// getting an item
	T* get(int);
	// setting an item
	void set(int index, T item);
	// removing an item
	void removeAt(int);
	void removeAll();
	// adding an item at a certain index
	void add(T i);
	void add(T, int);
	bool needtoResize();
	//index of thing
	int indexOf(T item);

	// last indexOf
	int lastIndexOf(T item);

	bool contains(T item);

	int getMaxSize();
};

#endif	//ARRAYLIST_

