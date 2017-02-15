#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  


using namespace std;
vector<int> usedTags;

class Videojuego
{
protected:
	string a;
	string b;
	string c;
	string name;
	float price;
public:
	Videojuego ()
	{
		a="primer atributo";
		b="segundo atributo";
		c="tercer atributo";
	}
	template <class VJ>
	Videojuego* clone()
	{
        return new VJ(dynamic_cast <VJ&>(*this));
	}
	float getPrice()
	{
		return price;
	}
	void setPrice(float _price)
	{
		price = _price;
	}
	string getName()
	{
		return name;
	}
	virtual void Concepcion()=0;
	virtual void Diseno ()=0;
	virtual void Planificacion ()=0;
	virtual void Produccion ()=0;
	virtual void Prueba ()=0;
};
class Estrategia : public Videojuego
{
public:
	Estrategia(string _name, float _price)
    {
    	name = _name;
    	price = _price;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Estrategia "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Estrategia "<<name<<endl;
	}
};
class Aventura : public Videojuego
{
public:
	Aventura(string _name, float _price)
    {
    	name = _name;
    	price = _price;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Aventura "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Aventura "<<name<<endl;
	}
};
class Aprendizaje : public Videojuego
{
public:
	Aprendizaje(string _name, float _price)
    {
    	name = _name;
    	price = _price;
    }
	virtual void Concepcion()
	{
		cout<<"Concepcion del nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Diseno ()
	{
		cout<<"Disenando el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Planificacion ()
	{
		cout<<"Planificando el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Produccion ()
	{
		cout<<"Produciendo el nuevo juego de Aprendizaje "<<name<<endl;
	}
	virtual void Prueba ()
	{
		cout<<"Probando el nuevo juego de Aprendizaje "<<name<<endl;
	}
};
template <class VJ> 
VJ* factoryMethod(string _name, float _price)
{
	std::cout<<"Ordenando creacion de videojuego "<<_name<<" y con precio "<<_price<<endl;
	VJ* tmp = new VJ(_name, _price);
    tmp->VJ::Concepcion();
    tmp->VJ::Diseno();
    tmp->VJ::Planificacion();
    tmp->VJ::Produccion();
    tmp->VJ::Prueba();
    return tmp;
}
class Item
{
protected:
	int tag;
	Videojuego* game;
public:
	Item(Videojuego* _game)
	{
		tag = generateTag();
		game = _game;
	}
	int generateTag()
	{
		srand (time(NULL));
		int tag = rand() % 85015245 * rand() % 26354165;
		/*for (int i = 0; i < usedTags->size(); i++)
		{
			if(tag==usedTags->at(i))
			{
				tag = rand() % 85015245 * rand() % 26354165;
				//i=0;
			}
		}*/
		usedTags.push_back(tag);
		return tag;
	}
	int getTag()
	{
		return tag;
	}
	float getPrice()
	{
		return game->getPrice();
	}
	string getName()
	{
		return game->getName();
	}
};
class Warehouse
{
private:
	static Warehouse* Instance;
	Warehouse()
	{
		Instance = this;
	}
protected:
	vector<Item> inventory;
	vector<Item> undoDel;
public:
	static Warehouse* create()
	{
		if (Instance==NULL)
		{
			Warehouse();
			return Instance;
		}
		return Instance;
	}
	void addInventory(Videojuego* _game, int invn)
	{
		Item tmp2 = Item(_game);
		std::cout<<"INVN: "<<invn<<endl;
		for (int j = 0; j < invn; j++)
		{
			inventory.push_back(tmp2);
			std::cout<<"Adding item "<<j<<" with tag: "<<tmp2.getTag()<<endl;
			tmp2 = Item(_game);
		}
	}
	void getInventory()
	{
		std::cout<<inventory.size()<<" items in inventory"<<endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			std::cout<<i<<". Name:"<<inventory.at(i).getName()<<", Serial Number: "<<inventory.at(i).getTag()<<", Price: "<<inventory.at(i).getPrice();
		}
	}
	void deleteItem (int _tag)
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			if(inventory.at(i).getTag()==_tag)
			{
				undoDel.push_back(inventory.at(i));
				inventory.erase(inventory.begin() + i);
			}
			if (undoDel.size()>2)
			{
				undoDel.erase(undoDel.begin());
			}

		}
	}
	void restoreItem()
	{
		if (undoDel.size()==0)
			cout<<"No items to restore"<<endl;
		for (int i = 0; i < undoDel.size(); i++)
		{
			inventory.push_back(undoDel.at(i));
		}
		undoDel.clear();
	}

};
void addGame(Warehouse** inv)
{

}
void menuPrint()
{
	cout<<"	1. Add games to inventory"<<endl;
	cout<<"	2. Delete games from inventory"<<endl;
	cout<<"	3. Undo deletion of last 3 elements"<<endl;
	cout<<"	4. Quit"<<endl;
}
void menu()
{
	cout<<"Hector Mauricio Gonzalez Coello"<<endl;
	int selection, s2, _tag = 0;
	Warehouse* nw = Warehouse::create();
	string _name = "HOLA";
	float _price = 10.06;
	Aprendizaje* x = factoryMethod<Aprendizaje>(_name, _price);
	menuPrint();
	cin>>selection;
	while(selection!=-1)
	{
		switch(selection)
	    {  
	        case 1:
	           	nw->addInventory(x->clone<Aprendizaje>(), 50);
	           	menuPrint();
	           	cin>>selection;
	           	break;  
	        case 2:
	        	cout<<"Give me the tag to delete"<<endl;
	        	cin>>_tag;
	        	nw->deleteItem(_tag);
	        	menuPrint();
	           	cin>>selection;
	           	break;
	        case 3:
	        	nw->restoreItem();
	        	menuPrint();
	           	cin>>selection;
	        	break;
	        case 4:
	        	selection=-1;
	        	cout<<"Goodbye"<<endl;
	        	break;  
	        default:
	        	cout<<"Invalid selection"<<endl;
	           	menuPrint();
	           	cin>>selection;
	           	break;  
	    }
    }  	
}
Warehouse* Warehouse::Instance = NULL;
int main()
{
	menu();
	//nw->getInventory();
}