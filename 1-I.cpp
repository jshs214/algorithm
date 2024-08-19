#include <bits/stdc++.h>

using namespace std;

int n, m;

map<int, string> poketmon;
map<string, int> s_poketmon;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//도감 채우기
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		poketmon.insert( {i, s} );
		s_poketmon.insert({ s, i });
		//poketmon[i] = s;
		//s_poketmon[s] = i;
	}
	
	//입력
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;

		if (atoi(s.c_str()) == 0)
			cout << s_poketmon[s] << "\n";
		else
			cout << poketmon[atoi(s.c_str())] << "\n";

	}

	return 0;
}


//26 5
//Bulbasaur
//Ivysaur
//Venusaur
//Charmander
//Charmeleon
//Charizard
//Squirtle
//Wartortle
//Blastoise
//Caterpie
//Metapod
//Butterfree
//Weedle
//Kakuna
//Beedrill
//Pidgey
//Pidgeotto
//Pidgeot
//Rattata
//Raticate
//Spearow
//Fearow
//Ekans
//Arbok
//Pikachu
//Raichu
// 
//25
//Raichu
//3
//Pidgey
//Kakuna