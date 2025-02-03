##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: /CPP-02/ex03/Makefile                        #
#                    Creation Date: January 24, 2025 14:39 PM                    #
#                    Last Updated: January 29, 2025 11:14 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= BSP

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SOURCE		= main.cpp		\
			askFloat.cpp	\
			bsp.cpp			\
			confirmExit.cpp	\
			Fixed.cpp		\
			Point.cpp

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