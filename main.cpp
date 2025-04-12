#include "class.hpp"  //kehgjjhdfjdjfsdjfdjhjhhj
#define J 100000
void test1(){
	srand(time(NULL));
	CRat a;
	int a1;
	int a2;
//	#pragma omp  parallel for
	for(int i = 0; i < J; i++){
			a1 = (rand() % 100) + 1;
			//if(a1 == 0) a1++;
			a2 = (rand() % 100) + 1;
			//if(a2 == 0) a2++;
			a.InPut(a1,a2);
		
		}
	CRat b;
	int b1;
	int b2;
//	#pragma omp parallel for
	for(int i = 0; i < J; i++){
			b1 = (rand() % 100) + 1;
			//if(b1 ==  0) b1++;
			b2 = (rand() % 100) + 1;
			//if(b2 == 0) b2++;
			b.InPut(b1,b2);
		
		}
	CRat c;
	CRat e;
	double d;
	double f;
//	d = a * b;
//	f = a % b;
//	cout << d << "\n";
//	cout << f<<"\n\n\n";
	int t1,t2;
	cout << "+\n";
	t1 = clock();
	c = a + b;
	t2 = clock();
	cout <<"TIME: " <<(double)(t2 - t1)/CLOCKS_PER_SEC << endl << endl; 

	t1 = clock();
	e = a & b;
	t2 = clock();
	cout <<"TIME_OMP: " <<(double)(t2 - t1)/CLOCKS_PER_SEC << endl << endl; 


	cout << "*\n";
	t1 = clock();
	d = a * b;//
	t2 = clock();
	cout <<"TIME: " <<(double)(t2 - t1)/CLOCKS_PER_SEC << endl << endl; 
	cout <<"d = " <<d << "\n";
	t1 = clock();
	f = a % b;
	t2 = clock();
	cout <<"TIME_OMP: " <<(double)(t2 - t1)/CLOCKS_PER_SEC << endl << endl; 
//	cout <<"d = "<<d << "\n";
	cout <<"f = "<<f;
}
void test2(){
     string InFile;
	 string OutFile;
     vector<CRat*> rat;
	 vector<CFabricRat*> fab;
	 fab.push_back(new CFabricRat1); fab.push_back(new CFabricRat2);


     cout << "Enter the name of Input file: ";
     cin >> InFile;
     CRat::Input(InFile, rat, fab);
     for (size_t i = 0; i < rat.size(); i++){
         rat[i] -> Output();
	//	 cout << *rat[i];
     } 
    for (size_t i = 0; i < rat.size(); i++) delete rat[i];
	 for (vector <CFabricRat*> :: iterator it = fab.begin();  it < fab.end(); ++it) delete *it;
}


int main(void){

    //  test2();
      test1();
     return 0;
}

