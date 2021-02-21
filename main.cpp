#include"Header.h"
int main()
{
	int Lenh = 0;
	while (Lenh != 4)
	{
		Lenh = fSelectCommand(fMainMenu());
		fRunMainMenu(Lenh);
	}
}