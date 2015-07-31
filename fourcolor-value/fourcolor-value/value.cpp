const int MAXN = 75, MAXM = 500;
const int MAXSH = 1000000, MAXSP = 10;

int H[MAXN], P[MAXM], E[MAXM], Ec;
int U, V, W, S[MAXM];
int G, F;

struct Backup
{
	int turn;
	int* p;
	int val;
};
Backup Rec[800];
int top;

int C[MAXN], NC[MAXN], OC[10];
int Turn, Alive, Bomb;

int Q[MAXN], U0;
int SearchCount, MaxStep;
int turn;
int First(int t)
{
	return (t & 1) ? -1 : 1;
}

int VALUE()
{
	int score = 0;
	const double around = 0.8;
	const double outer = 0.5;
	const double usebomb = 0.5;
	const double takeblank = 0.2;
	for (int i = 1; i <= U; ++i)
	{
		if (C[i] != -1)
		{
			score += S[i] * First(C[i]);
			bool counted[MAXN] = {0};
			counted[i] = true;
			for (int j = H[i]; j != 0; j = P[j])
			{
				int e = E[j];
				counted[e] = true;
				score -= S[e] * First(C[i]) * around;
			}
			for (int j = H[i]; j != 0; j = P[j])
			{
				for (int k = H[i]; k != 0; k = P[k])
				{
					int e2 = E[k];
					if((!counted[e2]) && e2 <= U && C[i] == -1) score += S[i] * First(C[i]) * outer;
				}
			}
		}
	}
	for (int i = U + 1; i <= V; ++i)
	{
		if (OC[i - U] > 0) score += S[i];
		if (OC[i - U] < 0) score -= S[i];
	}
	for (int i = V + 1; i <= W; ++i)
	{
		if (C[i] != -1) score += S[i] * First(C[i]);
	}
	int blank = 0;
	int total = 0;
	for(int i = 1; i <= U; ++i)
	{
		if(C[i] == -1) blank += S[i]; 
		total += S[i];
	}
	if(Bomb & 1 && !(Bomb & 2)) score += (total - blank) * usebomb;
	if(!(Bomb & 1) && Bomb & 2) score -= (total - blank) * usebomb;
	if(turn == 1 || turn == 3) score -= blank * takeblank;
	else score += blank * takeblank;
	return score;
} 

