#include <fstream>
using namespace std;
int main()
{
	ifstream f("adunscad.in");
	int N, M;
	f >> N >> M;
	int a[M], i;
	char semn[M];
	for (i = 0; i < M; i++)
	{
		f >> a[i];
		semn[i] = '+';
	}
	f.close();
	ofstream g("adunscad.out");
	bool ok = 0;
	while (1)
	{
		int s = 0;
		for (i = 0; i < M; i++)
			if (semn[i] == '+')
				s += a[i];
			else
				s -= a[i];
		if (s == N)
		{
			ok = 1;
			break;
		}
		for (i = M-1; i >= 0 && semn[i] == '-'; i--);
		if (i < 0) break;
		semn[i] = '-';
		for (i++; i < M; i++) semn[i] = '+';
	}
	if (ok)
	{
		if (semn[0] == '-') g << semn[0];
		for (i = 0; i < M-1; i++)
			g << a[i] << semn[i+1];
		g << a[i];
	}
	else g << 0;
	g.close();
	return 0;
}

