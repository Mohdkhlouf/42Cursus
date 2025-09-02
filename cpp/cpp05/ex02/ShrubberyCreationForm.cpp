#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target):AForm("ShrubberyCreationForm",145,137),target_(target){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj){
	target_ = obj.target_;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
	if(this != &obj){
		target_ = obj.target_;
	}
	return (*this);
}


bool ShrubberyCreationForm::draw_trees(const std::string &target) const{
	std::string tree1 = "  *\n"
						" * *\n"
						"*   *\n"
						"*****\n"
						"  *  \n"
						"  *  \n\n";

	std::string tree2 = "  |\n"
						" / \\\n"
						"/   \\\n"
						"|||||\\\n"
						"  |  \n"
						"  |  \n\n";

	std::string tree3 = "  $\n"
						" $ $\n"
						"$   $\n"
						"$$$$$\n"
						"  $  \n"
						"  $  \n\n";


	std::string fileName = target  + "_shrubbery";

	try{
		std::ofstream fs(fileName);
		fs.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		fs<<tree1<<tree2<<tree3;
		fs.close();
		return (true);
	}catch (std::ofstream::failure &e)
		{
			std::cout<<"Error creating file: "<<e.what()<<std::endl;
			return (false);

		}

}

bool  ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	if(getSignedStatus()){
		if(executor.getGrade() <= getExecuteItGrade()){
			std::cout<<"Test Execute function"<<std::endl;
			if(!draw_trees(this->target_) ){
				return (false);
			}
			return (true);
		}
	}
	return (false);
}