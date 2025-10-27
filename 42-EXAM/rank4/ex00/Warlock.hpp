#pragma once
#include <string>

class Warlock{
	private:
		std::string name_;
		std::string title_;
	public:
		Warlock() = delete;
		~Warlock();
		Warlock(const Warlock &obj) = delete;
		Warlock& operator=(const Warlock &obj) = delete;
		Warlock(const std::string &name, const std::string &title);
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
};