#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>

int main() {
	srand(time(0));

	//Genererer random størrelse på M og N (mellem 1 og 100)
    int M = rand() % 100 + 1;
	std::cout << "Size of M: " << M << std::endl;
	int N = rand() % 100 + 1;
    std::cout << "Size of N: " << N << std::endl;
	std::cout << std::endl;
	
    // Tilføjer M antal integers til vektor v
    std::vector<int> v;
    std::cout << "Numbers in M: ";
    for (int i = 0; i < M; i++) {
		v.push_back(rand() % 100 + 1);
		std::cout << v[i] << " ";
	}
    std::cout << std::endl;
	std::cout << std::endl;

	// Et set er valgt til at indeholde N tal fordi at opgaven ikke specificerer at vektore/arrays skal anvendes til at holde N's mængde af tal.
	// Der bliver stadig genereret N tilfældige tal i nedenstående for loop, men kun unikke gemmes.
	// Dette er valgt fordi det både er plads- og tidsbesparende.
	// Vi har fortolket opgaven således, at vi kun leder efter hvor mange af de forskellige tal som N indeholder også er i M.
	// Altså, vil vi ikke tælle det samme tal to gange

	// Tilføjer N antal integers til set s ()
	std::set<int> s;
    std::cout << "Numbers in N: ";
	for (int i = 0; i < N; i++){
		int toAdd = rand() % 100 + 1;

		// Der genereres N mængde af tal, men det er kun relevant for os at gemme unikke værdier, da det er dem som skal sammenlignes
		s.insert(toAdd); 

        std::cout << toAdd << " ";
	} 
    std::cout << std::endl;
	std::cout << std::endl;

	std::set<int> counter;

	std::vector<int>::iterator it = v.begin(); // 1
	while (it != v.end()) { // M
		// find er valgt over for loop da find er O(log n) og for loop er O(n)
		if (s.find(*it) != s.end()) counter.insert(*it); // log(N) + 1 + log(min(M,N))
		
        ++it; // 1
	}
    
	std::cout << "Same numbers in N and M: " << counter.size() << std::endl; // 1

	// M * (log(N) + 1 + 1) + 1 + 1

	return 0;
}