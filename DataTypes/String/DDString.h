#pragma once

#include <iostream>

#include "List/DDList.h"

class DDString
{
private:
	char* _buffer;
	int _bufferSize;
	int _bufferCapacity;

public:
	// Default constructor
	DDString();

	// Parameterized constructor
	DDString(char* inBuffer);

	// Parameterized constructor
	DDString(const char* inBuffer);

	// Copy constructor constructor
	DDString(const DDString& otherString);

	// Move constructor
	DDString(DDString&& otherString) noexcept;

	// Destructor
	~DDString();

private:
	// Increases buffer capacity by increase amount
	void IncreaseBufferSize(int increaseAmount);

public:
	const char* Data() const { return _buffer; }

	DDList<DDString> SplitBy(const char& characterToSplitBy) const;

	DDString SubString(int startIndex, int endIndex) const;

	bool Equals(const DDString& otherString) const;

public:
	// Copy assignment
	DDString& operator=(const DDString& otherString)
	{
		if (this == &otherString) return *this;
		delete[] _buffer;

		if (!otherString._buffer || otherString._bufferSize <= 0)
		{
			_bufferSize = 0;
			_bufferCapacity = 10;

			_buffer = new char[_bufferCapacity];
			_buffer[_bufferSize] = 0x00;
			return *this;
		}

		_bufferSize = otherString._bufferSize;
		_bufferCapacity = (_bufferSize >= otherString._bufferCapacity) ? (_bufferSize + 1) : otherString._bufferCapacity;
		_buffer = new char[_bufferCapacity];

		memcpy(_buffer, otherString._buffer, _bufferSize);
		_buffer[_bufferSize] = 0x00;

		return *this;
	}

	// Move assignment
	DDString& operator=(DDString&& otherString) noexcept
	{
		if (this == &otherString) return *this;
		delete[] _buffer;

		_buffer = otherString._buffer;
		_bufferSize = otherString._bufferSize;
		_bufferCapacity = otherString._bufferCapacity;

		otherString._buffer = nullptr;
		otherString._bufferSize = 0;
		otherString._bufferCapacity = 0;

		return *this;
	}

	bool operator==(const DDString& otherString) const
	{
		return Equals(otherString);
	}

	// Stream operator
	friend std::ostream& operator<<(std::ostream& stream, const DDString& string);
};

inline std::ostream& operator<<(std::ostream& stream, const DDString& string)
{
	stream << string.Data();
	return stream;
}