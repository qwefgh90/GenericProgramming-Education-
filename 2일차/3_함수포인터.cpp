//3_�Լ�������
// 1. ����Լ��� ȣ����� : 1��° �Լ����ڷ� ��ü�� �ּҰ� ���޵Ǵ� ��
// 
class Point
{
	int x, y;
public:
	void Set(int a, int b)	//void Set(Point* const this, int a, int b)
	{
		x = a;				//this->x = a;
		y = b;
	}
};

int main()
{
	Point p1, p2;
	p1.Set(10, 20);	// Set(&p1, 10, 20) ���� ������ �˴ϴ�.
}