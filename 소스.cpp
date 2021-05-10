#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int menu();
int search();
int borrow();
int return_book();
int select_menu();
int select_seat();
int select_Cancel();

int seatNo[10][10] = { 0, }; //좌석번호
const char* seat[10][10];
int select_seatNo[100] = { 0, }; //선택된 좌석 번호
int m = 0, color = 7;

int main()
{
	menu();
}

int menu()
{
	int input = 0;

	printf("1. 도서 검색하기\n");
	printf("2. 도서 대출하기\n");
	printf("3. 도서 반납하기\n");
	printf("4. 열람실 자리 선택하기\n");
	printf("5. 프로그램 종료\n\n");

	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: search; break;
	case 2: borrow; break;
	case 3: return_book; break;
	case 4: select_menu(); break;
	case 5: system("cls"); printf("프로그램 종료합니다\n\n"); break;
	default:
		break;
	}
	return 0;
}

int select_menu()
{
	int input = 0;

	system("cls");

	printf("1. 자리 선택하기\n");
	printf("2. 자리 취소하기\n");
	printf("3. 프로그램 종료\n\n");
	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); select_seat(); break;
	case 2: system("cls"); select_Cancel(); break;
	case 3: system("cls"); printf("\n\n프로그램 종료합니다.\n\n"); break;
	default:
		break;
	}

	return 0;
}

int select_seat()
{
	int k = 1, input;
	int select_seat;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			seat[i][j] = "■";
			seatNo[i][j] = k;
			k++;
		}
	}
start1:
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (seatNo[i][j] == select_seatNo[k])
				{
					color = 9;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				}
			}
			printf("%4s", seat[i][j]);
			color = 7;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		}
		printf("\n");
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (seatNo[i][j] == select_seatNo[k])
				{
					color = 9;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				}
			}
			printf("%4d", seatNo[i][j]);
			color = 7;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		}
		printf("\n");
	}

	printf("\n선택하고 싶은 좌석의 번호를 입력해주세요 : ");
	scanf_s("%d", &select_seat);

	if (select_seat > 100 || select_seat <= 0)
	{
		system("cls");
		printf("숫자 1~100에서 입력주세요\n\n\n");
		goto start2;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (select_seat == select_seatNo[k])
				{
					printf("\n이미 선택된 좌석입니다. \n");
					printf("다른 좌석을 선택해주세요\n");
					Sleep(700);
					system("cls");
					goto start1;
				}
			}
		}
	}
	printf("\n자리 선택 성공했습니다!\n\n\n");
	select_seatNo[m] = select_seat;
	m++;
start2:
	printf("1. 프로그램 종료하기 \n");
	printf("2. 도서관 열람실 자리메뉴로 돌아가기 \n\n");
	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1:system("cls"); printf("\n\n프로그램 종료합니다!\n\n"); break;
	case 2: select_menu(); break;
	default: printf("1 과 2중 입력해주세요!"); goto start2;
		break;
	}
	return 0;
}

int select_Cancel()
{
	int k = 1, cancel_seat, input;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			seat[i][j] = "■";
			seatNo[i][j] = k;
			k++;
		}
	}

	for (int k = 0; k < 100; k++)
		printf("%3d", select_seatNo[k]);
	printf("\n");

start3:
	//system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (seatNo[i][j] == select_seatNo[k])
				{
					color = 9;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				}
			}
			printf("%4s", seat[i][j]);
			color = 7;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		}
		printf("\n");
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (seatNo[i][j] == select_seatNo[k])
				{
					color = 9;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				}
			}
			printf("%4d", seatNo[i][j]);
			color = 7;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		}
		printf("\n");
	}

	printf("취소하고 싶은 자리의 번호를 입력해주세요 : ");
	scanf_s("%d", &cancel_seat);

	if (cancel_seat <= 0 || cancel_seat > 100)
	{
		printf("숫자 1~100까지 입력해주세요");
		goto start3;
	}


	for (int i = 0; i < 100; i++)
	{
		if (select_seatNo[i] != 0)
		{
			if (cancel_seat == select_seatNo[i])
			{
				printf("\n취소되었습니다!\n\n");
				select_seatNo[i] = 0;
				goto start4;
			}
		}

		for (int i = 0; i < 100; i++)
		{
			if (select_seatNo[i] != 0)
			{
				if (cancel_seat != select_seatNo[i])
				{
					printf("입력한 자리의 번호는 빈자리입니다!\n");
					goto start4;
				}
			}
			else
			{
				printf("\n\n선택된 자리가 없습니다!\n\n");
				goto start4;
			}
		}

	start4:
		printf("1. 프로그램 종료하기 \n");
		printf("2. 도서관 열람실 자리메뉴로 돌아가기 \n\n");
		printf("원하는 서비스를 입력해주세요 : ");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1: system("cls"); printf("프로그램 종료합니다\n\n"); break;
		case 2: select_menu(); break;
		default:
			break;
		}

		return 0;
	}
}

int search()
{
	char search_input;
	int input;
	
	start5:
	printf("검색할 도서명, 저자명을 입력해주세요 : ");
	scanf_s("%s", search_input);

	printf("\n\n1. 프로그램 종료하기 \n");
	printf("2. 다른 도서 검색하기 \n\n");
	printf("3. 도서 메뉴로 돌아가기 \n\n");
	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("프로그램 종료합니다\n\n"); break;
	case 2: goto start5; break;
	case 3: menu(); break;
	default:
		break;
	}

	return 0;
}

int borrow()
{
	int input;

start6:
	printf("대출할 도서명을 입력해주세요 : ");

	printf("\n\n1. 프로그램 종료하기 \n");
	printf("2. 다른 도서 대출하기 \n\n");
	printf("3. 도서 메뉴로 돌아가기 \n\n");
	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("프로그램 종료합니다\n\n"); break;
	case 2: goto start6; break;
	case 3: menu(); break;
	default:
		break;
	}

	return 0;
}

int return_book()
{
	int input;
start7:
	printf("대출할 도서명을 입력해주세요 : ");

	printf("\n\n1. 프로그램 종료하기 \n");
	printf("2. 다른 도서 반납하기 \n\n");
	printf("3. 도서 메뉴로 돌아가기 \n\n");
	printf("원하는 서비스를 입력해주세요 : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("프로그램 종료합니다\n\n"); break;
	case 2: goto start7; break;
	case 3: menu(); break;
	default:
		break;
	}

	return 0;
}