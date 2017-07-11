#pragma once

#ifndef __LINEEDITOR_H__
#define __LINEEDITOR_H__

#include "LinkedList.h"

class LineEditor : public LinkedList {
public:
	LineEditor() = default;
	void	Display(FILE* fp = stdout);
	void	InsertLine();
	void	DeleteLine();
	void	ReplaceLine();
	void	LoadFile(char* filename);
	void	StoreFile(char* filename);
};

//Feature : to print contents formatted out to console
void LineEditor::Display(FILE* fp)
{
	if (!isEmpty())
	{
		int lineNum = 0;
		for (Node* currentLine = getHead(); currentLine; currentLine = currentLine->getNext())
		{
			fprintf(stderr, "%3d: ", lineNum);
			currentLine->print(fp);
			fprintf(fp, "\n");
			++lineNum;
		}
			
	}
	else
		printf("Empty\n");
}

//Feature : to insert content into pos
void LineEditor::InsertLine()
{
	int pos;
	char line[MAX_DATA_SIZE];
	printf("  입력행 번호 : ");
	scanf_s("%d", &pos);
	printf("  입력행 내용 : ");
	getchar();	//for '\n'
	gets_s(line, MAX_DATA_SIZE);
	insert(pos, new Node(line));
}

//Feature : to delete the line at pos from editor
void LineEditor::DeleteLine()
{
	int pos;
	printf("  삭제 행 번호 : ");
	scanf_s("%d", &pos);
	getchar();	//for '\n'
	delete remove(pos);
}

//Feature : to replace the content with a line at pos
void LineEditor::ReplaceLine()
{
	int pos;
	char line[MAX_DATA_SIZE];
	printf("  바꿀 행 번호 : ");
	scanf_s("%d", &pos);
	printf("  바꿀 행 내용 : ");
	getchar();	//for '\n'
	gets_s(line, MAX_DATA_SIZE);
	replace(pos, new Node(line));
}

//Feature : to load contents from the file
void LineEditor::LoadFile(char * filename)
{
	FILE* fp;
	fopen_s(&fp, filename, "r");
	if (!fp)
	{
		puts("There is no file");
		return;
	}

	char line[MAX_DATA_SIZE];
	for (int pos = 0; fgets(line, MAX_DATA_SIZE, fp); ++pos)
		insert(pos, new Node(line));

	fclose(fp);
}

//Feature : to store contents into the file
void LineEditor::StoreFile(char * filename)
{
	FILE* fp;
	fopen_s(&fp, filename, "w");
	if (!fp)
	{
		puts("Unknown Error");
		return;
	}

	Display(fp);
	fclose(fp);
}
#endif