##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: /CPP-02/ex01/Makefile                        #
#                    Creation Date: January 21, 2025 11:04 AM                    #
#                    Last Updated: January 29, 2025 11:14 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= Towards_a_more_useful_fixed-point_number_class

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SOURCE		= main.cpp	\
			Fixed.cpp

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re