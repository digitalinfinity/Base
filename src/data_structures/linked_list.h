#pragma once

#include "base.h"

#ifndef BASE_VERSION
#error Must include Base.h
#endif

/// Type forward declarations
template <typename T>
class LinkedList;

template <typename TListType>
class Iterator;

/// 
/// LinkedList data type
/// 
/// This is a class that points to a ListNode, the head node, which
/// denotes the start of the linked list
/// This also has associated operations on the list
///
template <typename T>
class LinkedList
{
// Internal types and typedefs
public:
	typedef typename T TNodeType;
	typedef typename LinkedList<T> TListType;
	typedef typename Iterator<TListType> TListIteratorType;
	friend  TListIteratorType;

private:
	///
	/// ListNode data type
	///
	/// This is a templatized structure that has two members:
	///  Storage for an instance of its template type
	///  A pointer to a node signifying the next node in the list
	///
	struct ListNode
	{
		T data;
		ListNode* next;

		ListNode(const T& instance):
			data(instance),
			next(null)
		{
		}
	};

public:
	LinkedList() throw():
	  m_head(null)
	{
	}

	~LinkedList();
	bool AddToFront(const T& item) throw();
	bool RemoveOne(const T& item) throw();
	bool Contains(const T& item) throw();
	bool InsertAfter(const T& item, ListNode* node) throw();
	size_t Count() throw();

private:
	ListNode* m_head;
};

template <typename TListType>
class Iterator
{
private:
	typedef typename TListType::TNodeType T;
	typedef typename TListType::ListNode TListNodeType;

public:
	Iterator(TListType* list)
	{
		m_current = list->m_head;
	}

	bool AtEnd() 
	{
		return m_current == null;
	}

	T& Current()
	{
		return m_current->data; 
	}

	bool MoveNext()
	{
		if (!AtEnd()) 
		{
			m_current = m_current->next;
			return true;
		}

		return false;
	}

private:
	TListNodeType* m_current;
};
