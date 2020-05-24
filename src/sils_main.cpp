#include <iostream>
#include <Eigen>

using namespace std;
using namespace Eigen;

int main()
{

	Matrix3f A; 
	Vector3f b;
	A << 1,2,3,  4,5,6,  7,8,10;
	b << 3, 3, 4;
	cout << "Here is the matrix A:\n" << A << endl;
	cout << "Here is the vector b:\n" << b << endl;

	Vector3f x1 = A.partialPivLu().solve(b);       
	Vector3f x2 = A.fullPivLu().solve(b);            
	Vector3f x3 = A.householderQr().solve(b); 

	Vector3f x4 = A.colPivHouseholderQr().solve(b);  
	cout << "The solution (colPivHouseholderQr) is:\n" << x4 << endl;
	Vector3f x5 = A.fullPivHouseholderQr().solve(b); 
	Vector3f x6 = A.llt().solve(b);		
	Vector3f x7 = A.ldlt().solve(b);		
	cout << "The solution (partialPivLu) is:\n" << x1 << endl;
	cout << "The solution (fullPivLu) is:\n" << x2 << endl;
	cout << "The solution (householderQr) is:\n" << x3 << endl;
	cout << "The solution (fullPivHouseholderQr) is:\n" << x5 << endl;
	cout << "The solution (llt) is:\n" << x6 << endl;
	cout << "The solution (ldlt) is:\n" << x7 << endl;

}