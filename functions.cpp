#include "functions.h"//read header guard
//g++ functions.cpp square.cpp circle.cpp rectangle.cpp Main.cpp cross.cpp shapeTwoD.cpp -o csci_a2.exe
//./
vector<shapeTwoD*>shapeHolder;//hold shape 
const int PI = 3.142;//PI value for circle area
const int crossVertices = 12;//cross vertices will be same 
const int recSquareVertices =4;//square and rectangle vertices will be same
//
//print main menu for user 
int printMenu()
{
	bool menu_continue = true;
	int userinput;
	do
	{
		cout<<"Student ID: 7000"<<endl;
		cout<<"Student Name: Patel Mihir Mukeshbhai"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"Welcome to Assn2 program!"<<endl<<endl;
		cout<<"1) Input sensor data"<<endl;
		cout<<"2) Compute area(for all records)"<<endl;
		cout<<"3) Print shapes report"<<endl;
		cout<<"4) Sort shape data"<<endl;
		cout<<"5) Quit program"<<endl<<endl;
		cout<<"Please enter your choice:";
		cin>>userinput;
		//if user enters a unknown number make them types again
		while(!((userinput==1)||(userinput==2)||(userinput==3)||(userinput==4)||(userinput==5)))
		{
			cout<<"Please enter a valid choice from (1 to 5);"<<endl;
			cin>>userinput;
		}
		if(userinput ==1)
		{
			cout<<endl;
			option1();
			cout<<endl;
			cout<<"Record sucessfully stored,Going back to main menu..."<<endl<<endl;;
		}
		else if(userinput ==2)
		{
			cout<<endl;
			option2();
		}
		else if(userinput ==3)
		{
			cout<<endl;
			option3();
		}
		else if(userinput==4)
		{
			cout<<endl;
			option4();
		}
		else 
		{
			cout<<endl;
			menu_continue=false;
			cout<<"Exiting"<<endl;
			cout<<endl;
		}
	}while(menu_continue == true);
}

string toLowerCase(string name)
{
	char *cstr = new char[name.length()+1];
	strcpy(cstr,name.c_str());
	for(int i=0;i<name.length();i++)
	{
		cstr[i] =tolower(cstr[i]);
	}
	string s;
	for(int i=0;i<name.length();i++)
	{
		s+= cstr[i];
	}
	delete []cstr;
	return s;
}

void option1()
{
	string name;
	string special_Type;
	bool wronginput =true;
	bool containsWarpSpace;
	int tempX;
	int tempY;
	int tempRadius;
	int static counter = 0;
	
	cout<<"[Input sensory data]"<<endl;
	
	do
	{
		cout<<"Please enter name of shape: ";
		cin>>name;
		name =  toLowerCase(name);
		if((name == "cross") || (name == "rectangle")||(name =="square")||(name =="circle"))
		{
			wronginput=false; 
		}
		else 
		{
			cout<<"Please enter cross/rectangle/square/circle"<<endl;
		}
		
	}while(wronginput==true);
	
	wronginput = true;
	
	do
	{
		cout<<"Please enter special type: ";
		cin>>special_Type;
		special_Type  = toLowerCase(special_Type);
		if(special_Type == "ws" || special_Type =="ns")
		{
			wronginput = false;
		} 
		else 
		{	
			cout<<"Please enter correctly (WS OR NS) "<<endl;
		}
		
	}while(wronginput == true);
	
	if(special_Type == "ws")
	{
		containsWarpSpace = true;
	}
	else 
	{
		containsWarpSpace = false;
	}
		
	if(name == "cross")
	{
		shapeHolder.push_back(new cross(name, containsWarpSpace));
		int x[crossVertices];
		int y[crossVertices];
		int xy = 0;
		
		
		for(int i = 0; i < crossVertices; i++)
		{
		
			wronginput = true;
			bool okay;
			coord c;
			
			do
			{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < crossVertices; j++)
				{
					if(tempX == x[j] && tempY == y[j])
					{
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				
				if(okay == true)
				{
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					shapeHolder[(shapeHolder.size() - 1)]->setCoord(c);
					wronginput = false;
				}
				
				else if(okay == false)
				{
					wronginput = true;
				}
				
			}while(wronginput == true);
		} 
		
		shapeHolder[(shapeHolder.size() - 1)]-> setMinMax();
		shapeHolder[(shapeHolder.size() - 1)] -> setShapeNum(counter);
		counter += 1;
	}
	
	else if(name == "square")
	{
		shapeHolder.push_back(new square(name,containsWarpSpace));
		int x[recSquareVertices];
		int y[recSquareVertices];
		
		int xy = 0;
		
		for(int i = 0; i < recSquareVertices; i++)
		{
			coord c;
			wronginput = true;
			bool okay;
			do
			{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < recSquareVertices; j++)
				{
					if(tempX == x[j] && tempY == y[j])
					{
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				
				if(okay == true)
				{
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					shapeHolder[(shapeHolder.size() - 1)]->setCoord(c);
					wronginput = false;
				}
				
				else if(okay == false)
				{
					wronginput = true;
				}
				
			}while(wronginput == true);
		} 
		
		shapeHolder[(shapeHolder.size() - 1)]-> setMinMax();
		shapeHolder[(shapeHolder.size() - 1)] -> setShapeNum(counter);
		counter += 1;
	}
	else if(name == "rectangle")
	{
		shapeHolder.push_back(new rectangle(name, containsWarpSpace));
		int x[recSquareVertices];
		int y[recSquareVertices];
		int xy = 0;
		for(int i = 0; i < recSquareVertices; i++)
		{
			coord c;
			wronginput = true;
			bool okay;
			do
			{
				cout << "Please enter x-oridinate of pt." << i+1 << ": ";
				cin >> tempX;
				cout << "Please enter y-oridinate of pt." << i+1 << ": ";
				cin >> tempY;
				okay = true;
				for(int j = 0; j < recSquareVertices; j++)
				{
				
					if(tempX == x[j] && tempY == y[j])
					{
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						okay = false;
					}
				}
				if(okay == true)
				{
					x[xy] = tempX;
					y[xy] = tempY;
					c.x = tempX;
					c.y = tempY;
					xy += 1;
					shapeHolder[(shapeHolder.size() - 1)]->setCoord(c);
					wronginput = false;
				}
				else if(okay == false)
				{
					wronginput = true;
				}
			}while(wronginput == true);
		} 
		
		shapeHolder[(shapeHolder.size() - 1)]-> setMinMax();
		shapeHolder[(shapeHolder.size() - 1)] -> setShapeNum(counter);
		counter += 1;
	}
	
	else if(name == "circle")
	{
		shapeHolder.push_back(new circle(name, containsWarpSpace));
		coord c;
		int rad;
		
		cout << "Please enter x-oridinate of center: ";
		cin >> c.x;
		cout << "Please enter y-oridinate of center: ";
		cin >> c.y;
		
		shapeHolder[(shapeHolder.size() - 1)]->setCoord(c);
		
		cout << "Please enter radius(units): ";
		cin >> rad;
		
		shapeHolder[(shapeHolder.size() - 1)]->setRadius(rad);
		shapeHolder[(shapeHolder.size() - 1)]-> setMinMax();
		shapeHolder[(shapeHolder.size() - 1)] -> setShapeNum(counter);
		counter += 1;
	}

}
//sorting
bool compareAreaAsc(shapeTwoD *a, shapeTwoD *b)
{
	return b->getArea() > a->getArea();
}

bool compareAreaDesc(shapeTwoD *a, shapeTwoD *b)
{
	return b->getArea() < a->getArea();
}

bool compareWarpAreaDesc(shapeTwoD *a, shapeTwoD *b)
{
	if(a->getContainsWarpSpace() != b->getContainsWarpSpace())
	{
		return a-> getContainsWarpSpace() == true;
	}
	else
	{
		return a->getArea() > b-> getArea();
	}
}


void option2()
{
	if(shapeHolder.size() == 0)
	{
		cout << "You have not input data" << endl;
	}
	else
	{
		for(unsigned int i = 0; i < shapeHolder.size(); i++)
		{
			shapeHolder[i] -> computeArea();
		}
		
		cout << "Computation completed (" << shapeHolder.size() << " records were updated)" << endl<<endl;
	}
}

void option3()
{
	if(shapeHolder.size() == 0)
	{
		cout << "You have not input data" << endl;
	}
	else
	{
		cout << "Total no. of records available = " << shapeHolder.size() << endl;
		cout << endl;
		for(unsigned int i = 0; i < shapeHolder.size(); i++)
		{
			cout << shapeHolder[i] -> toString() << endl;
		}
	}
}
void option4()
{
	string abc;
	static int i = 0;
	if(shapeHolder.size() == 0)
	{
		cout << "You have not input data" << endl;
	}
	else
	{
		do
		{
			cout << "      a)    Sort by area (ascending)" << endl;
			cout << "      b)    Sort by area (descending)" << endl;
			cout << "      c)    Sort by special type and area" << endl;
			cout << "Please select sort option ('q' to go main menu) : ";
			cin >> abc;
		
			abc = toLowerCase(abc);
		
			if (abc == "a")
			{
				cout << "Sort by area (smallest to largest)" << endl;
				sort(shapeHolder.begin(), shapeHolder.end(), compareAreaAsc);
				abc = "q";
			}
			else if (abc == "b")
			{
				cout << "Sort by area (largest to smallest)" << endl;
				sort(shapeHolder.begin(), shapeHolder.end(), compareAreaDesc);
				abc = "q";
			}
			else if (abc == "c")
			{
				cout << "Sort by special type (WS then NS) and area (largest to smallest)" << endl;
				sort(shapeHolder.begin(), shapeHolder.end(), compareWarpAreaDesc);
				abc = "q";
			}
			else if (abc == "q")
			{
				break;
			}
			else
			{
				cout << "Please input the correct value (a,b,c,q)" << endl << endl; 
			}
		}while(abc != "q");
		
		cout << endl;
		for(unsigned int i = 0; i < shapeHolder.size(); i++){
			cout << shapeHolder[i]->toString() << endl;
		}
	}
}








