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

int seatNo[10][10] = { 0, }; //�¼���ȣ
const char* seat[10][10];
int select_seatNo[100] = { 0, }; //���õ� �¼� ��ȣ
int m = 0, color = 7;

int main()
{
	menu();
}

int menu()
{
	int input = 0;

	printf("1. ���� �˻��ϱ�\n");
	printf("2. ���� �����ϱ�\n");
	printf("3. ���� �ݳ��ϱ�\n");
	printf("4. ������ �ڸ� �����ϱ�\n");
	printf("5. ���α׷� ����\n\n");

	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: search; break;
	case 2: borrow; break;
	case 3: return_book; break;
	case 4: select_menu(); break;
	case 5: system("cls"); printf("���α׷� �����մϴ�\n\n"); break;
	default:
		break;
	}
	return 0;
}

int select_menu()
{
	int input = 0;

	system("cls");

	printf("1. �ڸ� �����ϱ�\n");
	printf("2. �ڸ� ����ϱ�\n");
	printf("3. ���α׷� ����\n\n");
	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); select_seat(); break;
	case 2: system("cls"); select_Cancel(); break;
	case 3: system("cls"); printf("\n\n���α׷� �����մϴ�.\n\n"); break;
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
			seat[i][j] = "��";
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

	printf("\n�����ϰ� ���� �¼��� ��ȣ�� �Է����ּ��� : ");
	scanf_s("%d", &select_seat);

	if (select_seat > 100 || select_seat <= 0)
	{
		system("cls");
		printf("���� 1~100���� �Է��ּ���\n\n\n");
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
					printf("\n�̹� ���õ� �¼��Դϴ�. \n");
					printf("�ٸ� �¼��� �������ּ���\n");
					Sleep(700);
					system("cls");
					goto start1;
				}
			}
		}
	}
	printf("\n�ڸ� ���� �����߽��ϴ�!\n\n\n");
	select_seatNo[m] = select_seat;
	m++;
start2:
	printf("1. ���α׷� �����ϱ� \n");
	printf("2. ������ ������ �ڸ��޴��� ���ư��� \n\n");
	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1:system("cls"); printf("\n\n���α׷� �����մϴ�!\n\n"); break;
	case 2: select_menu(); break;
	default: printf("1 �� 2�� �Է����ּ���!"); goto start2;
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
			seat[i][j] = "��";
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

	printf("����ϰ� ���� �ڸ��� ��ȣ�� �Է����ּ��� : ");
	scanf_s("%d", &cancel_seat);

	if (cancel_seat <= 0 || cancel_seat > 100)
	{
		printf("���� 1~100���� �Է����ּ���");
		goto start3;
	}


	for (int i = 0; i < 100; i++)
	{
		if (select_seatNo[i] != 0)
		{
			if (cancel_seat == select_seatNo[i])
			{
				printf("\n��ҵǾ����ϴ�!\n\n");
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
					printf("�Է��� �ڸ��� ��ȣ�� ���ڸ��Դϴ�!\n");
					goto start4;
				}
			}
			else
			{
				printf("\n\n���õ� �ڸ��� �����ϴ�!\n\n");
				goto start4;
			}
		}

	start4:
		printf("1. ���α׷� �����ϱ� \n");
		printf("2. ������ ������ �ڸ��޴��� ���ư��� \n\n");
		printf("���ϴ� ���񽺸� �Է����ּ��� : ");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1: system("cls"); printf("���α׷� �����մϴ�\n\n"); break;
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
	printf("�˻��� ������, ���ڸ��� �Է����ּ��� : ");
	scanf_s("%s", search_input);

	printf("\n\n1. ���α׷� �����ϱ� \n");
	printf("2. �ٸ� ���� �˻��ϱ� \n\n");
	printf("3. ���� �޴��� ���ư��� \n\n");
	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("���α׷� �����մϴ�\n\n"); break;
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
	printf("������ �������� �Է����ּ��� : ");

	printf("\n\n1. ���α׷� �����ϱ� \n");
	printf("2. �ٸ� ���� �����ϱ� \n\n");
	printf("3. ���� �޴��� ���ư��� \n\n");
	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("���α׷� �����մϴ�\n\n"); break;
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
	printf("������ �������� �Է����ּ��� : ");

	printf("\n\n1. ���α׷� �����ϱ� \n");
	printf("2. �ٸ� ���� �ݳ��ϱ� \n\n");
	printf("3. ���� �޴��� ���ư��� \n\n");
	printf("���ϴ� ���񽺸� �Է����ּ��� : ");
	scanf_s("%d", &input);

	switch (input)
	{
	case 1: system("cls"); printf("���α׷� �����մϴ�\n\n"); break;
	case 2: goto start7; break;
	case 3: menu(); break;
	default:
		break;
	}

	return 0;
}