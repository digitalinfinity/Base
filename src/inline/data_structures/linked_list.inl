#include <base.h>

#define Iterate(iterator) for (TListIteratorType iterator(this); !iterator.AtEnd();  iterator.MoveNext())

template <typename T>
bool LinkedList<T>::AddToFront(const T& item) throw()
{
	if (this->m_head != null)
	{
		InsertAfter(item, this->m_head);
	}
	else
	{
		ListNode* node = new (std::nothrow) ListNode(item);
		if (node == null)
		{
			return false;
		}

		this->m_head = node;
	}

	return true;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while (this->m_head != null)
	{
		ListNode* node = this->m_head;
		this->m_head = this->m_head->next;

		delete node;
	}
}

template <typename T>
bool LinkedList<T>::RemoveOne(const T& data) throw()
{
	for (ListNode** current = &this->m_head; *current != null; current = &((*current)->next))
	{
		if (Comparer<T>::Equals(data, (*current)->data))
		{
			(*current) = (*current)->next;
			return true;
		}
	}

	return false;
}

template <typename T>
bool LinkedList<T>::Contains(const T& item) throw()
{
	Iterate(iterator)
	{
		if (Comparer<T>::Equals(item, iterator.Current()))
		{
			return true;
		}
	}

	return false;
}

template <typename T>
bool LinkedList<T>::InsertAfter(const T& item, ListNode* node) throw()
{
	Assert(node != null);
	ListNode* newNode = new (std::nothrow) ListNode(item);

	if (newNode == null)
	{
		return false;
	}

	newNode->next = node->next;
	node->next = newNode;

	return true;
}

template <typename T>
size_t LinkedList<T>::Count() throw()
{
	size_t count = 0;
	Iterate(iterator)
	{
		count++;
	}

	return count;
}
