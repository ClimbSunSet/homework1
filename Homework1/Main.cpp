// Main.cpp

#include <iostream>
#include <string>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int PotionsValue[5]{ 0, }; // 가진 포션의 수량을 저장할 배열. (함수에 사용하려구 전역 배열로 설정.)
int* p_PotionsValue[5]{ 0, }; // 가진 포션의 수량을 수정해줄 포인터 배열. (함수에 사용하려구 전역 배열로 설정.)

int main(void)
{
	int StatusValue[5]{ 0, }; // 각 스테이터스의 값을 저장할 배열. 
	int* pStatusValue[5]{ 0, }; // 스테이터스의 값을 수정할 때 사용할 포인터 배열.

	for (int i = 0; i < 5; ++i) // index[0]: HP, index[1]: MP, index[2]: ATK, index[3]: DEF, index[4]: EXP 대한 값을 수정함.
	{
		pStatusValue[i] = &StatusValue[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		p_PotionsValue[i] = &PotionsValue[i];
	}

	string StatusName[5]{ "HP", "MP", "ATK", "DEF", "EXP"}; // 각 스테이터스의 명칭을 저장할 배열.
	string PotionsName[5]{"HP포션", "MP포션", "공격력포션", "방어력포션", "경험치포션"}; // 각 포션의 명칭을 저장할 배열.

	cout << "HP와 MP를 입력하세요\n";
	cin >> *pStatusValue[0];
	cin >> *pStatusValue[1];

	while(*pStatusValue[0] <= 50 || *pStatusValue[1] <= 50)
	{
		cout << "HP와 MP는 50이하로 설정할 수 없습니다.\n";
		cout << "다시 입력해 주세요.\n";

		cin >> *pStatusValue[0];
		cin >> *pStatusValue[1];

	}

	cout << "ATK와 DEF를 입력하세요.\n";
	cin >> *pStatusValue[2];
	cin >> *pStatusValue[3];

	while (*pStatusValue[2] <= 0 || *pStatusValue[3] <= 0)
	{
		cout << "ATK과 DEF은 0이하로 설정할 수 없습니다.\n";
		cout << "다시 입력해 주세요.\n";

		cin >> *pStatusValue[2];
		cin >> *pStatusValue[3];
	}

	int i = -1 ;

	while (true)
	{
		cout << "<<<스탯 관리 시스템>>>\n";
		cout << " 1. HP UP\n 2. MP UP\n 3. ATK UP\n 4. DEF UP\n 5. 현재 능력치 \n 6.Level UP\n 0. 나가기\n";
		cin >> i;

		if (i == 1)
		{
			cout << "HP가 1 증가했습니다!\n";
			*pStatusValue[0] = *pStatusValue[0] + 1;
		}

		if (i == 2)
		{
			cout << "MP가 1 증가했습니다!\n";
			*pStatusValue[1] = *pStatusValue[1] + 1;
		}

		if (i == 3)
		{
			cout << "ATK이 1 증가했습니다!\n";
			*pStatusValue[2] = *pStatusValue[2] + 1;
		}

		if (i == 4)
		{
			cout << "DEF가 1 증가했습니다!\n";
			*pStatusValue[3] = *pStatusValue[3] + 1;
		}

		if (i == 5)
		{
			cout << "현재 능력치\n";

			int j;

			for (j = 0; j < 4; ++j)
			{
				cout << (j + 1) << ". " << StatusName[j] << "=" << *pStatusValue[j] << "\n";
			}
		}

		if (i == 6)
		{
			cout << "레벨이 1 증가했습니다.\n";
			*pStatusValue[4] = *pStatusValue[4] + 1;
		}

		if (i == 0)
		{
			break;
		}

	}
	
	setPotion(5, p_PotionsValue[0], p_PotionsValue[1]);

	int k = -1;

	while (true)
	{
		cout << "\n<<포션시스템>>\n";

		cout << " 1.MP포션\n 2.HP포션\n 3.공격력 포션\n 4.방어력 포션\n 5.현재 능력치\n 6.Level Up\n 0번.프로그램 종료\n";

		cin >> k;

		if (k == 1)
		{
			if (PotionsValue[1] <= 0)
			{
				cout << "가지고 있는 MP포션이 없습니다.";
				continue;
			}

			*p_PotionsValue[1] = *p_PotionsValue[1] - 1;
			*pStatusValue[1] = *pStatusValue[1] + 20;
			cout << "MP포션을 사용했습니다.\n" << "MP가 '20' 올랐습니다.\n";

		}

		if (k == 2)
		{
			if (PotionsValue[0] <= 0)
			{
				cout << "가지고 있는 HP포션이 없습니다.";
				continue;
			}

			*p_PotionsValue[0] = *p_PotionsValue[0] - 1;
			*pStatusValue[0] = *pStatusValue[0] + 20;
			cout << "HP포션을 사용했습니다.\n" << "HP가 '20' 올랐습니다.\n";

		}

		if (k == 3)
		{
			if (PotionsValue[2] <= 0)
			{
				cout << "가지고 있는 공격력 증가 포션이 없습니다.";
				continue;
			}

			*p_PotionsValue[2] = *p_PotionsValue[2] - 1;
			*pStatusValue[2] = *pStatusValue[2] * 2;
			cout << "공격력 포션을 사용했습니다.\n" << "공격력이 2배가 되었습니다.\n";

		}

		if (k == 4)
		{
			if (PotionsValue[3] <= 0)
			{
				cout << "가지고 있는 방어력 포션이 없습니다.";
				continue;
			}

			*p_PotionsValue[3] = *p_PotionsValue[3] - 1;
			*pStatusValue[3] = *pStatusValue[3] * 2;
			cout << "방어력 포션을 사용했습니다.\n" << "방어력이 2배가 되었습니다.\n";
				
		}

		if (k == 5)
		{
			cout << "<<현재 능력치>>\n";

			for (int i = 0; i < 4; ++i)
			{
				cout << (i + 1) << ". " << StatusName[i] <<  StatusValue[i] << "\n";
			}
		}

		if (k == 6)
		{
			for (int i = 0; i < 5; ++i)
			{
				(*p_PotionsValue[i]) = (*p_PotionsValue[i]) + 1;
			}

			cout << "[Level Up!]\n"<<"모든 포션이 1개씩 추가되었습니다!";
		}

		if (k == 0)
		{
			break;
		}
	}

	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion += count;
	*p_MPPotion += count;

	cout << "HP포션과 MP포션이 " << count <<"개씩 기본 지급되었습니다!";

	return;
}