#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
class MyArray
{
private:
    float* data;
    int length;

public:
	// constructor function
    MyArray (int length);

	// initialize function
    MyArray (int length, float* init_data);

	// deconstructor function
    ~MyArray();

	// Get length of the array
    int GetLength()
	{
        return length;
    }

	// Access 1 element of the array
    float operator[] (int index);

	// Print all the elements of the array
	// If a function is defined as a friend function in C++, then
	// the private and protected data of a class can be accessed using the function.	
    friend std::ostream& operator<< (std::ostream& os, MyArray& a)
	{       
		os << std::endl << "Call << operator!" << std::endl;
		os << "This array has " << a.length << " elements:\n";
		for (int i = 0; i < a.length; i++)
		{
			os << "The element at index " << i << " is: " << a.data[i] << "\n";
		}
        os << std::endl;
		return os;
	};
	
	// Count the sum of all the elements of the array
    float operator() ();

	// Count the addition of 2 arrays
    friend MyArray operator+ (MyArray& lhs, MyArray& rhs)
    {
        MyArray sum (lhs.length);
        if ((lhs.data == NULL) || (rhs.data == NULL) || (lhs.length != rhs.length))
        {
            std::cout << "Error: Addition!" << std::endl;
        }
        else 
        {
            std::cout << "Call + operator!" << std::endl;
            sum.length = lhs.length;
            std::cout << "Addition array of 2 array is: [";
            for (int i = 0; i < lhs.length; i++)
            {
                sum.data[i] = lhs.data[i] + rhs.data[i];
                std::cout << sum.data[i] << " ";
            }
            std::cout << "]" << std::endl << std::endl;
            //for (int i = 0; i < sum.length; i++)
            //{
            //    std::cout << sum.data[i] << " ";
            //}
        }
        sum.length = lhs.length;
        return sum;
    };
    
    MyArray& operator= (const MyArray& other)
    {
        if ((other.data == NULL) || (other.length == 0))
        {
            std::cout << "Error: Equal!" << std::endl;
        }
        else 
        {
            std::cout << "Call = operator!" << std::endl;
            this->length = other.length;
            std::cout << "Addition array of 2 array is: [";
            for (int i = 0; i < other.length; i++)
            {
                this->data[i] = other.data[i];
                std::cout << this->data[i] << " ";
            }
            std::cout << "]" << std::endl << std::endl;
        }
        return *this;
    };
};

// constructor function
MyArray::MyArray (int length)
{
    data = new float [length];
    if (data == NULL)
	{
		std::cout << "Error: Creating Array\n";
	}
    else
	{
        memset (data, 0, sizeof (float) * length);
    }
}

// initialize function
MyArray::MyArray (int l, float* init_data)
{
	length = l;
    data = new float [length];
    if (data == NULL)
	{
		std::cout << "Error: Creating Array\n";
	}
    else
	{
        memcpy (data, init_data, sizeof (float) * length);
		std::cout << "Succesfully create new array!\n";
		std::cout << "Length of the array just created is " << length << std::endl << std::endl;
    }
}

// deconstructor function
MyArray::~MyArray()
{
    if (data) 
	{
		delete data;
	}
}

// Access 1 element of the array
float MyArray::operator[] (int index)
{
    if ((index < 0) || (index >= length))
	{
        std::cout << "Error: Indexing\n";
		std::cout << "Index of the element: " << index << std::endl;
		std::cout << "Length of the array now: " << length << std::endl << std::endl;
	}
    else
	{
		std::cout << "Call [] operator!" << std::endl;
		std::cout << "Index of the element: " << index << std::endl;
		std::cout << "Length of the array now: " << length << std::endl;
		std::cout << "Value of this element: ";
    return data[index];
	}
}

// Count the sum of all the elements of the array
float MyArray::operator() ()
{
    float sum = 0;
    if (data == NULL)
    {
        std::cout << "Error: Count Sum" << std::endl;
    }
    else
    {
        std::cout << "Call () operator!" << std::endl;
        for (int i = 0; i < length; i++)
        {
            sum = sum + data[i];
        }
        std::cout << "Sum of all the elements of the array is: " << sum << std::endl << std::endl;
    }
    return sum;
};

int main()
{
    float a[] = {1.1, 1.2, 2.1, 2.3};
    float b[] = {1, 2, 3, 4};
    float e;

    MyArray c (4, a);
    std::cout << c[1] << std::endl;
	  std::cout << c;

    MyArray d (4, b);
    std::cout << d[1] << std::endl;
	  std::cout << d;

    MyArray s (4);
    s =  c + d;
    std::cout << s[1] << std::endl;
	  std::cout << s;

    e = c();
	  system ("pause");
}
