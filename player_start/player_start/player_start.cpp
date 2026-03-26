#include <iostream> // 선언
#include <string> 

using namespace std; 

string Name; //스트링 함수
int Hp = 100; //hp level 기타등등 선언
int Level = 1;
int Attack = 30;
int Exp = 0;

void print() //나중에 한눈에 보기 위한 창
{
	cout << "이름: " << Name << endl; //나중에 호츨시 볼 수 있음
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Hp << endl;
	cout << "공격력: " << Attack << endl;
	cout << "경험치: " << Exp << endl;
}

void LevelUp() //경험치가 들어올 경우 레벨 1씩 증가
{
	Level++;
	Exp = 0;
	cout << "레벨업! \n";
}

void LevelUpCheck() //if 문으로 100이 넘을 경우 위에 있는 함수 호출 후 레벨업
{
	if (Exp >= 100)
	{
		LevelUp();
	}
}

int main() // 숫자값에 따른 입력창!
{
	cout << "이름 입력: ";
	cin >> Name; // 입력한 이름 호출

	while (true) // 2번 누르기 전까지 반복, 1번 누르면 상시 확인 가능
	{
		int number; // 여기서만 쓸 함수
		cout << "1. 상태보기 2. 종료\n"; 
		cin >> number;

		if (number == 1) //1을 누를 경우 위에 선언했던 프린트창 호출
		{
			print();
		}

		else if (number == 2) //2번 입력시 종료
		{
			break;
		}
	}

	return 0; // 끝
}