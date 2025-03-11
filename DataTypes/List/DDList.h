#pragma once

#include <iostream>

template <typename T>
class DDList
{
private:
	T* _buffer;
	int _bufferSize;
	int _bufferCapacity;

public:
	DDList()
	{
		_bufferSize = 0;
		_bufferCapacity = 1;

		_buffer = new T[_bufferCapacity];
	}
	DDList(const DDList<T>& otherList)
	{
		if (!otherList._buffer || otherList._bufferSize <= 0)
		{
			_bufferSize = 0;
			_bufferCapacity = 1;

			_buffer = new T[_bufferCapacity];
			return;
		}

		_bufferSize = otherList._bufferSize;
		_bufferCapacity = (_bufferSize >= otherList._bufferCapacity) ? (_bufferSize + 1) : otherList._bufferCapacity;
		_buffer = new char[_bufferCapacity];

		std::copy(otherList._buffer, otherList._buffer + otherList._bufferSize, _buffer);
	}
	DDList(DDList<T>&& otherList) noexcept
	{
		_buffer = otherList._buffer;
		_bufferSize = otherList._bufferSize;
		_bufferCapacity = otherList._bufferCapacity;

		otherList._buffer = nullptr;
		otherList._bufferSize = 0;
		otherList._bufferCapacity = 0;
	}
	~DDList()
	{
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = nullptr;
		}

		_bufferSize = 0;
		_bufferCapacity = 0;
	}

private:
	// Increases buffer capacity by increase amount
	void IncreaseBufferSize(int increaseAmount)
	{
		_bufferCapacity += increaseAmount;
		T* newBuffer = new T[_bufferCapacity];

		if (_buffer)
		{
			std::copy(_buffer, _buffer + _bufferSize, newBuffer);
			delete[] _buffer;
		}

		_buffer = newBuffer;
	}

public:
	const T* Data() const { return _buffer; }

	void AddItem(const T& itemToAdd)
	{
		if ((_bufferSize + 1) > _bufferCapacity) IncreaseBufferSize((_bufferSize + 1) - _bufferCapacity);
		_buffer[_bufferSize++] = itemToAdd;
	}

	int Length()
	{
		return _bufferSize;
	}

	T& GetAt(int at)
	{
		return _buffer[at];
	}

public:
	// Copy assignment
	DDList& operator=(const DDList& otherList)
	{
		if (this == &otherList) return *this;
		delete[] _buffer;

		if (!otherList._buffer || otherList._bufferSize <= 0)
		{
			_bufferSize = 0;
			_bufferCapacity = 1;

			_buffer = new T[_bufferCapacity];
			return;
		}

		_bufferSize = otherList._bufferSize;
		_bufferCapacity = (_bufferSize >= otherList._bufferCapacity) ? (_bufferSize + 1) : otherList._bufferCapacity;
		_buffer = new char[_bufferCapacity];

		std::copy(otherList._buffer, otherList._buffer + otherList._bufferSize, _buffer);

		return *this;
	}

	// Move assignment
	DDList& operator=(DDList&& otherList) noexcept
	{
		if (this == &otherList) return *this;
		delete[] _buffer;

		_buffer = otherList._buffer;
		_bufferSize = otherList._bufferSize;
		_bufferCapacity = otherList._bufferCapacity;

		otherList._buffer = nullptr;
		otherList._bufferSize = 0;
		otherList._bufferCapacity = 0;

		return *this;
	}
};

