#include <iostream>
#include <stdexcept>
#include "helpersFunc.h"

int helperFunc::operator()(std::istream *str)
{
	int n_ = 0;

	do
	{
		try
		{
			if(str->peek() == 10 && helperFunc::n == n_)
			{
				std::cout << "Sequence should end with 0!" << std::endl;

				return 1;
			}
			*str >> n_;

			if (str->fail())
			{
				std::cout << "Not a sequence!" << std::endl;

				return 2;
			}

			helperFunc::operator()(n_);
		}
		catch(std::exception &err)
		{
			err.what();
		}
		l_++;
	}while(n_);

	if (l_ < 3)
	{
		std::cout << "Too short sequence!" << std::endl;

		return 1;
	}

	std::cout << "Count: " << helperFunc::count << std::endl;

	return 0;
}

int helperFunc::operator()(int n_)
{
	((helperFunc::n = n_), (n_ + s) == helperFunc::n && !(l_ % 3) && (l_ != 0)) ? (helperFunc::count++, helperFunc::s = 0) : (helperFunc::n = n_);

	return 0;
}
