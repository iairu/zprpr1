#include <stdio.h>

int main() {
	int n,i;
	int vzostupne = 1;
	int zostupne = 1;
	int max_prvkov = 30;
	int pozicia_vkladu;
	double a[max_prvkov + 1];
	double vlozit;
	
	/* vstup a kontrola vstupu */
	scanf("%d",&n);
	if (!(n > 1 && n <= max_prvkov)) {
		return 0;
	}
	for(i=0;i<n;i++) {
		scanf("%lf",&a[i]);
	}
	scanf("%lf",&vlozit);
	
	/* zistuje usporiadanie postupnosti */
	for(i=0;i<n-1;i++) {
		if (a[i] < a[i+1]) {
			zostupne = 0;
		}
		else if (a[i] > a[i+1]) {
			vzostupne = 0;
		}
	}
	
	/* vlozi prvok "vlozit" do postupnosti ak je v nej miesto */ 
	if (n != max_prvkov) {
		/* v neusporiadanom poli na koniec */
		if (zostupne == 0 && vzostupne == 0) {
			n++;
			a[n-1] = vlozit;
		}
		/* v usporiadanom treba posunut prvky pola */
		else {
			for (i=0;i<n-1;i++){
				if ((vzostupne && (vlozit >= a[i]) && (vlozit <= a[i+1])) || 
					(zostupne && (vlozit >= a[i+1]) && (vlozit <= a[i])))
					pozicia_vkladu = i+1;
			}
			n++;
			for (i=n;i>pozicia_vkladu;i--){
				a[i] = a[i-1];
			}
			a[pozicia_vkladu] = vlozit;
		}
	}
	
	/* vystup */
	if (zostupne)
		printf("Postupnost je usporiadana zostupne\n");
	else if (vzostupne)
		printf("Postupnost je usporiadana vzostupne\n");
	else if (zostupne == 0 && vzostupne == 0)
		printf("Postupnost nie je usporiadana\n");
	for (i=0;i<n;i++){
		(i != n-1) ? printf("%g ", a[i]) : printf("%g\n", a[i]);
	}
	
    return 0;
}
