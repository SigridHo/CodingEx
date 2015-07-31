#include <iostream>
#include <bitset>
using namespace std;
int nGoalStatus;  
bitset<387420498> Flags;
char szResult[400000];   
char szMoves[400000]; 
int anFather[400000]; 
int MyQueue[400000]; 
int nQHead; 
int nQTail;
char sz4Moves[] = "udrl";
int NineToTen( char * s ) {


	int nResult = 0;
	for( int i = 0; s[i]; i ++ ) {
		nResult *= 9;
		nResult += s[i] - '0';
	}
	return nResult;
}
int TenToNine( int n, char * s) {
	int nZeroPos;
	int nBase = 1;
	int j = 0;
	while( nBase <= n) 
		nBase *= 9;
	nBase /= 9;
	do {
		s[j] = n/nBase + '0';
		if( s[j] == '0' )
			nZeroPos = j;
		j ++;
		n %= nBase;
		nBase /= 9;
	}while( nBase >= 1 );
	s[j] = 0;
	if( j < 9 ) {
		for( int i = j + 1; i > 0; i --)
			s[i] = s[i-1];
		s[0] = '0';
		return 0;
	}
	return nZeroPos;
}
int NewStatus( int nStatus, char cMove) {
	char szTmp[20];
	int nZeroPos = TenToNine(nStatus,szTmp);
	switch( cMove) {
		case 'u': if( nZeroPos - 3 < 0 )  return -1; 
			else {	szTmp[nZeroPos] = szTmp[nZeroPos - 3];
				szTmp[nZeroPos - 3] = '0';	}
			break;
		case 'd':	if( nZeroPos + 3 > 8 )  return -1;
			else {     szTmp[nZeroPos] = szTmp[nZeroPos + 3];
				szTmp[nZeroPos + 3] = '0';	}
			break;
		case 'l':	if( nZeroPos % 3 == 0)  return -1; 
			else {	szTmp[nZeroPos] = szTmp[nZeroPos -1];
				szTmp[nZeroPos -1 ] = '0';	}
			break;
		case 'r':	if( nZeroPos % 3 == 2)  return -1;
			else {	szTmp[nZeroPos] = szTmp[nZeroPos + 1];
				szTmp[nZeroPos + 1 ] = '0';	}
			break;
	}
	return NineToTen(szTmp);
}
bool Bfs(int nStatus){
	int nNewStatus;
	nQHead = 0;	nQTail = 1;
	MyQueue[nQHead] = nStatus;
	while ( nQHead != nQTail) { 
		nStatus = MyQueue[nQHead];
		if( nStatus == nGoalStatus ) 
			return true;
		for( int i = 0;i < 4;i ++ ) {
			nNewStatus = NewStatus(nStatus,sz4Moves[i]);	
			if( nNewStatus == -1 ) 	continue; 
			if( Flags[nNewStatus] )
			       continue; 
			Flags.set(nNewStatus,true); 
			MyQueue[nQTail] = nNewStatus; 
			anFather[nQTail] = nQHead; 
		

			szMoves[nQTail] = sz4Moves[i]; 
			nQTail ++;
		}
		nQHead ++; 
	}
	return false;	
}
int main(){
	nGoalStatus = NineToTen("123456780");
Flags.reset();
	char szLine[50];  char szLine2[20];
	cin.getline(szLine,48);
	int i,j;

	for( i = 0, j = 0; szLine[i]; i ++ ) {
		if( szLine[i] != ' ' ) {
			if( szLine[i] == 'x' )  szLine2[j++] = '0';
			else  szLine2[j++] = szLine[i];
		}
	}
	szLine2[j] = 0;
	if( Bfs(NineToTen(szLine2))) {
		int nMoves = 0;
		int nPos = nQHead;
		do { 
			szResult[nMoves++] = szMoves[nPos];
			nPos = anFather[nPos]; 
		} while( nPos);
		for( int i = nMoves -1; i >= 0; i -- ) 
			cout << szResult[i];
		cout << endl;
	}
	else
		cout << "unsolvable" << endl;
	system("pause");
	return 0;
}