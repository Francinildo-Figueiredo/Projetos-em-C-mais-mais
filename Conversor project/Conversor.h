#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
using std::string;

class Conversor
{
	public:
		Conversor( unsigned long long = 0, long long = 0, string = "0", string = "0");
		
		bool setDecimal( unsigned long long );
		bool setBinary( long long );
		bool setOctal( string );
		bool setHexadecimal( string );
		
		unsigned long long getDecimal() const;
		long long getBinary() const;
		string getOctal() const;
		string getHexadecimal() const;
		
		long long convertDecimaltoBinary() const;
		unsigned long long convertBinarytoDecimal() const;
		string convertDecimaltoOctal() const;
		unsigned long long convertOctaltoDecimal() const;
		string convertDecimaltoHexa() const;
		unsigned long long convertHexatoDecimal() const;
		
	private:
		unsigned long long decimal;
		long long binary;
		string octal;
		string hexadecimal;
		
};

#endif
