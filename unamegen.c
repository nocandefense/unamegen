#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_PATH "/usr/share/dict/words"

void generate_random_username(int word_count) {
	// function body here
	FILE *file = fopen(DICTIONARY_PATH, "r");
	char word[MAX_WORD_LENGTH];
	char username[MAX_WORD_LENGTH * word_count];
	int line_count = 0;

	if (file == NULL) {
		perror("Error opening dictionary");
		exit(1);
	}

	while (fgets(word, sizeof(word), file)) {
		line_count++;
	}

	// generate random words
	username[0] = '\0';
	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < word_count; i++) {
		int random_line = rand() % line_count;	
		int current_line = 0;
	
		// Find the random line in the file
		while (fgets(word, sizeof(word), file) && current_line < random_line) {
	current_line++;
}

	word[strcspn(word, "\n")] = '\0';
	strcat(username, word);
	fseek(file, 0, SEEK_SET);
	}
	
	printf("Generated Username: %s\n", username);
	fclose(file);
}

int main() {
	// set seed for randomness
	srand(time(NULL));

	// call the function with your desired configuration
	generate_random_username(2);

	return 0;
}


