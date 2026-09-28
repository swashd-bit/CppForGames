#include <iostream>


class Base
{
public:
	virtual ~Base() = default;
};

class Base2
{
public:
	virtual ~Base2() = default;
};



class Derived : public Base
{
public:
	virtual ~Derived() override = default;
};

class Derived2 : public Base
{
public:
	virtual ~Derived2() override = default;
};


int main()
{
	unsigned char c = 'A'; // 8 bit
	int i = c; // Widening conversion. 31 bit one is used for sign bit.

	c = static_cast<unsigned char>( i ); // Narrowing conversion.

	unsigned int ui = 3;
	i = static_cast<int>( ui ); // Narrowing conversion.

	ui = static_cast<unsigned int>(i); // Rusult in unitentional behaviour if i is negative. cant store negative value in unsigned int.

	float f = 3.14f; // 32 bit 23 bit mantissa, 8 bit exponent, 1 bit sign.
	double d = f; // Widening conversion. 52 bit mantissa, 11 bit exponent, 1 bit sign.
	f = static_cast<float>( d ); // Narrowing conversion.

	f = static_cast<float>( i ); //narrowing conversion.
	d = i; // Widening conversion.

	i = static_cast<int>( f ); // Narrowing conversion.


	//---------------------------------------------
	// C-style casts (try to avoid using them).
	//---------------------------------------------
	f = (float)i;
	i = (int)f;

	//---------------------------------------------
	// const casts.
	//---------------------------------------------
	const float cf = 3.14f;
	float* pf = const_cast<float*>(&cf); // Removing constness (try to avoid using it).


	//---------------------------------------------
	// dynamic casts.
	//---------------------------------------------
	Base* b = new Derived();

	Derived* d = dynamic_cast<Derived*>(b);
	Derived* d = new Derived();
	Derived2* d2 = dynamic_cast<Derived2*>(b);

	b = d;

	if (d != nullptr)
	{
		std::cout << "b is Derived" << std::endl;
	}
	if (d2 == nullptr)
	{
		std::cout << "b2 is not Derived2" << std::endl;
	}

	//---------------------------------------------
	// reinterpret casts.
	//---------------------------------------------
	Base* b = new Base();
	Base2* b2 = reinterpret_cast<Base2*>(b);



	return 0;
}