#include <iostream>
#include <string>

using namespace std;

class Data {
    public:
        Data();
		Data(int d, int m, int a);
        int dia, mes, ano;
        string toString();
};

Data::Data() {    
} 

Data::Data(int d, int m, int a) : dia(d), mes(m), ano(a) {    
}

string Data::toString() {
    char str[100];

    sprintf( str, " %d/%d/%d ", dia, mes, ano );
    return( str );
}

class Pessoa {
	protected:
		string nome;
		int identidade;
		Data nascimento;

	public:
		Pessoa(string n, int i, Data d);
		string toString();
};

Pessoa::Pessoa(string n, int i, Data d) {
	nome = n;
	identidade = i;
	nascimento = d;
}

string Pessoa::toString() {
	char texto[100];

	sprintf( texto, " id: %d ", identidade );
	return( "Nome: " + nome + texto + nascimento.toString() );
}

class Funcionario : public Pessoa {
	protected:
		Data admissao;
		float salario;

	public:
		Funcionario(string nome, int id, Data nasc, Data adm, float sal);
		string toString();
};

Funcionario::Funcionario ( string n, int id, Data nasc, Data adm, float sal ): Pessoa(n, id, nasc ) {
	admissao = adm;
	salario = sal;
}

string Funcionario::toString() {
	char texto[100];
	
    sprintf( texto, " sal: %f", salario );
    return( Pessoa::toString() + admissao.toString() + texto );
}

class Chefe : public Funcionario {
	private:
		string departamento;
		Data promocao;

	public:
		Chefe(string nome, int id, Data nasc, Data adm, float sal, string dep, Data prom);
		string toString();
};

Chefe::Chefe(string nome, int id, Data nasc, Data adm, float sal, string dep, Data prom) : 
 Funcionario(nome, id, nasc, adm, sal) {
	departamento = dep;
	promocao = prom;
}

string Chefe::toString() {
	
 	return( Funcionario::toString() + 
	        "\nDepartamento: " + departamento + 
			"\nPromocao: " + promocao.toString() );
}

int main (void)
{
	Data d1 = Data( 01,11,1990 );
	Data d2 = Data( 05,12,1980 );
	Data d3 = Data( 01,05,1970 );

	Pessoa p1 = Pessoa( "Tiago", 111111, d1 );
	Funcionario f1 = Funcionario( "Mateus", 111112, d1, d2, 1000.0 );
	Chefe c1 = Chefe( "Rodrigo", 111113, d3, d2, 1000.0, "DCE", d1 );

	cout << p1.toString() << endl;
	cout << f1.toString() << endl;
	cout << c1.toString() << endl;
}