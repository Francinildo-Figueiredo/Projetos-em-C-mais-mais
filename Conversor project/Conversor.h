#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
using std::string;

class Conversor
{
	public:
		Conversor( unsigned long long = 0, long long = 0, string = "0", string = "0");
		
		bool setDecimal( unsigned long long );
		bool setBinario( long long );
		bool setOctal( string );
		bool setHexadecimal( string );
		
		unsigned long long getDecimal() const;
		long long getBinario() const;
		string getOctal() const;
		string getHexadecimal() const;
		
		long long converteDecimalBinario() const;
		unsigned long long converteBinarioDecimal() const;
		string converteDecimalOctal() const;
		unsigned long long converteOctalDecimal() const;
		string converteDecimalHexa() const;
		unsigned long long converteHexaDecimal() const;
		
	private:
		unsigned long long decimal;
		long long binario;
		string octal;
		string hexadecimal;
		
};

#endif
