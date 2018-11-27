#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

	float customer(int, int &, int, int &, int, int &, float &);
	void manager(int &, int &, int &, int &, int &, int &, float);
	void supplier(int &, int &, int &);
	float robber(float &);
	void bum(int, int &, int, int &, int, int &);

int main () {
	srand(time(0));
	
	char type;
	cout << "Who is approaching Mr. Miyagi?" << endl;
	cin >> type;
	
	int hashbrowns = 100;
	int cokes = 100;
	int machetes = 100;
	
	int total_money = 0;
	float cash = 0;	
	
	int hi = hashbrowns;
	int ci = cokes;
	int	mi = machetes;
	
	int hs = 0;
	int cs = 0;
	int ms = 0;
	
	int h = 0;
	int c = 0;
	int m = 0;
		
	while (type != 'Q') {
		if (type == 'C'){
			total_money = cash;
			customer(hi, hs, ci, cs, mi, ms, cash);
			cash += total_money;
		}
		
		if (type == 'M') {
			manager(hi, hs, ci, cs, mi, ms, cash);
		}
		
		if (type == 'S') {
			supplier(h, c, m);
			hi += h;
			ci += c;
			mi += m;
		}
		
		if (type == 'R') {
			robber(cash);
		}
		
		if (type == 'B') {
			bum(hi, hs, ci, cs, mi, ms);
		}
		
		cout << "Who is approaching Mr. Miyagi, now?" << endl;
		cin >> type;
	}
	return 0;
}

void manager(int & hinv, int & hsol, int & cinv, int & csol, int & minv, int & msol, float money) {
		cout << "             Hashbrowns     Coke       Machetes" << endl;
		cout << "Inventory    " << hinv <<	"            " <<	cinv << "        " << minv << endl;
		cout << "Sold         " << hsol << "              " << csol << "          " << msol << endl;
		cout << "Remaining    " << hinv-hsol << "            " << cinv-csol << "        " << minv-msol << endl;
		cout << endl;
		cout << "Total Money $" << money << endl;
		
		hinv -= hsol;
		cinv -= csol;
		minv -= msol;
		
		hsol = 0;
		csol = 0;
		msol = 0;
}
void supplier(int & hash_inv, int & coke_inv, int & mache_inv){
		int hash_supply;
		int coke_supply;
		int mache_supply;
		
		cout << "How many hashbrowns did the supplier bring to the store?" << endl;
		cin >> hash_supply;
		hash_inv += hash_supply;
		
		cout << "How many cokes did the supplier bring to the store?" << endl;
		cin >> coke_supply;
		coke_inv += coke_supply;
		
		cout << "How many machetes did the supplier bring to the store?" << endl;
		cin >> mache_supply;
		mache_inv += mache_supply;
}
float robber (float & stolen_money) {
	int original_amt = stolen_money;
	stolen_money = 0;
	return original_amt;
}
float customer(int hash_inv, int & hash_sold, int coke_inv, int & coke_sold, int mache_inv, int & mache_sold, float & bill) {
	int orig_hash_sold = hash_sold;
	int orig_coke_sold = coke_sold;
	int orig_mache_sold = mache_sold;
	
	hash_sold -= hash_inv;
	coke_sold -= coke_inv;
	mache_sold -= mache_inv;
	
	cout << "How many hashbrowns?" << endl;
	cin >> hash_sold;
	while (hash_sold>hash_inv){
		if (hash_sold>hash_inv || hash_sold < 0) {
			cout << " We don't have that many hashbrowns!!!" << endl;
			cout << "How many hashbrowns?" << endl;
			cin >> hash_sold;
		}
	}
	hash_sold += orig_hash_sold;	
	
	cout << "How many cokes?" << endl;
	cin >> coke_sold;
	while (coke_sold>coke_inv)	{
		if (coke_sold>coke_inv ||  hash_sold < 0) {
			cout << " We don't have that many cokes!!!" << endl;
			cout << "How many cokes?" << endl;
			cin >> coke_sold;
		}
	}
	coke_sold += orig_coke_sold;
	
	cout << "How many machetes?" << endl;
	cin >> mache_sold;
	while (mache_sold>mache_inv){
		if (mache_sold>mache_inv || mache_sold < 0) {
			cout << " We don't have that many machetes!!!" << endl;
			cout << "How many machetes?" << endl;
			cin >> mache_sold;
		}
	}
	mache_sold += orig_mache_sold;
	
	hash_inv -= hash_sold;
	float hash_bill = 13.27 * hash_sold;			
	
	coke_inv -= coke_sold;
	float coke_bill = 24.29 * coke_sold;
	
	mache_inv -= mache_sold;
	float machete_bill = 17.00 * mache_sold;
	
	bill = hash_bill + coke_bill + machete_bill;
	cout << "Your total bill comes to $" << bill << ". Thank you!" << endl;
}
void bum(int hash_inv, int & hash_sold, int coke_inv, int & coke_sold, int mache_inv, int & mache_sold){
	int orig_hash_sold = hash_sold;
	int orig_coke_sold = coke_sold;
	int orig_mache_sold = mache_sold;
	
	hash_sold = 3 + rand() % (17-3+1);
	if (hash_sold>hash_inv || hash_sold <= 0){
		hash_sold = hash_inv;
	}
	hash_sold += orig_hash_sold;
	hash_inv -= hash_sold;
	
	coke_sold = 2 + rand() % (9-2+1);
	if (coke_sold>coke_inv || coke_sold <= 0){
		coke_sold = coke_inv;
	}
	coke_sold += orig_coke_sold;
	coke_inv -= coke_sold;
	
	mache_sold = 4 + rand() % (7-4+1);
	if (mache_sold>mache_inv || mache_sold <=0){
		mache_sold = mache_inv;
	}
	mache_sold += orig_mache_sold;
	mache_inv -= mache_sold;
}