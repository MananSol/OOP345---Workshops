#include <algorithm>
#include <iomanip>
#include "Book.h"

namespace sdds
{
	const std::string& Book::title() const {
		return b_title;
	}
	const std::string& Book::country() const {
		return b_country;
	}
	const size_t& Book::year() const {
		return b_year;
	}
	double& Book::price() {
		return b_price;
	}

	std::string Book::trim(std::string& str) {
		const char* spaces = "\f\n\r\t\v";
		std::string temp;
		temp = str.substr(0, str.find(","));
		temp.erase(0, temp.find_first_not_of(spaces));
		temp.erase(temp.find_first_not_of(spaces) + 1);
		str.erase(0, str.find(",") + 1);

		return temp;
	}

	Book::Book(const std::string& strBook) {
		std::string res = strBook;
		b_author = trim(res);
		b_title = trim(res);
		b_country = trim(res);
		b_price = std::stod(trim(res));
		b_year = std::stoi(trim(res));
		b_desc = res.substr(res.find_first_not_of(" \f\n\\r\t\v"), res.find_last_not_of(" \f\n\r\t\v") + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Book& obj) {
		if (obj.year() != 0)
		{
			os << std::setw(20) << obj.b_author << " | ";
			os << std::setw(22) << obj.title() << " | ";
			os << std::setw(5) << obj.country() << " | ";
			os << std::setw(4) << obj.year() << " | ";
			os << std::fixed << std::setw(6) << std::setprecision(2) << obj.b_price << " | ";
			os << obj.b_desc << std::endl;
		}
		return os;
	}
}