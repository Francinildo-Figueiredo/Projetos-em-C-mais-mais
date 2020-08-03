#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <locale>

#include "../lib/Biblioteca.h"
#include "../src/Biblioteca.cpp"

int main()
{
	setlocale( LC_ALL, "portuguese");

	Biblioteca biblioteca;
	int sentinela1(0), sentinela2(0);
	
	while(sentinela1 == 0)
	{
		system("cls");
		if(biblioteca.login())
		{
			while(sentinela2 == 0)
			{
				system("cls");
				int escolha;
				wcout << L"1 - Cadastrar livro"
					<< L"\n2 - Cadastrar usuário"
					<< L"\n3 - Realizar empréstimo"
					<< L"\n4 - Pesquisar livro"
					<< L"\n5 - Pesquisar usuário"
					<< L"\n6 - Ver estoque"
					<< L"\n7 - Ver usuários"
					<< L"\n0 - Sair"
					<< L"\nEscolha uma das opções acima: ";
					cin >> escolha;
					system("cls");
					cin.ignore();
				
				switch(escolha)
				{
					case 1:
						biblioteca.cadastrarLivro();
						break;
					case 2:
						biblioteca.cadastrarUsuario();
						break;
					case 3:
						biblioteca.realizarEmprestimo();
						break;
					case 4:
						biblioteca.pesquisarLivro();
						system("pause");
						break;
					case 5:
						biblioteca.pesquisarUsuario();
						system("pause");
						break;
					case 6:
						biblioteca.verEstoque();
						break;
					case 7:
						biblioteca.verUsuarios();
						break;
					case 0:
						cout << "Saindo..." << endl;
						system("pause");
						sentinela2 = 1;
						sentinela1 = 1;
						break;
					default:
						wcout << L"Opção escolhida não existe!" << endl;
						system("pause");
						break;
				}
			}
		}
		else
		{
			char aux;
			cout << "Realizar cadastro?(s/n): ";
			cin >> aux;
			system("cls");
			if(aux == 's')
			{
				cin.ignore();
				biblioteca.cadastrarUsuario();
			}
			else
				sentinela1 = 1;
		}
	}
	

	return 0;
}
