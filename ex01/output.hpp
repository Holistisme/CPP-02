/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-02/ex01/output.hpp                       *
*                    Creation Date: January 21, 2025 01:23 PM                    *
*                    Last Updated: January 21, 2025 01:24 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       To bring more joy to the terminal!                       *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#define RESET						"\033[0m"

/********************************************************************************/

#define BOLD						"\033[1m"
#define DIM							"\033[2m"
#define UNDERLINE					"\033[4m"
#define BLINK						"\033[5m"
#define REVERSE						"\033[7m"

#define BLACK						"\033[30m"
#define RED							"\033[31m"
#define GREEN						"\033[32m"
#define YELLOW						"\033[33m"
#define BLUE						"\033[34m"
#define MAGENTA						"\033[35m"
#define CYAN						"\033[36m"
#define WHITE						"\033[37m"

#define BG_BLACK					"\033[40m"
#define BG_RED						"\033[41m"
#define BG_GREEN					"\033[42m"
#define BG_YELLOW					"\033[43m"
#define BG_BLUE						"\033[44m"
#define BG_MAGENTA					"\033[45m"
#define BG_CYAN						"\033[46m"
#define BG_WHITE					"\033[47m"

#define BRIGHT_BLACK				"\033[90m"
#define BRIGHT_RED					"\033[91m"
#define BRIGHT_GREEN				"\033[92m"
#define BRIGHT_YELLOW				"\033[93m"
#define BRIGHT_BLUE					"\033[94m"
#define BRIGHT_MAGENTA				"\033[95m"
#define BRIGHT_CYAN					"\033[96m"
#define BRIGHT_WHITE				"\033[97m"

#define BG_BRIGHT_BLACK				"\033[100m"
#define BG_BRIGHT_RED				"\033[101m"
#define BG_BRIGHT_GREEN				"\033[102m"
#define BG_BRIGHT_YELLOW			"\033[103m"
#define BG_BRIGHT_BLUE				"\033[104m"
#define BG_BRIGHT_MAGENTA			"\033[105m"
#define BG_BRIGHT_CYAN				"\033[106m"
#define BG_BRIGHT_WHITE				"\033[107m"

#define READABLE_BG_BRIGHT_WHITE	BG_BRIGHT_WHITE BLACK

/********************************************************************************/

#define MOVE_CURSOR_UP				"\033[F"
#define ERASE_LINE					"\33[2K\33[1A\33[2K"

/********************************************************************************/

#define ERROR						BG_RED "ERROR:" RESET RED " "