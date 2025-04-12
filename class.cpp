#include "class.hpp"
#include <omp.h> //usdfjsgfjhgsdfhjsg
int gcd(int a, int b){
    a = fabs(a);
    b = fabs(b);
    while (a != 0 && b != 0){
        if (a > b)a = a % b;
        else b = b % a;
    }
    return (a + b);
} 


CRat CRat::operator+(const CRat& b){
    CRat rez(b);
        rez = *this;
        if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }
        else {
        for (int i = 0; i < b.len; i++){
            rez.denominator[i] = b.denominator[i] * this->denominator[i];
            rez.numerator[i] = b.numerator[i] * this->denominator[i] + this->numerator[i] * b.denominator[i];
        }
        }
 
    rez.reduction();
    return rez;
}
CRat CRat::operator-(const CRat& b){
    CRat rez(b);
    rez = *this;
    if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }

     else {
     		 for (int i = 0; i < b.len; i++){
            rez.denominator[i] = b.denominator[i] * this->denominator[i];
            rez.numerator[i] = -b.numerator[i] * this->denominator[i] + this->numerator[i] * b.denominator[i]; }
            rez.reduction(); }
            return rez;
        
}

double CRat::operator*(const CRat& b){
    double rez = 0.;
    /*  if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }*/

  //  else {
    for (int i = 0; i < len; i++) rez = rez + (((double)numerator[i] * (double)b.numerator[i]) / ((double)denominator[i] *(double)b.denominator[i]));
  //  	}    
    return rez;
    
}

void CRat::reduction(){
    int nod;
    for (int i = 0; i < this->len; i++){
        nod = gcd(this->numerator[i], this->denominator[i]);
        this->numerator[i] /= nod;
        this->denominator[i] /= nod;
    }
} 

void CRat::Input(string& filename,vector<CRat*>&rat,vector<CFabricRat*> &fab){
    int CRNo;
    int num;
	string File;
    string str;
    ifstream file(filename);
    while (getline(file, str)){
        stringstream line(str); 
        line>>CRNo>>File;
		fstream f(File,std::ios::out);
		f.close();
		 CRat* w = fab[CRNo - 1]->Create();
        if(CRNo<=0 || CRNo > static_cast<int>(fab.size())) {
			cout<<"error \n";
			break;}
			w->SetName(File);
			    while(line>>num){
                    w->numerator.push_back(num);
                    line>>num;
                    w->denominator.push_back(num);
                }
                w->SetLen(w->numerator.size());
		        w->reduction();
                rat.push_back(w);

          }
    file.close();
}

void CRat::reduction1(){
    int nod;
#pragma omp parallel for private(nod)
    for (int i = 0; i < this->len; i++){
        nod = gcd(this->numerator[i], this->denominator[i]);
        this->numerator[i] /= nod;
        this->denominator[i] /= nod;
    }
}

CRat CRat::operator&(const CRat& b){//+
    CRat rez(b);
        rez = *this;
        if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }
        else {
#pragma omp parallel for
        for (int i = 0; i < b.len; i++){
            rez.denominator[i] = b.denominator[i] * this->denominator[i];
            rez.numerator[i] = b.numerator[i] * this->denominator[i] + this->numerator[i] * b.denominator[i];
        }
        }
 
    rez.reduction1();
    return rez;
}
CRat CRat::operator/(const CRat& b){//-
    CRat rez(b);
    rez = *this;
    if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }

     else {
#pragma omp parallel for
     		 for (int i = 0; i < b.len; i++){
            rez.denominator[i] = b.denominator[i] * this->denominator[i];
            rez.numerator[i] = -b.numerator[i] * this->denominator[i] + this->numerator[i] * b.denominator[i]; }
            rez.reduction1(); }
            return rez;
        
}

double CRat::operator%(const CRat& b){//*
    double rez = 0.0;
//	double rez1 = 0.0;
    if(b.len != this -> len) {
        	cout << "Error";
        	return -1;
        }

    else {
#pragma omp parallel for reduction(+ : rez)
    for (int i = 0; i < len; i++) rez = rez + (((double)numerator[i] * (double)b.numerator[i]) / ((double)denominator[i] *(double)b.denominator[i]));
    	}    
    return rez;
/*	#pragma omp parallel sections
{
#pragma omp section
	{
    for (int i = 0; i < len/2; i++) rez = rez + (((double)numerator[i] * (double)b.numerator[i]) / ((double)denominator[i] *(double)b.denominator[i]));
    	}    

#pragma omp section
	{
for (int i = (len/2)+1; i < len; i++) rez1 = rez1 + (((double)numerator[i] * (double)b.numerator[i]) / ((double)denominator[i] *(double)b.denominator[i]));
    	} 
}
    
}
return rez + rez1; */
}



ostream& operator <<(ostream& cout, const CRat& b){
    for (int i = 0; i < b.len; i++){
        cout << "(" << b.numerator[i] << "/" << b.denominator[i] << ")";
    }
    cout << " \n";
    return cout;
}
void CRat1::Output(string& filename){
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()){
	out << "CRat1: " << '\n';
        for (int i = 0; i < len; i++){
            out << " (" << numerator[i] << "/" << denominator[i] << ")";
        }
        out << '\n';
    }
    out.close();
}

void CRat2::Output(string& filename){
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()){ 
     out << "CRat2: "<< '\n';
        for (int i = 0; i < len; i++){
            out << " {" << numerator[i] << "/" << denominator[i] << "}";
            if(i + 1 != len) out << '\n';
        }
        out << '\n';
   }
    out.close();
}

 void CRat::Output(string& filename){
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()){
        out << "CRats Output\n";
    }
    out.close();
}
