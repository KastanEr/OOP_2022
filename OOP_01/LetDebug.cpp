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

		�� �ڵ忡�� short �ڷ����� ���� ǥ�� ������ -2^15 ~ 2^15 - 1 ��, -32,768 ~ 32,767 ���� �̹Ƿ�
		s3 = s1 + s2, s3 = 32767 + 1 �� �� ��쿡 �����÷ο찡 �߻��� s3�� ���� -32768�� �ȴ�
		�̸� �ذ��ϱ� ���ؼ� s3 �� �ڷ����� int �� �ٲپ��ָ� �ȴ�
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