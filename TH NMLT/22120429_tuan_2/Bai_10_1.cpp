//Method 1. Use for loop
    //1. S(n) = 1 + 2 + 3 + ... + n
	//2. S(n) = 1^2 + 2^2 +3^2 + ... + n^2
	//3. S(n) = 1⁄2 + 1⁄4 + 1/6 + ... + 1/2n
	//4. S(n) = 1/(1*2) + 1/(2*3) + ... + 1/(n*(n+1))
	//5. S(n) = 1⁄2 + 2/3 + 3⁄4 + ... + n/(n+1)
	//6. S(n)=1/2+2/3+3/4+⋯+(2n+1)/(2n+2)
	//7. S(x,n) = x2 + x4 + ... + x2n, với x là số thực, n nguyên dương

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float x;
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter x: ";
	cin >> x;

	//1. S(n) = 1 + 2 + 3 + ... + n
	int sum1 = 0;
	for (int i = 1; i <= n; i++){
		sum1 += i;
	}
	cout << "1. S(" << n << ")" << " = " << sum1 << endl;

	//2. S(n) = 1^2 + 2^2 +3^2 + ... + n^2
	int sum2 = 0;
	for (int i = 1; i <= n; i++){
		sum2 += i * i;
	}
	cout << "2. S(" << n << ")" << " = " << sum2 << endl;

	//3. S(n) = 1⁄2 + 1⁄4 + 1/6 + ... + 1/2n
	float sum3 = 0;
	for (int i = 1; i <= n; i++) {
		sum3 += 1.0 /  (2 * i);
	}
	cout << "3. S(" << n << ")" << " = " << sum3 << endl;

	//4. S(n) = 1/(1*2) + 1/(2*3) + ... + 1/(n*(n+1))
	float sum4 = 0;
	for (int i = 1; i <= n; i++){
		sum4 += 1.0 / (i * (i + 1));
	}
	cout << "4. S(" << n << ")" << " = " << sum4 << endl;

	//5. S(n) = 1⁄2 + 2/3 + 3⁄4 + ... + n/(n+1)
	float sum5 = 0;
	for (int i = 1; i <= n; i++){
		sum5 += (float)i / (i + 1);
	}
	cout << "5. S(" << n << ")" << " = " << sum5 << endl;

	//6. S(n)=1/2+2/3+3/4+⋯+(2n+1)/(2n+2)
	float sum6 = 0;
	for (int i = 1; i <= n; i++){
		sum6 += (2.0 * i + 1)/( 2 * i + 2);
	}
	cout << "6. S(" << n <<")" << " = " << sum6 << endl;

	//7. S(x,n) = x^2 + x^4 + ... + x^2n, với x là số thực, n nguyên dương
	float sum7 = 0;
	for (int i = 1; i <= n; i++){
		sum7 += pow(x, 2 * n);
	}
	cout << "7. S(" << n << ")" << " = " << sum7 << endl;

	return 0;
}