#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> first_semester = { "�����г�","�̻걸��","������α׷���","������Ȱ��ǽ�","���м���1" };//1�б� �������
vector<string> second_semester = { "��ü�������α׷���","���������","�ڷᱸ��","�ý��ۼ���Ʈ����","�ڷᱸ���ǽ�","���¼ҽ�����Ʈ�����" };//2�б� �������
vector<string> commons;//�̹� �б� ������� �����ϴ� ���ڿ� ����

void show_subject(int semester) {
	cout << endl;
	cout << semester << "�б� ��������Դϴ�." << endl;
	if (semester == 1)
	{
		for (string a : first_semester)
		{
			cout << a << "  ";
			commons.push_back(a);
		}
		cout << endl;
	}
	else
	{
		for (string a : second_semester)
		{
			cout << a << "  ";
			commons.push_back(a);
		}
		cout << endl;
	}
	cout << endl;
}
int main(void)
{
	vector<string> select;//������ ���� ������ ���ڿ� ����
	int limit = 21;//�ִ��̼����� 21����
	int current_grades = 0;//���� ������û�� ����
	int semester;
restart:
	cout << "2�г� �� �б� �Դϱ�? (1/2) : ";
	cin >> semester;
	if (semester == 1 || semester == 2)
	{
		show_subject(semester);
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		goto restart;
	}
	while (current_grades <= 21)
	{
		string choose;
		int cnt = 0;
		cout << "������� �� ������ ���� ���� : ";
		cin >> choose;
		for (string a : commons)
		{
			if (a == choose) {
				cnt++;//������ ������ �ش��б� ������� ���� �� cnt�� ������Ű�� �ݺ����� �������´�.
				break;
			}
		}
		if (cnt == 1)//cnt�� 1�̶�� ���� ������ ������ �ش��б� ������� �����Ѵٴ� �ǹ��̴�.
		{
			int num = 0;
			for (string a : select)
			{
				if (a == choose) {
					num++;//choose�� �Է��� ������ �̹� select ���� �ȿ� �����ϴ� ���� �����ϸ� num�� ������Ű�� �ݺ��� �������´�.
					break;
				}
			}
			if (num == 1)//num�� 1�̶�� ���� select ���� �ȿ� choose�� ���� ���� �����ϴ� ���̴�.
			{
				cout << "�ش������ �̹� ��û�ϼ̽��ϴ�.";
				cout << endl;
			}
			else//num�� 1�� �ƴ� ��� �� select ���� �ȿ� choose�� ������ ���� ���ٴ� ���̴�. 
			{
				select.push_back(choose);//select�ȿ� choose�� �߰��õg��.
				if (choose.find("�ǽ�") != string::npos)//�ǽ������� ��� ���� ��û�� ������ 2�� �߰��ȴ�.
				{
					current_grades += 2;
				}
				else//�ǽ������� �ƴ� ��� ���� ��û�� ������ 3�� �߰��ȴ�.
				{
					current_grades += 3;
				}
			}
		}
		else//cnt�� 1�� �ƴ� ��� �� 0 �ΰ�� ������ ������ �ش� �б� ������� ���ٴ� ���� �ǹ��Ѵ�. 
		{
			cout << "�ش������ �̹��б� ������� �����ϴ�.";
			cout << endl;
		}

		cout << "�� ������û�� ���� ��� : ";
		for (string a : select)
		{
			cout << a << " ";
		}
		cout << endl;
		cout << "���� ��û�� ���� : " << current_grades << endl;
		cout << endl;
	}
}