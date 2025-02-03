/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-02/ex03/confirmExit.cpp                     *
*                    Creation Date: February 3, 2025 11:26 AM                    *
*                    Last Updated: February 3, 2025 11:40 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                 To be able to get out of the program properly                  *
*********************************************************************************/

#include "./Fixed.hpp"

/********************************************************************************/

static inline bool	matchesAny(const std::string &input, const char *options[], const size_t size);
static std::string	getInputLine(void);
static void			trimSpaces(std::string &string);
static bool			sameString(const std::string &first, const std::string &second);

/********************************************************************************/

/**
 * @brief Wait for the user's confirmation to exit.
 */
void	confirmExit(void) {
	const char *acceptOptions[] = { "y", "yes", "agree",
		"sure", "why note", "absolutely", "of course", "go for it",
		"do it", "Accept away!" , "ok", "yeah", "yup", "aye", "confirmed",
		"let's go", "do it up!", "+1", "true", "enable", "sure thing",
		"heck yeah!", "go ahead", "yessir", "fine", "alright", "let's do this",
		"To infinity and beyond!", "Make it so!", "Engage!", "Do it like it's hot!",
		"Chop chop!", "Houston, we are go for this!",
		"Yes, my liege!", "Activate protocol!", "Ready to roll!"
	};
	const char *declineOptions[] = { "n", "no", "disagree",
		"nah", "nope", "not really", "never", "don't", "stop", "leave it",
		"disable", "false", "negative", "why?", "not today", "hard pass", "forget it",
		"no way", "declined", "I said no", "just no", "abort", "Not on my watch!",
		"Over my dead body!", "Hard no!", "I don't think so, pal.", "Step away from the keyboard!",
		"No means no!", "Abort mission!", "Don't touch my spaces!", "I like my chaos!", "Nah, I'm a rebel like that."
	};

	std::cout << "Do you want to " << RED << "exit" << RESET << "?" << std::endl;
	while (forever) {
		std::string input = getInputLine();

		if (matchesAny(input, acceptOptions, sizeof(acceptOptions) / sizeof(*acceptOptions))) {
			std::cout << "\nThank you for using " << GREEN << "BSP" RESET "!\n" << std::endl;
			exit(EXIT_SUCCESS);
		}
		else if (matchesAny(input, declineOptions, sizeof(declineOptions) / sizeof(*declineOptions)))
			return;
		else {
			std::cout << '"' << YELLOW << input << RESET <<  '"' << RED << " is not a valid input! " << RESET
				<< "Try something like: " << GREEN << acceptOptions[std::rand() % (sizeof(acceptOptions) / sizeof(*acceptOptions))] << RESET
				<< " or " << RED << declineOptions[std::rand() % (sizeof(declineOptions) / sizeof(*declineOptions))] << RESET << '.' << std::endl;
		}
	};
}

/**
 * @brief Check if a given input matches any option in a list.
 * 
 * @param input The user input to check.
 * @param options The array of valid options.
 * @param size The size of the options array.
 * @return true: if the input matches any option, false otherwise.
 */
static inline bool matchesAny(const std::string &input, const char *options[], const size_t size) {
	for (size_t i = 0 ; i < size ; ++i)
		if (sameString(input, options[i]))
			return true;
	return false;
}


/********************************************************************************/

/**
 * @brief Recovers a line from standard input and handle EOF or errors gracefully.
 * 
 * This function ensures proper handling of EOF (CTRL-D) and returns a clean string input.
 * Also prohibits any form of signal.
 * 
 * @return std::string: The line read.
 */
static std::string getInputLine(void) {
	std::string input;
	std::getline(std::cin, input);

	if (std::cin.eof()) {
		std::cout << BG_RED "Confirmed CTRL-D:" RESET RED " exit: " RESET
			"Thank you for using " << GREEN << "BSP" RESET "!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << ERROR << "Invalid input. Enter a float value!" << RESET << std::endl;
	}
	else if (input.find(SIGNAL) != std::string::npos) {
		std::cout << ERROR << "BSP refuses to carry signals!" << RESET << std::endl;
		input = "no";
	}
	trimSpaces(input);
	return input;
}

/**
 * @brief Removes leading and trailing spaces from a string.
 * 
 * @param string The string to process.
 */
static void trimSpaces(std::string &string) {
	size_t start = 0;
	size_t end	 = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	string = string.substr(start, end - start);
}

/**
 * @brief Compares two strings case-insensitively.
 * 
 * This function checks if two strings are alphabetically identical,
 * ignoring differences in capitalization.
 * 
 * @param first The first string to compare.
 * @param second The second string to compare.
 * @return true: If the strings are identical (case-insensitive), false otherwise.
 */
static bool sameString(const std::string &first, const std::string &second) {
	if (first.length() != second.length())
		return (false);

	for (size_t i = 0 ; i < first.length() ; i++) {
		char firstCurrentChar	= (first[i] >= 'a' && first[i] <= 'z')   ? (first[i] - 'a' + 'A')  : first[i];
		char secondCurrentChar	= (second[i] >= 'a' && second[i] <= 'z') ? (second[i] - 'a' + 'A') : second[i];

		if (firstCurrentChar != secondCurrentChar)
			return (false);
	}
	return (true);
}