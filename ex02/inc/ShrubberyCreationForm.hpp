#include "AForm.hpp"

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#define tree1 R"(@@ Christmas Trees @@ 11/96
          \ /
        -->*<--
          /_\
         /_\_\
        /_/_/_\
        /_\_\_\
       /_/_/_/_\
       /_\_\_\_\
      /_/_/_/_/_\
      /_\_\_\_\_\
     /_/_/_/_/_/_\
     /_\_\_\_\_\_\
    /_/_/_/_/_/_/_\
jgs      [___]
------------------------------------------------
Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/art/1825
)"

#define tree2 R"(
           |
         '.'.'
        -= o =-
         .'.'.
           |
           ,
          / \
        .'. o'.
       / 6 s ^.\
      /.-.o *.-.\
      `/. '.'9  \`
     .'6. *  s o '.
    /.--.s .6 .--.\
    `/ s '. .' * .\`
   .' o 6 .` .^ 6 s'.
  /.---. * ^ o .----.\
  `/s * `.^ s.' ^ * \`
 .' o , 6 `.' ^ o  6 '.
/,-^--,  o ^ * s ,----,\
`'-._s.;-,_6_^,-;._o.-'
     jgs |   |
         `"""`
------------------------------------------------
Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/art/5221
)"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();


	protected:
		void executeFormAction() const override;

	private:
		ShrubberyCreationForm();
		std::string target;

};

#endif // SHRUBBERYCREATIONFORM_HPP