#include <iostream>

class LetDebug
{
public:
	void printNum()
	{
		/*
		short s1 = 32767;
		short s2 = 1;
		short s3 = (short)s1 + s2;
		std::cout << s3 << std::endl;

		위 코드에서 short 자료형의 정수 표현 범위는 -2^15 ~ 2^15 - 1 즉, -32,768 ~ 32,767 까지 이므로
		s3 = s1 + s2, s3 = 32767 + 1 을 할 경우에 오버플로우가 발생해 s3의 값이 -32768이 된다
		이를 해결하기 위해서 s3 의 자료형을 int 로 바꾸어주면 된다
		*/

		short s1 = 32767;
		short s2 = 1;
		int s3 = s1 + s2;
		std::cout << s3 << std::endl;
	}
};

int main()
{
	LetDebug* ld = new LetDebug;
	ld->printNum();
	return 0;
}