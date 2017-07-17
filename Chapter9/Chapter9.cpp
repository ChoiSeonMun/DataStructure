#include "Dictionary.h"
#include <conio.h>

void help() { printf("[사용법] i - 추가 d - 삭제 w - 단어검색 m - 의미검색 p - 출력 q - 종료 => "); }

int main()
{
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;
	do {
		help();
		command = _getche();
		puts("");
		switch (command) {
		case 'i':
			printf("  > 삽입 단어 : ");
			gets_s(word, 80);
			printf("  > 단어 설명 : ");
			gets_s(meaning, 200);
			tree.insert(new BinRecordNode(word, meaning));
			break;
		case 'd':
			printf("  > 삭제 단어 : ");
			gets_s(word, 80);
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();
			puts("");
			break;
		case 'w':
			printf("  > 검색 단어 : ");
			gets_s(word, 80);
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > 검색 의미 : ");
			gets_s(meaning, 200);
			tree.searchMeaning(meaning);
			break;
		}
	} while (command != 'q');

	return 0;
}