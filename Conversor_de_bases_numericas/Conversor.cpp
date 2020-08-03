#include "Conversor.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;
using std::stoi;

#include <cmath>
using std::pow;

#include <cctype>
using std::isdigit;

Conversor::Conversor( unsigned long long d, long long b, string oct, string hd )
{
	setDecimal( d );
	setBinary( b );
	setOctal( oct );
	setHexadecimal( hd );
}

bool Conversor::setDecimal( unsigned long long d )
{
	bool verificador = true;
	
	if ( d >= 0 )
	{
		decimal = d;
	}
	else
		verificador = false;
	
	return verificador;
}

bool Conversor::setBinary( long long b )
{
	long long aux = b;
	
	while ( aux != 0 )
	{
		if ( aux % 10 == 1 || aux % 10 == 0 )
		{
			aux /= 10;
		}
		else
		{
			aux = 0;
			b = 0;
			cout << "O número digitado não esta em binário!" << endl;
			return false;
		}
	}
	
	if ( aux == 0 && b != 0 )
		binary = b;
	else
		binary = 0;
	
	return true;
}

bool Conversor::setOctal( string oct )
{
	bool verificador = true;
	
	if ( oct.size() < 22 || oct[0] >= '0' && oct[0] < '2' )
	{
		for ( size_t i = 0; i < oct.size(); i++ )
		{
			if ( oct[i] >= '0' && oct[i] <= '7' )
				octal = oct;
			else
			{
				verificador = false;
				cout << "O número digitado não está em octal!\n" << endl;
			}
		}
	}
	else
	{
		cout << "O octal digitado não esta na faixa de 0 - 777777777777777777777!\n" << endl;
		verificador = false;
	}
	
	return verificador;
}

bool Conversor::setHexadecimal( string hexd )
{
	if ( hexd.size() <= 16 )
	{
		for ( size_t i = 0; i < hexd.size(); i++ )
		{
			hexd[i] = toupper( hexd[i] );
		}
		
		for ( size_t i = 0; i < hexd.size(); i++ )
		{
			if ( ( hexd[i] >= 'A' && hexd[i] <= 'F' ) || isdigit( hexd[i] ) )
			{
				hexadecimal = hexd;
			}
			else
			{
				cout << "O número digitado não esta em hexadecimal!\n" << endl;
				return false;
			}
		}
		return true;
	}
	else
	{
		cout << "O hexadecimal digitado não esta na faixa de 0 - FFFFFFFFFFFFFFFF!" << endl;
		return false;
	}
}

unsigned long long Conversor::getDecimal() const
{
	return decimal;
}

long long Conversor::getBinary() const
{
	return binary;
}

string Conversor::getOctal() const
{
	return octal;
}

string Conversor::getHexadecimal() const
{
	return hexadecimal;
}

long long Conversor::convertDecimaltoBinary() const
{
	unsigned long long aux = getDecimal();
	int resto = 0;
	int i = 0;
	long long bin = 0;
	
	if ( aux <= 65535 )
	{
		while ( aux != 0 )
		{
			resto = aux % 2;
			bin += resto * pow( 10, i );
			i++;
			aux /= 2;
		}
	}
	
	return bin;
}

unsigned long long Conversor::convertBinarytoDecimal() const
{
	long long aux = getBinary();
	unsigned long long decimalNumber = 0;
	int i = 0;
	
	while ( aux != 0 )
	{
		decimalNumber += ( aux % 10 ) * pow( 2, i );
		i++;
		aux /= 10; 
	}
	
	return decimalNumber;
}

string Conversor::convertDecimaltoOctal() const
{
	unsigned long long aux = getDecimal();
	size_t count = 0;
	
	while ( aux != 0 )
	{
		aux /= 8;
		count++;
	}
	
	int *numbers = new int[ count ];
	aux = getDecimal();
	
	if ( aux == 0 )
		return "0";
	
	for ( size_t i = count - 1; aux != 0; i-- )
	{
		numbers[i] = aux % 8;
		aux /= 8;
	}
	
	string oct;
	
	for ( size_t i = 0; i < count; i++ )
	{
		oct.append( to_string( numbers[i] ) );
	}
	
	delete [] numbers;
	
	return oct;
}

unsigned long long Conversor::convertOctaltoDecimal() const
{
	string oct = getOctal();
	int size = getOctal().size();
	
	string *aux = new string[size];
	
	unsigned long long number = 0;
	int p = size - 1;
	
	for ( size_t i = 0; i < size; i++ )
	{
		aux[i] = oct[i];
	}
	
	for ( size_t i = 0; i < size; i++ )
	{
		number += stoi( aux[i] ) * pow( 8, p);
		p--;
	}
	
	delete [] aux;
	
	return number;
}

string Conversor::convertDecimaltoHexa() const
{
	unsigned long long aux = getDecimal();
	size_t count = 0;
	
	while ( aux != 0 )
	{
		aux /= 16;
		count++;
	}
	
	int *numbers = new int[ count ];
	aux = getDecimal();
	
	for ( size_t i = count - 1; aux != 0; i-- )
	{
		numbers[i] = aux % 16;
		aux /= 16;
	}
	
	string hexadecimal;
	
	for ( size_t i = 0; i < count; i++ )
	{
		if ( numbers[i] > 9 )
		{
			switch( numbers[i] )
			{
				case 10:
					hexadecimal.append( "A" );
					break;
				
				case 11:
					hexadecimal.append( "B" );
					break;
				
				case 12:
					hexadecimal.append( "C" );
					break;
				
				case 13:
					hexadecimal.append( "D" );
					break;
				
				case 14:
					hexadecimal.append( "E" );
					break;
				
				case 15:
					hexadecimal.append( "F" );
					break;
				
				default:
					break;
			}
		}
		else
			hexadecimal.append( to_string( numbers[i] ) );
	}
	
	delete [] numbers;
	
	return hexadecimal;
}

unsigned long long Conversor::convertHexatoDecimal() const
{
	string hexad = getHexadecimal();
	int size = getHexadecimal().size();
	string *aux = new string[ size ];
	int *numbers = new int[ size ];
	
	for ( size_t i = 0; i < size; i++ )
	{
		switch( hexad[i] )
		{
			case 'A':
				aux[i] = "10";
				break;
				
			case 'B':
				aux[i] = "11";
				break;
				
			case 'C':
				aux[i] = "12";
				break;
				
			case 'D':
				aux[i] = "13";
				break;
				
			case 'E':
				aux[i] = "14";
				break;
				
			case 'F':
				aux[i] = "15";
				break;
			
			default:
				break;
				
		}
			
		if ( isdigit( hexad[i] ) )
			aux[i] = hexad[i];
	}
	
	int p = size - 1;
	
	cout << "Calculo: ";
	for ( size_t i = 0; i < size; i++ )
	{
		cout << aux[i] << "x16^" << p << " + ";
		p--;
	}
	cout << '0' << endl << endl;
	
	for ( size_t i = 0; i < size; i++ )
	{
		numbers[i] = stoi( aux[i] );
	}
	
	delete [] aux;
	
	unsigned long long number = 0;
	p = size - 1;
	
	for ( size_t i = 0; i < size; i++ )
	{
		number += numbers[i] * pow(16, p);
		p--;
	}
	
	delete [] numbers;
	
	if ( hexad == "FFFFFFFFFFFFFFFF" )
		return 18446744073709551615;
	else
		return number;
}
