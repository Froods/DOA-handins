#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>

int main() {
	srand(time(0));

	//Genererer random størrelse på M (mellem 1)
    int M = 10;
	std::cout << "Size of M: " << M << std::endl;
	

    //Tilføjer M antal integers til vektor v
    std::vector<int> v;
    std::cout << "Numbers in M: ";
    for (int i = 0; i < M; i++) {
		v.push_back(rand() % 100 + 1);
		std::cout << v[i] << " ";
	}
    std::cout << std::endl;

    int N = 5;
    std::cout << "Size of N: " << N << std::endl;

	std::set<int> s;
    std::cout << "Numbers in N: ";
	for (int i = 0; i < N; i++){
		int toAdd = rand() % 100 + 1;
		s.insert(toAdd); // Der genereres N mængde af tal, men det er kun relevant for os at gemme unikke værdier, da det er dem som skal sammenlignes
        std::cout << toAdd << " ";
	} 
    std::cout << std::endl;

	std::set<int> counter;

	std::vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		if (s.find(*it) != s.end()) counter.insert(*it); // find er valgt over for loop da find er O(log n) og for loop er O(n)
		
        ++it;
	}
    
	std::cout << "Same numbers in N and M: " << counter.size() << std::endl;
}