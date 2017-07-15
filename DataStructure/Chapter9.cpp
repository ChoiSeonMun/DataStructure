#include "Dictionary.h"
#include <conio.h>

void help() { printf("[����] i - �߰� d - ���� w - �ܾ�˻� m - �ǹ̰˻� p - ��� q - ���� => "); }

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
			printf("  > ���� �ܾ� : ");
			gets_s(word, 80);
			printf("  > �ܾ� ���� : ");
			gets_s(meaning, 200);
			tree.insert(new BinRecordNode(word, meaning));
			break;
		case 'd':
			printf("  > ���� �ܾ� : ");
			gets_s(word, 80);
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();
			puts("");
			break;
		case 'w':
			printf("  > �˻� �ܾ� : ");
			gets_s(word, 80);
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > �˻� �ǹ� : ");
			gets_s(meaning, 200);
			tree.searchMeaning(meaning);
			break;
		}
	} while (command != 'q');

	return 0;
}