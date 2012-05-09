#pragma once

namespace BasePrivate
{
	template <typename T>
	class StandardDeletePolicy
	{
	public:
		static void Free(T* object)
		{
			delete object;
		}
	};

	template <typename T>
	class StandardArrayDeletePolicy
	{
	public:
		static void Free(T* object)
		{
			delete[] object;
		}
	};

};

template <typename T, template <typename T> class TDeletePolicyType>
class BasePtr
{
	typedef TDeletePolicyType<T> TDeletePolicy;

public:
	typedef BasePtr<T, TDeletePolicyType> BasePtrType;

	BasePtr(T* object):
	  m_object(object)
	{
	}

	BasePtr():
	  m_object(null)
	{
	}

	BasePtrType& operator= (BasePtrType const& rhs)
	{
		Assert(false, "Assigning from one BasePtr to another is not allowed");
	}

	BasePtrType& operator= (T* rhs)
	{
		Assert(m_object == null);
		m_object = rhs;
		return (*this);
	}

	operator T*()
	{
		return m_object;
	}

	T* operator->()
	{
		return m_object;
	}

	T* Detach()
	{
		T* object = m_object;
		m_object = null;
		return object;
	}

	~BasePtr()
	{
		if (m_object != null)
		{
			TDeletePolicy::Free(m_object);
		}
	}

private:
	T* m_object;
};

template <typename T>
class AutoPtr: public BasePtr<T, BasePrivate::StandardDeletePolicy>
{
};

template <typename T>
class AutoArrayPtr: public BasePtr<T, BasePrivate::StandardArrayDeletePolicy>
{
	typedef BasePtr<T, BasePrivate::StandardArrayDeletePolicy> base;

public:
	AutoArrayPtr(T* object):
	  base(object)
	{
	}

	AutoArrayPtr():
	  base()
	{
	}

	AutoArrayPtr<T>& operator= (AutoArrayPtr<T> const& rhs)
	{
		BasePtr<T, BasePrivate::StandardArrayDeletePolicy>::operator=(rhs);
		return (*this);
	}

	AutoArrayPtr<T>& operator= (T* rhs)
	{
		BasePtr<T, BasePrivate::StandardArrayDeletePolicy>::operator=(rhs);
		return (*this);
	}

};
