/**
*	@author Thomas Angles
*	@date	02/03/2020
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}
// No variable names changed
template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}
// No variable names changed
template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	for (int i = 1; i <= m_size; i++)
  {
    if (temp->getValue() == value)
    {
      isFound = true;
    }
    temp = temp->getNext();
  }
  return (isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

//Changed the method definition from the given structure
// No longer using bool isRemoved and used newly declared nodes tmp and tail
// added checks for when the size is 0 or 1
// tmp is the looping node that is redeclared into tail when its traversed to the end of the linked LinkedList
// then after that tmp is deleted and tail next pointer is set to null
template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* tmp = m_front;
	Node<T>* tail;

  if (m_size == 0)
  {
    return(false);
  }
	if (m_size == 1) {
		delete m_front;
		m_front = nullptr;
	}else{
		while (tmp -> getNext() != nullptr) {
			tail = tmp;
			tmp = tmp->getNext();
		}
		delete tmp;
		tail->setNext(nullptr);
	}
	m_size--;
  return (true);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
