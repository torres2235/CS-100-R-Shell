#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "Base.hpp"
#include "Executor.hpp"

class Command : public Base {
	private:
		std::string input;

	public:
		Command(std::string leaf) : Base() {
			input = leaf;
		};
		
		virtual int evaluate() {
			Executor toRun = Executor();
			return toRun.execute(input);
		};
};

#endif //__COMMAND_HPP__
